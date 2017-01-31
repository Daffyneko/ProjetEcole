#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>


#include "ecole.h"


//                                             ****        ecole.c        ****


// ------------------------------------------------------- Cyril --------------------------------------------------------- //

void AfficherEcole (struct Ecole E) // Affiche les parmètres de l'école
{
    printf("Nom de l'ecole: %s\n", E.nomEcole); // Affiche le nom dde l'école
    printf("Nom du directeur: %s\n", E.nomDirecteur); // Affiche le nom du directeur
    printf("Nombre de classe: %d\n", E.nbClasse); // Affiche le nombre de classe dans l'école
    printf("Nombre d'eleve dans l'ecole: %d\n", E.nbEleveTotal); // Affiche le nombre d'élève dans l'école
}

void SaisirEcole (struct Ecole *E) // Saisi les paramètres de l'école
{
    char poubelle[80];
    printf("Saisir le nom d'ecole : ");
    fgets(E->nomEcole,sizeof(E->nomEcole), stdin); // Permet de saisir le nom de l'école
    if (E->nomEcole[strlen(E->nomEcole)-1]=='\n') // On regarde si l'avant dernier caractère de la chaine est un retour à la ligne
        E->nomEcole[strlen(E->nomEcole)-1]='\0'; // Si oui, on mets '\0' à la place
    else // S'il n'y a pas de retour à la ligne ça veut dire que la saisie est trop longue
        fgets(poubelle, sizeof(poubelle), stdin);

    printf("Saisir le nom du directeur : ");
    fgets(E->nomDirecteur,sizeof(E->nomDirecteur), stdin); // Permet de saisir le nom du directeur
    if (E->nomDirecteur[strlen(E->nomDirecteur)-1]=='\n') // On regarde si l'avant dernier caractère de la chaine est un retour à la ligne
        E->nomDirecteur[strlen(E->nomDirecteur)-1]='\0'; // Si oui, on mets '\0' à la place
    else // S'il n'y a pas de retour à la ligne ça veut dire que la saisie est trop longue
        fgets(poubelle, sizeof(poubelle), stdin);

}

void AfficherEleveTotal(struct Ecole E) // Affiche TOUT les élèves de l'école
{
    int i;
    for (i=0; i<E.nbClasse; i++) // Navigue dans les classes
        AfficherEleveClasse(E.TabClasse[i]); // Envoie les élèves à la fonction d'affichage
}

void AfficherParametreClasse(struct Ecole E) // Affiche les paramètres de toutes les classes (Niveau, numéro, instit... )
{
    int i;
    for (i=0; i<E.nbClasse; i++) // Navigue dans les classes
            AfficherClasse(E.TabClasse[i]); // Envoie les classes à la fonction d'affichage de paramètres
}

void ChoixClasseAfficher(struct Ecole E) // N'affiche les élèves que d'une seule classe
{ // Affiche les élèves d'une classe choisie
    char choixClasse[4]; // Stock le nom de la classe rechercher
    int i, j, resultat; // resultat garde en mémoire la valeur de la comparaison
    int choixNum; // choixNum est le numéro de classe associé au nom que l'utilisateur veut faire afficher
    char poubelle[80];

    do
    {
        printf("Saisir le nom et le numero de la classe a afficher : ");
        printf("\nNom de la classe (-1 pour annuler): ");
        fgets(choixClasse,sizeof(choixClasse), stdin); // Permet de saisir le nom du directeur
        if (choixClasse[strlen(choixClasse)-1]=='\n') // On regarde si l'avant dernier caractère de la chaine est un retour à la ligne
            choixClasse[strlen(choixClasse)-1]='\0'; // Si oui, on mets '\0' à la place
        else // S'il n'y a pas de retour à la ligne ça veut dire que la saisie est trop longue
            fgets(poubelle, sizeof(poubelle), stdin);

        for (i=0; i<E.nbClasse; i++)
        {
            resultat = Recherche(choixClasse, E.TabClasse[i].niveau);
            if(strcmp(choixClasse, "-1")==0)
                return;
            if (resultat == 0)
            {
                do
                {
                    printf("Numero de la classe (-1 pour annuler): ");
                    scanf("%d", &choixNum);
                    for (j=i; j<E.nbClasse; j++)
                        {
                            if(choixNum==-1)
                                return;
                            if (choixNum==E.TabClasse[j].numClasse)
                            {
                                AfficherClasse (E.TabClasse[j]);
                                return;
                            }
                            if(j==E.nbClasse)
                                printf("Erreur de saisie. Ce numero de classe n'existe pas.\n");
                        }
                }while(1);
            }
            if(i==E.nbClasse)
                printf("Erreur de saisie. Ce numero de classe n'existe pas.");
        }
    }while(1);
}

int Recherche(char *A, char *B) // Fonction de recherche. Prends en paramètres deux chaines de caractères
{
    return strcmp(A, B);
}

void ModifierEcole(struct Ecole *E)
{ // Modifie l'école en spécifiant le champ
    char saisie[5];
    int choix=-1;
    int resultat;
    char choixDeux[5];
    char poubelle[80];
    printf("\n\n\t1- Nom de l'ecole\n");
    printf("\t2- Nom du directeur\n");
    printf("\t0- Annuler\n");
    do
    {
        printf("Quel champ modifier: ");
        fgets(saisie,sizeof(saisie), stdin); // Permet de saisir le nom du directeur
        if (saisie[strlen(saisie)-1]=='\n') // On regarde si l'avant dernier caractère de la chaine est un retour à la ligne
            saisie[strlen(saisie)-1]='\0'; // Si oui, on mets '\0' à la place
        else // S'il n'y a pas de retour à la ligne ça veut dire que la saisie est trop longue
            fgets(poubelle, sizeof(poubelle), stdin);
//

    }while(!(saisie[0]=='0'||saisie[0]=='1'||saisie[0]=='2'));

    choix=atoi(saisie);

    switch (choix)
    {// En fonction du champ  nous emmène à modifier soit l'école soit le nom du directeur

        case 1: printf("Saisir le nouveau nom de l'ecole: ");
                fgets(E->nomEcole,sizeof(E->nomEcole), stdin); // Permet de saisir le nom de l'école
                if (E->nomEcole[strlen(E->nomEcole)-1]=='\n') // On regarde si l'avant dernier caractère de la chaine est un retour à la ligne
                    E->nomEcole[strlen(E->nomEcole)-1]='\0'; // Si oui, on mets '\0' à la place
                else // S'il n'y a pas de retour à la ligne ça veut dire que la saisie est trop longue
                    fgets(poubelle, sizeof(poubelle), stdin);
               //     getchar(); // Donc la fonction n'aura pas enregistré la touche <entrée>
            break;

        case 2: printf("Saisir le nouveau nom du directeur: ");
                fgets(E->nomDirecteur,sizeof(E->nomDirecteur), stdin); // Permet de saisir le nom du directeur
                if (E->nomDirecteur[strlen(E->nomDirecteur)-1]=='\n') // On regarde si l'avant dernier caractère de la chaine est un retour à la ligne
                    E->nomDirecteur[strlen(E->nomDirecteur)-1]='\0'; // Si oui, on mets '\0' à la place
                else // S'il n'y a pas de retour à la ligne ça veut dire que la saisie est trop longue
                    fgets(poubelle, sizeof(poubelle), stdin);
            break;

        case 0: return;
            break;
    }
    do
    {


        printf("Modifier d'autres champs ?(o/n)");
        fgets(choixDeux,sizeof(choixDeux), stdin); // Permet de saisir le nom de l'école
        if (choixDeux[strlen(choixDeux)-1]=='\n') // On regarde si l'avant dernier caractère de la chaine est un retour à la ligne
            choixDeux[strlen(choixDeux)-1]='\0'; // Si oui, on mets '\0' à la place
        else // S'il n'y a pas de retour à la ligne ça veut dire que la saisie est trop longue
            fgets(poubelle, sizeof(poubelle), stdin); // Donc la fonction n'aura pas enregistré la touche <entrée>

        if((resultat=strcmp(choixDeux, "o"))==0)
        {
            ModifierEcole(E);
        }

        if((resultat=strcmp(choixDeux, "n"))==0)
        {
            return;
        }
    }while(!(resultat=strcmp(choixDeux, "o"))!=0 || (resultat=strcmp(choixDeux, "n"))!=0);
}

void Initialisation(struct Ecole *E)
{ // Initialise toutes les variables de l'école à 0 (de 0 à Max define pour les tableaux)
    int i, j;

    strcpy(E->nomEcole,"\0");
    strcpy(E->nomDirecteur,"\0");
    E->nbEleveTotal=0;
    E->nbClasse=0;
    for (i=0; i<MAXCLASSE; i++)
    {
        strcpy(E->TabClasse[i].niveau,"\0");
        strcpy(E->TabClasse[i].nomEnseignant,"\0");
        E->TabClasse[i].nbEleveClasse=0;
        E->TabClasse[i].numClasse=0;
        for(j=0; j<MAXELEVES; j++)
        {
            strcpy(E->TabClasse[i].TabEleve[j].nom,"\0");
            strcpy(E->TabClasse[i].TabEleve[j].prenom,"\0");
            E->TabClasse[i].TabEleve[j].sexe='\0';
            memset(&E->TabClasse[i].TabEleve[j].dateNaissance, 0,sizeof(E->TabClasse[i].TabEleve[j].dateNaissance));
        }
    }
}

// ----------------------------------------------------------------------------------------------------------------------- //

/***********************************************Daphne***********************************************/
void RechercherEleve(Ecole_t E){
    char recherche[MAX];//le mot a rechercher
    int trouve, modifie;
    int i, j;
    printf("\nVeuillez entrer le nom de l'eleve a modifier : ");
    fscanf(stdin,"%s",recherche);
    getchar();
    modifie=0;
    for(i=0;i<E.nbClasse;i++){
        for(j=0;j<E.TabClasse[i].nbEleveClasse;j++){
            trouve=Recherche(E.TabClasse[i].TabEleve[j].nom, recherche);
            if(trouve==0){
                ModifierEleve(&E.TabClasse[i].TabEleve[j]);
                modifie=1;
            }
        }
    }
    if(modifie!=1){
        printf("\n***L'eleve n'a pas ete trouve***\n");
    }
}

int RechercherClasse(Ecole_t E){
    char recherche[MAX];//le mot a rechercher
    int trouve, numero;
    int i;
    printf("\nVeuillez entrer le nom de la classe a modifier : ");
    fscanf(stdin,"%s",recherche);
    getchar();
    printf("\nVeuillez entrer le numero de la classe a modifier : ");
    scanf("%d", &numero);
    for(i=0;i<E.nbClasse;i++){
        trouve=Recherche(E.TabClasse[i].niveau, recherche);
        if(trouve==0 && E.TabClasse[i].numClasse==numero){
            return i;
            }
    }
    printf("\n***La classe n'a pas ete trouvee***\n");
    return -1;
}

void AjouterClasse(Ecole_t *E, int position){
    SaisirClasse(&E->TabClasse[position]);
    E->nbClasse+=1;
}

void SupprimerEleve(Ecole_t *E){
    char recherche[MAX];//le mot a rechercher
    char choixsup;
    int trouve, suppr;
    int i, j, k;
    printf("\nVeuillez entrer le nom de l'eleve a supprimer : ");
    fscanf(stdin,"%s",recherche);
    getchar();
    suppr=0;
    for(i=0;i<E->nbClasse;i++){
        for(j=0;j<E->TabClasse[i].nbEleveClasse;j++){
            trouve=Recherche(E->TabClasse[i].TabEleve[j].nom, recherche);
            if(trouve==0){
                AfficherEleve(E->TabClasse[i].TabEleve[j]);
                printf("\n\n*************Voulez-vous vraiment supprimer cet eleve ? (o/n)*************\n");
                scanf("%c",&choixsup);
                if(choixsup=='o'){
                    for(k=j;k<E->TabClasse[i].nbEleveClasse;k++){
                        strcpy(E->TabClasse[i].TabEleve[j].nom, E->TabClasse[i].TabEleve[j+1].nom);
                        strcpy(E->TabClasse[i].TabEleve[j].prenom, E->TabClasse[i].TabEleve[j+1].prenom);
                        E->TabClasse[i].TabEleve[j].sexe=E->TabClasse[i].TabEleve[j+1].sexe;
                        E->TabClasse[i].TabEleve[j].dateNaissance.tm_mday=E->TabClasse[i].TabEleve[j+1].dateNaissance.tm_mday;
                        E->TabClasse[i].TabEleve[j].dateNaissance.tm_mon=E->TabClasse[i].TabEleve[j+1].dateNaissance.tm_mon;
                        E->TabClasse[i].TabEleve[j].dateNaissance.tm_year=E->TabClasse[i].TabEleve[j+1].dateNaissance.tm_year;
                    }
                    suppr=1;
                    strcpy(E->TabClasse[i].TabEleve[E->TabClasse[i].nbEleveClasse].nom, " ");
                    strcpy(E->TabClasse[i].TabEleve[E->TabClasse[i].nbEleveClasse].prenom, " ");
                    E->TabClasse[i].TabEleve[E->TabClasse[i].nbEleveClasse].sexe=' ';
                    E->TabClasse[i].TabEleve[E->TabClasse[i].nbEleveClasse].dateNaissance.tm_mday=0;
                    E->TabClasse[i].TabEleve[E->TabClasse[i].nbEleveClasse].dateNaissance.tm_mon=0;
                    E->TabClasse[i].TabEleve[E->TabClasse[i].nbEleveClasse].dateNaissance.tm_year=0;
                    E->TabClasse[i].nbEleveClasse-=1;
                }
                if(suppr==1){
                    printf("\n*****L'eleve a bien ete supprime*****\n");
                }
            }
        }
    }
    if(suppr!=1){
        printf("\n***L'eleve n'a pas ete trouve***\n");
    }
}

void RangerEcole(Ecole_t *E){
    int i;
    RangerClasses(E->TabClasse, E->nbClasse);
    for(i=0;i<E->nbClasse;i++){
        RangerEleves(E->TabClasse[i].TabEleve, E->TabClasse[i].nbEleveClasse);
    }
}
/****************************************************************************************************/
