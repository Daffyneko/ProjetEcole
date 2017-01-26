#include <stdio.h>
#include <stdlib.h>
#include <time.h>

# define MAX 30
# define CHAINE 150
# define MAXELEVE 25



// *********** Fonction "BONUS" ****************
/*
typedef struct Bulletin
{
	char matiere[MAX];
	double note;
	char appreciation[CHAINE];
	int abscence;
	int retard;
} bulletin_t;

typedef struct Parent
{
	char nomPere[MAX];
	char nomMere[MAX];
	char adresse[CHAINE];
	char numPere[MAX];
	char num Mere[MAX];
} Parent_t;
************************************************/

typedef struct Eleve
{
	char nom[MAX]; // Nom de l'élève
	char prenom[MAX]; // Prenom de l'élève
	char sexe; // Sexe: juste un char pour mettre "m" ou "f"
	struct tm dateNaissance; // Date de naissance. Utilisation de la structure tm. Ajout de la biblio <time.h>
//	struct Parent renseignement; // Renseignement sur les parents numero nom et adresse
//	struct Bulletin note; // Bulletins de notes. notes matières retard abscences...

//	struct Eleve *suivant; // Utilisation de liste chainée pour avoir une liste d'élève
	
} Eleve_t;

typedef struct Classe
{
	char niveau[4]; // Niveau de la classe CP CE1...
	char nomEnseignant[MAX]; // Nom du prof s'occupant de la classe
	int numClasse; // Numero de la classe dans le cas ou il y aurait plusieurs CP ou autres classes...
	int nbEleveClasse; // Nombre d'élève par classe
/*	struct Eleve *premier; // Appel de la structure Eleve pour saisir un élève dans la classe
	struct Classe *suivant; // Utilisation de liste chainée pour avoir une liste de classe */
	
	struct Eleve TabEleve[MAxELEVE];
} Classe_t;

typedef struct Ecole
{
	char nomEcole[MAX]; // Nom de l'école
	char nomDirecteur[MAX]; // Nom du directeur de lécole
	int nbEleveTotal; // Nombre total d'élève dans l'école
	int nbEleveNiveau[5]; // Nombre d'élève par niveau. Chaque case représente un niveau
	int nbClasse; // Nombre de classe totale dans l'école
	
	struct Classe TabClasse[4];
	
//	struct Classe *classe[5]; // Appel de la fonction classe pour saisir une classe dans l'école
//          ******  Utilisation d'un simple tableau ou bien d'une table de hachage ?    *******
} Ecole_t;



