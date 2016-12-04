#include <stdio.h>
#include <string.h>
#define MAX 32

//structures
define struct Date{
  int jour;
  int mois;
  int an;
}Date_t;

typedef struct Eleve{
  char nom[MAX];
  char prenom[MAX];
  Date_t Naissance;//peut aussi s'écrire "struct Date Naissance;"
}Eleve_t;

typedef struct Classe{
  char niveau[4];
  char instit[MAX];
  int numClasse;
  int nbEleve;
  Eleve_t TabEleve[MAX];//peut aussi s'écrire "struct Eleve TabEleve[MAX];"
}Classe_t;

typedef struct Ecole{
  char nom[MAX];
  int nbClasse;
  Classe_t TabClasse[MAX];//peut aussi s'écrire "struct Classe TabClasse[MAX];"
 }Ecole_t;
 
 //fonctions
 //Delphine
 AfficherEleve(){
 
 }
 
 //Daphné
 ModifierEleve(){
 
 }
 
 //Cyril
 AfficherClasse(){
 
 }
 
 //Yannick
 AfficherEcole(){
 
 }
 
 //Delphine
 SaisirEleve(){
 
 }
 
 //Cyril
 AffecterEleve(){
 
 }
 
 //Daphné
 RechercherEleve(){
 
 }
 
 //Yannick
 InscrireEleve(){
 
 }
 
 //BONUS
 RepartirEleves(){
 
 }
 
 OuvrirClasse(){
 
 }
 
 PasserAnnee(){
 
 }
 
 AfficherMenu(){
 
 }
 
 
 main(){
 
 }
 
