# ExplodingDjanni
Progetto di programmazione 1:  Exploding Djanni

Funzionamento generale

Si ha un mazzo si carte che contiene, tra le altre, le carte EXPLODING DJANNI. Si gioca girando carta per
carta fino a quando qualcuno pesca un EXPLODING DJANNI. Quando la persona pesca la carta esplosiva
essa stessa esplode, e muore, ovvero è fuori dal gioco. Numero giocatori stabilito a 4.
Il gioco prosegue fino a quando tutti i giocatori tranne uno sono morti. Colui che si salva è il vincitore.
In poche parole se esplodi perdi, se non esplodi, vinci. Tutte le carte nel mezzo permettono di salvarsi da
eventuali esplosioni. L’unico modo per non morire con l’EXPLODING DJANNI è utilizzare subito dopo
una carta MEOOOW.
All’inizio del gioco di tolgono le carte EXPLODING DJANNI (3 carte) e le carte MEOOOW (4 nella
modalità HARD, 6 nella MEDIUM, 8 nella EASY) e si mettono da una parte, si mescolano le rimanenti e si
danno 4 carte a giocatore. Si consegna una carta MEOOOW ad ogni giocatore in modo che ogni
giocatore abbia in totale 5 carte. Si reinseriscono nel mazzo le carte MEOOOW e le carte EXPLODING
DJANNI e si mescola nuovamente.
Si inizia poi dal primo giocatore (scelto casualmente tra i quattro iniziali) che scarterà eventuali carte e il
suo turno terminerà con il pescare la carta dal mazzo a mano che non utilizzi carte speciali chiamate SKIP
o ATTACK. Ci sono altre carte che permettono di vedere le prime tre carte del mazzo, di prendere una
carta all’avversario, di impedire un’azione, ecc. Vedi le relative specifiche.

Il Funzionalità base

Nuova partita
1. caricamento carte file di testo (vedi specifiche file di testo). La lettura deve funzionare per le tre
tipologie di mazzo (easy, medium, hard) senza mettere embedded il numero di EXPLODING
DJANNI e MEOOOW ma leggendolo dalla prima riga;
2. creazione giocatori, mescolamento carte (escludendo tutti gli EXPLODING DJANNI e tutte le
carte MEOOOW), assegnamento carte (4 carte del mazzo mescolato + 1 MEOOOW),
mescolamento carte rimanenti aggiungendo EXPLODING DJANNI;
Caricamento partita (nome file predefinito: partita.sav)
3. caricamento carte file salvataggio (vedi specifiche), caricamento giocatori file salvataggio (vedi
specifiche), nessun mescolamento e si inizia dal giocatore a cui spetta il turno di gioco;
Salvataggio partita (nome file predefinito: partita.sav)
4. su file binario (vedi specifiche) in ogni momento (qualsiasi turno, qualsiasi giro);
5. scelta casuale del primo giocatore, poi si procede in ordine;
6. memorizzazione mazzo carte in gioco e carte giocatori in Array Dinamico;
7. memorizzazione giocatori in Array Statico;
8 gestione eventi singole carte (vedi specifiche);
9. proclamazione del vincitore;
10. commentare opportunamente tutto il codice (in italiano o in inglese);

Funzionalità medie

caricamento e salvataggio nome file inserito dall'utente;
rendere la carta NOPE utilizzabile da un giocatore qualsiasi in qualsiasi turno;
memorizzazione mazzo carte in gioco in una lista lineare concatenata (anziché array dinamico);
aggiunta regola 3 DJANNI CARDS uguali;
creazione logger, salvare in un file di testo tutti gli eventi della partita (ogni riga rappresenta un evento
e deve essere numerato) in modo da poterne leggerne la “storia”. Devono essere quindi salvate le
carte giocate, estratte e il nome del giocatore che ha compiuto l’azione.

Funzionalità avanzate

Implementare la componente AI (Artificial Intelligence)
• l'implementazione deve permettere di giocare contro il computer. Il computer dovrà gestire tutti
i giocatori diversi dall'utente. Il gioco dovrà quindi funzionare per 4 giocatori reali, per 4
giocatori computer e per tutte le varie combinazioni.
Più simile al comportamento umano sarà la giocata del computer maggiore sarà la valutazione, ad
esempio: creare un sistema AI che giochi sempre la prima carta del giocatore avrà una valutazione pari a
0 su 5. Scegliere se giocare o meno, e quale carta giocare, sulla base della carta scartata dall'avversario
precedente e delle carte disponibili punterà ad una valutazione di 5 su 5. Il computer deve tentare di
vincere!

Significato carte:

1. NOPE (Annulla l'azione di una carta del giocatore precedente)
blocca l’effetto di un’altra carta, NOPE compreso;
2. ATTACK (Permette di saltare il turno e costringe il giocatore successivo a fare due turni)
il giocatore successivo esegue due turni e può essere annullato dal NOPE o annulla un
precedente ATTACK che ha effetto quindi sul giocatore successivo;
3. SKIP (Permette di non pescare una carta dal mazzo)
il turno passa al giocatore successivo, può essere annullato dal NOPE;
4. FAVOR ( Permette al giocatore che la usa di rubare una carta ad un avversario, la carta viene scelta da quest'ultimo. )
Il giocatore deve scegliere un avversario ed egli sceglierà quale carta dargli, può essere annullato
dalla carta NOPE;
5. SEE THE FUTURE (Permette di vedere le prime tre carte del mazzo)
il giocatore può vedere le prime tre carte del mazzo, può essere annullato dal NOPE;
6. SHUFFLE (Permette di mischiare il mazzo)
il mazzo deve essere mescolato, può essere annullato dal NOPE
7. DJANNI CARDS (Permettono di rubare carte all’avversario se giocate in coppia identica o tripla identica)
se giocata da sola non ha effetto; se giocata in coppia, il giocatore deve scegliere un avversario e
prenderà a caso una sua carta; se giocata in tripla, il giocatore deve scegliere un avversario e
prenderà una sua carta a scelta (funzionalità media), può essere annullata dal NOPE;
8. EXPLODING DJANNI (Causa l’uscita dal gioco)
causa l’uscita del giocatore a meno che egli non giochi una carta MEOOOW, solo in questo caso
la carta EXPLODING DJANNI deve essere rimessa nel mazzo in posizione casuale;
9. MEOOOW (Permette di salvarsi in seguito alla carta EXPLODING DJANNI)
Permette di restare in gioco nel caso in cui sia uscita la carta EXPLODING DJANNI.

Il file binario è così strutturato:
1. un blocco per giocatore, contenente:
2. una stringa del nome giocatore (23+1 char)
3. un booleano per indicare se il giocatore è ancora in gioco o meno (1 _Bool)
4. se questo valore è true:
5. il numero di carte in mano del giocatore (1 int)
6. il tipo del giocatore: se computer o reale (1 enum)
7. un blocco per ogni carta giocatore, contenente:
8. una stringa della frase riportata sulla carta (127+1 char)
9. il tipo della carta (1 enum)
10. se questo valore è false:
11. nessun altro byte viene scritto
12. un blocco per le carte, contenente:
13. il numero di carta rimanenti nel mazzo (1 int)
14. un blocco per ogni carta, contenente:
15. una stringa della frase riportata sulla carta (127+1 char)
16. il tipo della carta (1 enum)
17. un blocco di info aggiuntive, contenente:
18. l'indice (da zero a tre) del giocatore a cui spetta il turno (1 int)
19. un booleano che indica se la partita è stata salvata subito dopo che un giocatore ha scartato un ATTACK (1 _Bool)
