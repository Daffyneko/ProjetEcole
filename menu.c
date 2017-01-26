#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

void MenuEleve(Ecole_t E){
    int choix=-1;
    char recherche[MAX];//le mot à rechercher
    int trouve, modifie;
    int i, j;
    Eleve_t eleve;
    do{
        printf("\n*****Gestion des élèves*****\n");
        printf("\nQue voulez-vous faire ?\n1 - Ajouter un élève\n2 - Afficher les élèves\n3 - Modifier un élève\n4 - Supprimer un élève\n0 - Retourner au menu précédent\n");
        scanf("%d",&choix);
        switch(choix){
            default : break;
            case 0 : break;
            case 1 :
                SaisirEleve(&eleve);
                E.nbEleveTotal++;
                printf("\n\nVous avez saisi les informations suivantes : ");
                AfficherEleve(eleve);
                break;
            case 2 :
                printf("\n***Affichage des élèves***\n");
                AfficherEleve(eleve);//fonction temporaire, à remplacer par affichertabeleve
                break;
            case 3 :
                printf("\nVeuillez entrer le nom de l'élève à modifier : ");
                fscanf(stdin,"%s",recherche);
                modifie=0;
                for(i=0;i<E.nbClasse;i++){
                    for(j=0;j<E.TabClasse[i].nbEleveClasse;j++){
                        trouve=Recherche(E.TabClasse[i].TabEleve[j].nom, recherche);
                        if(trouve==0){
                            ModifierEleve(&E.TabClasse[i].TabEleve[j]);
                            modifie=1;
                        }
                    }
                }
                if(modifie!=1){
                    printf("\n***L'élève n'a pas été trouvé***\n");
                }
                break;
            case 4 :
                printf("\n***Suppression d'un élève***\n");
                break;
        }
    }while(choix!=0);
}
void MenuClasse(Ecole_t E){
    int choix=-1;
    int i, trouve, modifie, numero;
    char recherche;
    Classe_t C;
    do{
        printf("\n*****Gestion des classes*****\n");
        printf("\nQue voulez-vous faire ?\n1 - Ajouter une classe\n2 - Modifier une classe\n3 - Afficher une classe\n0 - Retourner au menu précédent\n");
        scanf("%d",&choix);
        switch(choix){
            default : break;
            case 0 : break;
            case 1 :
                printf("\n\n*****Saisie d'une classe*****\n");
                SaisirClasse(&C);
                break;
            case 2 :
                printf("\nVeuillez entrer le nom de la classe à modifier : ");
                fscanf(stdin,"%s",recherche);
                getchar();
                printf("\nVeuillez entrer le numéro de la classe à modifier : ");
                scanf("%d", &numero);
                modifie=0;
                for(i=0;i<E.nbClasse;i++){
                    trouve=Recherche(E.TabClasse[i].niveau, recherche);
                    if(trouve==0 && E.TabClasse[i].numClasse==numero){
                        ModifierClasse(&E.TabClasse[i]);
                        modifie=1;
                        }
                }
                if(modifie!=1){
                    printf("\n***La classe n'a pas été trouvée***\n");
                }
                break;
            case 3 :
                printf("\n\n*****Affichage d'une classe*****\n");
                AfficherClasse(C);
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
                SaisirEcole(&E);
                break;
            case 2 :
                printf("\n\n*****Modification des informations de l'école*****\n");
                break;
            case 3 :
                printf("\n\n*****Affichage de l'école*****\n");
                AfficherEcole(E);
                break;
        }
    }while(choix!=0);
}
