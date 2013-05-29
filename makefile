Sudoku : main.o GestionCandidats.o GestionCases.o resolution.o initialisation.o affiche.o methodeResolution.o
	gcc main.o GestionCandidats.o GestionCases.o resolution.o initialisation.o affiche.o methodeResolution.o -o Sudoku
	
main.o :initialisation.o resolution.o GestionCandidats.o GestionCases.o affiche.o methodeResolution.o
	gcc -c GestionCandidats.o GestionCases.o resolution.o initialisation.o affiche.o methodeResolution.o tui/main.c 
	
initialisation.o : GestionCandidats.o GestionCases.o resolution.o
	gcc  -c GestionCandidats.o GestionCases.o resolution.o  src/initialisation.c
	
resolution.o : GestionCandidats.o GestionCases.o
	gcc -c GestionCandidats.o GestionCases.o src/resolution.c
	
affiche.o:
	gcc -c tui/affiche.c
	
GestionCandidats.o :
	gcc -c src/GestionCandidats.c  
	
GestionCases.o :
	gcc -c  src/GestionCases.c 

methodeResolution.o :
	gcc -c src/methodeResolution.c


#effacer les fichers '*.o'
clean : 
	rm *.o
	
#efface les fichier '*.o' plus l'executable 'Sudoku'
reset :
	rm *.o Sudoku
