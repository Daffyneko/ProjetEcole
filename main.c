#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ecole.h"
#include "menu.h"

/***********************************************Daphne***********************************************/
int main(){
    Ecole_t MonEcole;
    int choix=-1;

    /* AUTHENTIFICATION
    char login[30]="admin";
    char mdp[30]="root";
    char entree[30];
    printf("\t\t*****AUTHENTIFICATION*****\n\t\tVeuillez vous identifier.");
    do{
        printf("\n\tLogin : ");
        fscanf(stdin,"%s",entree);
    }while(strcmp(entree,login)!=0);

    do{
        printf("\n\tMot de passe : ");
        fscanf(stdin,"%s",entree);
    }while(strcmp(entree,mdp)!=0);
*/

    Initialisation(&MonEcole);
    LireEcole(&MonEcole);
    LireClasse(&MonEcole);
    Lire_Fichier_Classe(&MonEcole);
    printf("\n----------Bienvenue sur le logiciel de gestion de l'ecole----------\n");
    do{
        printf("\nQue voulez-vous faire ?");
        printf("\n1 - Tests unitaires");
        printf("\n2 - Gestion des eleves");
        printf("\n3 - Gestion des classes");
        printf("\n4 - Gestion de l'ecole");
        printf("\n0 - Quitter\n");
        scanf("%d",&choix);
        getchar();

        switch(choix){
        default : return -1;
        case 0 : break;
        case 1 ://Ecrivez ici les fonctions que vous voulez tester
                AfficherEleveTotal(MonEcole);
                printf("\n\n%d",MonEcole.nbEleveTotal);
                break;
        case 2 :
                MenuEleve(&MonEcole);
                break;
        case 3 :
                MenuClasse(&MonEcole);
                break;
        case 4 :
                MenuEcole(&MonEcole);
                break;
        }
    }while(choix!=0);

    return 0;
}
/****************************************************************************************************/
