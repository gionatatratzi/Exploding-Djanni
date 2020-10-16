#ifndef GESTIONE_CARTE_H_INCLUDED
#define GESTIONE_CARTE_H_INCLUDED

int scendiCarta(int i, int w, int carteRimaste, Tipologia *vettoreCarte, Tipologia *giocatore[N_GIOC], DatiGioco Id[N_GIOC]){
	int h, a, sceltaCarta, counter=0;//variabili

	printf("\nLe tue carte sono:\n\n");
    for(h=0; h<Id[i].number.numero; h++){//ciclo stampa le carte rimaste
        printf("%d %s\n", h, stringaCarta[(int)giocatore[i][h]]);//stampa le carte
	}
	printf("\nScegli la carta digitando il numero posto al lato sinistro  ");
	scanf("%d", &sceltaCarta);
	getchar();
	printf("\nLa carta scesa e'\n%s\n", stringaCarta[sceltaCarta]);

	//controllo per stabilire se il giocatore quale carta possiede
	if(((int)giocatore[i][sceltaCarta]>=MIN_MEOOOW)&&((int)giocatore[i][sceltaCarta]<=MAX_MEOOOW)){
		Id[i].number.numMeooow--;//decrementa numero carte meooow del giocatore i
	}else if(((int)giocatore[i][sceltaCarta]>=MIN_NOPE)&&((int)giocatore[i][sceltaCarta]<=MAX_NOPE)){
		Id[i].number.numNope--;//decrementa numero carte nope del giocatore i
	}else if(((int)giocatore[i][sceltaCarta]>=MIN_SHUFFLE)&&((int)giocatore[i][sceltaCarta]<=MAX_SHUFFLE)){
		shuffle(counter, i, carteRimaste, vettoreCarte, Id);//subroutine
	}else if(((int)giocatore[i][sceltaCarta]>=MIN_SEE_THE_FUTURE)&&((int)giocatore[i][sceltaCarta]<=MAX_SEE_THE_FUTURE)){
		seeTheFuture(counter, i, vettoreCarte, Id);//subroutine
	}else if(((int)giocatore[i][sceltaCarta]>=MIN_ATTACK)&&((int)giocatore[i][sceltaCarta]<=MAX_ATTACK)){
		attack(counter, i, Id);//subroutine
	}else if(((int)giocatore[i][sceltaCarta]>=MIN_SKIP)&&((int)giocatore[i][sceltaCarta]<=MAX_SKIP)){
		skip(counter, i, Id);//subroutine
	}else if(((int)giocatore[i][sceltaCarta]>=MIN_FAVOR)&&((int)giocatore[i][sceltaCarta]<=MAX_FAVOR)){
		favor(counter, i, giocatore, Id);//subroutine
	}else if(((int)giocatore[i][sceltaCarta]>=MIN_DJANNI_CARDS)&&((int)giocatore[i][sceltaCarta]<=MAX_DJANNI_CARDS)){
		djanniCards(counter, i, giocatore, Id);//subroutine
	}
	Id[i].flag.nonPesca=false;//flag settato a false

    for(h=sceltaCarta, a=sceltaCarta+UNO; a<Id[i].number.numero; h++, a++){
        giocatore[i][h]=giocatore[i][a];
    }
    Id[i].number.numero--;

	//ri-allocazione dinamica dei mazzi dei 4 giocatori
    giocatore[i]=(Tipologia*)realloc(giocatore[i], Id[i].number.numero*sizeof(Tipologia));//viene allocata
    if(giocatore[i]==NULL) exit(-1);//verifica se l'allocazione e' andata a buon fine

	return sceltaCarta;//valore restituito
}
void pescaCarta(int sceltaCarta, int i, int carteRimaste, Tipologia *vettoreCarte, Tipologia *giocatore[N_GIOC], DatiGioco Id[N_GIOC]){
	int h, a;//variabili

	printf("\nPeschiamo una carta dal mazzo\n");
	printf("\nLa carta pascata e'\n");//pesca la carta dal mazzo se hai premuto p,P
	printf("%s\n\n\n", stringaCarta[(int)vettoreCarte[ZERO]]);

	if(!((sceltaCarta>=MIN_EXPLODING_DJANNI)&&(sceltaCarta<=MAX_EXPLODING_DJANNI))){
         giocatore[i][Id[i].number.numero+1]=vettoreCarte[ZERO];//inserisci la carta pescata
    }
	//controllo per stabilire se il giocatore i possiede una meooow e/o una nope
	if(((int)vettoreCarte[0]>=MIN_MEOOOW)&&((int)vettoreCarte[0]<=MAX_MEOOOW)){
		Id[i].number.numMeooow++;//incremento numero meooow
	}else if(((int)vettoreCarte[0]>=MIN_NOPE)&&((int)vettoreCarte[0]<=MAX_NOPE)){
		Id[i].number.numNope++;//incremento numero nope di i
	}else if(((int)vettoreCarte[0]>=MIN_EXPLODING_DJANNI)&&((int)vettoreCarte[0]<=MAX_EXPLODING_DJANNI)){
		explodingDjanni(i, carteRimaste, vettoreCarte, giocatore, Id);//subroutine
	}
	Id[i].number.numero++;//incremento del numero di carte di i

	 //ri-allocazione dinamica mazzo di carte principale
    giocatore[i]=(Tipologia*)realloc(giocatore[i], Id[i].number.numero*sizeof(Tipologia));//viene allocata
    if(giocatore[i]==NULL) exit(-1);//verifica se l'allocazione e' andata a buon fine

    giocatore[i][Id[i].number.numero-UNO]=vettoreCarte[0];

	for(h=0, a=1; h<carteRimaste; h++, a++){//ciclo
		vettoreCarte[h]=vettoreCarte[a];//scala di una posizione le carte del mazzo principale
	}
	carteRimaste--;//carte rimaste nel mazzo princiale

	//ri-allocazione dinamica mazzo di carte principale
    vettoreCarte=(Tipologia*)realloc(vettoreCarte, carteRimaste*sizeof(Tipologia));//viene allocata
    if(vettoreCarte==NULL) exit(-1);//verifica se l'allocazione e' andata a buon fine

	Id[i].flag.flagPesca=true;//flag settatoa true
	Id[i].flag.nonPesca=true;//flag settatoa true
}
void turnoGiocatore(int i, int carteRimaste, Tipologia *vettoreCarte, Tipologia *giocatore[N_GIOC], DatiGioco Id[N_GIOC]){
    int h, w, k, sceltaCarta;
    FILE *fp=NULL;//puntatore per il file di salvataggio e caricamento della partita
    char opzione, scelta;//variabibli
    char nomeFile[DIM+1]="partita.sav";//nome file di salvataggio

    w=i+1;
    for(h=4, k=0; k<=3; h++, k++){//ciclo
        if(w==h) w=k;//se w=4 allora w=0, se w=7 allora w=3
    }
    if(w==8) w=0;//se w=8 allora w=0

    do{
        printf("\nPer scendere una carta..........premi 'g'");
        printf("\nSe vuoi pescare................premi  'p'");
        printf("\nPer uscire dal gioco...........premi  'x'");
        printf("\nPer salvare la partita.........premi  's'\n");
        scanf("%c", &scelta);
        getchar();//getchar per il carattere invio

        switch(scelta){
            case 'g':
            case 'G':
                do{
                    if(Id[i].flag.nonScende==false){//controllo per il giocatore che non deve scendere carte
                        sceltaCarta=scendiCarta(i, w, carteRimaste, vettoreCarte, giocatore, Id);//subroutine
                    }
                }while(sceltaCarta>=Id[i].number.numero);//controllo se la carta scelta è >= del numero di carte del giocatore

                if(Id[i].number.numero==0){//quando non hai piu' carte pesca e passa il turno
                    printf("\nNon hai piu' carte quindi pesca e termina il turno\n");
                    pescaCarta(sceltaCarta, i, carteRimaste, vettoreCarte, giocatore, Id);
                }else if(Id[i].flag.nonPesca==false){//controllo per il giocatore che non deve pescare
                    do{
                        printf("\nSe vuoi scendere un'altra carta premi 'y'");
                        printf("\nAltrimanti pesca una carta premendo 'p'\n");
                        scanf("%c", &opzione);
                        getchar();//getchar per il carattere invio

                        for(h=0; h<Id[i].number.numero; h++){//ciclo stampa le carte rimaste
                                printf("%d %s\n", h, stringaCarta[(int)giocatore[i][h]]);
                            }
                        switch(opzione){//ciclo
                            case 'p':
                            case 'P':
                                //ripesca la carta dal mazzo se hai premuto p,P
                                pescaCarta(sceltaCarta, i, carteRimaste, vettoreCarte, giocatore, Id);//subroutine
                                break;
                            case 'y':
                            case 'Y':
                                return turnoGiocatore(i, carteRimaste, vettoreCarte, giocatore, Id);//subroutine
                                break;
                            default:
                                printf("\nCarattere inserito non valido\n");
                                break;
                        }
                    }while((Id[i].flag.nonPesca==false)||//controllo per il giocatore che non deve pescare
                           (!((opzione=='P')||(opzione=='p')||(opzione=='Y')||(opzione=='y'))));
                }
                break;
            case 'p':
            case 'P':
                if(Id[i].flag.nonPesca==false){//controllo per il giocatore che non deve pescare
                    do{
                        pescaCarta(sceltaCarta, i, carteRimaste, vettoreCarte, giocatore, Id);
                    }while(Id[i].flag.nonPesca==false);//controllo per il giocatore che non deve pescare
                }
                break;
            case 's':
            case 'S':
                /*Salvataggio partita (nome file predefinito: partita.sav)
                su file binario (vedi specifiche) in ogni momento (qualsiasi turno, qualsiasi giro);*/
                fp=fopen(nomeFile, "wb");//file di salvataggio

                fwrite(vettoreCarte, sizeof(Tipologia), MAX_CARTA, fp);//salva carte mazzo principale
                fwrite(&carteRimaste, sizeof(int), 1, fp);//salva carte rimaste nel mazzo principale
                for(h=0; h<4; h++){//ciclo
                    fwrite(giocatore[h], sizeof(Tipologia), MAX_CARTA, fp);//salva carte mazzo di 4 giocatori
                    fwrite(&Id[h].flag.doppioTurno, sizeof(_Bool), 1, fp);//salva chi deve fare 2 turni
                    fwrite(&Id[h].number.numero, sizeof(int), 1, fp);//salva numero carte rimaste nei 4 mazzi dei giocatori
                    fwrite(Id[h].nome, sizeof(char), STRINGA_GIOCATORE+1, fp);//salva stringa nome giocatore 1
                }
                fclose(fp);//chiusura file di salvattaggio
                break;
            case 'x':
            case 'X':
                exit(-1);//uscita
                break;
            default:
                printf("\nOpzione inserita non valida\n");
                break;
        }
    }while((Id[i].flag.flagPesca==false)||//condizione di uscita ciclo
           (!((scelta=='G')||(scelta=='g')||(scelta=='P')||(scelta=='p')||
                (scelta=='S')||(scelta=='s')||(scelta=='X')||(scelta=='x'))));
}
#endif // GESTIONE_CARTE_H_INCLUDED
