
#ifndef PROGETTO_ESAME_C_SERVIZIO_H
#define PROGETTO_ESAME_C_SERVIZIO_H

typedef struct {                // le variabili disponibili per ogni prodotto
    int c_prodotto;
    char nome[500];
    double prezzo;
    int pz_disponibili;
}prodotto;

typedef struct {                // variabili dei prodotti scelti dall'utente
    int codice;
    int quantita;
}prodotto_scelto;


//------------------------------------------------------------------------------------------------------------------

typedef struct {
    prodotto m[30];             // sono disponibili un massimo di 30 prodotti
    int stato;                  // indica se è stato caricato il menu
    int len;                    // indica la quantità di elementi nel menu (utile in sovrascittura)
}elenco_prodotti;

//------------------------------------------------------------------------------------------------------------------

void c_menu(elenco_prodotti*);        //funzione per caricare il menu in elenco_prodotti
int is_new_day();                     //funzione non più necessaria
int menu_status(elenco_prodotti*);                    //funzione che restituisce lo stato del menu, se è stato caricato ritorna 1
int menu_len(elenco_prodotti*);                        //funzione che restituisce la lunghezza del menu
int canc_menu(elenco_prodotti*);
#endif //PROGETTO_ESAME_C_SERVIZIO_H
