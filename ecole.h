#include <stdio.h>
#include <stdlib.h>
#include "classe.h"


//          ****        ecole.h        ****


#ifndef ECOLE_H
#define ECOLE_H
#define MAXCLASSE 15
#define MAX 30

typedef struct Ecole
{
    char nomEcole[MAX];
    char nomDirecteur[MAX];
    int nbEleveTotal;
    int nbEleveNiveau[5];
    int nbClasse;
    struct Classe TabClasse[MAXCLASSE];
} Ecole_t;


void AfficherEcole(struct Ecole); // Affiche les parmètres de l'école

void SaisirEcole(struct Ecole *); // Saisi les paramètres de l'école

void ModifierEcole(struct Ecole *);

void AfficherParametreClasse(struct Ecole); // Affiche les paramètres de toutes les classes (Niveau, numéro, instit... )

void AfficherEleveTotal(struct Ecole); // Affiche TOUT les élèves de l'école

void AfficherEleveClasse(struct Ecole); // N'affiche les élèves que d'une seule classe

int Recherche(char *A, char *B); // Fonction de recherche. Prends en paramètres deux chaines de caractères

void Initialisation(struct Ecole *);

/*Ecrit un tableau de classes de l'école dans un fichier csv appelé FichierEcole*/
void Ecrire_Fichier_Classe(const char *FichierEcole, Ecole_t E, int nb);


/*Lit un tableau de classes de l'école du fichier FichierEcole.csv*/
void Lire_Fichier_Classe(const char *FichierEcole, Ecole_t *E, int nb);


void FonctionSave(struct Ecole);

void FonctionChargeEcole(struct Ecole *);

void FonctionChargeClasse(struct Ecole *);


#endif // ECOLE_H
