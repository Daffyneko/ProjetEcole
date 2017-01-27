#include <stdio.h>
#include <time.h>

#ifndef ELEVE_H
#define ELEVE_H

#define MAX 30
/***********************************************Daphné***********************************************/
typedef struct Eleve{
	char nom[MAX]; // Nom de l'élève
	char prenom[MAX]; // Prenom de l'élève
	char sexe; // Sexe: juste un char pour mettre "m" ou "f"
	struct tm dateNaissance; // Date de naissance. Utilisation de la structure tm. Ajout de la biblio <time.h>
//	struct Parent renseignement; // Renseignement sur les parents numero nom et adresse
//	struct Bulletin note; // Bulletins de notes. notes matières retard abscences...

//	struct Eleve *suivant; // Utilisation de liste chainée pour avoir une liste d'élève

} Eleve_t;

void SaisirEleve(Eleve_t *E);
void AfficherEleve(Eleve_t E);
void ModifierEleve(Eleve_t *E);

/****************************************************************************************************/

#endif // ELEVE_H
