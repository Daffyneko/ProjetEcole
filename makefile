# nom du compilateur
compilator=gcc

ecole: main.c eleve.o classe.o ecole.o save.o menu.o
	echo "edition de liens"
	${compilator} main.c eleve.o classe.o ecole.o save.o menu.o -o ecole

menu.o: menu.c save.o ecole.o classe.o eleve.o
	echo "edition de menu.o"
	${compilator} -c menu.c

save.o: save.c ecole.o classe.o eleve.o
	echo "edition de save.o"
	${compilator} -c save.c

ecole.o: ecole.c classe.o eleve.o
	echo "edition de ecole.o"
	${compilator} -c ecole.c

classe.o: classe.c eleve.o
	echo "edition de classe.o"
	${compilator} -c classe.c

eleve.o: eleve.c
	echo "edition de eleve.o"
	${compilator} -c eleve.c
