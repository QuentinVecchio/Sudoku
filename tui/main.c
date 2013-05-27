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
	char lien[] = "res/g1.txt";

	Init_Data(LC, LO, Grille, lien);
	Affiche_Grille(Grille);
	
	int ligne, colonne;
	
	for(ligne = 0; ligne <9; ligne ++)
	{
			for(colonne = 0; colonne < 9; colonne++)
			{
				printf("Affichage de la ligne %d colonne %d\n", ligne, colonne);
				affiche_liste_Candidats(LC[ligne][colonne]);
			}
	}
	return 0;
}