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
        printf("\n\t\t***** Gestion des eleves *****\n");
        printf("\nQue voulez-vous faire ?\n\n\t1 - Ajouter un eleve\n\t2 - Afficher les eleves\n\t3 - Modifier un eleve\n\t4 - Supprimer un eleve\n\t0 - Retourner au menu precedent\n");
        scanf("%d",&choix);
        getchar();
        switch(choix){
            default : break;
            case 0 : break;
            case 1 :
                SaisirEleve(&eleve);
                printf("\n\nVous avez saisi les informations suivantes : \n");
                AfficherEleve(eleve);
                printf("\nListe des classes enregistrées : \n");
                AfficherParametreClasse(*E);
                printf("\n*** Veuillez indiquer la classe a laquelle l'eleve sera affecte ***\n");
                i=RechercherClasse(*E);
                if(E->TabClasse[i].nbEleveClasse<25){
                        AffecterEleve(eleve, &E->TabClasse[i]);
                        E->nbEleveTotal++;
                        EcrireEcole(*E);
                        EcrireClasse(*E);
                        Ecrire_Fichier_Classe(*E);
                }else{
                        printf("\nAttention ! Cette classe est deja complete. Voulez-vous creer une nouvelle classe ?(o/n) ");
                        scanf("%c", &nvelleclasse);
                        getchar();
                        if(nvelleclasse=='o'){
                                AjouterClasse(E, E->nbClasse);
                                AffecterEleve(eleve, &E->TabClasse[i]);
                                E->nbEleveTotal++;
                                EcrireEcole(*E);
                                EcrireClasse(*E);
                                Ecrire_Fichier_Classe(*E);
                        }else{
                                printf("\nOperation annulee.");
                        }
                }
                /*if(E->nbClasse>1 && E->nbEleveTotal){
                        RangerEcole(E);
                }*/
                EcrireEcole(*E);
                EcrireClasse(*E);
                Ecrire_Fichier_Classe(*E);
                break;
            case 2 :
                printf("\n*** Affichage des eleves ***\n");
                AfficherEleveTotal(*E);
                break;
            case 3 :
                RechercherEleve(E);
                EcrireEcole(*E);
                EcrireClasse(*E);
                Ecrire_Fichier_Classe(*E);
                break;
            case 4 :
                printf("\n*** Suppression d'un eleve ***\n");
                SupprimerEleve(E);
                /*if(E->nbClasse>1 && E->nbEleveTotal){
                        RangerEcole(E);
                }*/
                EcrireEcole(*E);
                EcrireClasse(*E);
                Ecrire_Fichier_Classe(*E);
                break;
        }
    }while(choix!=0);
}
void MenuClasse(Ecole_t *E){
    int choix=-1;
    int i;
    do{
        printf("\n***** Gestion des classes *****\n");
        printf("\nQue voulez-vous faire ?\n\n\t1 - Ajouter une classe\n\t2 - Modifier une classe\n\t3 - Afficher une classe\n\t4 - Afficher toutes les classes\n\t0 - Retourner au menu precedent\n");
        scanf("%d",&choix);
        getchar();
        switch(choix){
            default : break;
            case 0 : break;
            case 1 :
                printf("\n\n***** Saisie d'une classe *****\n");
                printf("\nListe des classes enregistrées : \n");
                AfficherParametreClasse(*E);
                AjouterClasse(E, E->nbClasse);
                /*if(E->nbClasse>1 && E->nbEleveTotal){
                        RangerEcole(E);
                }*/
                EcrireEcole(*E);
                EcrireClasse(*E);
                Ecrire_Fichier_Classe(*E);
                break;
            case 2 :
                //Modification d'une classe
                printf("\nListe des classes enregistrées : \n");
                AfficherParametreClasse(*E);
                i=RechercherClasse(*E);
                ModifierClasse(&E->TabClasse[i]);
                EcrireEcole(*E);
                EcrireClasse(*E);
                Ecrire_Fichier_Classe(*E);
                break;
            case 3 :
                printf("\n\n***** Affichage d'une classe *****\n");
                printf("\nListe des classes enregistrées : \n");
                AfficherParametreClasse(*E);
                ChoixClasseAfficher(*E);
                break;
                case 4 :
                printf("\n\n***** Affichage de toutes les classes *****\n\n");
                for(i=0;i<E->nbClasse;i++){
                        AfficherClasse(E->TabClasse[i]);
                        printf(" -------------------------------------------------------------\n");
                        AfficherEleveClasse(E->TabClasse[i]);
                        printf(" -------------------------------------------------------------\n\n");
                }
                break;
        }
    }while(choix!=0);
}
void MenuEcole(Ecole_t *E){
    int choix=-1;
    do{
        printf("\n***** Gestion de l'ecole *****\n");
        printf("\nQue voulez-vous faire ?\n\n\t1 - Modifier les informations de l'ecole\n\t2 - Afficher l'ecole\n\t3 - Enregistrer le back-up\n\t4 - Récupérer le back-up\n\t0 - Retourner au menu precedent\n");
        scanf("%d",&choix);
        getchar();
        switch(choix){
            default : break;
            case 0 : break;
            case 1 :
                printf("\n\n***** Modification des informations de l'ecole *****\n");
                ModifierEcole(E);
                EcrireEcole(*E);
                EcrireClasse(*E);
                Ecrire_Fichier_Classe(*E);
                break;
            case 2 :
                /*if(E->nbClasse>1 && E->nbEleveTotal){
                        RangerEcole(E);
                }*/
                printf("\n\n***** Affichage de l'ecole *****\n");
                AfficherEcole(*E);
                break;
        case 3 :
                printf("\n\n***** Enregistrement du back-up *****\n");
                EcrireBinaire(E);
                break;
        case 4 :
                printf("\n\n***** Récupération du back-up *****\n");
                LireBinaire(E);
                break;
        }
    }while(choix!=0);
}
/****************************************************************************************************/
