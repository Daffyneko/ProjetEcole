#include <stdio.h>
#include <time.h>

#ifndef ELEVE_H
#define ELEVE_H

#define MAX 30

typedef struct Eleve{
    char nom[MAX];
    char prenom[MAX];
    char sexe;
    struct tm dateNaissance; // Date de naissance. Utilisation de la structure tm. Ajout de la biblio <time.h>
//	struct Parent renseignement; // Renseignement sur les parents numero nom et adresse
//	struct Bulletin note; // Bulletins de notes. notes matières retard abscences...

    struct Eleve *suivant; // Utilisation de liste chainée pour avoir une liste d'élève
}Eleve_t;

void SaisirEleve(Eleve_t *E);
void AfficherEleve(Eleve_t E);
void ModifierEleve(Eleve_t *E);

#endif // ELEVE_H
