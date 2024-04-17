
#include "servizio.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void c_menu(elenco_prodotti * mptr) {
    //carico il menu
    FILE *fp;
    int i = 0;
    char file_name[100];
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\tI prodotti oltre al 30 non verranno inseriti!\n");
    printf("\n\t\t\t\t\tInserisci il nome del file (ricorda il .txt):\n\n\t\t\t\t\t\t\t");
    scanf("%s", file_name);
    getchar();

    char nfC[100] = "text_files/";

    strcat(nfC, file_name);

    fp = fopen(nfC, "r");

    if (!fp) {
        printf("\n\t\t\t\t\tImpossibile aprire il file.\n");
        printf("\t\t\t\t\tINVIO per continuare...");
        getchar();
        return;
    } else {
        while (!feof(fp)&&i<30) {
            mptr->m[i].c_prodotto = i+1;
            fscanf(fp, "%s %lf %d", mptr->m[i].nome, &mptr->m[i].prezzo, &mptr->m[i].pz_disponibili);
            i++;
        }

        fclose(fp);
        mptr->len = i;   //indico quanto è lungo il menu, utile in caso di sovrascrittura dell'elenco
        mptr->stato = 1; //modifico lo stato del menu (1 se il menu è stato inserito altrimenti 0 perchè deve ancora
        //essere caricato)

        printf("\n\t\t\t\t\t\tmenu caricato correttamente");
        printf("\n\t\t\t\t\t\tINVIO per continuare...");
        getchar();


    }
}

int menu_status(elenco_prodotti * mptr){
    return mptr->stato;
}

int menu_len(elenco_prodotti * mptr){
    return mptr->len;
}

int canc_menu(elenco_prodotti * mptr){
    if(mptr->stato == 1){
        mptr->stato = 0;
        return 1;
    }
    else return 0;
}


/*int is_new_day(){                      // funzione deprecata
    static int act_day = 0;
    int ris = 0;              // 0 se il giorno è lo stesso, 1 se il giorno è cambiato

    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    if(act_day!=timeinfo->tm_mday){
        act_day = timeinfo->tm_mday;
        ris = 1;
    }
    else ris = 0;

    return ris;
}*/