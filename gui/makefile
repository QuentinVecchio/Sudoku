#.PHONY: clean, reset

#.SUFFIXES:

all : gui_main.o gui_jeux.o gui_resoudre.o gui_credit.o initialisation.o GestionCandidats.o GestionCases.o resolution.o methodeResolution.o affiche.o
	gcc -O3 gui_main.o gui_resoudre.o  gui_credit.o gui_jeux.o initialisation.o GestionCandidats.o GestionCases.o resolution.o methodeResolution.o affiche.o -o Sudoku `pkg-config --cflags --libs gtk+-2.0` -lpthread

gui_main.o : gui_main.c ../src/initialisation.h ../src/GestionCandidats.h ../src/GestionCases.h gui_credit.h gui_resoudre.h gui_jeux.h
	gcc -c -O3 gui_main.c `pkg-config --cflags --libs gtk+-2.0` -o gui_main.o

gui_credit.o : gui_credit.c ../src/initialisation.h ../src/GestionCandidats.h ../src/GestionCases.h 
	gcc -c -O3 gui_credit.c `pkg-config --cflags --libs gtk+-2.0` -o gui_credit.o
	
gui_resoudre.o : gui_resoudre.c ../src/initialisation.h ../src/GestionCandidats.h ../src/GestionCases.h 
	gcc -c -O3 gui_resoudre.c `pkg-config --cflags --libs gtk+-2.0` -o gui_resoudre.o
  
gui_jeux.o : gui_jeux.c ../src/initialisation.h ../src/GestionCandidats.h ../src/GestionCases.h
	gcc -c  -O3 gui_jeux.c `pkg-config --cflags --libs gtk+-2.0` -lpthread -o gui_jeux.o

methodeResolution.o : ../src/methodeResolution.c ../src/GestionCases.h ../src/GestionCandidats.h ../src/initialisation.h ../src/resolution.h
	gcc -c -O3 ../src/methodeResolution.c -o methodeResolution.o

initialisation.o : ../src/initialisation.c ../src/GestionCandidats.h ../src/GestionCases.h ../src/resolution.h
	gcc -c -O3 ../src/initialisation.c -o initialisation.o

resolution.o : ../src/resolution.c ../src/GestionCandidats.h ../src/GestionCases.h
	gcc -c -O3 ../src/resolution.c -o resolution.o

affiche.o : ../tui/affiche.c
	gcc -c -O3 ../tui/affiche.c -o affiche.o

GestionCandidats.o : ../src/GestionCandidats.c
	gcc -c -O3 ../src/GestionCandidats.c -o GestionCandidats.o

GestionCases.o : ../src/GestionCases.c 
	gcc -c  -O3 ../src/GestionCases.c -o GestionCases.o

#effacer les fichers '*.o'
clean :
	rm -rf *.o

#efface les fichier '*.o' plus l'executable 'Sudoku'
reset : clean
	rm -rf Sudoku

