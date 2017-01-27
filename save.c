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


void Lire_Fichier_Classe(const char *FichierEcole, Ecole_t *E, int nbClasse)


{
    int i,j;            // variable de boucle

    FILE *ptr_fichier;  //pointeur sur fichier
    char ligne[300];    //chaîne temporaire contenant les lignes du fichier (une a une)
    char *champ;


    ptr_fichier = fopen("FichierEcole.csv", "r"); // ouverture du fichier en mode lecture

    if(!ptr_fichier) // si l'ouverture se passe mal
    {
        perror("erreur ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    while (!feof (ptr_fichier))
    for(i=0; i<E->nbClasse; i++) // on parcourt le tableau de classe
    {
        fgets(ligne, 300, ptr_fichier); // lire la ligne

        champ= strtok(ligne, ";"); // mettre dans champ les éléments de ligne jusqu'au prochain ';'
        strcpy(E->TabClasse[i].niveau, champ); // copier champ dans le niveau de la classe

        champ=strtok(NULL, ";"); // mettre dans champ les éléments de ligne jusqu'au prochain ';'
       E->TabClasse[i].numClasse=atoi(champ);//transformer champ en nombre et le copier dans le numero de la classe


        champ = strtok(NULL, ";");// mettre dans champ les éléments de ligne jusqu'au prochain ';'
        E->TabClasse[i].nbEleveClasse =atoi(champ); //transformer champ en nombre et le copier dans le nombre d'élèves dans la classe

//printf("\n nb livres %d", tab[i].nb_livres);

        for(j=0; j<E->TabClasse[i].nbEleveClasse; j++) // on parcourt les élèves de la classe
        {
            champ = strtok(NULL, ";");// mettre dans champ les élément de ligne jusqu'au prochain ';'
            strcpy(E->TabClasse[i].TabEleve[j].nom, champ); //copier champ dans le nom de l'élèvé
//        printf("\n  %s", champ);
            champ = strtok(NULL, ";");// mettre dans champ les éléments de ligne jusqu'au prochain ';'
            strcpy(E->TabClasse[i].TabEleve[j].prenom, champ); //copier champ dans le prénom de l'élèvé
//        printf("\n  %s", champ);

            champ = strtok(NULL, ";");// mettre dans champ les éléments de ligne jusqu'au prochain ';'
           E->TabClasse[i].TabEleve[j].sexe = champ;//copier champ dans le sexe de l'élèvé
//        printf("\n  %s", champ);

            champ = strtok(NULL, ";"); // mettre dans champ les élément de ligne jusqu'au prochain ';'
            // copie les différents éléments du champ actuel, mais sans utiliser champ

            memset (&E->TabClasse[i].TabEleve[j].dateNaissance, 0, sizeof(E->TabClasse[i].TabEleve[j].dateNaissance)); // initialisation de la structure tm (tmretour)
            sscanf(champ,"%d/%d/%d", &E->TabClasse[i].TabEleve[j].dateNaissance.tm_mday, &E->TabClasse[i].TabEleve[j].dateNaissance.tm_mon, &E->TabClasse[i].TabEleve[j].dateNaissance.tm_year);
//            printf(" ------la date est %d/%d/%d----", &TabClasse[i].TabEleve[j].dateNaissance.tm_mday, &TabClasse[i].TabEleve[j].dateNaissance.tm_mday, &TabClasse[i].TabEleve[j].dateNaissance.tm_mday);
            //soustraction de 1 mois et 1900 ans pour rentrer dans les conditions de tm (cf time.h)
           E->TabClasse[i].TabEleve[j].dateNaissance.tm_mon -= 1;
           E->TabClasse[i].TabEleve[j].dateNaissance.tm_year -= 1900;



        }



    }
    fclose(ptr_fichier);
}

/*Ecrit un tableau de classe dans un fichier*/
void Ecrire_Fichier_Classe(const char *FichierEcole2, Ecole_t E, int nbClasse)
{ int i,j;   // variables de boucle

    FILE *ptr_fichier; // pointeur de fichier

    ptr_fichier =fopen("FichierEcole2.csv", "w"); // ouverture du fichier en mode écriture

    if(!ptr_fichier) // si l'ouverture se passe mal
    {
        perror("erreur ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    for(i=0; i<E.nbClasse; i++) // on parcourt le tableau de classes
    {
        // écriture du niveau de la classe, du numéro, du nom de l'enseignant et du nombre d'élèves
        fprintf(ptr_fichier, "%s ; %d ; %s ;", E.TabClasse[i].niveau,E.TabClasse[i].numClasse, E.TabClasse[i].nomEnseignant);

        for(j=0; j<E.TabClasse[i].nbEleveClasse; j++) // pour chaque classe on parcourt ses élèves
        {
          // écriture du prénom, nom, sexe et date de naissance
            fprintf(ptr_fichier, "%s ; %s ; %c ; %d/%d/%d", E.TabClasse[i].TabEleve[j].nom,E.TabClasse[i].TabEleve[j].prenom,
            E.TabClasse[i].TabEleve[j].sexe, E.TabClasse[i].TabEleve[j].dateNaissance.tm_mday, E.TabClasse[i].TabEleve[j].dateNaissance.tm_mon,
            E.TabClasse[i].TabEleve[j].dateNaissance.tm_year);


        }
        fprintf(ptr_fichier,"\n"); // passage à la ligne pour inscrire la classe suivante (dans le tableau en paramètre)
    }
    fclose(ptr_fichier); // fermeture du fichier
}
