#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ecole.h"


//                                             ****        save.c        ****



void FonctionSave(struct Ecole E)// écrit les données nom directeur, nom d'école nombre d'élèves total, nombre d'élève par classe et nombre Classes total
{
    FILE *ptr_sauvegarde;
    ptr_sauvegarde=fopen("ecole.csv", "w");

    if(!ptr_sauvegarde)
    {
        perror("Impossible d'ouvrir le fichier ecole.csv\n");
        exit(-1);
    }




    fclose(ptr_sauvegarde);
}

void FonctionChargeEcole(struct Ecole *E)
{
    char ligne[500];
    char poubelle[500];
    char *champ;

    FILE *ptr_sauvegarde;
    ptr_sauvegarde=fopen("ecole.csv", "r");

    if(!ptr_sauvegarde)
    {
        perror("Impossible d'ouvrir le fichier ecole.csv\n");
        exit(-1);
    }

fgets(poubelle, sizeof(ligne), ptr_sauvegarde); // Pour sauter la première ligne qui est tout simplement le détail de ce que représente chaque colonnes

    while(!feof(ptr_sauvegarde))
    {
        fgets(ligne, sizeof(ligne), ptr_sauvegarde);
        champ=strtok(ligne, ";");
        strcpy(E->nomEcole, champ);
        champ=strtok(NULL,";");
        strcpy(E->nomDirecteur, champ);
        champ=strtok(NULL,"");
        sscanf(champ,"%d ; %d ; %d ; %d ; %d ; %d ; %d",&E->nbEleveTotal,&E->nbEleveNiveau[0],&E->nbEleveNiveau[1],&E->nbEleveNiveau[2],&E->nbEleveNiveau[3],&E->nbEleveNiveau[4],&E->nbClasse);
    }
    fclose(ptr_sauvegarde);
}


void Lire_Fichier_Classe(struct Ecole *E)
{    int i, j;
    char poubelle[300];
    char test[2];
    char *champ;
    char ligne[300];
    FILE *ptr_fichier;
//    printf("test 1");
    ptr_fichier = fopen("FichierClasse10.csv", "r"); // ouverture du fichier en mode lecture

    if(!ptr_fichier) // si l'ouverture se passe mal
    {
        perror("erreur ouverture du fichier");
        exit(EXIT_FAILURE);
    }

// Pour sauter la première ligne qui est tout simplement le détail de ce que représente chaque colonnes
    for (i=0; i<7; i++)

 //  printf("test %d\n", i);
    {//fgets(poubelle, sizeof(ligne), ptr_fichier);
  /* {    fgets(ligne, 300, ptr_fichier); // lire la ligne

        champ= strtok(ligne, ";"); // mettre dans champ les éléments de ligne jusqu'au prochain ';'
        strcpy(E->TabClasse[i].niveau, champ); // copier champ dans le niveau de la classe
        printf("%s", champ);

        champ=strtok(NULL, ";"); // mettre dans champ les éléments de ligne jusqu'au prochain ';'
        E->TabClasse[i].numClasse=atoi(champ);//transformer champ en nombre et le copier dans le numero de la classe
        printf("%s", champ);

        champ=strtok(NULL, ";");
        strcpy(E->TabClasse[i].nomEnseignant, champ); // copier champ dans le niveau de la classe
        printf("%s", champ);

        champ = strtok(NULL, ";");// mettre dans champ les éléments de ligne jusqu'au prochain ';'
        E->TabClasse[i].nbEleveClasse =atoi(champ); //transformer champ en nombre et le copier dans le nombre d'élèves dans la classe
        printf("%s", champ);
*/
       for (j=0; j<10; j++)
        {
       // printf("test %d\n", j);
      fgets(ligne, 300, ptr_fichier); // lire la ligne

        printf ("test3 \n");
        champ = strtok(ligne, ";");// mettre dans champ les élément de ligne jusqu'au prochain ';'
        printf ("test 4 \n");

        strcpy(E->TabClasse[i].TabEleve[j].nom, ligne); //copier champ dans le nom de l'élèvé
        printf ("test 5\n");
        printf("%s", champ);

        champ = strtok(NULL, ";");// mettre dans champ les éléments de ligne jusqu'au prochain ';'
        strcpy(E->TabClasse[i].TabEleve[j].prenom, champ); //copier champ dans le prénom de l'élèvé
        printf("%s", champ);

        champ=strtok(NULL, ";");
        strcpy(test, champ);
        E->TabClasse[i].TabEleve[j].sexe=test[0];
        printf("%s", champ);

        champ = strtok(NULL, ";"); // mettre dans champ les élément de ligne jusqu'au prochain ';'
            // copie les différents éléments du champ actuel, mais sans utiliser champ

        memset (&E->TabClasse[i].TabEleve[j].dateNaissance, 0, sizeof(E->TabClasse[i].TabEleve[j].dateNaissance)); // initialisation de la structure tm (tmretour)
        sscanf(champ,"%d/%d/%d", &E->TabClasse[i].TabEleve[j].dateNaissance.tm_mday,
        &E->TabClasse[i].TabEleve[j].dateNaissance.tm_mon, &E->TabClasse[i].TabEleve[j].dateNaissance.tm_year);
        printf("%s", champ);
        /*    printf(" ------la date est %d/%d/%d----", E->TabClasse[i].TabEleve[j].dateNaissance.tm_mday,
                   E->TabClasse[i].TabEleve[j].dateNaissance.tm_mon, E->TabClasse[i].TabEleve[j].dateNaissance.tm_year);*/

        }
    }
}


/*Ecrit un tableau de classe dans un fichier*/
/*Ecrit un tableau de classe dans un fichier*/

void Ecrire_Fichier_Classe(Ecole_t E)
{ int i,j;   // variables de boucle

    FILE *ptr_fichier; // pointeur de fichier

    ptr_fichier =fopen("Test5.csv", "w"); // ouverture du fichier en mode écriture

    if(!ptr_fichier) // si l'ouverture se passe mal
    {
        perror("erreur ouverture du fichier");
        exit(EXIT_FAILURE);
    }

   for(i=0; i<7; i++) // on parcourt le tableau de classes
    {
        // écriture du niveau de la classe, du numéro, du nom de l'enseignant et du nombre d'élèves
    //  fprintf(ptr_fichier, " %s; %d; %s;", E.TabClasse[i].niveau, E.TabClasse[i].numClasse, E.TabClasse[i].nomEnseignant);
      //  fprintf(ptr_fichier, "\n");

       for(j=0; j<10; j++) // pour chaque classe on parcourt ses élèves
        {
          // écriture du prénom, nom, sexe et date de naissance
        fprintf(ptr_fichier, "%s; %s; %c; %d/%d/%d", E.TabClasse[i].TabEleve[j].nom, E.TabClasse[i].TabEleve[j].prenom, E.TabClasse[i].TabEleve[j].sexe,
        E.TabClasse[i].TabEleve[j].dateNaissance.tm_mday,E.TabClasse[i].TabEleve[j].dateNaissance.tm_mon, E.TabClasse[i].TabEleve[j].dateNaissance.tm_year);
        fprintf(ptr_fichier,"\n");

        }
        fprintf(ptr_fichier,"\n"); // passage à la ligne pour inscrire la classe suivante (dans le tableau en paramètre)
   }
 
    fclose(ptr_fichier); // fermeture du fichier
}

