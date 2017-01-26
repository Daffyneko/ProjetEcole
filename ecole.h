#include <stdio.h>
#include <stdlib.h>
#include "classe.h"


//          ****        ecole.h        ****


#ifndef ECOLE_H
#define ECOLE_H

#define MAX 30

typedef struct Ecole
{
    char nomEcole[MAX];
    char nomDirecteur[MAX];
    int nbEleveTotal;
    int nbEleveNiveau[5];
    int nbClasse;
    struct Classe TabClasse[5];
} Ecole_t;


void AfficherEcole (struct Ecole); // Affiche les parmètres de l'école

void SaisirEcole (struct Ecole *); // Saisi les paramètres de l'école

void AfficherParametreClasse (struct Ecole); // Affiche les paramètres de toutes les classes (Niveau, numéro, instit... )

void AfficherEleveTotal (struct Ecole); // Affiche TOUT les élèves de l'école

void AfficherEleveClasse(struct Ecole); // N'affiche les élèves que d'une seule classe

int Recherche(char *A, char *B); // Fonction de recherche. Prends en paramètres deux chaines de caractères


#endif // ECOLE_H
