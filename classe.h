#include <stdio.h>
#include "eleve.h"

#ifndef CLASSE_H
#define CLASSE_H

#define MAX 30
#define MAXELEVES 25

typedef struct Classe
{char niveau[5]; // Niveau de la classe
char nomEnseignant[MAX];// Nom du prof s'occupant de la classe
int numClasse; // Numéro de la classe dans le cas où il y a plusieurs classes par niveau
int nbEleveClasse; // Nombre d'élève par classe
struct Eleve TabEleve[MAXELEVES];
//struct Eleve *premier;// les données d'un élève
//struct Classe*suivant;// pointeur sur l'élève suivant dans la classe
}Classe_t


void SaisirClasse (Classe_t *C);

void AfficherClasse(Classe_t C);



/*LISTE CHAINEES*/


#endif
