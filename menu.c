#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

/***********************************************Daphne***********************************************/

void MenuEleve(Ecole_t *E){
    int choix=-1;
    int i;
    char nvelleclasse;
    Eleve_t eleve;
    do{
        printf("\n*****Gestion des eleves*****\n");
        printf("\nQue voulez-vous faire ?\n1 - Ajouter un eleve\n2 - Afficher les eleves\n3 - Modifier un eleve\n4 - Supprimer un eleve\n0 - Retourner au menu precedent\n");
        scanf("%d",&choix);
        getchar();
        switch(choix){
            default : break;
            case 0 : break;
            case 1 :
                SaisirEleve(&eleve);
                E->nbEleveTotal++;
                printf("\n\nVous avez saisi les informations suivantes : ");
                AfficherEleve(eleve);
                printf("\n***Veuillez indiquer la classe a laquelle l'eleve sera affecte.***\n");
                i=RechercherClasse(*E);
                if(E->TabClasse[i].nbEleveClasse<25){
                        AffecterEleve(eleve, &E->TabClasse[i]);
                }else{
                        printf("\nAttention ! Cette classe est deja complete. Voulez-vous creer une nouvelle classe ?(o/n) ");
                        scanf("%c", &nvelleclasse);
                        getchar();
                        if(nvelleclasse=='o'){
                                AjouterClasse(E, E->nbClasse);
                        }else{
                                printf("\nOperation annulee.");
                        }
                }
                RangerEcole(E);
                break;
            case 2 :
                printf("\n***Affichage des eleves***\n");
                AfficherEleveTotal(*E);
                break;
            case 3 :
                RechercherEleve(*E);
                break;
            case 4 :
                printf("\n***Suppression d'un eleve***\n");
                SupprimerEleve(E);
                RangerEcole(E);
                break;
        }
    }while(choix!=0);
}
void MenuClasse(Ecole_t *E){
    int choix=-1;
    int i;
    do{
        printf("\n*****Gestion des classes*****\n");
        printf("\nQue voulez-vous faire ?\n1 - Ajouter une classe\n2 - Modifier une classe\n3 - Afficher une classe\n0 - Retourner au menu precedent\n");
        scanf("%d",&choix);
        getchar();
        switch(choix){
            default : break;
            case 0 : break;
            case 1 :
                printf("\n\n*****Saisie d'une classe*****\n");
                AjouterClasse(E, E->nbClasse);
                if(E->nbClasse>1 && E->nbEleveTotal){
                        RangerEcole(E);
                }
                break;
            case 2 :
                //Modification d'une classe
                i=RechercherClasse(*E);
                ModifierClasse(&E->TabClasse[i]);
                break;
            case 3 :
                printf("\n\n*****Affichage d'une classe*****\n");
                ChoixClasseAfficher(*E);
                break;
        }
    }while(choix!=0);
}
void MenuEcole(Ecole_t *E){
    int choix=-1;
    do{
        printf("\n*****Gestion de l'ecole*****\n");
        printf("\nQue voulez-vous faire ?\n1 - Modifier les informations de l'ecole\n2 - Afficher l'ecole\n0 - Retourner au menu precedent\n");
        scanf("%d",&choix);
        getchar();
        switch(choix){
            default : break;
            case 0 : break;
            case 1 :
                printf("\n\n*****Modification des informations de l'ecole*****\n");
                ModifierEcole(E);
                break;
            case 2 :
                RangerEcole(E);
                printf("\n\n*****Affichage de l'ecole*****\n");
                AfficherEcole(*E);
                break;
        }
    }while(choix!=0);
}
/****************************************************************************************************/
