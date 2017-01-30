#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib>
#include "classe.h"


void AfficherClasse (Classe_t C)
{int i;
printf("Classe niveau:%s , numero:%d, nom de l'enseignant: %s", C.niveau, C.numClasse, C.nomEnseignant);
for (i=0; i<25; i++)
AfficherEleve(C.TabEleve[i]);

};


void SaisirClasse(Classe_t *C)
{int i;
    printf("Niveau de la classe: \n ");     //saisie du niveau
    scanf("%s", C->niveau);

    printf("Nom de l'enseignant/e :\n");
    fgets(C->nomEnseignant, MAX, stdin); // on récupère la ligne de caractère
    C->nomEnseignant[strlen(C->nomEnseignant)-1] = '\0'; // on supprime le '\n')

    printf("Numéro de la classe : \n"); // saisie du numéro de la classe
    scanf("%d", &C->numClasse);
    getchar();

    for(i=0; i <C->nbEleveClasse; i++) // saisie de chacun des élèves de la classe
    {
        SaisirEleve(&C->TabEleve[i]); // utilisation de la fonction de saisie des élèves
    }
};

void ModifierClasse(Classe_t *C)
{
    int choix=-1;

    printf("Veuillez saisir le champ à modifier : \n1 - Niveau de la classe\n2 - Nom de l'enseignant(e)\n3 - Nombre d'élèves\n 4 - Annuler\n");
    scanf("%d",&choix);
    switch(choix)
    {
        default : break;
        case 1 :
            do {
                printf("\nVeuillez entrer le niveau de la classe : ");// entrer le nouveau niveau pour remplacer l'ancien
                scanf("%s", C->niveau);
            }while(strcmp(C->niveau,"CP")!=0 && strcmp(C->niveau,"CE1")!=0 && strcmp(C->niveau,"CE2")!=0 && strcmp(C->niveau,"CM1")!=0 && strcmp(C->niveau,"CM2")!=0); // redemande tant que le niveau ne correspond pas
            printf("\n***Modification effectuée***\n");
            break;

        case 2 :
            printf("\nVeuillez entrer le nom de l'enseignant(e) : \n");// entrer le nouveau nom pour remplacer l'ancien

            fgets(C->nomEnseignant, MAX, stdin); // on récupère la ligne de caractère
            C->nomEnseignant[strlen(C->nomEnseignant)-1] = '\0'; // on supprime le '\n')

            printf("\n***Modification effectuée***\n");
            break;

        case 3 :
            printf("\nVeuillez entrer le nombre d'élèves souhaité : ");
            scanf("%d", &C->nbEleveClasse);
            printf("\n***Modification effectuée***\n");
            break;

        case 4 :
            printf("\n***Modification annulée***\n");
            break;
    }
}



/* LISTES CHAINEES-----------------------*********************

void SaisirClasse{Classe_t *C);


/*Affiche la classe en parcourant la structure récursive classe. L'étoile n'est pas un pointeur
mais le début de la première cellule

void AfficherClasse(Classe_t *tete);
{   //int i
   Classe_t *courant;

    // 1 : se positionner en tête. Equivalent de i = 0.
    eleve = tete;

    // i<taille , tant qu'on n'arrive pas à la fin de la liste (plus d'éléments)
    while(eleve!= NULL)
    {
        //2 : affichage : traitement : afficher les données de l'adhérent
        AfficherClasse(courant->eleve);

        //3 : aller au suivant. Equivalent de i = i +1
        eleve = eleve->suivant;
    }
}
/***********************************************Daphné***********************************************/
void AffecterEleve(Eleve_t E, Classe_t *C){
    strcpy(C->TabEleve[C->nbEleveClasse].nom,E.nom);
    strcpy(C->TabEleve[C->nbEleveClasse].prenom,E.prenom);
    C->TabEleve[C->nbEleveClasse].sexe=E.sexe;
    C->TabEleve[C->nbEleveClasse].dateNaissance.tm_mday=E.dateNaissance.tm_mday;
    C->TabEleve[C->nbEleveClasse].dateNaissance.tm_mon=E.dateNaissance.tm_mon;
    C->TabEleve[C->nbEleveClasse].dateNaissance.tm_year=E.dateNaissance.tm_year;
    C->nbEleveClasse++;
}

void RangerClasses(Classe_t C[], int nbe){
    int i, permut=1;
    Classe_t temp;
    while(permut==1){
        permut=0;
        for(i=0;i<nbe;i++){
            if(strcmp(C[i].niveau,C[i+1].niveau)>0){
                permut=1;
                /* COPIE E[i]-->temp */
                strcpy(temp.niveau, C[i].niveau);
                strcpy(temp.nomEnseignant, C[i].nomEnseignant);
                temp.numClasse=C[i].numClasse;
                temp.nbEleveClasse=C[i].nbEleveClasse;
                /* COPIE E[i+1]-->E[i] */
                strcpy(C[i].niveau, C[i+1].niveau);
                strcpy(C[i].nomEnseignant, C[i+1].nomEnseignant);
                C[i].numClasse=C[i+1].numClasse;
                C[i].nbEleveClasse=C[i+1].nbEleveClasse;
                /* COPIE temp-->E[i+1] */
                strcpy(C[i+1].niveau, temp.niveau);
                strcpy(C[i+1].nomEnseignant, temp.nomEnseignant);
                C[i+1].numClasse=temp.numClasse;
                C[i].nbEleveClasse=C[i+1].nbEleveClasse;
            }
        }
    }
}
/****************************************************************************************************/
