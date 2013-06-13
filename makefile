#.PHONY: clean, reset, copie

#.SUFFIXES:

CFLAGS = -c -O3

tui : copie dist/GestionCandidats.o dist/GestionCases.o dist/resolution.o dist/initialisation.o dist/affiche.o dist/methodeResolution.o dist/main.o
	gcc -O3 dist/GestionCandidats.o dist/GestionCases.o dist/resolution.o dist/initialisation.o dist/affiche.o dist/methodeResolution.o dist/main.o -o dist/Sudoku_tui
	
gui : copie dist/gui_main.o dist/gui_jeux.o dist/gui_resoudre.o dist/gui_credit.o dist/initialisation.o dist/GestionCandidats.o dist/GestionCases.o dist/resolution.o dist/methodeResolution.o dist/affiche.o
		gcc -O3 dist/gui_main.o dist/gui_resoudre.o  dist/gui_credit.o dist/gui_jeux.o initialisation.o GestionCandidats.o GestionCases.o resolution.o methodeResolution.o affiche.o -o dist/Sudoku_gui `pkg-config --cflags --libs gtk+-2.0` -lpthread

#CIBLE CONSOLE
dist/main.o : src/GestionCandidats.h src/GestionCases.h src/initialisation.h src/resolution.h tui/affiche.h src/methodeResolution.h dist/resolution.o
	gcc $(CFLAGS) tui/main.c -o dist/main.o 
	
	
#CIBLES SOURCES
dist/methodeResolution.o : src/methodeResolution.c src/GestionCases.h src/GestionCandidats.h src/initialisation.h src/resolution.h
	gcc $(CFLAGS) src/methodeResolution.c -o dist/methodeResolution.o
	
dist/initialisation.o : src/initialisation.c src/GestionCandidats.h src/GestionCases.h src/resolution.h
	gcc $(CFLAGS) src/initialisation.c -o dist/initialisation.o
	
dist/resolution.o : src/resolution.c src/GestionCandidats.h src/GestionCases.h
	gcc $(CFLAGS) src/resolution.c -o dist/resolution.o
	
dist/affiche.o : tui/affiche.c   
	gcc $(CFLAGS) tui/affiche.c -o dist/affiche.o
	
dist/GestionCandidats.o : src/GestionCandidats.c
	gcc $(CFLAGS) src/GestionCandidats.c -o dist/GestionCandidats.o
	
dist/GestionCases.o : src/GestionCases.c
	gcc $(CFLAGS) src/GestionCases.c -o dist/GestionCases.o
	
	
#CIBLES GRAPHIQUES
dist/gui_main.o : gui/gui_main.c src/initialisation.h src/GestionCandidats.h src/GestionCases.h gui/gui_credit.h gui/gui_resoudre.h gui/gui_jeux.h
	gcc $(CFLAGS) gui/gui_main.c `pkg-config --cflags --libs gtk+-2.0` -o dist/gui_main.o

dist/gui_credit.o : gui/gui_credit.c src/initialisation.h src/GestionCandidats.h src/GestionCases.h 
	gcc $(CFLAGS) gui_credit.c `pkg-config --cflags --libs gtk+-2.0` -o gui_credit.o
	
dist/gui_resoudre.o : gui/gui_resoudre.c src/initialisation.h src/GestionCandidats.h src/GestionCases.h 
	gcc $(CFLAGS) gui/gui_resoudre.c `pkg-config --cflags --libs gtk+-2.0` -o dist/gui_resoudre.o
  
dist/gui_jeux.o : gui/gui_jeux.c src/initialisation.h src/GestionCandidats.h src/GestionCases.h
	gcc $(CFLAGS) gui/gui_jeux.c `pkg-config --cflags --libs gtk+-2.0` -lpthread -o dist/gui_jeux.o
	
dist/gui_credit.o : gui/gui_credit.c src/initialisation.h src/GestionCandidats.h src/GestionCases.h 
	gcc $(CFLAGS) gui/gui_credit.c `pkg-config --cflags --libs gtk+-2.0` -o dist/gui_credit.o
	
copie : gui/fondEcran.png gui/gtkrc.rc gui/icon.png res/
	cp gui/fondEcran.png ./dist/ && cp gui/gtkrc.rc ./dist/ && cp gui/icon.png ./dist/ && cp -r res/ dist/

	
#effacer les fichers '*.o'
clean : 
	rm -rf *.o && rm -rf dist/*.o
	
#efface les fichier '*.o' plus l'executable 'Sudoku'
reset : clean
	rm -rf Sudoku_tui && rm -rf dist/Sudoku_gui
