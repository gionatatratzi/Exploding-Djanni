#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "macro_strutture_stringhe.h"
#include "carte_da_gioco.h"
#include "gestione_carte.h"
#include "istruzioni.h"

//***************************************
//********* EXPLODING DJANNI ************
//**** TRATZI GIONATA 60/61/65246 *******
//***************************************

/*Funzionamento generale
Si ha un mazzo si carte che contiene, tra le altre, le carte EXPLODING DJANNI. Si gioca girando carta per
carta fino a quando qualcuno pesca un EXPLODING DJANNI. Quando la persona pesca la carta esplosiva
essa stessa esplode, e muore, ovvero è fuori dal gioco. Numero giocatori stabilito a 4.
Il gioco prosegue fino a quando tutti i giocatori tranne uno sono morti. Colui che si salva è il vincitore.
In poche parole se esplodi perdi, se non esplodi, vinci. Tutte le carte nel mezzo permettono di salvarsi da
eventuali esplosioni. L’unico modo per non morire con l’EXPLODING DJANNI è utilizzare subito dopo
una carta MEOOOW.*/
int main(int argc, char *argv[]){//funzione main

	FILE *fp=NULL;//puntatore per il file di salvataggio e caricamento della partita
    DatiGioco Id[N_GIOC];//array della struttura DatiGioco
	char nomeFile[DIM+1]="partita.sav";//nome file di salvataggio
	char intro, uscita;//variabili char
	int randomTurno;//variabili
	int h, i, j, w, k, a;//variabili indice
	int carteRimaste;//variabile
	_Bool flagCartaBool;//flag
	_Bool cartaBooleano[MAX_CARTA];//flag carte scese
    Tipologia *vettoreCarte=NULL;//puntatore mazzo principale
    Tipologia *giocatore[N_GIOC]={NULL, NULL, NULL, NULL};//puntatore di puntatore delle carte possedute dai 4 giocatori

	srand(time(NULL));//seme della randomizzazione

	//menu' principale
	do{
		printf("\n***********************************************************************");
		printf("\n***********************************************************************");
		printf("\n****************         EXPLODING  DJANNI          *******************");
		printf("\n***********************************************************************");
		printf("\n***********************************************************************\n\n");
		printf("\nNuova partita............premi 'n'");
		printf("\nCarica partita...........premi 'c'");
		printf("\nLeggi istruzioni.........premi 'i'");
		printf("\n");
		scanf("%c", &intro);
		getchar();//getchar per non considerare l'invio come un carattere

			switch(intro){//ciclo
				case 'i':
				case 'I':
					istruzioni();//subroutine istruzioni gioco
					break;
				case 'c':
				case 'C':
					/*Caricamento partita (nome file predefinito: partita.sav)
					caricamento carte file salvataggio (vedi specifiche), caricamento giocatori file salvataggio (vedi
					specifiche), nessun mescolamento e si inizia dal giocatore a cui spetta il turno di gioco;*/
					fp=fopen(nomeFile, "rb");//file di caricamento partita

				   	fread(vettoreCarte, sizeof(Tipologia), MAX_CARTA, fp);//carica mazzo principale
				   	fread(&carteRimaste, sizeof(int), 1, fp);//carica carte rimaste nel mazzo principali
				   	for(h=0; h<4; h++){//ciclo
                        fread(giocatore[h], sizeof(Tipologia), MAX_CARTA, fp);//carica mazzo 4 giocatori
                        fread(&Id[h].flag.doppioTurno, sizeof(_Bool), 1, fp);//carica chi deve fare 2 turni
                        fread(&Id[h].number.numero, sizeof(int), 1, fp);//carica numero carte rimaste ai 4 giocatori
                        fread(Id[h].nome, sizeof(char), STRINGA_GIOCATORE+1, fp);//carica stringa nome giocatore 1
				   	}
				    fclose(fp);//chiusura file di caricamento
					break;
				case 'n':
				case 'N':
					printf("Inserire il nome del giocatore 1:  ");
					scanf("%[^\n]s", Id[utente1].nome);//input nome giocatore 1
					getchar();//getchar per non considerare l'invio come un carattere
					printf("Inserire il nome del giocatore 2:  ");
					scanf("%[^\n]s", Id[utente2].nome);//input nome giocatore 2
					getchar();//getchar per non considerare l'invio come un carattere
					printf("Inserire il nome del giocatore 3:  ");
					scanf("%[^\n]s", Id[utente3].nome);//input nome giocatore 3
					getchar();//getchar per non considerare l'invio come un carattere
					printf("Inserire il nome del giocatore 4:  ");
					scanf("%[^\n]s", Id[utente4].nome);//input nome giocatore 4
					getchar();//getchar per non considerare l'invio come un carattere
					break;
				default:
					printf("\nERRORE - tasto premuto non valido\n");
					break;
				}
		}while(!((intro=='c')||(intro=='C')||(intro=='n')||(intro=='N'))||
			(intro=='i')||(intro=='I'));//cicla se intro e' diverso da c,C,n,N

	/*All’inizio del gioco di tolgono le carte EXPLODING DJANNI (3 carte) e le carte MEOOOW (4 nella
	modalità HARD, 6 nella MEDIUM, 8 nella EASY) e si mettono da una parte, si mescolano le rimanenti e si
	danno 4 carte a giocatore. Si consegna una carta MEOOOW ad ogni giocatore in modo che ogni
	giocatore abbia in totale 5 carte. Si reinseriscono nel mazzo le carte MEOOOW e le carte EXPLODING
	DJANNI e si mescola nuovamente.*/

	//allocazione dinamica mazzo di carte principale
    vettoreCarte=(Tipologia*)malloc(MAX_CARTA*sizeof(Tipologia));//viene allocata la malloc
    if(vettoreCarte==NULL) exit(-1);//verifica se l'allocazione e' andata a buon fine

	//allocazione dinamica dei mazzi dei 4 giocatori
    for(h=0; h<N_GIOC; h++){
        giocatore[h]=(Tipologia*)malloc(MAX_CARTA*sizeof(Tipologia));//viene allocata la malloc
        if(giocatore[h]==NULL) exit(-1);//verifica se l'allocazione e' andata a buon fine
    }

	//mescolamento carte
	for(h=MIN_CARTA; h<MAX_CARTA-PARAMETRO_INIZIALE; h++){//ciclo
		do{
			flagCartaBool=false;//flag
			vettoreCarte[h]=(Tipologia)PARAMETRO_INIZIALE+rand()%(MAX_CARTA-PARAMETRO_INIZIALE+1);//generazione casuale della carta

			for (j=PARAMETRO_INIZIALE; j<h; j++) {//ciclo
                if((vettoreCarte[h]==vettoreCarte[j])&&(flagCartaBool==false)){
                    //contollo se il vettroreCarte con indice h che va da 0 a MAX_CARTA
                    //e' uguale al vettoreCarte con indice j che va da 11 a j<h
                    flagCartaBool=true;//flag
                }
            }
		}while(flagCartaBool==true);//cicla sinche le caselle non sono tutte piene
	}
	//cliclo per la stampa delle carte
	for(i=0; i<4; i++){//ciclo utente i-esimo
        printf("\n\n%s\n", Id[i].nome);//distribuzione carte ai giocatori 5 a testa
        printf("\n%s", stringaCarta[MIN_MEOOOW+i]);//distribuzione di 4 carte + 1 MEOOOW a 4 giocatori
        giocatore[i][ZERO]=MIN_MEOOOW+i;//assegnamento carta meooow a giocatore i
        cartaBooleano[MIN_MEOOOW+i]=true;

        for(h=0; h<4; h++){
            printf("\n%s", stringaCarta[(int)vettoreCarte[h+i]]);//le carte scese dei giocatori vengono messe a true
            giocatore[i][h+UNO]=vettoreCarte[h+i];//assegnamento delle carte al mazzo del singolo giocatore
            cartaBooleano[(int)vettoreCarte[h+i]]=true;
        }
        Id[i].number.numero=CINQUE;//tutti i giocatori possiedono 5 carte
	}
	carteRimaste=RIMASTE-SETTE;//le carte sono 30

	for(h=0, a=SEDICI; a<MAX_CARTA; h++, a++){
        vettoreCarte[h]=vettoreCarte[a];//scala le carte di 16 posizioni
	}
	for(h=carteRimaste, a=0; a<TRE; h++, a++){
        vettoreCarte[h]=(int)a;//aggiungi in coda exploding djanni
	}
	for(h=carteRimaste+TRE, a=SETTE; a<PARAMETRO_INIZIALE; h++, a++){
        vettoreCarte[h]=(int)a;//aggiungi in coda meooow rimanenti
	}
	carteRimaste=RIMASTE;//le carte rimaste prima il mescolamento sono 37
	//mescolamento carte
	for(h=MIN_CARTA; h<carteRimaste; h++){//ciclo
		do{
			flagCartaBool=false;//flag
			vettoreCarte[h]=(Tipologia)MIN_CARTA+rand()%(carteRimaste-MIN_CARTA+1);//generazione casuale della carta

			for (j=0; j<h; j++) {//ciclo
                if((vettoreCarte[h]==vettoreCarte[j])&&(flagCartaBool==false)&&(cartaBooleano[h]==false)){
                    //contollo se il vettroreCarte con indice h che va da 0 a MAX_CARTA
                    //e' uguale al vettoreCarte con indice j che va da 0 a j<h
                    flagCartaBool=true;//flag
                }
            }
				//cicla sinche le caselle non sono tutte piene
		}while(flagCartaBool==true);//ciclo
	}
	for(i=0; i<4; i++){//ciclo
		Id[i].number.numMeooow=1;//all'inizio i meooow sono uno a testa
		for(h=1; h<=4; h++){//controllo per stabilire se il giocatore i possiede una o più nope
			if(((int)giocatore[i][h]>=MIN_NOPE)&&((int)giocatore[i][h]<=MAX_NOPE)){
				Id[i].number.numNope++;//incremento numero nope del giocatore i
			}
		}
	}
	randomTurno=rand()%4;//generazione casuale turno giocatori
	for(h=0; h<N_GIOC; h++){//ciclo
        Id[h].flag.morto=false;//all'inizio tutti i giocatori sono vivi
	}
	//il gioco comincia*********************************************************
    for(i=randomTurno, w=(randomTurno+1); i<=(4+randomTurno); i++, w++){//ciclo che stabilisce il turno dei giocatori
        for(h=4, k=0; k<=3; h++, k++){
            if(i==h) i=k;//se i=4 allora i=0, se i=7 allora i=3
            if(w==h) w=k;//se w=4 allora w=0, se w=7 allora w=3
        }
        if(w==8) w=0;//se w=8 allora w=0

        if((Id[w].flag.doppioTurno==true)&&(Id[w].number.flagDoppio<3)){//flag di controllo per chi deve fare 2 turni
            Id[w].number.flagDoppio++;//incremento flag
            if(Id[w].number.flagDoppio>1) {i--; w--;}
            if(i<0) i=3;//se i è minore di zero i=3
            if(w<0) w=3;//se w che è i+1 è minore di zero w=3
        }else{
            Id[w].number.flagDoppio=0;//azzeramento flag
            Id[w].flag.doppioTurno=false;//flag settato a false
        }
        //flag di controllo per chi deve saltare 1 turno
        if(Id[i].flag.flagTurno==true) {i++; w++;}
        else{
            Id[i].flag.flagTurno=false;//flag settato a false
        }
        //se il giocatore i è morto passa al giocatore sucessivo
        if(Id[i].flag.morto==true) {i++; w++;}
        if(i==4) i=0;//se i=4 azzera i
        if(w==4) w=0;//se w=4 azzera w

        Id[i].flag.nonPesca=false;//flag se non deve pescare
        Id[i].flag.flagPesca=false;//flag per stabilire se ha pescato
        Id[i].number.grasso=0;//djanni cards settate a zero
        Id[i].number.social=0;//djanni cards settate a zero
        Id[i].number.miagolante=0;//djanni cards settate a zero
        Id[i].number.affamato=0;//djanni cards settate a zero
        Id[i].number.dormiente=0;//djanni cards settate a zero

        printf("\n\n\n**********************************");
        printf("\n\tTURNO DEL GICATORE: %s", Id[i].nome);
        printf("\n**********************************\n");

        turnoGiocatore(i, carteRimaste, vettoreCarte, giocatore, Id);//subroutine

        if((Id[utente1].flag.morto==false)&&(Id[utente2].flag.morto==true)&&
                (Id[utente3].flag.morto==true)&&(Id[utente4].flag.morto==true)){//ha vinto il giocatore 1
            printf("\n\n***********************************************************************\n");
            printf("        IL GIOCATORE %s HA VINTO\n", Id[utente1].nome);
            printf("\n\n***********************************************************************\n");

            free(giocatore[utente1]);//deallocazione carte giocatore
            free(vettoreCarte);//deallocazione mazzo carte principale

            printf("\n\n\nPer uscire premi 'x':  ");
            scanf("%c", &uscita);
            getchar();//getchar per il carattere invio

            do{
                if((uscita=='x')||(uscita=='X')){
                    exit(-1);
                }else{
                    printf("\nCarattere inserito non valido\nripetere   ");
                }
            }while(!((uscita=='x')||(uscita=='X')));//il gioco finisce

        }else if((Id[utente2].flag.morto==false)&&(Id[utente3].flag.morto==true)&&
                (Id[utente4].flag.morto==true)&&(Id[utente1].flag.morto==true)){//ha vinto il giocatore 2
            printf("\n\n***********************************************************************\n");
            printf("        IL GIOCATORE %s HA VINTO\n", Id[utente2].nome);
            printf("\n\n***********************************************************************\n");

            free(giocatore[utente2]);//deallocazione carte giocatore
            free(vettoreCarte);//deallocazione mazzo carte principale

            printf("\n\n\nPer uscire premi 'x':  ");
            scanf("%c", &uscita);
            getchar();//getchar per il carattere invio

            do{
                if((uscita=='x')||(uscita=='X')){
                    exit(-1);
                }else{
                    printf("\nCarattere inserito non valido\nripetere   ");
                }
            }while(!((uscita=='x')||(uscita=='X')));//il gioco finisce

        }else if((Id[utente3].flag.morto==false)&&(Id[utente1].flag.morto==true)&&
                (Id[utente2].flag.morto==true)&&(Id[utente4].flag.morto==true)){//ha vinto il giocatore 3
            printf("\n\n***********************************************************************\n");
            printf("        IL GIOCATORE %s HA VINTO\n", Id[utente3].nome);
            printf("\n\n***********************************************************************\n");

            free(giocatore[utente3]);//deallocazione carte giocatore
            free(vettoreCarte);//deallocazione mazzo carte principale

            printf("\n\n\nPer uscire premi 'x':  ");
            scanf("%c", &uscita);
            getchar();//getchar per il carattere invio

            do{
                if((uscita=='x')||(uscita=='X')){
                    exit(-1);
                }else{
                    printf("\nCarattere inserito non valido\nripetere   ");
                }
            }while(!((uscita=='x')||(uscita=='X')));//il gioco finisce

        }else if((Id[utente4].flag.morto==false)&&(Id[utente1].flag.morto==true)&&
                (Id[utente2].flag.morto==true)&&(Id[utente3].flag.morto==true)){//ha vinto il giocatore 4
            printf("\n\n***********************************************************************\n");
            printf("        IL GIOCATORE %s HA VINTO\n", Id[utente4].nome);
            printf("\n\n***********************************************************************\n");

            free(giocatore[utente4]);//deallocazione carte giocatore
            free(vettoreCarte);//deallocazione mazzo carte principale

            printf("\n\n\nPer uscire premi 'x':  ");
            scanf("%c", &uscita);
            getchar();//getchar per il carattere invio

            do{
                if((uscita=='x')||(uscita=='X')){
                    exit(-1);
                }else{
                    printf("\nCarattere inserito non valido\nripetere   ");
                }
            }while(!((uscita=='x')||(uscita=='X')));//il gioco finisce
        }
    }
	return 0;//fine del main
}
