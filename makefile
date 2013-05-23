Sudoku : main.o GestionCandidats.o GestionCases.o resolution.o initialisation.o affiche.o
	gcc main.o GestionCandidats.o GestionCases.o resolution.o initialisation.o affiche.o -o Sudoku
	
main.o :initialisation.o resolution.o GestionCandidats.o GestionCases.o affiche.o
	gcc  -c GestionCandidats.o GestionCases.o resolution.o initialisation.o affiche.o tui/main.c 
	
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



#effacer les fichers '*.o'
clean : 
	rm *.o
	
reset :
	rm *.o Sudoku
