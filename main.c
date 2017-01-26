#include <stdio.h>
#include <stdlib.h>

#include "ecole.h"
#include "menu.h"

int main(){
    Eleve_t E;
    Ecole_t MonEcole;
    int choix=-1;
    printf("\n----------------------Bienvenue à l'école LDNR----------------------\n");
    do{
        printf("\nQue voulez-vous faire ?");
        printf("\n1 - Tests unitaires");
        printf("\n2 - Gestion des élèves");
        printf("\n3 - Gestion des classes");
        printf("\n4 - Gestion de l'école");
        printf("\n0 - Quitter\n");
        scanf("%d",&choix);

        switch(choix){
        default : return -1;
        case 0 : break;
        case 1 ://Ecrivez ici les fonctions que vous voulez tester
                SaisirEleve(&E);
                AfficherEleve(E);
                break;
        case 2 :
                MenuEleve(MonEcole);
                break;
        case 3 :
            MenuClasse(MonEcole);
            break;
        case 4 :
            MenuEcole(MonEcole);
        }
    }while(choix!=0);

    return 0;
}
