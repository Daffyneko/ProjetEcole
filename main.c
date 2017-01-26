#include <stdio.h>
#include <stdlib.h>

#include "ecole.h"

int main(){
    //Eleve_t E;
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
                //Cela nous permet de voir aussi comment les autres utilisent leurs fonctions
                //SaisirEleve(&E);
                //AfficherEleve(E); 
                //SaisirClasse(&C);
                // AfficherClasse (C);
                
                break;
        case 2 :
            printf("\nGestion des élèves.");
            break;
        case 3 :
            printf("\nGestion des classes.");
            break;
        case 4 :
            printf("\nGestion de l'école.");
        }
    }while(choix!=0);

    return 0;
}
