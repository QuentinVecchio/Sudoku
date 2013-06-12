#ifndef RESOLUTION_H
#define RESOLUTION_H
/**
 *	HEADER resolution.h
 *	
 *	@author Quentin Vecchio
 *	@version 1.0.0
 *	@date 11/06/2013
*/


/**
 * 	Fonction qui indique si oui ou non un chiffre donné est candidat pour une case donné dans un sudoku
 * 	@param chiffre, le chiffre a tester
 * 	@param Case, les coordonnées dans la grille 'grille'
 * 	@param grille, grille du sudoku
 * 	@return 0 si le 'chiffre' n'est pas candidat, 1 sinon
 */
int Est_Candidat(int chiffre,T_Case Case , int grille[9][9]);

/**
 * 	Fonction qui attribue définitivement un chiffre à une case de la grille et élimine ce chiffre des listes de candidats des cases voisines.
 * 	@param chiffre,le nombre a attribuer definitivement a la case
 * 	@param grille, la grille du sudoku
 * 	@param Case, les coordonnées dans les tableaux 'grille' et 'LC'
 * 	@param LC, tableau de liste des candidats
 */

void Fermer_Case(int chiffre, int grille[9][9],T_Case Case, L_Candidats LC[9][9]);

/**
 * 	Fonction qui réouvre une case fermé, utilisé uniquement pour la backtracking
 * 	@param chiffre,chiffre a mettre dans la case 'case'
 * 	@param grille, 
 * 	@param case,coordonné de la case cible
 * 	@param LC,liste des candidats
 * 	@param LO,liste des cases ouverte
 */
void Ouvrir_Case(int chiffre, int grille[9][9],T_Case Case, L_Candidats LC[9][9], L_Cases LO);

/**
 * 	Vérifie qui la case 'Case' ne contient qu'un seul candidats
 * 	@param LC, tableau de liste de candidats
 * 	@param Case, coordonné de la case a vérifier
 * 	@return int, 0 s'il y a plusieurs candidats, le candidat unique sinon!
 */
int Admet_Unique(L_Candidats LC[9][9], T_Case Case);

#endif
