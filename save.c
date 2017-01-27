#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ecole.h"


//                                             ****        save.c        ****



void FonctionSave(struct Ecole E)
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

void FonctionChargeClasse(struct Ecole *E)
{
    char ligne[500];
    char poubelle[500];
    char *champ;
    int i=0;

    FILE *ptr_sauvegarde;
    ptr_sauvegarde=fopen("classe.csv", "r");

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
        strcpy(E->TabClasse[i].niveau, champ);
        champ=strtok(NULL, ";");
        strcpy(E->TabClasse[i].nomEnseignant, champ);
        champ=strtok(NULL, "");
        sscanf(champ,"%d ; %d",&E->TabClasse[i].numClasse ,&E->TabClasse[i].nbEleveClasse);
        i++;
    }
}
