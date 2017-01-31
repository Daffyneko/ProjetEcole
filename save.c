#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ecole.h"


//                                             ****        save.c        ****


// ------------------------------------------------------- Cyril --------------------------------------------------------- //

void EcrireEcole(struct Ecole E) // Télécharge l'école depuis un fichier csv
{
    FILE *ptr_sauvegarde;
    ptr_sauvegarde=fopen("ecole.csv", "w");

    if(!ptr_sauvegarde)
    {
        printf("ecole.csv\n");
        perror("Impossible d'ouvrir le fichier ecole.csv\n");
        exit(-1);
    }
    // La première ligne di fichier pour faciliter la lecture d'un être humain
    fprintf(ptr_sauvegarde,"Nom de l'ecole;Nom du directeur;Nombre de classe Total\n");
    // On enregistre les structures dans notre fichier
    fprintf(ptr_sauvegarde,"%s;%s;%d;%d", E.nomEcole,E.nomDirecteur,E.nbClasse,E.nbEleveTotal);

    fclose(ptr_sauvegarde);
}

void LireEcole(struct Ecole *E) // Sauvegarde l'école sur un fichier csv
{
    char ligne[500];
    char poubelle[500];
    char *champ;

    FILE *ptr_sauvegarde;
    ptr_sauvegarde=fopen("ecole.csv", "r");

    if(!ptr_sauvegarde)
    {
        printf("ecole.csv\n");
        perror("Impossible d'ouvrir le fichier ecole.csv\n");
        exit(-1);
    }

    fgets(poubelle, sizeof(ligne), ptr_sauvegarde); // Pour sauter la première ligne qui est tout simplement le détail de ce que représente chaque colonnes

    while(!feof(ptr_sauvegarde))
    {
        fgets(ligne, sizeof(ligne), ptr_sauvegarde);
        champ=strtok(ligne,";");
        strcpy(E->nomEcole, champ);
        champ=strtok(NULL,";");
        strcpy(E->nomDirecteur, champ);
        champ=strtok(NULL,"");
        E->nbClasse=atoi(champ);
        champ=strtok(NULL,"");
        E->nbEleveTotal=atoi(champ);
    }
    fclose(ptr_sauvegarde);
}

void EcireClasse(struct Ecole E) // Télécharge les classes depuis un fichier csv
{
    int i;
    FILE *ptr_sauvegarde;
    ptr_sauvegarde=fopen("classe.csv", "r");

    if(!ptr_sauvegarde)
    {
        printf("classe.csv\n");
        perror("Impossible d'ouvrir le fichier classe.csv\n");
        exit(-1);
    }
    fprintf(ptr_sauvegarde,"Niveau ; Numero de classe ; Nom de l'enseigant; Nombre d'eleve dans la classe");
    for(i=0; i<5; i++)
        fprintf(ptr_sauvegarde,"\n%s;%d;%s;%d ", E.TabClasse[i].niveau, E.TabClasse[i].numClasse, E.TabClasse[i].nomEnseignant, E.TabClasse[i].nbEleveClasse);
}

void LireClasse(struct Ecole *E) // Sauvegarde les classes sur un fichier csv
{
    char ligne[500];
    char poubelle[500];
    char *champ;
    int i=0;

    FILE *ptr_sauvegarde;
    ptr_sauvegarde=fopen("classe.csv", "r");

    if(!ptr_sauvegarde)
    {
        printf("classe.csv\n");
        perror("Impossible d'ouvrir le fichier ecole.csv\n");
        exit(-1);
    }

fgets(poubelle, sizeof(ligne), ptr_sauvegarde); // Pour sauter la première ligne qui est tout simplement le détail de ce que représente chaque colonnes

    while(!feof(ptr_sauvegarde))
    {
        fgets(ligne, sizeof(ligne), ptr_sauvegarde); // Lis la ligne

        champ=strtok(ligne,";");
        strcpy(E->TabClasse[i].niveau, champ);

        champ=strtok(NULL,";");
        E->TabClasse[i].numClasse=atoi(champ);

        champ=strtok(NULL,";");
        strcpy(E->TabClasse[i].nomEnseignant, champ);

        champ=strtok(NULL,"");
        E->TabClasse[i].nbEleveClasse=atoi(champ);
        i++;
    }
}


void EcrireBinaire(struct Ecole *E)
{
  //  int nb=15;
    FILE *ptr_fichier;

    ptr_fichier=fopen("backup", "wb");

    if(!ptr_fichier)
    {
        perror("Impossible d'ouvrir le fichier backup\n");
        exit(-1);
    }

    fwrite(E,sizeof(struct Eleve),1,ptr_fichier);

    fclose(ptr_fichier);
}

void LireBinaire(struct Ecole *E)
{
    FILE *ptr_fichier;

    ptr_fichier=fopen("backup", "rb");

    if(!ptr_fichier)
    {
        perror("Impossible d'ouvrir le fichier backup\n");
        exit(-1);
    }

    fread(E,sizeof(struct Ecole),1,ptr_fichier);

    fclose(ptr_fichier);
}

// ----------------------------------------------------------------------------------------------------------------------- //


// ------------------------------------------------------- Delphine ------------------------------------------------------ //


/*Ecrit un tableau de classe dans un fichier*/
void Lire_Fichier_Classe(struct Ecole *E)
{    int i, j;
    char poubelle[300];
    char test[2];
    char *champ;
    char ligne[300];
    FILE *ptr_fichier;
    ptr_fichier = fopen("eleve.csv", "r"); // ouverture du fichier en mode lecture

    if(!ptr_fichier) // si l'ouverture se passe mal
    {
        perror("erreur ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    for (i=0; i<E->nbClasse; i++)
   {fgets(poubelle, sizeof(poubelle), ptr_fichier);// on ne prend pas en compte la première ligne


       for (j=0; j<E->TabClasse[i].nbEleveClasse; j++)
        {

      fgets(ligne, 300, ptr_fichier); // lire la ligne

        champ = strtok(ligne, ";");// mettre dans champ les élément de ligne jusqu'au prochain ';'
        strcpy(E->TabClasse[i].TabEleve[j].nom, ligne); //copier champ dans le nom de l'élèvé

        champ = strtok(NULL, ";");// mettre dans champ les éléments de ligne jusqu'au prochain ';'
        strcpy(E->TabClasse[i].TabEleve[j].prenom, champ); //copier champ dans le prénom de l'élèvé

        champ=strtok(NULL, ";");
        strcpy(test, champ);
        E->TabClasse[i].TabEleve[j].sexe=test[0];

        champ = strtok(NULL, ";"); // mettre dans champ les élément de ligne jusqu'au prochain ';'
            // copie les différents éléments du champ actuel, mais sans utiliser champ

        memset (&E->TabClasse[i].TabEleve[j].dateNaissance, 0, sizeof(E->TabClasse[i].TabEleve[j].dateNaissance)); // initialisation de la structure tm (tmretour)
        sscanf(champ,"%d/%d/%d", &E->TabClasse[i].TabEleve[j].dateNaissance.tm_mday,
        &E->TabClasse[i].TabEleve[j].dateNaissance.tm_mon, &E->TabClasse[i].TabEleve[j].dateNaissance.tm_year);
        }
        fgets(poubelle, sizeof(poubelle), ptr_fichier);// on saute une ligne avant la classe suivante
    }
}

/*Ecrit un tableau de classe dans un fichier*/
void Ecrire_Fichier_Classe(Ecole_t E)
{ int i,j;   // variables de boucle

    FILE *ptr_fichier; // pointeur de fichier

    ptr_fichier =fopen("eleve.csv", "w"); // ouverture du fichier en mode écriture

    if(!ptr_fichier) // si l'ouverture se passe mal
    {
        perror("erreur ouverture du fichier");
        exit(EXIT_FAILURE);
    }
   for(i=0; i<E.nbClasse; i++) // on parcourt le tableau de classes
    {
        // écriture du niveau de la classe, du numéro, du nom de l'enseignant et du nombre d'élèves
     fprintf(ptr_fichier, "%s;%d;%s", E.TabClasse[i].niveau, E.TabClasse[i].numClasse, E.TabClasse[i].nomEnseignant);
     fprintf(ptr_fichier, "\n");

       for(j=0; j<E.TabClasse[i].nbEleveClasse; j++) // pour chaque classe on parcourt ses élèves
        {
          // écriture du prénom, nom, sexe et date de naissance
        fprintf(ptr_fichier, "%s;%s;%c;%d/%d/%d", E.TabClasse[i].TabEleve[j].nom, E.TabClasse[i].TabEleve[j].prenom, E.TabClasse[i].TabEleve[j].sexe,
        E.TabClasse[i].TabEleve[j].dateNaissance.tm_mday,E.TabClasse[i].TabEleve[j].dateNaissance.tm_mon, E.TabClasse[i].TabEleve[j].dateNaissance.tm_year);
        fprintf(ptr_fichier,"\n");

        }
     fprintf(ptr_fichier,"\n"); // passage à la ligne pour inscrire la classe suivante (dans le tableau en paramètre)
   }
    fclose(ptr_fichier); // fermeture du fichier
}

// ----------------------------------------------------------------------------------------------------------------------- //
