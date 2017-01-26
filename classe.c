#include <stdio.h>
#include <string.h>
#include <time.h>
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
