#ifndef MACRO_STRUTTURE_STRINGHE_H_INCLUDED
#define MACRO_STRUTTURE_STRINGHE_H_INCLUDED

#define ZERO 0
#define UNO 1
#define DUE 2
#define TRE 3
#define CINQUE 5
#define SETTE 7
#define SEDICI 16
#define MIN_CARTA 0
#define MAX_CARTA 56
#define MAX_STRINGA 127
#define STRINGA_GIOCATORE 27
#define DIM 15
#define MIN_EXPLODING_DJANNI 0
#define MAX_EXPLODING_DJANNI 2
#define MIN_MEOOOW 3
#define MAX_MEOOOW 10
#define MIN_SHUFFLE 11
#define MAX_SHUFFLE 14
#define MIN_NOPE 15
#define MAX_NOPE 19
#define MIN_SEE_THE_FUTURE 20
#define MAX_SEE_THE_FUTURE 24
#define MIN_ATTACK 25
#define MAX_ATTACK 28
#define MIN_SKIP 29
#define MAX_SKIP 32
#define MIN_FAVOR 33
#define MAX_FAVOR 36
#define MIN_DJANNI_CARDS 37
#define MAX_DJANNI_CARDS 56
#define PARAMETRO_INIZIALE 11
#define N_GIOC 4
#define RIMASTE 36
#define MIN_GRASSO 37
#define MAX_GRASSO 40
#define MIN_SOCIAL 41
#define MAX_SOCIAL 44
#define MIN_MIAGOLANTE 45
#define MAX_MIAGOLANTE 48
#define MIN_AFFAMATO 49
#define MAX_AFFAMATO 52
#define MIN_DORMIENTE 53
#define MAX_DORMIENTE 56

typedef enum{//enumerazione della tipologia di carta
		EXPLODING_DJANNI, MEOOOW, SHUFFLE, NOPE, SEE_THE_FUTURE, ATTACK, SKIP, FAVOR, DJANNI_CARDS
	}Tipologia;
typedef enum{utente1, utente2, utente3, utente4}Utenti;//enumerazione dell'utente giocatore da 0 a 3

typedef struct{
    int numMeooow;//variabile che numera quanti meooow hanno i 4 giocatori
    int numNope;//variabile che numera quante nope hanno i 4 giocatori
    int numero;//variabile numero carte rimaste nei 4 mazzi giocatori
    int flagDoppio;//variabile flag che conta 2 turni consecutivi
    int grasso;//variabile djanni cards
    int social;//variabile djanni cards
    int miagolante;//variabile djanni cards
    int affamato;//variabile djanni cards
    int dormiente;//variabile djanni cards
}Number;
typedef struct{
    _Bool doppioTurno;//variabile giocatore doppio turno, carta ATTACJ
    _Bool nonPesca;//variabile per il giocatore che non deve pescare
    _Bool nonScende;//variabile per il giocatore che non deve scendere carte
    _Bool flagTurno;//variabile per il giocatore che salta il turno
    _Bool flagPesca;//variabile per sapere se il giocatore ha pescato
    _Bool morto;//variabile giocatore morto
}Flag;
typedef struct{
    char nome[STRINGA_GIOCATORE+1];//stringa nome giocatore
    Flag flag;//struttura flag
    Number number;//struttura number
}DatiGioco;

char stringaCarta[MAX_CARTA+1][MAX_STRINGA+1]={//stringhe di testo associate ad un tipo di carta
		"EXPLODING DJANNI",//0-exploding djanni
		"EXPLODING DJANNI",//0-exploding djanni
		"EXPLODING DJANNI",//0-exploding djanni
		"MEOOOW  TI SALVI CHIUDENDO DJANNI IN LAB T",//1-meooow
		"MEOOOW  TI SALVI OFFRENDO UN KAFFEEEEE A DJANNI",//1-meooow
		"MEOOOW  TI SALVI CIBANDO DJANNI",//1-meooow
		"MEOOOW  TI SALVI ACCAREZZANDO DJANNI SULLA PANCIA",//1-meooow
		"MEOOOW  TI SALVI DISTRAENDO DJANNI CON UNA PALLA",//1-meooow
		"MEOOOW  TI SALVI CON UN BUONGIORNISSIMOOOOO!",//1-meooow
		"MEOOOW  TI SALVI OFFRENDO UNA BIRRA A DJANNI",//1-meooow
		"MEOOOW  TI SALVI PUNTANDO UN LASER SULLA PORTA",//1-meooow
		"SHUFFLE  DJANNI VEDE LE CARTE E CI GIOCA",//2-shuffle
		"SHUFFLE  DJANNI USA LE CARTE DOPO AVER USATO LA LETTIERA",//2-shuffle
		"SHUFFLE  DJANNI LANCIA LE CARTE RECLAMANDO CIBO",//2-shuffle
		"SHUFFLE  DJANNI E’ APPENA DIVENTATO CROUPIER",//2-shuffle
		"NOPE  DJANNI DICE NO, E BASTA",//3-nope
		"NOPE  DJANNI TI GUARDA, E' UN NO",//3-nope
		"NOPE  DJANNI DICE NO MIAGOLANDO A 220DB",//3-nope
		"NOPE  DJANNI TI FA LO SGAMBETTO CON LA CODA E TI BLOCCA",//3-nope
		"NOPE  DJANNI TI BLOCCA CON UN CALCIO VOLANTE… E CHUCK NORRIS MUTO.",//3-nope
		"SEE THE FUTURE  DJANNI VEDE IL FUTURO LECCANDOSI LE ZAMPE",//4-see the future
		"SEE THE FUTURE  DJANNI GUARDA IL SUO IO E VEDE IL FUTURO",//4-see the future
		"SEE THE FUTURE  DJANNI VIENE DAL FUTURO E GUARDA AL PASSATO",//4-see the future
		"SEE THE FUTURE  DJANNI VEDE IL FUTURO DALLA CODA",//4-see the future
		"SEE THE FUTURE  DJANNI GUARDANDO NELLA SUA OMBRA VEDE CIÒ CHE GLI ALTRI NON VEDONO",//4-see the future
		"ATTACK  DJANNI TI LANCIA CONTRO UNA PALLINA",//5-attack
		"ATTACK  DJANNI SEGNA IL TERRITORIO NEI TUOI PIEDI",//5-attack
		"ATTACK  DJANNI TI PORTA UN TOPO VIVO",//5-attack
		"ATTACK  DJANNI SALTA SULLA POLTRONA E SI FA LE UNGHIE",//5-attack
		"SKIP  DJANNI UBRIACO SALTA IL TURNO",//6-skip
		"SKIP  DJANNI DORME DIMENTICANDOSI DI PESCARE",//6-skip
		"SKIP  DJANNI E' IN VACANZA, NIENTE CARTA",//6-skip
		"SKIP  DJANNI SALTA UN FOGLIO DI CARTA",//6-skip
		"FAVOR  DJANNI CHIEDE UNA CARTA, DAGLIELA!",//7-favor
		"FAVOR  DJANNI CHIEDE UNA CARTA MIAGOLANDO INSISTENTMENTE",//7-favor
		"FAVOR  DJANNI CHIEDE UNA CARTA STRUSCIANDOSI",//7-favor
		"FAVOR  DJANNI CHIEDE UNA CARTA, NON HA FRETTA",//7-favor
		"DJANNI CARDS  DJANNI GRASSO",//8-djanni cards
		"DJANNI CARDS  DJANNI GRASSO",//8-djanni cards
		"DJANNI CARDS  DJANNI GRASSO",//8-djanni cards
		"DJANNI CARDS  DJANNI GRASSO",//8-djanni cards
		"DJANNI CARDS  DJANNI SOCIAL",//8-djanni cards
		"DJANNI CARDS  DJANNI SOCIAL",//8-djanni cards
		"DJANNI CARDS  DJANNI SOCIAL",//8-djanni cards
		"DJANNI CARDS  DJANNI SOCIAL",//8-djanni cards
		"DJANNI CARDS  DJANNI MIAGOLANTE",//8-djanni cards
		"DJANNI CARDS  DJANNI MIAGOLANTE",//8-djanni cards
		"DJANNI CARDS  DJANNI MIAGOLANTE",//8-djanni cards
		"DJANNI CARDS  DJANNI MIAGOLANTE",//8-djanni cards
		"DJANNI CARDS  DJANNI AFFAMATO",//8-djanni cards
		"DJANNI CARDS  DJANNI AFFAMATO",//8-djanni cards
		"DJANNI CARDS  DJANNI AFFAMATO",//8-djanni cards
		"DJANNI CARDS  DJANNI AFFAMATO",//8-djanni cards
		"DJANNI CARDS  DJANNI DORMIENTE",//8-djanni cards
		"DJANNI CARDS  DJANNI DORMIENTE",//8-djanni cards
		"DJANNI CARDS  DJANNI DORMIENTE",//8-djanni cards
		"DJANNI CARDS  DJANNI DORMIENTE"//8-djanni cards
	};

#endif // MACRO_STRUTTURE_STRINGHE_H_INCLUDED
