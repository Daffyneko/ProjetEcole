#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "classe.h"


void AfficherClasse (Classe_t C)
{
    int i, longueur;

    longueur=strlen(C.niveau);
    printf("\t%s",C.niveau);
    for(i=0;i<(5-longueur);i++){
        printf(" ");
    }

    printf("%d",C.numClasse);
    for(i=0;i<3;i++){
        printf(" ");
    }
    printf("%s   \n",C.nomEnseignant);
}

void AfficherEleveClasse(Classe_t C)
{
    int i;
    for (i=0; i<C.nbEleveClasse; i++)
        AfficherEleve(C.TabEleve[i]);
}


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
}

void ModifierClasse(Classe_t *C)
{
    int choix=-1;

    printf("Veuillez saisir le champ à modifier : \n1 - Niveau de la classe\n2 - Nom de l'enseignant(e)\n3 - Nombre d'élèves\n 4 - Annuler\n");
    scanf("%d",&choix);
    switch(choix)
    {
        default : break;
        case 1 :
            do {
                printf("\nVeuillez entrer le niveau de la classe : ");// entrer le nouveau niveau pour remplacer l'ancien
                scanf("%s", C->niveau);
            }while(strcmp(C->niveau,"CP")!=0 && strcmp(C->niveau,"CE1")!=0 && strcmp(C->niveau,"CE2")!=0 && strcmp(C->niveau,"CM1")!=0 && strcmp(C->niveau,"CM2")!=0); // redemande tant que le niveau ne correspond pas
            printf("\n***Modification effectuée***\n");
            break;

        case 2 :
            printf("\nVeuillez entrer le nom de l'enseignant(e) : \n");// entrer le nouveau nom pour remplacer l'ancien

            fgets(C->nomEnseignant, MAX, stdin); // on récupère la ligne de caractère
            C->nomEnseignant[strlen(C->nomEnseignant)-1] = '\0'; // on supprime le '\n')

            printf("\n***Modification effectuée***\n");
            break;

        case 3 :
            printf("\nVeuillez entrer le nombre d'élèves souhaité : ");
            scanf("%d", &C->nbEleveClasse);
            printf("\n***Modification effectuée***\n");
            break;

        case 4 :
            printf("\n***Modification annulée***\n");
            break;
    }
}



/* LISTES CHAINEES-----------------------*********************


//Affiche la classe en parcourant la structure récursive classe. L'étoile n'est pas un pointeur
//mais le début de la première cellule

void Afficher_Classe(Classe_t *premier)
{   //int i
   Classe_t *courant;

    // 1 : se positionner en tête. Equivalent de i = 0.
    courant = premier;

    // i<taille , tant qu'on n'arrive pas à la fin de la liste (plus d'éléments)
    while(courant!= NULL)
    {
        //2 : affichage : traitement : afficher les données de l'élève
        AfficherEleve(courant->eleve);

        //3 : aller au suivant. Equivalent de i = i +1
        courant= courant->suivant;
    }
}

/*Compte le nombre d'élèves de la classe*/
/*int compter_Classe(Classe_t *premier)
{
    Classe_t *courant; // création d'un pointeur de liste qui contiendra l'objet courant
    int i=0; //variable compteur

    courant = premier; // initialisation de courant

    while(courant != NULL) // jusqu'à ce qu'il n'y ait plus d'élément dans la boucle
    {
        i++; // incrementation du compteur
        courant = courant->suivant; // passe à l'élément suivant
    }
    return i; // retourne le nombre d'élément de la liste
}

/*Ajoute un élève en tête de la liste de la classe*/
/*void Ajouter_en_tete(Classe_t **premier)
{
    Classe_t *nouveau; // création d'un pointeur sur le nouvel élément de la liste liste

    // initialisation de nouveau
    // réserve une place en mémoire de la taille d'un élément liste, et place l'adresse de cet élément dans nouveau
    nouveau = (Classe_t*)malloc(sizeof(Classe_t));

    if(nouveau==NULL) // si l'allocation c'est mal passé
    {
        perror("pas possible");
        return;
    }

    // saisir un adhérent et placer les données dans l'espace aloué en mémoire
    Saisireleve(&nouveau->eleve);

    nouveau->suivant = *premier;   // accroche  le premier élément de la liste à la fin d'un nouvel élément
    *premier = nouveau;    // accroche le nouvel élément à la tête de liste
    // le nouvel élément devient le premier élément de la liste)
}


/*Insère un adhérent dans la liste en foncion de son nom*/
/*void Inserer_Classe(Classe_t **premier)
{
    Classe_t *courant = *premier; //création d'un pointeur courant initialisé avec le premier élément de la liste
    Classe_t *avant = NULL;    //création d'un pointeur contiendra l'élément précédent courant
    Classe_t*nouveau;        //création d'un pointeur sur un nouvel élément

    nouveau = (Classe_t*)malloc(sizeof(Classe_t)); // initialisation de nouveau

    if(nouveau==NULL) // si l'allocation se passe mal
    {
        perror("pas possible");
        return;
    }

    SaisirEleve(&nouveau->eleve); // saisie d'un eleve  placé dans l'espace mémoire de nouveau

    // tant que l'on n'est pas à la fin de la liste et que l'eleve courant est plus haut dans l'ordre alphabétique
    while(courant != NULL && strcmp (courant->eleve.nom, nouveau->eleve.nom) <0)
    {
        avant = courant;            // le courant devient précédent
        courant = courant->suivant;// l'élément suivant de la liste devient le courant
    }

    // la boucle s'arrête soit à la fin, soit à l'endroit où on insère le nouvel élément

    nouveau->suivant = courant; // on place courant derrière le nouvel élément

    // si courant n'est pas le premier élément de la liste
    if(avant != NULL)
        avant->suivant = nouveau; // affecter nouveau derrière l'élément précédent courant
    else
        *premier = nouveau; // sinon affecter nouveau en tête de liste
}


/*Supprime l'eleve en tête de liste*/
/*void Supprimer_en_tete(Liste_t **premier)
{
    Classe_t *courant = *premier; //creation d'un pointeur courant initialisé avec le premier élément de la liste

    if(*premier == NULL) // si la liste est vide
        return;

    // mettre l'élément suivant le premier élément de la liste (2eme de la liste) en tete de liste
    *premier = (*premier)->suivant;

    free(courant);// libérer l'espace mémoire de l'ancien élément de tête
}


/*Supprime l'eleve de la liste en fonction de son nom*/
/*void Supprimer(Classe_t **premier, const char *eleve.nom)
{
    Liste_t *courant = *premier; //création d'un pointeur courant initialisé avec le premier élément de la liste

    Liste_t *avant = NULL; //création d'un pointeur qui contiendra l'élément précédent courant

    // tant que l'on n'est pas à la fin de la liste et que l'adhérent courant n'est pas celui recherché
    while(courant != NULL && strcmp(courant->eleve.nom, nom) != 0)
    {
      avant = courant;            // le courant devient précédent
        courant = courant->suivant;// l'élément suivant de la liste devient le courant
    }

    if(courant ==NULL) // si l'on n'est pas à la fin de la liste (l'adhérent recherché est dans la liste)
    {
        if(avant == NULL) // si l'élément courant n'est pas en tête de liste
        {
            avant->suivant = courant->suivant; // on accroche l'élément suivant courant derrière l'élément précédent courant
            free(courant); // on libère l'espace mémoire de courant
        }
        else // si l'élément courant est en tête de liste
        {
            *premier = courant->suivant; // mettre l'élément suivant courant en tête de liste
            free(courant); // libérer l'espace mémoire de courant
        }
    }


}

/***********************************************Daphne***********************************************/
void AffecterEleve(Eleve_t E, Classe_t *C){
    strcpy(C->TabEleve[C->nbEleveClasse].nom,E.nom);
    strcpy(C->TabEleve[C->nbEleveClasse].prenom,E.prenom);
    C->TabEleve[C->nbEleveClasse].sexe=E.sexe;
    C->TabEleve[C->nbEleveClasse].dateNaissance.tm_mday=E.dateNaissance.tm_mday;
    C->TabEleve[C->nbEleveClasse].dateNaissance.tm_mon=E.dateNaissance.tm_mon;
    C->TabEleve[C->nbEleveClasse].dateNaissance.tm_year=E.dateNaissance.tm_year;
    C->nbEleveClasse++;
}

void RangerClasses(Classe_t C[], int nbe){
    int i, permut=1;
    Classe_t temp;
    while(permut==1){
        permut=0;
        for(i=0;i<nbe;i++){
            if(strcmp(C[i].niveau,C[i+1].niveau)>0){
                permut=1;
                /* COPIE E[i]-->temp */
                strcpy(temp.niveau, C[i].niveau);
                strcpy(temp.nomEnseignant, C[i].nomEnseignant);
                temp.numClasse=C[i].numClasse;
                temp.nbEleveClasse=C[i].nbEleveClasse;
                /* COPIE E[i+1]-->E[i] */
                strcpy(C[i].niveau, C[i+1].niveau);
                strcpy(C[i].nomEnseignant, C[i+1].nomEnseignant);
                C[i].numClasse=C[i+1].numClasse;
                C[i].nbEleveClasse=C[i+1].nbEleveClasse;
                /* COPIE temp-->E[i+1] */
                strcpy(C[i+1].niveau, temp.niveau);
                strcpy(C[i+1].nomEnseignant, temp.nomEnseignant);
                C[i+1].numClasse=temp.numClasse;
                C[i].nbEleveClasse=C[i+1].nbEleveClasse;
            }
        }
    }
}
/****************************************************************************************************/

