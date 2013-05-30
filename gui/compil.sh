gcc gui_main.c gui_resoudre.c  gui_credit.c gui_jeux.c ../src/initialisation.c ../src/GestionCandidats.c ../src/GestionCases.c ../src/resolution.c -o sudoku `pkg-config --cflags --libs gtk+-2.0` -lpthread

