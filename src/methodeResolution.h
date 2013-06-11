#ifndef methodeResolutionH
#define methodeResolutionH

/**
 *	HEADER methodeResolotion
 *
 *	Contient les fonctions permettant de résoudre les sudoku
 *
 *	@author Cindy Binder, Matthieu Clin
 * 	@version 1.0.0
 *	@date 12/06/2013
 */


/**
 * 	Fonction qui permet de résoudre un sudoku par la méthode des candidats uniques
 * 	@param grille, la grille d'entiers du sudoku
 * 	@param LO, Liste des cases ouvertes
 * 	@param LC, Liste des Candidats
 * 	@return 1 si la grille a été résolu, 0 sinon
 */
int fermerGrille(int grille[9][9], L_Cases LO, L_Candidats LC[9][9]);


/**
 * 	Fonction récursive qui réalise le backtracking
 * 	@param grille, la grille d'entiers du sudoku
 * 	@param LO, Liste des cases ouvertes
 * 	@param LC, Liste des Candidats
 * 	@return 1 si la grille a été résolu, 0 sinon
 */
int Backtrack(int grille[9][9], L_Cases LO, L_Candidats LC[9][9]);

#endif