#include <stdio.h>
#include "../src/GestionCandidats.h"
#include "../src/GestionCases.h"

main()
{
	printf("Bienvenue dans le logiciel de résolution de sudoku\n");
	int Grille[9][9]={0};
	L_Candidats  LC[9][9];
	L_Cases LO;
	char lien[] = "../res/g1.txt";

	Init_Data(LC, LO, Grille, lien);
	
	
}