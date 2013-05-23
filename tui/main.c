#include <stdio.h>
#include "../src/GestionCandidats.h"
#include "../src/GestionCases.h"
#include "../src/initialisation.h"
#include "affiche.h"
<<<<<<< local

int main()
=======
#include "../src/GestionCandidats.h"
#include "../src/GestionCases.h"
#include "../src/initialisation.h"
main()
>>>>>>> other
{
	printf("Bienvenue dans le logiciel de résolution de sudoku\n");
<<<<<<< local
	int Grille[9][9]={{0}};
	L_Candidats  LC[9][9];
=======
// 	int Grille[9][9]={0};
// 	lireGrille(Grille,"../res/g1.txt");
// 	Affiche_Grille(Grille);
	L_Candidats LC[9][9];
>>>>>>> other
	L_Cases LO = NULL;
<<<<<<< local
	char lien[] = "res/g1.txt";

	Init_Data(LC, LO, Grille, lien);
	Affiche_Grille(Grille);
	//affiche_liste_case(LO);
	return 0;
=======
	Init_Data(LC, LO);
	
>>>>>>> other
}