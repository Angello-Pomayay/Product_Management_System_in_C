#include <stdio.h>
#include <stdlib.h>
#include "servizio.h"
#include <Windows.h>
#include <wchar.h>
#include <locale.h>
#include <fcntl.h>
#include <io.h>

int main(void) {

    system("mode con: cols=128 lines=45");         //set con comando system le dimensioni della finestra
    HWND consoleWindow = GetConsoleWindow();                //script che acquisisce i valori attuali della finestra+
    //sovrascivo i valori della finestra con le stesse dimensioni ma bloccando l'opzione per schermo intero o ridimensionamento
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
    printf("\033[0;32m");       //comando per rendere i colori della console verdi

    //SEZIONE PROTOTIPI
    void menu_principale();     // prototipo della funzione che cicla il menu principale per le ordinazioni

    //STAMPE DI AVVIO
    system("cls");
    _setmode(_fileno(stdout), _O_U16TEXT);
    wprintf(L"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t    \u2588\u2588\u2588\u2588\u2588  \u2588\u2588    \u2588\u2588 \u2588\u2588    \u2588\u2588 \u2588\u2588  \u2588\u2588\u2588\u2588\u2588\u2588           \n\t\t\t\t\t   \u2588\u2588   \u2588\u2588 \u2588\u2588    \u2588\u2588 \u2588\u2588    \u2588\u2588 \u2588\u2588 \u2588\u2588    \u2588\u2588          \n\t\t\t\t\t   \u2588\u2588\u2588\u2588\u2588\u2588\u2588 \u2588\u2588    \u2588\u2588 \u2588\u2588    \u2588\u2588 \u2588\u2588 \u2588\u2588    \u2588\u2588          \n\t\t\t\t\t   \u2588\u2588   \u2588\u2588  \u2588\u2588  \u2588\u2588   \u2588\u2588  \u2588\u2588  \u2588\u2588 \u2588\u2588    \u2588\u2588          \n\t\t\t\t\t   \u2588\u2588   \u2588\u2588   \u2588\u2588\u2588\u2588     \u2588\u2588\u2588\u2588   \u2588\u2588  \u2588\u2588\u2588\u2588\u2588\u2588  \u2588\u2588 \u2588\u2588 \u2588\u2588 ");
    _setmode(_fileno(stdout), _O_TEXT);

    Sleep(1000);
    printf("\n\n\n\n\t\t\t\t\t\t () () () () () () ()");
    Sleep(500);
    printf("\n\t\t\t\t\t\t _____________________ _______________");
    Sleep(500);
    printf("\n\t\t\t\t\t\t \\                   /_______________/");
    Sleep(500);
    printf("\n\t\t\t\t\t\t  \\                 /");
    Sleep(500);
    printf("\n\t\t\t\t\t\t   \\_______________/");

    Sleep(1500);

    menu_principale();

    printf("\n\n\n\t\t\t\t    PROGRAMMA TERMINATO, PREMERE INVIO PER CHIUDERE...");
    getchar();


    return 0;
}

//FUNZIONE CHE STAMPA IL MENU DI SCELTA PRINCIPALE
void menu_principale(){

    int scelta=0;
    elenco_prodotti menu;
    elenco_prodotti *mdg; // dichiaro un puntatore al menu

    mdg = &menu; //assegno il puntatore al menu

    mdg->stato = 0; //azzero lo stato all'avvio
    double tot_inc = 0, *tot;
    tot = &tot_inc;
    void sez_amministratore(elenco_prodotti*);           // protoptipi delle funzioni che richiamano le due sezioni principali del
    void sez_ordinazioni(elenco_prodotti*, double*);              // programma


    //MENU CICLICO PER LA SCELTA DELLA SEZIONE DEL PROGRAMMA A CUI ACCEDERE
    do{

        do {
            system("cls");
            _setmode(_fileno(stdout), _O_U16TEXT);
            wprintf(L"\n\n\n\n\n\n\n       \u2588\u2588\u2588\u2588\u2588\u2588  \u2588\u2588\u2588\u2588\u2588\u2588  \u2588\u2588\u2588\u2588\u2588\u2588  \u2588\u2588 \u2588\u2588\u2588    \u2588\u2588  \u2588\u2588\u2588\u2588\u2588  \u2588\u2588\u2588\u2588\u2588\u2588\u2588 \u2588\u2588  \u2588\u2588\u2588\u2588\u2588\u2588  \u2588\u2588\u2588    \u2588\u2588 \u2588\u2588     \u2588\u2588\u2588\u2588\u2588\u2588   \u2588\u2588\u2588\u2588\u2588\u2588   \u2588\u2588\u2588\u2588\u2588\u2588   \u2588\u2588\u2588\u2588\u2588\u2588  \n      \u2588\u2588    \u2588\u2588 \u2588\u2588   \u2588\u2588 \u2588\u2588   \u2588\u2588 \u2588\u2588 \u2588\u2588\u2588\u2588   \u2588\u2588 \u2588\u2588   \u2588\u2588    \u2588\u2588\u2588  \u2588\u2588 \u2588\u2588    \u2588\u2588 \u2588\u2588\u2588\u2588   \u2588\u2588 \u2588\u2588          \u2588\u2588 \u2588\u2588  \u2588\u2588\u2588\u2588 \u2588\u2588  \u2588\u2588\u2588\u2588 \u2588\u2588  \u2588\u2588\u2588\u2588 \n      \u2588\u2588    \u2588\u2588 \u2588\u2588\u2588\u2588\u2588\u2588  \u2588\u2588   \u2588\u2588 \u2588\u2588 \u2588\u2588 \u2588\u2588  \u2588\u2588 \u2588\u2588\u2588\u2588\u2588\u2588\u2588   \u2588\u2588\u2588   \u2588\u2588 \u2588\u2588    \u2588\u2588 \u2588\u2588 \u2588\u2588  \u2588\u2588 \u2588\u2588      \u2588\u2588\u2588\u2588\u2588  \u2588\u2588 \u2588\u2588 \u2588\u2588 \u2588\u2588 \u2588\u2588 \u2588\u2588 \u2588\u2588 \u2588\u2588 \u2588\u2588 \n      \u2588\u2588    \u2588\u2588 \u2588\u2588   \u2588\u2588 \u2588\u2588   \u2588\u2588 \u2588\u2588 \u2588\u2588  \u2588\u2588 \u2588\u2588 \u2588\u2588   \u2588\u2588  \u2588\u2588\u2588    \u2588\u2588 \u2588\u2588    \u2588\u2588 \u2588\u2588  \u2588\u2588 \u2588\u2588 \u2588\u2588          \u2588\u2588 \u2588\u2588\u2588\u2588  \u2588\u2588 \u2588\u2588\u2588\u2588  \u2588\u2588 \u2588\u2588\u2588\u2588  \u2588\u2588 \n       \u2588\u2588\u2588\u2588\u2588\u2588  \u2588\u2588   \u2588\u2588 \u2588\u2588\u2588\u2588\u2588\u2588  \u2588\u2588 \u2588\u2588   \u2588\u2588\u2588\u2588 \u2588\u2588   \u2588\u2588 \u2588\u2588\u2588\u2588\u2588\u2588\u2588 \u2588\u2588  \u2588\u2588\u2588\u2588\u2588\u2588  \u2588\u2588   \u2588\u2588\u2588\u2588 \u2588\u2588     \u2588\u2588\u2588\u2588\u2588\u2588   \u2588\u2588\u2588\u2588\u2588\u2588   \u2588\u2588\u2588\u2588\u2588\u2588   \u2588\u2588\u2588\u2588\u2588\u2588  \n\n\n\n ");
            _setmode(_fileno(stdout), _O_TEXT);
            printf("\t\t\t\t\t\t 1 - Sezione amministratore\n");
            printf("\t\t\t\t\t\t 2 - Sezione ordinazioni\n");
            printf("\t\t\t\t\t\t 3 - Visualizza incasso totale di oggi\n");
            printf("\t\t\t\t\t\t 0 - Esci\n");
            if(scelta < 0 || scelta > 2) printf("\n\t\t\t\t\t\t    SCELTA NON VALIDA\n");
            printf("\n\t\t\t\t\t\tSCELTA: ");
            scanf("%d", &scelta);
            getchar();
        }while(scelta < 0 || scelta > 3);

        switch (scelta) {
            case 0:
                system("cls");
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t   CHIUSURA IN CORSO...");
                Sleep(2000);
                break;
            case 1:
                sez_amministratore(mdg);
                break;
            case 2:
                if(menu_status(mdg))   sez_ordinazioni(mdg, tot);
                else printf("\n\t\t\t\t\t\tIl menu' non e' stato ancora caricato\n");
                printf("\n\t\t\t\t\t\tPremere INVIO per continuare...");
                getchar();
                break;
            case 3:
                system("cls");
                _setmode(_fileno(stdout), _O_U16TEXT);
                wprintf(L"\n\n\n\t\t\t          \u2588\u2588    \u2588\u2588               \u2588\u2588    \u2588\u2588              \u2588\u2588    \u2588\u2588\n\t\t\t         \u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588           \u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588          \u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588  \n\t\t\t       \u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588       \u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588      \u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588 \n\t\t\t     \u2588\u2588\u2588\u2588  \u2588\u2588    \u2588\u2588  \u2588\u2588\u2588\u2588   \u2588\u2588\u2588\u2588  \u2588\u2588    \u2588\u2588  \u2588\u2588\u2588\u2588  \u2588\u2588\u2588\u2588  \u2588\u2588    \u2588\u2588  \u2588\u2588\u2588\u2588\n\t\t\t     \u2588\u2588\u2588\u2588  \u2588\u2588    \u2588\u2588  \u2588\u2588\u2588\u2588   \u2588\u2588\u2588\u2588  \u2588\u2588    \u2588\u2588  \u2588\u2588\u2588\u2588  \u2588\u2588\u2588\u2588  \u2588\u2588    \u2588\u2588  \u2588\u2588\u2588\u2588\n\t\t\t     \u2588\u2588\u2588\u2588  \u2588\u2588    \u2588\u2588         \u2588\u2588\u2588\u2588  \u2588\u2588    \u2588\u2588        \u2588\u2588\u2588\u2588  \u2588\u2588    \u2588\u2588      \n\t\t\t       \u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588         \u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588        \u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588    \n\t\t\t         \u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588         \u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588        \u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588  \n\t\t\t           \u2588\u2588    \u2588\u2588  \u2588\u2588\u2588\u2588         \u2588\u2588    \u2588\u2588  \u2588\u2588\u2588\u2588        \u2588\u2588    \u2588\u2588  \u2588\u2588\u2588\u2588\n\t\t\t     \u2588\u2588\u2588\u2588  \u2588\u2588    \u2588\u2588  \u2588\u2588\u2588\u2588   \u2588\u2588\u2588\u2588  \u2588\u2588    \u2588\u2588  \u2588\u2588\u2588\u2588  \u2588\u2588\u2588\u2588  \u2588\u2588    \u2588\u2588  \u2588\u2588\u2588\u2588\n\t\t\t     \u2588\u2588\u2588\u2588  \u2588\u2588    \u2588\u2588  \u2588\u2588\u2588\u2588   \u2588\u2588\u2588\u2588  \u2588\u2588    \u2588\u2588  \u2588\u2588\u2588\u2588  \u2588\u2588\u2588\u2588  \u2588\u2588    \u2588\u2588  \u2588\u2588\u2588\u2588\n\t\t\t       \u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588       \u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588      \u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588  \n\t\t\t         \u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588           \u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588          \u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588 \n\t\t\t           \u2588\u2588    \u2588\u2588               \u2588\u2588    \u2588\u2588              \u2588\u2588    \u2588\u2588  ");
                _setmode(_fileno(stdout), _O_TEXT);
                printf("\n\n\n\n\n\n\t\t\t\t\t\t   INCASSO TOTALE DI OGGI:\n");
                _setmode(_fileno(stdout), _O_U16TEXT);
                wprintf(L"\n\t\t\t\t\t\t\t  \u20AC ");
                _setmode(_fileno(stdout), _O_TEXT);
                printf("%.2lf\n", tot_inc);
                printf("\n\n\t\t\t\t\t\tPremere INVIO per continuare...");
                getchar();
                break;
        }

    }while(scelta!=0);

}


//FUNZIONE CHE CARICA LA SEZIONE AMMINISTRATORE
void sez_amministratore(elenco_prodotti *mdg){

    int scelta=1, contr_canc = 0;

    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t   SEZIONE AMMINISTRATORE\n");
    printf("\n\t\t\t\t\t\t\tLOADING...");
    Sleep(500);


    do {
        system("cls");
        _setmode(_fileno(stdout), _O_U16TEXT);
        wprintf(L"\n\n\n\n\n\n\n       \u2588\u2588\u2588\u2588\u2588  \u2588\u2588\u2588    \u2588\u2588\u2588 \u2588\u2588\u2588    \u2588\u2588\u2588 \u2588\u2588 \u2588\u2588\u2588    \u2588\u2588 \u2588\u2588 \u2588\u2588\u2588\u2588\u2588\u2588\u2588 \u2588\u2588\u2588\u2588\u2588\u2588\u2588\u2588 \u2588\u2588\u2588\u2588\u2588\u2588   \u2588\u2588\u2588\u2588\u2588  \u2588\u2588\u2588\u2588\u2588\u2588\u2588 \u2588\u2588  \u2588\u2588\u2588\u2588\u2588\u2588  \u2588\u2588\u2588    \u2588\u2588 \u2588\u2588\u2588\u2588\u2588\u2588\u2588 \n      \u2588\u2588   \u2588\u2588 \u2588\u2588\u2588\u2588  \u2588\u2588\u2588\u2588 \u2588\u2588\u2588\u2588  \u2588\u2588\u2588\u2588 \u2588\u2588 \u2588\u2588\u2588\u2588   \u2588\u2588 \u2588\u2588 \u2588\u2588         \u2588\u2588    \u2588\u2588   \u2588\u2588 \u2588\u2588   \u2588\u2588    \u2588\u2588\u2588  \u2588\u2588 \u2588\u2588    \u2588\u2588 \u2588\u2588\u2588\u2588   \u2588\u2588 \u2588\u2588      \n      \u2588\u2588\u2588\u2588\u2588\u2588\u2588 \u2588\u2588 \u2588\u2588\u2588\u2588 \u2588\u2588 \u2588\u2588 \u2588\u2588\u2588\u2588 \u2588\u2588 \u2588\u2588 \u2588\u2588 \u2588\u2588  \u2588\u2588 \u2588\u2588 \u2588\u2588\u2588\u2588\u2588\u2588\u2588    \u2588\u2588    \u2588\u2588\u2588\u2588\u2588\u2588  \u2588\u2588\u2588\u2588\u2588\u2588\u2588   \u2588\u2588\u2588   \u2588\u2588 \u2588\u2588    \u2588\u2588 \u2588\u2588 \u2588\u2588  \u2588\u2588 \u2588\u2588\u2588\u2588\u2588   \n      \u2588\u2588   \u2588\u2588 \u2588\u2588  \u2588\u2588  \u2588\u2588 \u2588\u2588  \u2588\u2588  \u2588\u2588 \u2588\u2588 \u2588\u2588  \u2588\u2588 \u2588\u2588 \u2588\u2588      \u2588\u2588    \u2588\u2588    \u2588\u2588   \u2588\u2588 \u2588\u2588   \u2588\u2588  \u2588\u2588\u2588    \u2588\u2588 \u2588\u2588    \u2588\u2588 \u2588\u2588  \u2588\u2588 \u2588\u2588 \u2588\u2588      \n      \u2588\u2588   \u2588\u2588 \u2588\u2588      \u2588\u2588 \u2588\u2588      \u2588\u2588 \u2588\u2588 \u2588\u2588   \u2588\u2588\u2588\u2588 \u2588\u2588 \u2588\u2588\u2588\u2588\u2588\u2588\u2588    \u2588\u2588    \u2588\u2588   \u2588\u2588 \u2588\u2588   \u2588\u2588 \u2588\u2588\u2588\u2588\u2588\u2588\u2588 \u2588\u2588  \u2588\u2588\u2588\u2588\u2588\u2588  \u2588\u2588   \u2588\u2588\u2588\u2588 \u2588\u2588\u2588\u2588\u2588\u2588\u2588\n\n\n\n");
        _setmode(_fileno(stdout), _O_TEXT);
        printf("\t\t\t\t\t\t 1 - Carica il menu\n");
        printf("\t\t\t\t\t\t 2 - Cancella il menu\n");
        printf("\t\t\t\t\t\t 3 - Torna al menu' principale\n");
        if(scelta < 1 || scelta > 3) printf("\n\t\t\t\t\t\t    SCELTA NON VALIDA\n");
        printf("\n\t\t\t\t\t\tSCELTA: ");
        scanf("%d", &scelta);
        getchar();

        switch (scelta) {
            case 1:
                c_menu(mdg);            //carico il menu
                break;

            case 2:
                contr_canc =  canc_menu(mdg);          //cancello il menu
                if(contr_canc == 1)
                printf("\n\t\t\t\t\t\tIl menu e' stato cancellato");
                else printf("\n\t\t\t\t\t\terrore nella cancellazione del menu'");
                printf("\n\t\t\t\t\t\tPremere INVIO per continuare...");
                getchar();
                break;


            case 3:
                system("cls");
                printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tRITORNO AL MENU PRINCIPALE...");
                Sleep(1000);
                break;
            default:

                break;
        }
    } while (scelta != 3);
}

//FUNZIONE CHE CARICA LA SEZIONE ORDINAZIONI
void sez_ordinazioni(elenco_prodotti *mdg, double *tot_inc){

    int i, c, k;
    char ordinazioni[400];
    int prodot[200];
    double pr_prodot[200];
    char *prod;
    const char s[2] = " ";
    int cod_prod;
    double tot_so = 0;

    char scelta;

    //SEZIONE DICHIARAZIONE VARIABILI
    prodotto_scelto carrello;

    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t   SEZIONE ORDINAZIONI\n");
    printf("\n\t\t\t\t\t\t\tLOADING...");
    Sleep(500);

    system("cls");
    printf("\n\n\n\t\t\t\t\t\t\t  MENU DEL GIORNO\n\n");

    printf("\t\t\t\t\tnum\t     nome\t        prezzo        pz.disp.\n\n");
    for(i = 0 ; i < menu_len(mdg) ; i++) {
        printf("\t\t\t\t\t%d\t%s\t\t%.2lf\t\t%d\n", mdg->m[i].c_prodotto, mdg->m[i].nome, mdg->m[i].prezzo, mdg->m[i].pz_disponibili);
    }
    printf("\n\t\t\t\t\tinserire una o piu' scelte separate da uno spazio\n\t\t\t\t\t(Valori non esistenti non verranno contati):  ");
    fgets(ordinazioni, 400, stdin);


    system("cls");
    printf ("\n\n\n\n\t\t\t\t\tSono stati selezionati i seguenti elementi dal Menu\n");

    c=0;
    prod = strtok(ordinazioni, s);
    while(prod!=NULL){
        cod_prod = atoi(prod);
        if(cod_prod>0&&cod_prod < menu_len(mdg)+1){
            if(mdg->m[cod_prod-1].pz_disponibili > 0) {
                printf("\n\t\t\t\t\t\t %d - %s", cod_prod, mdg->m[cod_prod - 1].nome);
                mdg->m[cod_prod-1].pz_disponibili = mdg->m[cod_prod-1].pz_disponibili-1;
                prodot[c] = cod_prod;
                pr_prodot[c] = mdg->m[cod_prod - 1].prezzo;
                c++;
            }
            else printf("\n\t\t\t\t\t\tProdotto non disponibile");
        }
        prod = strtok(NULL, s);
    }

    printf("\n\n\t\t\t\t\t\tConfermare? [Y][N]: ");
    scelta = getchar();

    if(scelta == 'Y'||scelta =='y'){
        for(k = 0; k<c; k++){
            tot_so = tot_so + pr_prodot[k];
        }
        printf("\n\n\t\t\t\t\t\tScelte confermate");
        _setmode(_fileno(stdout), _O_U16TEXT);
        wprintf(L"\n\n\t\t\t\t\t\tTotale: \u20AC ");
        _setmode(_fileno(stdout), _O_TEXT);
        printf("%.2lf", tot_so);
        *tot_inc = *tot_inc + tot_so;
    }
    else {
        for(k = 0; k<c; k++){
            mdg->m[prodot[k]-1].pz_disponibili = mdg->m[prodot[k]-1].pz_disponibili+1;
        }
        printf("\n\n\t\t\t\t\t\tScelte annullate");
    }
    getchar();

}






