#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#include "ecole.h"


//                                             ****        ecole.c        ****


// ------------------------------------------------------- Cyril --------------------------------------------------------- //

void AfficherEcole (struct Ecole E)
{
    printf("Nom de l'ecole : %s\n", E.nomEcole); // Affiche le nom dde l'école
    printf("Nom du directeur : %s\n", E.nomDirecteur); // Affiche le nom du directeur
    printf("Nombre de classe : %d\n", E.nbClasse); // Affiche le nombre de classe dans l'école
    printf("Nombre d'eleve dans l'ecole : %d\n", E.nbEleveTotal); // Affiche le nombre d'élève dans toute l'école
}

void SaisirEcole (struct Ecole *E)
{
    printf("Saisir le nom d'ecole : ");
    fgets(E->nomEcole,sizeof(E->nomEcole), stdin); // Permet de saisir le nom de l'école
    if (E->nomEcole[strlen(E->nomEcole)-1]=='\n')
        E->nomEcole[strlen(E->nomEcole)-1]='\0';

    printf("Saisir le nom du directeur : ");
    fgets(E->nomDirecteur,sizeof(E->nomDirecteur), stdin); // Permet de saisir le nom du directeur
    if (E->nomDirecteur[strlen(E->nomDirecteur)-1]=='\n') // On regarde si l'avant dernier caractère de la chaine est un retour à la ligne
        E->nomDirecteur[strlen(E->nomDirecteur)-1]='\0'; // Si oui, on mets '\0' à la place
}

void AfficherEleveTotal(struct Ecole E)
{
    int i, j;
    for (i=0; i<10; i++) // Navigue dans les classes
        for (j=0; j<10; j++) // Navigue dans les élèves
            AfficherEleve(E.TabClasse[i].TabEleve[j]); // Envoie les élèves à la fonction d'affichage
}

void AfficherParametreClasse(struct Ecole E)
{
    int i;
    for (i=0; i<10; i++) // Navigue dans les classes
            AfficherClasse(E.TabClasse[i]); // Envoie les classes à la fonction d'affichage de paramètres
}

void AfficherUneClasse(struct Ecole E)
{ // Affiche les élèves d'une classe choisie
    char choixClasse[4]; // Stock le nom de la classe rechercher
    int i, j, resultat, choixNum; // resultat garde en mémoire la valeur de la comparaison
                                // choixNum est le numéro de classe associé au nom que l'utilisateur veut faire afficher

    printf("Saisir le nom et le numéro de la classe à afficher : ");
    printf("Nom: ");
    fgets(choixClasse,sizeof(choixClasse), stdin); // Permet de saisir le nom du directeur
    if (choixClasse[strlen(choixClasse)-1]=='\n') // On regarde si l'avant dernier caractère de la chaine est un retour à la ligne
        choixClasse[strlen(choixClasse)-1]='\0'; // Si oui, on mets '\0' à la place

    for (i=0; i<E.nbClasse; i++)
    {
        resultat = Recherche(choixClasse, E.TabClasse[i].niveau);
        if (resultat == 0)
        {
            printf("Numero: ");
            scanf("%d", &choixNum);
            for (j=i; j<E.nbClasse; j++)
                if (choixNum==E.TabClasse[j].numClasse)
                    printf(" ");
        // --------- Fonction qui affiche les élèves d'une classe ---------- //
        }
    }
}

int Recherche(char *A, char *B)
{
    return strcmp(A, B);
}

// ------------------------------------------------------------------------------------------------------------------------ //


