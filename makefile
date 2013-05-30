#.PHONY: clean, reset

#.SUFFIXES:


all : GestionCandidats.o GestionCases.o resolution.o initialisation.o affiche.o methodeResolution.o main.o
	gcc main.o -o Sudoku
	
main.o : tui/affiche.h src/methodeResolution.h
	gcc resolution.o initialisation.o affiche.o methodeResolution.o tui/main.c -o main.o 

methodeResolution.o : src/methodeResolution.c src/GestionCases.h src/GestionCandidats.h src/initialisation.h src/resolution.h
	gcc -c src/methodeResolution.c GestionCases.o GestionCandidats.o -o methodeResolution.o
	
initialisation.o : src/initialisation.c src/GestionCandidats.h src/GestionCases.h src/resolution.h
	gcc -c src/initialisation.c -o initialisation.o
	
resolution.o : src/resolution.c src/GestionCandidats.h src/GestionCases.h
	gcc -c src/resolution.c -o resolution.o
	
affiche.o : tui/affiche.c   
	gcc -c tui/affiche.c -o affiche.o
	
GestionCandidats.o : src/GestionCandidats.c
	gcc -c src/GestionCandidats.c -o GestionCandidats.o
	
GestionCases.o : src/GestionCases.c
	gcc -c src/GestionCases.c -o GestionCases.o



#effacer les fichers '*.o'
clean : 
	rm -rf *.o
	
#efface les fichier '*.o' plus l'executable 'Sudoku'
reset : clean
	rm -rf Sudoku
