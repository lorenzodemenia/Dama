#include "function.h"

int main() {
    tgame *arr;
    arr=create(7,7);
    print(*arr,7,7);

    int winner=game(*arr);

    if(winner==1){
        printf("White gamer is the winner!!!");
    }else {
        printf("Black player is the winner!!!");
    }
    freegame(arr,7);

    return 0;
}


/* Da implementare :
 * - Regole MiniLaska
 * - Menu
 * - Modalita' 2 Giocatori Interattiva
 * - Modalita' Giocatore vs PC (con varie strategie)
 * - Strategia PC
 * - Strategia Ricorsiva
 * - Regole Laska
 * - Grafica Scacchiera
 * */

/* Valutazione
I criteri di valutazione sono i seguenti:


    Qualità della relazione:
        – è completa e chiara come potrebbe esserlo un libro di testo?
        XML, HTML ...

        Una relazione scritta di al massimo 3 pagine che descriva la struttura del vostro progetto, l’organizzazione
        del lavoro tra i componenti del gruppo, le principali difficoltà incontrate. Relazioni più lunghe verranno
        penalizzate.


    Qualità del codice:
        – è ben strutturato in funzioni che risolvono task ben definiti?
        – è stato fatto un uso dei tipi appropriato?
        – è comprensibile e ben documentato?

        DOXYGEN
        Documentazione delle funzioni, dei tipi e dei file generata con Doxygen


    Funzionalità implementate:
        – sono state implementate tutte le funzionalità richieste?
        – sono state implementate funzionalità aggiuntive?


    Interrogazione orale sul programma del corso e sul linguaggio C
        – ogni membro di ogni gruppo verrà interrogato assieme agli altri membri sul progetto
        – ogni membro di ogni gruppo verrà anche interrogato separatamente sul programma del corso e sul
        linguaggio C in generale
 * */

/*  Organizzazione Files
 *  - Main
 *  - Table
 *  - Moves
 *  - Strategies
 *  -
 *
 * */