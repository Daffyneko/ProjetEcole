#include <stdio.h>
#include <time.h>
#include <string.h>

#include "eleve.h"

/***********************************************Daphne***********************************************/

void SaisirEleve(Eleve_t *E){
    int j, m, a;//variables de lecture de la date de naissance
    char sexe;
    printf("\nVeuillez entrer le nom de l'eleve : ");
    fscanf(stdin,"%s", E->nom);
    printf("\nVeuillez entrer le prenom de l'eleve : ");
    fscanf(stdin,"%s", E->prenom);
    getchar();
    do{
        printf("\nVeuillez entrer le sexe de l'eleve (f pour fille ou g pour garçon) : ");
        fscanf(stdin,"%c", &sexe);
    }while(sexe!='g' && sexe!='f');
    E->sexe=sexe;
    printf("\nVeuillez entrer la date de naissance de l'eleve (jj/mm/aaaa) : ");
    scanf("%d/%d/%d", &j, &m, &a);
    E->dateNaissance.tm_mday=j;
    E->dateNaissance.tm_mon=m;
    E->dateNaissance.tm_year=a;
    printf("\n***Eleve enregistre***\n");
}
void AfficherEleve(Eleve_t E){
    int longueur, i;

    /*printf("\n***************************************\n");
    printf("Nom : %s\tPrenom : %s\nSexe : %c\tDate de naissance : %d/%d/%d\n", E.nom, E.prenom, E.sexe, E.dateNaissance.tm_mday, E.dateNaissance.tm_mon, E.dateNaissance.tm_year);
    printf("\n***************************************\n");*/
    longueur=strlen(E.nom);
    printf("|%s",E.nom);
    for(i=0;i<30-longueur;i++){
        printf(" ");
    }
    longueur=strlen(E.prenom);
    printf("|%s",E.prenom);
    for(i=0;i<30-longueur;i++){
        printf(" ");
    }
    printf("| %c  ",E.sexe);
    printf("| %d/%d/%d       |\n", E.dateNaissance.tm_mday, E.dateNaissance.tm_mon, E.dateNaissance.tm_year);

}

void ModifierEleve(Eleve_t *E){
    int choix=-1;
    char sexe;
    int j, m, a;
    printf("Veuillez saisir le champ a modifier : \n1 - Nom\n2 - Prenom\n3 - Sexe\n4 - Date de naissance\n0 - Annuler\n");
    scanf("%d",&choix);
    switch(choix){
        default : break;
        case 0 :
            printf("\n***Modification annulee***\n");
            break;
        case 1 :
            printf("\nVeuillez entrer le nom de l'eleve : ");
            fscanf(stdin,"%s", E->nom);
            printf("\n***Modification effectuee***\n");
            break;
        case 2 :
            printf("\nVeuillez entrer le prenom de l'eleve : ");
            fscanf(stdin,"%s", E->prenom);
            printf("\n***Modification effectuee***\n");
            break;
        case 3 :
            do{
                printf("\nVeuillez entrer le sexe de l'eleve (f pour fille ou g pour garçon) : ");
                fscanf(stdin,"%c", &sexe);
            }while(sexe!='g' && sexe!='f');
            E->sexe=sexe;
            printf("\n***Modification effectuee***\n");
            break;
        case 4 :
            printf("\nVeuillez entrer la date de naissance de l'eleve (jj/mm/aaaa) : ");
            scanf("%d/%d/%d", &j, &m, &a);
            E->dateNaissance.tm_mday=j;
            E->dateNaissance.tm_mon=m;
            E->dateNaissance.tm_year=a;
            printf("\n***Modification effectuee***\n");
            break;
    }
}

void RangerEleves(Eleve_t E[], int nbe){
    int i, permut=1;
    Eleve_t temp;
    while(permut==1){
        permut=0;
        for(i=0;i<nbe;i++){
            if(strcmp(E[i].nom,E[i+1].nom)>0){
                permut=1;
                /* COPIE E[i]-->temp */
                strcpy(temp.nom, E[i].nom);
                strcpy(temp.prenom, E[i].prenom);
                temp.sexe=E[i].sexe;
                temp.dateNaissance.tm_mday=E[i].dateNaissance.tm_mday;
                temp.dateNaissance.tm_mon=E[i].dateNaissance.tm_mon;
                temp.dateNaissance.tm_year=E[i].dateNaissance.tm_year;
                /* COPIE E[i+1]-->E[i] */
                strcpy(E[i].nom, E[i+1].nom);
                strcpy(E[i].prenom, E[i+1].prenom);
                E[i].sexe=E[i+1].sexe;
                E[i].dateNaissance.tm_mday=E[i+1].dateNaissance.tm_mday;
                E[i].dateNaissance.tm_mon=E[i+1].dateNaissance.tm_mon;
                E[i].dateNaissance.tm_year=E[i+1].dateNaissance.tm_year;
                /* COPIE temp-->E[i+1] */
                strcpy(E[i+1].nom, temp.nom);
                strcpy(E[i+1].prenom, temp.prenom);
                E[i+1].sexe=temp.sexe;
                E[i+1].dateNaissance.tm_mday=temp.dateNaissance.tm_mday;
                E[i+1].dateNaissance.tm_mon=temp.dateNaissance.tm_mon;
                E[i+1].dateNaissance.tm_year=temp.dateNaissance.tm_year;
            }
        }
    }

}

/****************************************************************************************************/
