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
        printf("\nQue voulez-vous faire ?\n\n");
        printf("\t1 - Ajouter un eleve\n");
        printf("\t2 - Afficher les eleves\n");
        printf("\t3 - Modifier un eleve\n");
        printf("\t4 - Supprimer un eleve\n");
        printf("\t0 - Retourner au menu precedent\n");
        scanf("%d",&choix);
        getchar();
        switch(choix){
            default : break;
            case 0 : break;
            case 1 :
                SaisirEleve(&eleve);
                printf("\n\nVous avez saisi les informations suivantes : \n");
                AfficherEleve(eleve);
                printf("\nListe des classes enregistrees : \n");
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
                                E->TabClasse[i].nbEleveClasse++;
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
        printf("\nQue voulez-vous faire ?\n\n\t1 - Modifier les informations de l'ecole\n\t2 - Afficher l'ecole \n\t0 - Retourner au menu precedent\n");
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
        }
    }while(choix!=0);
}

/****************************************************************************************************/


// ------------------------------------------------------- Cyril --------------------------------------------------------- //

void MenuBackup(struct Ecole *E)
{
    int choix=-1;
    char choixDeux;
    printf("\n\t1- Sauvegarder les donnees de l'ecole");
    printf("\n\t2- Chargement les donnees de l'ecole");
    printf("\n\t1- Retour\n");
    printf("Choix: ");
    scanf("%d", &choix);
    getchar();
    switch (choix)
    {
        case 0: return;
            break;
        case 1: printf("!! Attention, un enregistrement sur ce document sera definitif. En cas d'erreur, un retour en arriere ne sera pas possible !!\n");
                printf("Etes vous sur de vouloir poursuivre ? (o/n)");
                do
                {   printf("Votre choix:");
                    scanf("%c", &choixDeux);
                    getchar();
                }while(!(choixDeux=='o' || choixDeux=='n'));
                EcrireBinaire(E);
            break;
        case 2: LireBinaire(E);
                EcrireEcole(*E);
                EcrireClasse(*E);
                Ecrire_Fichier_Classe(*E);
            break;
    }
}



// ----------------------------------------------------------------------------------------------------------------------- //








