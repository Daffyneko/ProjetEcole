#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib>
#include "classe.h"


void AfficherClasse (Classe_t C)
{int i;
printf("Classe niveau:%s , numero:%d, nom de l'enseignant: %s", C.niveau, C.numClasse, C.nomEnseignant);
for (i=0; i<25; i++)
AfficherEleve(C.TabEleve[i]);

};


void SaisirClasse(Classe_t *C)
{int i;
    printf("Niveau de la classe: \n ");     //saisie du niveau
    scanf("%s", C->niveau);

    printf("Nom de l'enseignant/e :\n");
    fgets(C->nomEnseignant, MAX, stdin); // on récupère la ligne de caractère
    C->nomEnseignant[strlen(C->nomEnseignant)-1] = '\0'; // on supprime le '\n')

    printf("Numéro de la classe : \n"); // saisie du numéro de la classe
    scanf("%d", &C->numClasse);
    getchar();

    for(i=0; i <C->nbEleveClasse; i++) // saisie de chacun des élèves de la classe
    {
        SaisirEleve(&C->TabEleve[i]); // utilisation de la fonction de saisie des élèves
    }
};

void AffecterEleve(Eleve_t E, Classe_t *C){
    strcpy(C->TabEleve[C->nbEleveClasse+1].nom,E.nom);
}

/*Ecrit un tableau de classe dans un fichier*/
void Ecrire_Fichier_Classe(const char *FichierEcole, Classe_t *TabClasse, int nb)
{ int i,j;   // variables de boucle

    FILE *ptr_fichier; // pointeur de fichier

    ptr_fichier =fopen(FichierEcole, "w"); // ouverture du fichier en mode écriture

    if(!ptr_fichier) // si l'ouverture se passe mal
    {
        perror("erreur ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    for(i=0; i<nb; i++) // on parcourt le tableau de classes
    {
        // écriture du niveau de la classe, du numéro, du nom de l'enseignant et du nombre d'élèves
        fprintf(ptr_fichier, "%s ; %d ; %s ;", TabClasse[i].niveau,TabClasse[i].numClasse, TabClasse[i].nomEnseignant);

        for(j=0; j<TabClasse[i].nbEleveClasse; j++) // pour chaque classe on parcourt ses élèves
        {
          // écriture du prénom, nom, sexe et date de naissance
            fprintf(ptr_fichier, "%s ; %s ; %c ; %d/%d/%d", TabClasse[i].TabEleve[j].nom,TabClasse[i].TabEleve[j].prenom, TabClasse[i].TabEleve[j].sexe, 
            TabClasse[i].TabEleve[j].dateNaissance.tm_mday,TabClasse[i].TabEleve[j].dateNaissance.tm_mon, TabClasse[i].TabEleve[j].dateNaissance.tm_year);


        }
        fprintf(ptr_fichier,"\n"); // passage à la ligne pour inscrire la classe suivante (dans le tableau en paramètre)
    }
    fclose(ptr_fichier); // fermeture du fichier
};


/* LISTES CHAINEES-----------------------*********************

void SaisirClasse{Classe_t *C);


/*Affiche la classe en parcourant la structure récursive classe. L'étoile n'est pas un pointeur
mais le début de la première cellule

void AfficherClasse(Classe_t *tete);
{   //int i
   Classe_t *courant;

    // 1 : se positionner en tête. Equivalent de i = 0.
    eleve = tete;

    // i<taille , tant qu'on n'arrive pas à la fin de la liste (plus d'éléments)
    while(eleve!= NULL)
    {
        //2 : affichage : traitement : afficher les données de l'adhérent
        AfficherClasse(courant->eleve);

        //3 : aller au suivant. Equivalent de i = i +1
        eleve = eleve->suivant;
    }
}
