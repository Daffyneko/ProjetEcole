#include <stdio.h>
#include <string.h>
#include <time.h>
#include "classe.h"


void AfficherClasse (Classe_t C)
{int i;
printf("Classe niveau:%s , numero:%d, nom de l'enseignant: %s", C.niveau, C.numClasse, C.nomEnseignant);
for (i=0; i<25; i++)
AfficherEleve(TabEleve[i]);

};


void SaisirClasse(Classe_t *C)
{int i;
    printf("Niveau de la classe: \n ");     //saisie du niveau
    scanf("%s", C->niveau);

    printf("Nom de l'enseignant/e :\n");
    fgets(C->nomEnseignant, MAX, stdin); // on r�cup�re la ligne de caract�re
    C->nomEnseignant[strlen(C->nomEnseignant)-1] = '\0'; // on supprime le '\n')

    printf("Num�ro de la classe : \n"); // saisie du num�ro de la classe
    scanf("%d", &C->numClasse);
    getchar();

    for(i=0; i <C->nbEleveClasse; i++) // saisie de chacun des �l�ves de la classe
    {
        SaisirEleve(&C->TabEleve[i]); // utilisation de la fonction de saisie des �l�ves
    }
}



};

/* LISTES CHAINEES-----------------------*********************

void SaisirClasse{Classe_t *C);


/*Affiche la classe en parcourant la structure r�cursive classe. L'�toile n'est pas un pointeur
mais le d�but de la premi�re cellule

void AfficherClasse(Classe_t *tete);
{   //int i
   Classe_t *courant;

    // 1 : se positionner en t�te. Equivalent de i = 0.
    eleve = tete;

    // i<taille , tant qu'on n'arrive pas � la fin de la liste (plus d'�l�ments)
    while(eleve!= NULL)
    {
        //2 : affichage : traitement : afficher les donn�es de l'adh�rent
        AfficherClasse(courant->eleve);

        //3 : aller au suivant. Equivalent de i = i +1
        eleve = eleve->suivant;
    }
}
*/
/*Saisie les donn�es de l'adh�rent*/
void Saisir_Adherent(Adherent_t *adherent)
{
    int i;
    printf("Votre nom : ");     //saisie du nom
    scanf("%s", adherent->nom);

    printf("Combient de livre : "); // saisie du nombre de livre
    scanf("%d", &adherent->nb_livres);
    getchar();

    for(i=0; i <adherent->nb_livres; i++) // saisie de chacun des livres
    {
        Saisir_Livre(&adherent->livre[i]);
    }
}
