#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

/***********************************************Daphné***********************************************/

void MenuEleve(Ecole_t E){
    int choix=-1;
    int i;
    Eleve_t eleve;
    do{
        printf("\n*****Gestion des élèves*****\n");
        printf("\nQue voulez-vous faire ?\n1 - Ajouter un élève\n2 - Afficher les élèves\n3 - Modifier un élève\n4 - Supprimer un élève\n0 - Retourner au menu précédent\n");
        scanf("%d",&choix);
        getchar();
        switch(choix){
            default : break;
            case 0 : break;
            case 1 :
                SaisirEleve(&eleve);
                E.nbEleveTotal++;
                printf("\n\nVous avez saisi les informations suivantes : ");
                AfficherEleve(eleve);
                printf("\n***Veuillez indiquer la classe à laquelle l'élève sera affecté.***\n");
                i=RechercherClasse(E);
                AffecterEleve(eleve, &E.TabClasse[i]);
                break;
            case 2 :
                printf("\n***Affichage des élèves***\n");
                AfficherEleveTotal(E);
                break;
            case 3 :
                RechercherEleve(E);
                break;
            case 4 :
                printf("\n***Suppression d'un élève***\n");
                break;
        }
    }while(choix!=0);
}
void MenuClasse(Ecole_t E){
    int choix=-1;
    int i;
    Classe_t C;
    do{
        printf("\n*****Gestion des classes*****\n");
        printf("\nQue voulez-vous faire ?\n1 - Ajouter une classe\n2 - Modifier une classe\n3 - Afficher une classe\n0 - Retourner au menu précédent\n");
        scanf("%d",&choix);
        getchar();
        switch(choix){
            default : break;
            case 0 : break;
            case 1 :
                printf("\n\n*****Saisie d'une classe*****\n");
                SaisirClasse(&C);
                AfficherClasse(C);
                AjouterClasse(C,&E);
                break;
            case 2 :
                //Modification d'une classe
                i=RechercherClasse(E);
                ModifierClasse(&E.TabClasse[i]);
                break;
            case 3 :
                printf("\n\n*****Affichage d'une classe*****\n");
                ChoixClasseAfficher(E);
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
        getchar();
        switch(choix){
            default : break;
            case 0 : break;
            case 1 :
                printf("\n\n*****Saisie des informations de l'école*****\n");
                SaisirEcole(&E);
                break;
            case 2 :
                printf("\n\n*****Modification des informations de l'école*****\n");
                ModifierEcole(&E);
                break;
            case 3 :
                printf("\n\n*****Affichage de l'école*****\n");
                AfficherEcole(E);
                break;
        }
    }while(choix!=0);
}
/****************************************************************************************************/
