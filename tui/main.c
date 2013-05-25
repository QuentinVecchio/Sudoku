#include <stdio.h>
#include "../src/GestionCandidats.h"
#include "../src/GestionCases.h"
#include "../src/initialisation.h"
#include "affiche.h"

int main()
{
	printf("Bienvenue dans le logiciel de résolution de sudoku\n");
	int Grille[9][9]={{0}};
	L_Candidats  LC[9][9]= {{NULL}};
	L_Cases LO = NULL;
	char lien[] = "res/g1.txt";

	Init_Data(LC, LO, Grille, lien);
	Affiche_Grille(Grille);
	//affiche_liste_case(LO);
	return 0;
}