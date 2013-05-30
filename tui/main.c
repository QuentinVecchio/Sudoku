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
	L_Cases LO = creer_liste_vide();
	char lien[] = "res/g9.txt";

	Init_Data(LC, LO, Grille, lien);
	int grille_simple=fermerGrille(Grille, LO, LC);
	if (grille_simple)
	{
		printf("Grille résolue\n");
		Affiche_Grille(Grille);
		
	}
	else
	{
		printf("Grille complexe\n");
		printf("Lancement du backtracking\n");
		int grille_possible=Backtrack(Grille,LO,LC);
		if (grille_possible==1)Affiche_Grille(Grille);
		else printf("Grille impossible\n");
	}

	return 0;
}