#include <stdio.h>
//#include "../src/GestionCandidats.h"
//#include "../src/struc.c"
#include "affiche.h"
#include "../src/GestionCandidats.h"
#include "../src/GestionCases.h"
#include "../src/initialisation.h"
main()
{
	printf("Bienvenue dans le logiciel de résolution de sudoku\n");
// 	int Grille[9][9]={0};
// 	lireGrille(Grille,"../res/g1.txt");
// 	Affiche_Grille(Grille);
	L_Candidats LC[9][9];
	L_Cases LO = NULL;
	Init_Data(LC, LO);
	
}