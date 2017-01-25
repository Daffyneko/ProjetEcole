#include <stdio.h>

#include "eleve.h"

#ifndef CLASSE_H
#define CLASSE_H

#define MAX 30
#define CHAINE 150

typedef struct Classe
{
	char niveau[4]; // Niveau de la classe CP CE1...
	char nomEnseignant[MAX]; // Nom du prof s'occupant de la classe
	int numClasse; // Numero de la classe dans le cas ou il y aurait plusieurs CP ou autres classes...
	int nbEleveClasse; // Nombre d'élève par classe
	struct Eleve eleveClasse; // Appel de la structure Eleve pour saisir un élève dans la classe

	struct Classe *suivant; // Utilisation de liste chainée pour avoir une liste de classe
} Classe_t;

void SaisirClasse(Classe_t *C);
void AfficherClasse(Classe_t C);

#endif // CLASSE_H
