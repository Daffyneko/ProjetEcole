#include <stdio.h>
#include <time.h>

#ifndef ECOLE_H
#define ECOLE_H

#include "classe.h"
# define MAX 30
# define CHAINE 150
# define MAXELEVE 25

typedef struct Ecole{
	char nomEcole[MAX]; // Nom de l'école
	char nomDirecteur[MAX]; // Nom du directeur de lécole
	int nbEleveTotal; // Nombre total d'élève dans l'école
	int nbEleveNiveau[5]; // Nombre d'élève par niveau. Chaque case représente un niveau
	int nbClasse; // Nombre de classe totale dans l'école

	struct Classe TabClasse[4];

//	struct Classe *classe[5]; // Appel de la fonction classe pour saisir une classe dans l'école
//          ******  Utilisation d'un simple tableau ou bien d'une table de hachage ?    *******
} Ecole_t;

#endif //ECOLE_H
