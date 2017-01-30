#Cible principale
ecole: main.c ecole.o classe.o eleve.o save.o menu.o
	gcc main.c ecole.o classe.o eleve.o save.o menu.o -o ecole
	
#Dependences
save.o: ecole.o classe.o eleve.o 
	gcc -c save.c
	
menu.o: ecole.o classe.o eleve.o
	gcc -c menu.c
	
ecole.o: classe.o eleve.o
	gcc -c ecole.c
	
classe.o: eleve.o
	gcc -c classe.c
	
eleve.o: eleve.c
	gcc -c eleve.c
	
#Cible fictive pour nettoyer les fichiers .o
MrProper:
	rm -f *.o
