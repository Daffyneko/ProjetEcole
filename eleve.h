#include <stdio.h>
#include <time.h>

#ifndef ELEVE_H
#define ELEVE_H

# define MAX 30
# define CHAINE 150
# define MAXELEVE 25

/***********************************************Daphne***********************************************/
typedef struct Eleve{
	char nom[MAX]; // Nom de l'eleve
	char prenom[MAX]; // Prenom de l'eleve
	char sexe; // Sexe: juste un char pour mettre "m" ou "f"
	struct tm dateNaissance; // Date de naissance. Utilisation de la structure tm. Ajout de la biblio <time.h>
//	struct Parent renseignement; // Renseignement sur les parents numero nom et adresse
//	struct Bulletin note; // Bulletins de notes. notes matieres retard abscences...

//	struct Eleve *suivant; // Utilisation de liste chainee pour avoir une liste d'eleve

} Eleve_t;

void SaisirEleve(Eleve_t *E);
void AfficherEleve(Eleve_t E);
void ModifierEleve(Eleve_t *E);
void RangerEleves(Eleve_t E[], int nbe);
/****************************************************************************************************/
#endif // ELEVE_H
