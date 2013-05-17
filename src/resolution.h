/*
	HEADER resolution.h
	Quentin Vecchio
	17 mai 2013
*/

//Fonction qui indique si oui ou non un chiffre donné est candidat pour une case donné.
int Est_Candidat(int chiffre,T_Case Case , int grille[][]);

//Fonction qui attribue définitivement un chiffre à une case de la grille et élimine ce chiffre des listes de candidats des cases voisines.
void Fermer_Case(int chiffre, int grille[][],T_Case Case, L_Candidats LC[][]);


