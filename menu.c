#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

void MenuEleve(Ecole_t E){
    int choix=-1;
    Eleve_t eleve;
    do{
        printf("\n*****Gestion des élèves*****\n");
        printf("\nQue voulez-vous faire ?\n1 - Ajouter un élève\n2 - Afficher les élèves\n3 - Supprimer un élève\n0 - Retourner au menu précédent\n");
        scanf("%d",&choix);
        switch(choix){
            default : break;
            case 0 : break;
            case 1 :
                SaisirEleve(&eleve);
                printf("\n\nVous avez saisi les informations suivantes : ");
                AfficherEleve(eleve);
                break;
            case 2 :
                printf("\n***Affichage des élèves***\n");
                AfficherEleve(eleve);//fonction temporaire, à remplacer par affichertabeleve
                break;
            case 3 :
                printf("\n***Suppression d'un élève***\n");
                break;
        }
    }while(choix!=0);
}
void MenuClasse(Ecole_t E){
    int choix=-1;
    do{
        printf("\n*****Gestion des classes*****\n");
        printf("\nQue voulez-vous faire ?\n1 - Ajouter une classe\n2 - Modifier une classe\n3 - Afficher une classe\n0 - Retourner au menu précédent\n");
        scanf("%d",&choix);
        switch(choix){
            default : break;
            case 0 : break;
            case 1 :
                printf("\n\n*****Saisie d'une classe*****\n");
                break;
            case 2 :
                printf("\n\n*****Modification d'une classe*****\n");
                break;
            case 3 :
                printf("\n\n*****Affichage d'une classe*****\n");
                break;
        }
    }while(choix!=0);
}
void MenuEcole(Ecole_t E){
    int choix=-1;
    do{
        printf("\n*****Gestion de l'école*****\n");
        printf("\nQue voulez-vous faire ?\n1 - Saisir les informations de l'école\n2 - Modifier l'école\n3 - Afficher l'école\n0 - Retourner au menu précédent\n");
        scanf("%d",&choix);
        switch(choix){
            default : break;
            case 0 : break;
            case 1 :
                printf("\n\n*****Saisie des informations de l'école*****\n");
                break;
            case 2 :
                printf("\n\n*****Modification des informations de l'école*****\n");
                break;
            case 3 :
                printf("\n\n*****Affichage de l'école*****\n");
                break;
        }
    }while(choix!=0);
}
