#ifndef ISTRUZIONI_H_INCLUDED
#define ISTRUZIONI_H_INCLUDED

void istruzioni(void){//subroutine per leggere le istruzioni del gioco
	printf("************************************************************************************\n");
	printf("   EXPLODING DJANNI               EXPLODING DJANNI               EXPLODING DJANNI \n");
	printf("************************************************************************************\n");
	printf("\n                 FUNZIONAMENTO GENERALE:\n");
	printf("Si ha un mazzo si carte che contiene, tra le altre, le carte EXPLODING DJANNI.\n");
	printf("Si gioca girando carta per carta fino a quando qualcuno pesca un EXPLODING DJANNI.\n");
	printf("Quando la persona pesca la carta esplosiva essa stessa esplode, e muore, ovvero è fuori dal gioco.\n");
	printf("Numero giocatori stabilito a 4.\n");
	printf("Il gioco prosegue fino a quando tutti \ni giocatori tranne uno sono morti.\n");
	printf("Colui che si salva è il vincitore.\n");
	printf("Il gioco prosegue fino a quando tutti i giocatori tranne uno sono morti.\n");
	printf("Colui che si salva è il vincitore.\n");
	printf("In poche parole se esplodi perdi, se non esplodi, vinci.\n");
	printf("************************************************************************************");
	printf("\n                 COME SI GIOCA:\n\n");
	printf("Ad ogni turno, ogni giocatore potrà giocare nessuna o più carte e per concludere il proprio turno, a meno\n");
    printf("di carte speciali giocate dal giocatore stesso, dovrà pescare una carta. Una volta pescata la carta, se\n");
    printf("questa non è un “Exploding Djanni”, la conserverà e il suo turno sarà concluso passando dunque al\n");
    printf("giocatore successivo. Pescare una carta è ovviamente un’operazione pericolosa perché si potrebbe\n");
    printf("esplodere (man mano che si va avanti, ci saranno sempre meno carte nel mazzo e quindi sarà più alta la\n");
    printf("probabilità di esplodere)\n");
    printf("Nel caso in cui invece un giocatore estragga un “Exploding Djanni”, ci sono due casi:\n");
    printf("-lo sfortunato giocatore possiede una carta “Meooow”: la gioca (ossia viene scartata) e sopravvive.\n");
	printf("   La carta “Exploding Djanni” dovrà quindi riposta casualmente nel mazzo, e il turno\n");
    printf("   passa al giocatore successivo.\n");
    printf("-lo sfortunato giocatore non possiede una carta “Meooow”: la carta “Exploding Djanni” viene\n");
    printf("   scartata e con essa tutte le carte possedute dal giocatore esploso, che uscirà dunque dal gioco.\n");
    printf("   Un giocatore e un exploding djanni in meno! Il turno passa al giocatore successivo.\n");
    printf("Durante il proprio turno un giocatore potrà giocare tutte le carte che vorrà (non c’è un limite sul numero\n");
    printf("di carte che può possedere o giocare un giocatore: può tenerle sempre in mano e non giocarle mai,\n");
    printf("oppure può sempre giocarle tutte e rimanere con zero carte in mano).\n");
	printf("****************************************************************************************");
	printf("\n                 UTILIZZO DELLE CARTE DA GIOCO:\n\n");
	printf("NOPE...............(Annulla l'azione di una carta del giocatore precedente)\n");
	printf("ATTACK.............(Permette di saltare il turno e costringe il giocatore successivo a fare due turni)\n");
	printf("SKIP...............(Permette di non pescare una carta dal mazzo)\n");
	printf("FAVOR..............(Permette al giocatore che la usa di rubare una carta ad un avversario, la carta viene scelta da quest'ultimo)\n");
	printf("SEE THE FUTURE.....(Permette di vedere le prime tre carte del mazzo)\n");
	printf("SHUFFLE............(Permette di mischiare il mazzo)\n");
	printf("DJANNI CARDS.......(Permettono di rubare carte all’avversario se giocate in coppia identica o tripla identica)\n");
	printf("EXPLODING DJANNI...(Causa l’uscita dal gioco)\n");
	printf("MEOOOW.............(Permette di salvarsi in seguito alla carta EXPLODING DJANNI)\n\n\n");
}
#endif // ISTRUZIONI_H_INCLUDED
