#include <stdio.h>
#include <time.h>
#include <string.h>

#include "eleve.h"



void SaisirEleve(Eleve_t *E){
    int j, m, a;//variables de lecture de la date de naissance
    char sexe;
    printf("\nVeuillez entrer le nom de l'élève : ");
    fscanf(stdin,"%s", E->nom);
    printf("\nVeuillez entrer le prénom de l'élève : ");
    fscanf(stdin,"%s", E->prenom);
    getchar();
    do{
        printf("\nVeuillez entrer le sexe de l'élève (f pour fille ou g pour garçon) : ");
        fscanf(stdin,"%c", &sexe);
    }while(sexe!='g' && sexe!='f');
    E->sexe=sexe;
    printf("\nVeuillez entrer la date de naissance de l'élève (jj/mm/aaaa) : ");
    scanf("%d/%d/%d", &j, &m, &a);
    E->dateNaissance.tm_mday=j;
    E->dateNaissance.tm_mon=m-1;
    E->dateNaissance.tm_year=a-1900;
    printf("\n***Elève enregistré***\n");
}
void AfficherEleve(Eleve_t E){
    printf("\n---------------------------------\n");
    printf("\nNom : %s\nPrénom : %s\nSexe : %c\nDate de naissance : %d/%d/%d", E.nom, E.prenom, E.sexe, E.dateNaissance.tm_mday, E.dateNaissance.tm_mon+1, E.dateNaissance.tm_year+1900);
    printf("\n\n---------------------------------\n");
}
