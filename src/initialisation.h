#ifndef INITIALISATION_H
#define INITIALISATION_H

/**
 * 	Initialisaton des listes et des tableaux
 * 
 * 	@author Cindy Binder, Nicolas Weissenbach
 * 	@version 1.0.0
 * 	@date 9/06/2013
 */

/**
 * 	Initialisaton des tableaux 'LC', 'Grille' de la liste 'LO'
 * 	@param LC, tableau contenant des listes candidats de la grille, 'NULL' si la case est fermé
 * 	@param LO, liste des cases ouvertes de la grille
 * 	@param Grille, tableau du sudoku
 * 	@param lien, chaine de caractere contenant le chemain du fichier a lire
 */
void Init_Data(L_Candidats  LC[9][9], L_Cases LO, int Grille[9][9],char lien[] );

/**
 * 	Lecture du fichier de la grille
 * 	@param Grille, grille du sudoku, les nombre y sont initialisé a partire du fichier, 0 sinon
 * 	@param lien, chemain du fichier a lire pour initialiser 'Grille'
 */
void lireGrille(int Grille[9][9],char lien[]);

#endif
