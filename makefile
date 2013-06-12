#.PHONY: clean, reset

#.SUFFIXES:

CFLAGS = -c -O3

tui : GestionCandidats.o GestionCases.o resolution.o initialisation.o affiche.o methodeResolution.o main.o
	gcc -O3 GestionCandidats.o GestionCases.o resolution.o initialisation.o affiche.o methodeResolution.o main.o -o Sudoku
	
gui : gui_main.o gui_jeux.o gui_resoudre.o gui_credit.o initialisation.o GestionCandidats.o GestionCases.o resolution.o methodeResolution.o affiche.o
		gcc -O3 gui_main.o gui_resoudre.o  gui_credit.o gui_jeux.o initialisation.o GestionCandidats.o GestionCases.o resolution.o methodeResolution.o affiche.o -o Sudoku `pkg-config --cflags --libs gtk+-2.0` -lpthread

#CIBLES CONSOLES
main.o : src/GestionCandidats.h src/GestionCases.h src/initialisation.h src/resolution.h tui/affiche.h src/methodeResolution.h resolution.o
	gcc $(CFLAGS) tui/main.c -o main.o 

	
#CIBLES SOURCES
methodeResolution.o : src/methodeResolution.c src/GestionCases.h src/GestionCandidats.h src/initialisation.h src/resolution.h
	gcc $(CFLAGS) src/methodeResolution.c -o methodeResolution.o
	
initialisation.o : src/initialisation.c src/GestionCandidats.h src/GestionCases.h src/resolution.h
	gcc $(CFLAGS) src/initialisation.c -o initialisation.o
	
resolution.o : src/resolution.c src/GestionCandidats.h src/GestionCases.h
	gcc $(CFLAGS) src/resolution.c -o resolution.o
	
affiche.o : tui/affiche.c   
	gcc $(CFLAGS) tui/affiche.c -o affiche.o
	
GestionCandidats.o : src/GestionCandidats.c
	gcc $(CFLAGS) src/GestionCandidats.c -o GestionCandidats.o
	
GestionCases.o : src/GestionCases.c
	gcc $(CFLAGS) src/GestionCases.c -o GestionCases.o
	
	
#CIBLES GRAPHIQUES
gui_main.o : gui/gui_main.c src/initialisation.h src/GestionCandidats.h src/GestionCases.h gui/gui_credit.h gui/gui_resoudre.h gui/gui_jeux.h
	gcc $(CFLAGS) gui/gui_main.c `pkg-config --cflags --libs gtk+-2.0` -o gui_main.o

gui_credit.o : gui/gui_credit.c src/initialisation.h src/GestionCandidats.h src/GestionCases.h 
	gcc $(CFLAGS) gui_credit.c `pkg-config --cflags --libs gtk+-2.0` -o gui_credit.o
	
gui_resoudre.o : gui/gui_resoudre.c src/initialisation.h src/GestionCandidats.h src/GestionCases.h 
	gcc $(CFLAGS) gui/gui_resoudre.c `pkg-config --cflags --libs gtk+-2.0` -o gui_resoudre.o
  
gui_jeux.o : gui/gui_jeux.c src/initialisation.h src/GestionCandidats.h src/GestionCases.h
	gcc $(CFLAGS) gui/gui_jeux.c `pkg-config --cflags --libs gtk+-2.0` -lpthread -o gui_jeux.o
	
gui_credit.o : gui/gui_credit.c src/initialisation.h src/GestionCandidats.h src/GestionCases.h 
	gcc $(CFLAGS) gui/gui_credit.c `pkg-config --cflags --libs gtk+-2.0` -o gui_credit.o


#effacer les fichers '*.o'
clean : 
	rm -rf *.o
	
#efface les fichier '*.o' plus l'executable 'Sudoku'
reset : clean
	rm -rf Sudoku
