// #ifndef methodeResolutionH
// #define methodeResolutionH
/*
	HEADER methodeResolotion

	Contient les fonctions permettant de résoudre les sudoku
*/

//Fonction qui permet de résoudre un sudoku par la méthode des candidats uniques
int fermerGrille(int grille[][], L_Case LO, L_Candidats LC[][]);

//Fonction récursive qui réalise le backtracking
int Backtrack(int grille[][], L_Case LO, L_Candidats LC[][]);

// #endif methodeResolutionH