#include <stdio.h>
#include <stdlib.h>
#include "classe.h"


//                                              ****        ecole.h        ****


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
    Classe_t TabClasse[MAXCLASSE];
} Ecole_t;


void AfficherEcole(struct Ecole); // Affiche les parmètres de l'école

void SaisirEcole(struct Ecole *); // Saisi les paramètres de l'école

void ModifierEcole(struct Ecole *); // Modifie les paramètres de l'école

void AfficherParametreClasse(struct Ecole); // Affiche les paramètres de toutes les classes (Niveau, numéro, instit... )

void ChoixClasseAfficher(struct Ecole E); // Affiche les élèves de la classe choisie

void AfficherEleveTotal(struct Ecole); // Affiche TOUT les élèves de l'école

int Recherche(char *A, char *B); // Fonction de recherche. Prends en paramètres deux chaines de caractères

void Initialisation(struct Ecole *); // Initialise une école à 0 (avec les valeurs max)

void EcrireEcole(struct Ecole); // Télécharge l'école depuis un fichier csv

void LireEcole(struct Ecole *); // Sauvegarde l'école sur un fichier csv

void EcrireClasse(struct Ecole); // Télécharge les classes depuis un fichier csv

void LireClasse(struct Ecole *); // Sauvegarde les classes sur un fichier csv

void LireBinaire(struct Ecole *); // Lis dans un fichier illisible par l'humain

void EcrireBinaire(struct Ecole *); // Sauvegarde dans un fichier illisible par l'humain

void Lire_Fichier_Classe(struct Ecole *); // Lis la liste d'élève et l'enregistre dans la structure

void Ecrire_Fichier_Classe(Ecole_t E); // Sauvegarde la structure élève dans un fichier 


/******************************Daphne***************************/
void RechercherEleve(Ecole_t E);

int RechercherClasse(Ecole_t E);

void AjouterClasse(Ecole_t *E, int position);

void SupprimerEleve(Ecole_t *E);

void RangerEcole(Ecole_t *E);
/***************************************************************/




#endif // ECOLE_H
