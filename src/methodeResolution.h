#ifndef methodeResolutionH
#define methodeResolutionH
/*
	HEADER methodeResolotion

	Contient les fonctions permettant de résoudre les sudoku
*/

//Fonction qui permet de résoudre un sudoku par la méthode des candidats uniques
int fermerGrille(int grille[9][9], L_Cases LO, L_Candidats LC[9][9]);

//Fonction récursive qui réalise le backtracking
int Backtrack(int grille[9][9], L_Cases LO, L_Candidats LC[9][9]);

#endif