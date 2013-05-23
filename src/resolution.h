// #ifndef resolutionH
// #define resolutionH
/*
	HEADER resolution.h
	Quentin Vecchio
	17 mai 2013
*/

//Fonction qui indique si oui ou non un chiffre donné est candidat pour une case donné.
int Est_Candidat(int chiffre,T_Case Case , int grille[9][9]);

//Fonction qui attribue définitivement un chiffre à une case de la grille et élimine ce chiffre des listes de candidats des cases voisines.
void Fermer_Case(int chiffre, int grille[9][9],T_Case Case, L_Candidats LC[9][9]);
// #endif