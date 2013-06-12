#.PHONY: clean, reset

#.SUFFIXES:


all : GestionCandidats.o GestionCases.o resolution.o initialisation.o affiche.o methodeResolution.o main.o
	gcc -O3 GestionCandidats.o GestionCases.o resolution.o initialisation.o affiche.o methodeResolution.o main.o -o Sudoku
	
main.o : src/GestionCandidats.h src/GestionCases.h src/initialisation.h src/resolution.h tui/affiche.h src/methodeResolution.h resolution.o
	gcc -c -O3 tui/main.c -o main.o 

methodeResolution.o : src/methodeResolution.c src/GestionCases.h src/GestionCandidats.h src/initialisation.h src/resolution.h
	gcc -c -O3 src/methodeResolution.c -o methodeResolution.o
	
initialisation.o : src/initialisation.c src/GestionCandidats.h src/GestionCases.h src/resolution.h
	gcc -c -O3 src/initialisation.c -o initialisation.o
	
resolution.o : src/resolution.c src/GestionCandidats.h src/GestionCases.h
	gcc -c -O3 src/resolution.c -o resolution.o
	
affiche.o : tui/affiche.c   
	gcc -c -O3 tui/affiche.c -o affiche.o
	
GestionCandidats.o : src/GestionCandidats.c
	gcc -c -O3 src/GestionCandidats.c -o GestionCandidats.o
	
GestionCases.o : src/GestionCases.c
	gcc -c -O3 src/GestionCases.c -o GestionCases.o



#effacer les fichers '*.o'
clean : 
	rm -rf *.o
	
#efface les fichier '*.o' plus l'executable 'Sudoku'
reset : clean
	rm -rf Sudoku
