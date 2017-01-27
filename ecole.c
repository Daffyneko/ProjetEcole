#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#include "ecole.h"


//                                             ****        ecole.c        ****


// ------------------------------------------------------- Cyril --------------------------------------------------------- //

void AfficherEcole (struct Ecole E) // Affiche les parmètres de l'école
{
    printf("Nom de l'ecole : %s\n", E.nomEcole); // Affiche le nom dde l'école
    printf("Nom du directeur : %s\n", E.nomDirecteur); // Affiche le nom du directeur
    printf("Nombre de classe : %d\n", E.nbClasse); // Affiche le nombre de classe dans l'école
    printf("Nombre d'eleve dans l'ecole : %d\n", E.nbEleveTotal); // Affiche le nombre d'élève dans toute l'école
}

void SaisirEcole (struct Ecole *E) // Saisi les paramètres de l'école
{
    printf("Saisir le nom d'ecole : ");
    fgets(E->nomEcole,sizeof(E->nomEcole), stdin); // Permet de saisir le nom de l'école
    if (E->nomEcole[strlen(E->nomEcole)-1]=='\n') // On regarde si l'avant dernier caractère de la chaine est un retour à la ligne
        E->nomEcole[strlen(E->nomEcole)-1]='\0'; // Si oui, on mets '\0' à la place

    printf("Saisir le nom du directeur : ");
    fgets(E->nomDirecteur,sizeof(E->nomDirecteur), stdin); // Permet de saisir le nom du directeur
    if (E->nomDirecteur[strlen(E->nomDirecteur)-1]=='\n') // On regarde si l'avant dernier caractère de la chaine est un retour à la ligne
        E->nomDirecteur[strlen(E->nomDirecteur)-1]='\0'; // Si oui, on mets '\0' à la place
}

void AfficherEleveTotal(struct Ecole E) // Affiche TOUT les élèves de l'école
{
    int i, j;
    for (i=0; i<E.nbClasse; i++) // Navigue dans les classes
        for (j=0; j<E.nbEleveTotal; j++) // Navigue dans les élèves
            AfficherEleve(E.TabClasse[i].TabEleve[j]); // Envoie les élèves à la fonction d'affichage
}

void AfficherParametreClasse(struct Ecole E) // Affiche les paramètres de toutes les classes (Niveau, numéro, instit... )
{
    int i;
    for (i=0; i<E.nbClasse; i++) // Navigue dans les classes
            AfficherClasse(E.TabClasse[i]); // Envoie les classes à la fonction d'affichage de paramètres
}
/*
void ChoixClasseAfficher2(struct Ecole E)
{
    AfficherParametreClasse(E);
}
*/
void ChoixClasseAfficher(struct Ecole E) // N'affiche les élèves que d'une seule classe
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
                    AfficherClasse (E.TabClasse[j]);
        }
    }
}

int Recherche(char *A, char *B) // Fonction de recherche. Prends en paramètres deux chaines de caractères
{
    return strcmp(A, B);
}

void ModifierEcole(struct Ecole *E)
{ // Modifie l'école en spécifiant le champ
    int choix=-1;

    printf("\n\n\t1- Nom de l'ecole\n");
    printf("\t2- Nom du directeur\n");
    printf("Quel champ modifier: ");
    scanf("%d", &choix); // spécifie le champ à modifier

    switch (choix)
    {// En fonction du champ  nous emmène à modifier soit l'école soit le nom du directeur

        case 1: printf("Saisir le nouveau nom de l'ecole: ");
                printf("Saisir le nom d'ecole : ");
                fgets(E->nomEcole,sizeof(E->nomEcole), stdin); // Permet de saisir le nom de l'école
                if (E->nomEcole[strlen(E->nomEcole)-1]=='\n') // On regarde si l'avant dernier caractère de la chaine est un retour à la ligne
                    E->nomEcole[strlen(E->nomEcole)-1]='\0'; // Si oui, on mets '\0' à la place
            break;

        case 2: printf("Saisir le nouveau nom du directeur: ");
                fgets(E->nomDirecteur,sizeof(E->nomDirecteur), stdin); // Permet de saisir le nom du directeur
                if (E->nomDirecteur[strlen(E->nomDirecteur)-1]=='\n') // On regarde si l'avant dernier caractère de la chaine est un retour à la ligne
                    E->nomDirecteur[strlen(E->nomDirecteur)-1]='\0'; // Si oui, on mets '\0' à la place
            break;
    }
}

void Initialisation(struct Ecole *E)
{
    int i, j;

    strcpy(E->nomEcole,"\0");
    strcpy(E->nomDirecteur,"\0");
    E->nbEleveTotal=0;
    E->nbClasse=0;
    for (i=0; i<5; i++)
        E->nbEleveNiveau[i]=0;
    for (i=0; i<MAXCLASSE; i++)
    {
        strcpy(E->TabClasse[i].niveau,"\0");
        strcpy(E->TabClasse[i].nomEnseignant,"\0");
        E->TabClasse[i].nbEleveClasse=0;
        E->TabClasse[i].numClasse=0;
        for(j=0; j<MAXELEVES; j++)
        {
            strcpy(E->TabClasse[i].TabEleve[j].nom,"\0");
            strcpy(E->TabClasse[i].TabEleve[j].prenom,"\0");
            E->TabClasse[i].TabEleve[j].sexe='\0';
            memset(&E->TabClasse[i].TabEleve[j].dateNaissance, 0,sizeof(E->TabClasse[i].TabEleve[j].dateNaissance));
        }
    }
}


// ------------------------------------------------------------------------------------------------------------------------ //
