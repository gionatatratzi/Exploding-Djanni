#ifndef CARTE_DA_GIOCO_H_INCLUDED
#define CARTE_DA_GIOCO_H_INCLUDED

void attackDefault(int, int, DatiGioco[]);
void seeTheFutureDefault(int, Tipologia*, DatiGioco[]);
void shuffleDefault(int, int, Tipologia*, DatiGioco[]);
void skipDefault(int, DatiGioco[]);
void favorDefault(int, int, Tipologia*[], DatiGioco[]);
void djanniCardsDefault(int, int, Tipologia*[], DatiGioco []);

/*ATTACK (Permette di saltare il turno e costringe il giocatore successivo a fare due turni)
il giocatore successivo esegue due turni e può essere annullato dal NOPE o annulla un
precedente ATTACK che ha effetto quindi sul giocatore successivo;*/
void attack(int counter,  int i, DatiGioco Id[N_GIOC]){
	int h, k, w;//variabile
	char scelta;//variabile char
    _Bool flagEsci=false;//flag

    w=i+1;
    for(h=4, k=0; k<=3; h++, k++){//ciclo
        if(w==h) w=k;//se w=4 allora w=0, se w=7 allora w=3
    }
    if(w==8) w=0;//se w=8 allora w=0

	if(Id[w].number.numNope==0){//il giocatore i+1 non possiede la nope (w=i+1)
		return attackDefault(i, w, Id);//subroutine
	}else{//il giocatore i+1 possiede una nope
	    if(counter<6 && flagEsci==false){//controllo contatore e flag
            if((counter%2==0)&&(Id[w].number.numNope>0)){
                //controllo nope di w e turno pari di i
                do{
                printf("\n\nIl giocatore %s ha una NOPE", Id[w].nome);
                printf("\nVuoi giocarlo?");
                printf("\nSe si......premi 's'");
                printf("\nSe no......premi 'n'\n");
                scanf("%c", &scelta);
                getchar();//getchar per il carattere invio

                switch(scelta){
                    case 's'://il giocatore gioca la nope
                    case 'S':
                        printf("\nIl giocatore gioca la nope\n");
                        Id[w].number.numNope--;
                        Id[w].number.numero--;
                        return attack(counter+1, i, Id);//subroutine invoca se stessa
                        break;
                    case 'n'://il giocatore non gioca la nope
                    case 'N':
                        printf("\nIl giocatore non gioca la nope\n");
                        return attackDefault(i, w, Id);//subroutine
                        flagEsci=true;//flag
                        break;
                    default:
                        printf("\nDato inserito non valido\n");
                        break;
                    }
                }while(!((scelta=='s')||(scelta=='S')||(scelta=='n')||(scelta=='N')));//cicla se la scelta e' diversa dai case
            }else if((counter%2!=0)&&(Id[i].number.numNope>0)){
                //controllo nope di i e turno dispari di w
                do{
                printf("\n\nIl giocatore %s ha una NOPE", Id[i].nome);
                printf("\nVuoi giocarlo?");
                printf("\nSe si......premi 's'");
                printf("\nSe no......premi 'n'\n");
                scanf("%c", &scelta);
                getchar();//getchar per il carattere invio

                switch(scelta){
                    case 's'://il giocatore gioca la nope
                    case 'S':
                        printf("\nIl giocatore gioca la nope\n");
                        Id[i].number.numNope--;
                        Id[i].number.numero--;
                        return attack(counter+1, i, Id);//subroutine invoca se stessa
                        break;
                    case 'n'://il giocatore non gioca la nope
                    case 'N':
                        printf("\nIl giocatore non gioca la nope\n");
                        printf("\nCarta bloccata\n");
                        flagEsci=true;//flag
                        break;
                    default:
                        printf("\nDato inserito non valido\n");
                        break;
                    }
                }while(!((scelta=='s')||(scelta=='S')||(scelta=='n')||(scelta=='N')));//cicla se la scelta e' diversa dai case
            }
        }
    }
}
void attackDefault(int i, int w, DatiGioco Id[N_GIOC]){
	printf("\nSalta il turno e il giocatore successivo fa 2 turni\n");
    Id[i].number.numero--;
	Id[i].flag.nonPesca=true;//flag pesca
	Id[w].flag.doppioTurno=true;//flag doppio tirno
}
/*SEE THE FUTURE (Permette di vedere le prime tre carte del mazzo)
il giocatore può vedere le prime tre carte del mazzo, può essere annullato dal NOPE;*/
void seeTheFuture(int counter, int i, Tipologia *vettoreCarte, DatiGioco Id[N_GIOC]){
	int h, k, w;//variabile
    _Bool flagEsci=false;//variabile booleana
    char scelta;//variabile char

    w=i+1;
    for(h=4, k=0; k<=3; h++, k++){//ciclo
        if(w==h) w=k;//se w=4 allora w=0, se w=7 allora w=3
    }
    if(w==8) w=0;//se w=8 allora w=0

    if(Id[w].number.numNope==0){//il giocatore i+1 non possiede la nope (w=i+1)
        return seeTheFutureDefault(i, vettoreCarte, Id);//subroutine
    }else{//il giocatore i+1 possiede una nope
        if(counter<6 && flagEsci==false){//controllo contatore e flag
            if((counter%2==0)&&(Id[w].number.numNope>0)){
                //controllo parita' per il giocatore i e se il giocatore w possiede una nope
                do{
                printf("\n\nIl giocatore %s ha una NOPE", Id[w].nome);
                printf("\nVuoi giocarlo?");
                printf("\nSe si......premi 's'");
                printf("\nSe no......premi 'n'\n");
                scanf("%c", &scelta);
                getchar();//getchar per il carattere invio

                switch(scelta){
                    case 's'://il giocatore gioca la nope
                    case 'S':
                        printf("\nIl giocatore gioca la nope\n");
                        Id[w].number.numNope--;
                        Id[w].number.numero--;
                        return seeTheFuture(counter+1, i, vettoreCarte, Id);//subroutine invoca se stessa
                        break;
                    case 'n'://il giocatore non gioca la nope
                    case 'N':
                        printf("\nIl giocatore non gioca la nope\n");
                        return seeTheFutureDefault(i, vettoreCarte, Id);//subroutine
                        flagEsci=true;//flag esci
                        break;
                    default:
                        printf("\nDato inserito non valido\n");
                        break;
                    }
                }while(!((scelta=='s')||(scelta=='S')||(scelta=='n')||(scelta=='N')));//cicla se la scelta e' diversa dai case
            }else if((counter%2!=0)&&(Id[i].number.numNope>0)){
                //controllo sulla disparita' per il giocatore w e se il giocatore i ha la nope
                do{
                printf("\n\nIl giocatore %s ha una NOPE", Id[i].nome);
                printf("\nVuoi giocarlo?");
                printf("\nSe si......premi 's'");
                printf("\nSe no......premi 'n'\n");
                scanf("%c", &scelta);
                getchar();//getchar per il carattere invio

                switch(scelta){
                    case 's'://il giocatore gioca la nope
                    case 'S':
                        printf("\nIl giocatore gioca la nope\n");
                        Id[i].number.numNope--;
                        Id[i].number.numero--;
                        return seeTheFuture(counter+1, i, vettoreCarte, Id);//subroutine invoca se stessa
                        break;
                    case 'n'://il giocatore non gioca la nope
                    case 'N':
                        printf("\nIl giocatore non gioca la nope\n");
                        printf("\nCarta bloccata\n");
                        flagEsci=true;//flag esci
                        break;
                    default:
                        printf("\nDato inserito non valido\n");
                        break;
                    }
                }while(!((scelta=='s')||(scelta=='S')||(scelta=='n')||(scelta=='N')));//cicla se la scelta e' diversa dai case
            }
        }
    }
}
void seeTheFutureDefault(int i, Tipologia *vettoreCarte, DatiGioco Id[N_GIOC]){
    //subroutine che stampa a video le prossime tre carte dal mazzo principale
    Id[i].number.numero--;
	printf("\nSbirciamo le prime tre carte del mazzo\n");
	printf("\n%d  %s", 0, stringaCarta[(int)vettoreCarte[ZERO]]);
	printf("\n%d  %s", 1, stringaCarta[(int)vettoreCarte[UNO]]);
	printf("\n%d  %s\n\n", 2, stringaCarta[(int)vettoreCarte[DUE]]);
}
/*SHUFFLE (Permette di mischiare il mazzo)
il mazzo deve essere mescolato, può essere annullato dal NOPE*/
void shuffle(int counter, int i, int carteRimaste, Tipologia *vettoreCarte, DatiGioco Id[N_GIOC]){
	int w, h, k;//variabile
	_Bool flagEsci=false;//flag booleano
	char scelta;//variabile char

    w=i+1;
    for(h=4, k=0; k<=3; h++, k++){//ciclo
        if(w==h) w=k;//se w=4 allora w=0, se w=7 allora w=3
    }
    if(w==8) w=0;//se w=8 allora w=0

    if(Id[w].number.numNope==0){//il giocatore i+1 non possiede la nope (w=i+1)
        return shuffleDefault(i, carteRimaste, vettoreCarte, Id);//subroutine
    }else{//il giocatore i+1 possiede una nope
        if(counter<6 && flagEsci==false){//controllo contatore e flag esci
            if((counter%2==0)&&(Id[w].number.numNope>0)){
                //controllo sulla parita' per il giocatore i e se il giocatore w ha la nope
                do{
                printf("\n\nIl giocatore %s ha una NOPE", Id[w].nome);
                printf("\nVuoi giocarlo?");
                printf("\nSe si......premi 's'");
                printf("\nSe no......premi 'n'\n");
                scanf("%c", &scelta);
                getchar();//getchar per il carattere invio

                switch(scelta){
                    case 's'://il giocatore gioca la nope
                    case 'S':
                        printf("\nIl giocatore gioca la nope\n");
                        Id[w].number.numNope--;
                        Id[w].number.numero--;
                        return shuffle(counter+1, i, carteRimaste, vettoreCarte,  Id);//subroutine invoca se stessa
                        break;
                    case 'n'://il giocatore non gioca la nope
                    case 'N':
                        printf("\nIl giocatore non gioca la nope\n");
                        return shuffleDefault(i, carteRimaste, vettoreCarte, Id);//subroutine
                        flagEsci=true;//flag esci
                        break;
                    default:
                        printf("\nDato inserito non valido\n");
                        break;
                    }
                }while(!((scelta=='s')||(scelta=='S')||(scelta=='n')||(scelta=='N')));//cicla se la scelta e' diversa dai case
            }else if((counter%2!=0)&&(Id[i].number.numNope>0)){
                //controllo sulla disparita' per il giocatore w e se il giocatore i ha una nope
                do{
                printf("\n\nIl giocatore %s ha una NOPE", Id[i].nome);
                printf("\nVuoi giocarlo?");
                printf("\nSe si......premi 's'");
                printf("\nSe no......premi 'n'\n");
                scanf("%c", &scelta);
                getchar();//getchar per il carattere invio

                switch(scelta){
                    case 's'://il giocatore gioca la nope
                    case 'S':
                        printf("\nIl giocatore gioca la nope\n");
                        Id[i].number.numNope--;
                        Id[i].number.numero--;
                        return shuffle(counter+1, i, carteRimaste, vettoreCarte, Id);//subroutine invoca se stessa
                        break;
                    case 'n'://il giocatore non gioca la nope
                    case 'N':
                        printf("\nIl giocatore non gioca la nope\n");
                        printf("\nCarta bloccata\n");
                        flagEsci=true;//flag esci
                        break;
                    default:
                        printf("\nDato inserito non valido\n");
                        break;
                    }
                }while(!((scelta=='s')||(scelta=='S')||(scelta=='n')||(scelta=='N')));//cicla se la scelta e' diversa dai case
            }
        }
    }
}
void shuffleDefault(int i, int carteRimaste, Tipologia *vettoreCarte, DatiGioco Id[N_GIOC]){
	int h, j;//variabile
	_Bool flagCartaBool;//variabile booleana

	printf("\nMischiamo le carte\n");
    Id[i].number.numero--;

	for(h=MIN_CARTA; h<carteRimaste; h++){//ciclo
		do{
			flagCartaBool=false;//flag booleano
			vettoreCarte[h]=MIN_CARTA+rand()%(MAX_CARTA-MIN_CARTA+1);//generazione casuale della carta

			for (j=MIN_CARTA; j<h; j++){//ciclo
                if((vettoreCarte[h]==vettoreCarte[j])&&(flagCartaBool==false)){
                    //controllo se il vettoreCarte col pedice h che va da 0 a carteRimaste
                    //e' uguale al pedice j che va da
                    flagCartaBool=true;//flag booleano
                }
            }
				//cicla sinche le caselle non sono tutte piene
		}while(flagCartaBool==true);//controllo booleano
	}
}
/*SKIP (Permette di non pescare una carta dal mazzo)
il turno passa al giocatore successivo, può essere annullato dal NOPE;*/
void skip(int counter, int i, DatiGioco Id[N_GIOC]){
	int h, k, w;//variabili
	_Bool flagEsci=false;//flag settato a false
	char scelta;//variabile char

    w=i+1;
    for(h=4, k=0; k<=3; h++, k++){//ciclo
        if(w==h) w=k;//se w=4 allora w=0, se w=7 allora w=3
    }
    if(w==8) w=0;//se w=8 allora w=0

    if(Id[w].number.numNope==0){//il giocatore i+1 non possiede la nope (w=i+1)
        return skipDefault(i, Id);//subroutine
    }else{//il giocatore i+1 possiede una nope
        if(counter<6 && flagEsci==false){//controllo con tatore e flag esci
            if((counter%2==0)&&(Id[w].number.numNope>0)){
                //controllo parita' per il giocatore i e se il giocatore w ha una nope
                do{
                printf("\n\nIl giocatore %s ha una NOPE", Id[w].nome);
                printf("\nVuoi giocarlo?");
                printf("\nSe si......premi 's'");
                printf("\nSe no......premi 'n'\n");
                scanf("%c", &scelta);
                getchar();//getchar per il carattere invio

                switch(scelta){
                    case 's'://il giocatore gioca la nope
                    case 'S':
                        printf("\nIl giocatore gioca la nope\n");
                        Id[w].number.numNope--;
                        Id[w].number.numero--;
                        return skip(counter+1, i, Id);//subroutine invoca se stessa
                        break;
                    case 'n'://il giocatore non gioca la nope
                    case 'N':
                        printf("\nIl giocatore non gioca la nope\n");
                        return skipDefault(i, Id);//subroutine
                        flagEsci=true;//flag esci
                        break;
                    default:
                        printf("\nDato inserito non valido\n");
                        break;
                    }
                }while(!((scelta=='s')||(scelta=='S')||(scelta=='n')||(scelta=='N')));//cicla se la scelta e' diversa dai case
            }else if((counter%2!=0)&(Id[i].number.numNope>0)){
                //controllo sulla disparita' per il giocatore w e se il giocatore i ha una nope
                do{
                printf("\n\nIl giocatore %s ha una NOPE", Id[i].nome);
                printf("\nVuoi giocarlo?");
                printf("\nSe si......premi 's'");
                printf("\nSe no......premi 'n'\n");
                scanf("%c", &scelta);
                getchar();//getchar per il carattere invio

                switch(scelta){
                    case 's'://il giocatore gioca la nope
                    case 'S':
                        printf("\nIl giocatore gioca la nope\n");
                        Id[i].number.numNope--;
                        Id[i].number.numero--;
                        return skip(counter+1, i, Id);//subroutine che invoca se stessa
                        break;
                    case 'n'://il giocatore non gioca la nope
                    case 'N':
                        printf("\nIl giocatore non gioca la nope\n");
                        printf("\nCarta bloccata\n");
                        flagEsci=true;//flag esci
                        break;
                    default:
                        printf("\nDato inserito non valido\n");
                        break;
                    }
                }while(!((scelta=='s')||(scelta=='S')||(scelta=='n')||(scelta=='N')));//cicla se la scelta e' diversa dai case
            }
        }
    }
}
void skipDefault(int i, DatiGioco Id[N_GIOC]){
	printf("\nIl tuo turno e' concluso e non peschi\n");
    Id[i].number.numero--;
	Id[i].flag.nonPesca=true;//flag non pesca = true
	Id[i].flag.nonScende=true;//flag non scende = true
	Id[i].flag.flagTurno=true;//flag turno = true
}
/*FAVOR (Permette al giocatore che la usa di rubare una carta ad un avversario, la carta viene scelta da quest'ultimo.)
Il giocatore deve scegliere un avversario ed egli sceglierà quale carta dargli, può essere annullato
dalla carta NOPE;*/
void favor(int counter, int i, Tipologia *giocatore[N_GIOC], DatiGioco Id[N_GIOC]){
	int h, k, w;//variabili
    _Bool flagEsci=false;//flag esci
    char scelta;//variabile char

    w=i+1;
    for(h=4, k=0; k<=3; h++, k++){//ciclo
        if(w==h) w=k;//se w=4 allora w=0, se w=7 allora w=3
    }
    if(w==8) w=0;//se w=8 allora w=0

	if(Id[w].number.numNope==0){//il giocatore i+1 non possiede la nope (w=i+1)
		return favorDefault(w, i, giocatore, Id);//subroutine
	}else{//il giocatore i+1 possiede una nope
	    if(counter<6 && flagEsci==false){//controllo contatore e flag
            if((counter%2==0)&&(Id[w].number.numNope>0)){
                //controllo nope di w e se il contatore e' pari per giocare i
                do{
                printf("\n\nIl giocatore %s ha una NOPE", Id[w].nome);
                printf("\nVuoi giocarlo?");
                printf("\nSe si......premi 's'");
                printf("\nSe no......premi 'n'\n");
                scanf("%c", &scelta);
                getchar();//getchar per il carattere invio

                switch(scelta){
                    case 's'://il giocatore gioca la nope
                    case 'S':
                        printf("\nIl giocatore gioca la nope\n");
                        Id[w].number.numNope--;
                        Id[w].number.numero--;
                        return favor(counter+1, i, giocatore, Id);//subroutine invoca se stessa
                        break;
                    case 'n'://il giocatore non gioca la nope
                    case 'N':
                        printf("\nIl giocatore non gioca la nope\n");
                        return favorDefault(w, i, giocatore, Id);//subroutine
                        flagEsci=true;//flag esci
                        break;
                    default:
                        printf("\nDato inserito non valido\n");
                        break;
                    }
                }while(!((scelta=='s')||(scelta=='S')||(scelta=='n')||(scelta=='N')));//cicla se la scelta e' diversa dai case
            }else if((counter%2!=0)&&(Id[i].number.numNope>0)){
                do{
                printf("\n\nIl giocatore %s ha una NOPE", Id[i].nome);
                printf("\nVuoi giocarlo?");
                printf("\nSe si......premi 's'");
                printf("\nSe no......premi 'n'\n");
                scanf("%c", &scelta);
                getchar();//getchar per il carattere invio

                switch(scelta){
                    case 's'://il giocatore gioca la nope
                    case 'S':
                        printf("\nIl giocatore gioca la nope\n");
                        Id[i].number.numNope--;
                        Id[i].number.numero--;
                        printf("\nCarta bloccata\n");
                        flagEsci=true;//flag esci
                        break;
                    case 'n'://il giocatore non gioca la nope
                    case 'N':
                        printf("\nIl giocatore non gioca la nope\n");
                        printf("\nCarta bloccata\n");
                        flagEsci=true;//flag esci
                        break;
                    default:
                        printf("\nDato inserito non valido\n");
                        break;
                    }
                }while(!((scelta=='s')||(scelta=='S')||(scelta=='n')||(scelta=='N')));//cicla se la scelta e' diversa dai case
            }
        }
    }
}
void favorDefault(int w, int i, Tipologia *giocatore[N_GIOC], DatiGioco Id[N_GIOC]){
	int h, a, sceltaCarta;//variabili

	printf("\nIl giocatore %s sceglie quale carta dare a %s\n", Id[w].nome, Id[i].nome);
	printf("\nLe carte di %s sono\n", Id[w].nome);
	for(h=0; h<Id[w].number.numero; h++){//ciclo
		printf("%d %s\n", h, stringaCarta[(int)giocatore[w][h]]);//stampa a video stringa
	}
	printf("\nDigita il numero posto al lato sinistro  ");
	scanf("%d", &sceltaCarta);
	do{
		if(sceltaCarta>=Id[w].number.numero){//il numero inserito non deve essere >= al numero di carte
			printf("\nNumero troppo alto\nEffettua un'altra scelta\n");
		}else{
			printf("\nHai scelto\n");
			printf("%s\n", stringaCarta[(int)giocatore[w][sceltaCarta]]);
		}
	}while(sceltaCarta>=Id[w].number.numero);//ciclo se scelta >= numero carte giocatore

    Id[i].number.numero++;//incremento le carte di i
    //ri-allocazione dinamica dei mazzi dei 4 giocatori
    giocatore[i]=(Tipologia*)realloc(giocatore[i], Id[i].number.numero*sizeof(Tipologia));//viene allocata
    if(giocatore[i]==NULL) exit(-1);//verifica se l'allocazione e' andata a buon fine

	giocatore[i][Id[i].number.numero-UNO]=giocatore[w][sceltaCarta];//giocatore prende carta pescata

	for(h=sceltaCarta, a=sceltaCarta+1; a<Id[w].number.numero; h++, a++){//ciclo
		giocatore[w][h]=giocatore[w][a];//ri-numera le carte
	}
	Id[w].number.numero--;//decremento le carte di w

	//ri-allocazione dinamica dei mazzi dei 4 giocatori
    giocatore[w]=(Tipologia*)realloc(giocatore[w], Id[w].number.numero*sizeof(Tipologia));//viene allocata
    if(giocatore[w]==NULL) exit(-1);//verifica se l'allocazione e' andata a buon fine
}
/*DJANNI CARDS (Permettono di rubare carte all’avversario se giocate in coppia identica o tripla identica)
se giocata da sola non ha effetto; se giocata in coppia, il giocatore deve scegliere un avversario e
prenderà a caso una sua carta; se giocata in tripla, il giocatore deve scegliere un avversario e
prenderà una sua carta a scelta (funzionalità media), può essere annullata dal NOPE;*/
void djanniCards(int counter, int i, Tipologia *giocatore[N_GIOC], DatiGioco Id[N_GIOC]){
	int h, k, w;//variabili
	_Bool flagEsci=false;//flag uscita
	char scelta;//variabile char

    w=i+1;
    for(h=4, k=0; k<=3; h++, k++){//ciclo
        if(w==h) w=k;//se w=4 allora w=0, se w=7 allora w=3
    }
    if(w==8) w=0;//se w=8 allora w=0

	//controllo per stabilire se ha due carte uguali
	for(h=0; h<Id[i].number.numero; h++){//ciclo da 0 a numero di carte possedute
		if(((int)giocatore[i][h]>=MIN_GRASSO)&&((int)giocatore[i][h]<=MAX_GRASSO)){//controllo
			Id[i].number.grasso++;//incremento djanni grasso
		}else if(((int)giocatore[i][h]>=MIN_SOCIAL)&&((int)giocatore[i][h]<=MAX_SOCIAL)){//controllo
			Id[i].number.social++;//incremento djanni social
		}else if(((int)giocatore[i][h]>=MIN_MIAGOLANTE)&&((int)giocatore[i][h]<=MAX_MIAGOLANTE)){//controllo
			Id[i].number.miagolante++;//incremento djanni miagolante
		}else if(((int)giocatore[i][h]>=MIN_AFFAMATO)&&((int)giocatore[i][h]<=MAX_AFFAMATO)){//controllo
			Id[i].number.affamato++;//incremento djanni affamato
		}else if(((int)giocatore[i][h]>=MIN_DORMIENTE)&&((int)giocatore[i][h]<=MAX_DORMIENTE)){//controllo
			Id[i].number.dormiente++;//incremento djanni dormiente
		}
	}
	if((Id[i].number.grasso>=2)||(Id[i].number.social>=2)||(Id[i].number.miagolante>=2)||
            (Id[i].number.affamato>=2)||(Id[i].number.dormiente>=2)){//controllo djanni cards
        if(Id[w].number.numNope==0){//il giocatore i+1 non possiede la nope (w=i+1)
            return djanniCardsDefault(w, i, giocatore, Id);//subroutine
        }else{//il giocatore i+1 possiede una nope
            if(counter<6 && flagEsci==false){//controllo contatore e flag
                if((counter%2==0)&&(Id[w].number.numNope>0)){
                    //controllo nope di w e parita' del contatore per il turno di i
                    do{
                    printf("\n\nIl giocatore %s ha una NOPE", Id[w].nome);
                    printf("\nVuoi giocarlo?");
                    printf("\nSe si......premi 's'");
                    printf("\nSe no......premi 'n'\n");
                    scanf("%c", &scelta);
                    getchar();//getchar per il carattere invio

                    switch(scelta){
                        case 's'://il giocatore gioca la nope
                        case 'S':
                            printf("\nIl giocatore gioca la nope\n");
                            Id[w].number.numNope--;
                            Id[w].number.numero--;
                            return djanniCards(counter+1, i, giocatore, Id);//subroutine invoca se stessa
                            break;
                        case 'n'://il giocatore non gioca la nope
                        case 'N':
                            printf("\nIl giocatore non gioca la nope\n");
                            return djanniCardsDefault(w, i, giocatore, Id);//subroutine
                            flagEsci=true;//flag esci
                            break;
                        default:
                            printf("\nDato inserito non valido\n");
                            break;
                        }
                    }while(!((scelta=='s')||(scelta=='S')||(scelta=='n')||(scelta=='N')));//cicla se la scelta e' diversa dai case
                }else if((counter%2!=0)&&(Id[i].number.numNope>0)){
                    //controllo nope di i e disparita' contatore per turno di w
                    do{
                    printf("\n\nIl giocatore %s ha una NOPE", Id[i].nome);
                    printf("\nVuoi giocarlo?");
                    printf("\nSe si......premi 's'");
                    printf("\nSe no......premi 'n'\n");
                    scanf("%c", &scelta);
                    getchar();//getchar per il carattere invio

                    switch(scelta){
                        case 's'://il giocatore gioca la nope
                        case 'S':
                            printf("\nIl giocatore gioca la nope\n");
                            Id[i].number.numNope--;
                            Id[i].number.numero--;
                            return djanniCards(counter+1, i, giocatore, Id);//subroutine invoca se stessa
                            break;
                        case 'n'://il giocatore non gioca la nope
                        case 'N':
                            printf("\nIl giocatore non gioca la nope\n");
                            printf("\nCarta bloccata\n");
                            flagEsci=true;//flag esci
                            break;
                        default:
                            printf("\nDato inserito non valido\n");
                            break;
                        }
                    }while(!((scelta=='s')||(scelta=='S')||(scelta=='n')||(scelta=='N')));//cicla se la scelta e' diversa dai case
                }
            }
        }
	}
}
void djanniCardsDefault(int w, int i, Tipologia *giocatore[N_GIOC], DatiGioco Id[N_GIOC]){
	int sceltaCarta, h, a;//variabili

	printf("\nIl giocatore %s sceglie un numero di carta del giocatore %s\n", Id[i].nome, Id[w].nome);
	printf("\nLe carte di %s sono\n", Id[w].nome);
	printf("\nDigita il numero post al lato sinistro  ");
	scanf("%d", &sceltaCarta);//scelta
	do{
		if(sceltaCarta>=Id[w].number.numero){//il numero inserito non deve essere >= al numero di carte
			printf("\nNumero troppo alto\nEffettua un'altra scelta\n");
		}else{
			printf("\nHai scelto\n");
			printf("%s\n", stringaCarta[(int)giocatore[w][sceltaCarta]]);//stampa a video la carta
		}
	}while(sceltaCarta>=Id[w].number.numero);//cicla se il numero scelto e' >= della quantita' di carte

	Id[i].number.numero++;//incremento le carte di i
    //ri-allocazione dinamica dei mazzi dei 4 giocatori
    giocatore[i]=(Tipologia*)realloc(giocatore[i], Id[i].number.numero*sizeof(Tipologia));//viene allocata
    if(giocatore[i]==NULL) exit(-1);//verifica se l'allocazione e' andata a buon fine

	giocatore[i][Id[i].number.numero-UNO]=giocatore[w][sceltaCarta];//giocatore prende carta pescata

	for(h=sceltaCarta, a=sceltaCarta+1; a<Id[w].number.numero; h++, a++){//ciclo
		giocatore[w][h]=giocatore[w][a];//ri-numera le carte
	}
	Id[w].number.numero--;//decremento le carte di w

	//ri-allocazione dinamica dei mazzi dei 4 giocatori
    giocatore[w]=(Tipologia*)realloc(giocatore[w], Id[w].number.numero*sizeof(Tipologia));//viene allocata
    if(giocatore[w]==NULL) exit(-1);//verifica se l'allocazione e' andata a buon fine
}
/*EXPLODING DJANNI (Causa l’uscita dal gioco)
causa l’uscita del giocatore a meno che egli non giochi una carta MEOOOW, solo in questo caso
la carta EXPLODING DJANNI deve essere rimessa nel mazzo in posizione casuale;*/
void explodingDjanni(int i, int carteRimaste, Tipologia *vettoreCarte, Tipologia *giocatore[N_GIOC], DatiGioco Id[N_GIOC]){
	int h, a, var, randExploding;//variabili
	char scelta;//variabile char

	if(Id[i].number.numMeooow>0){//controlla se il giocatore i ha una carta meooow
		do{
		printf("\nVuoi giocare la carta MEOOOW per annullare l'EXPLODING DJANNI?");
		printf("\nSe si......premi 's'");
		printf("\nSe no......premi 'n'\n");
		scanf("%c", &scelta);
		getchar();//getchar per il carattere invio

		switch(scelta){
			case 's'://il giocatore gioca la meooow
			case 'S':
                Id[i].number.numero--;//decremento il numero di carte del giocatore i
                Id[i].number.numMeooow--;
                printf("\nTi sei salvato!!\n");
				Id[i].number.numMeooow--;//decremento numero di meooow
                carteRimaste++;//incremento le carte del mazzo principale

				randExploding=MIN_CARTA+rand()%(carteRimaste-MIN_CARTA+1);//generazione casuale
				var=(int)vettoreCarte[0];//variabile d'appoggio

				for(h=0, a=1; h<randExploding; h++, a++){//ciclo
					vettoreCarte[h]=vettoreCarte[a];//scala di una posizione le carte
				}
				vettoreCarte[randExploding]=var;//assegnamento della nuova locazione
				break;
			case 'n'://il giocatore non gioca la meooow
			case 'N':
                printf("\nIl giocatore %s e' morto\n", Id[i].nome);
                Id[i].flag.morto=true;//flag morto
                free(giocatore[i]);//deallocazione
				break;
			default:
				printf("\nDato inserito non valido\n");
				break;
            }
        }while(!((scelta=='s')||(scelta=='S')||(scelta=='n')||(scelta=='N')));//cicla se scelta non corrisponde al case
	}
}
#endif // CARTE_DA_GIOCO_H_INCLUDED
