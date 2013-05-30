/*
 	CODE SOURCE des fonctions de résolutions
	QUENTIN VECCHIO
	17 mai 2013
*/
#include "GestionCases.h"
#include "GestionCandidats.h"
#include <stdio.h>

int Est_Candidat(int chiffre,T_Case Case , int grille[9][9])
{
/*
	Fonction qui prend en paramètre une case et qui cherche si le chiffre donné peut etre clé candidate pour la case.
	On cherche si le chiffre est dans la ligne de la case, ensuite de la colonne et enfin dans le carré. On s'aide de la grille qui est remplie.
	La fonction s'arrête directement si elle trouve dans la grille le chiffre. Si l'opération se déroule bien alors le chifffe peut être candidat de la case.
*/

	int i;
		
	//On cherche le chiffre dans la ligne
  //On cherche le chiffre dans la colonne
	for(i=0;i<9;i++)
	{
		if(grille[i][Case.colonne] == chiffre || grille[Case.ligne][i] == chiffre)
		return 0;
	}

        
	//On cherche dans le carré
	int x = Case.ligne-Case.ligne%3;
	int val_x = x;
	int y = Case.colonne-Case.colonne%3;
	int val_y = y;

	while(x < val_x+3)
	{
		while(y < val_y+3)
		{
			if(grille[x][y] == chiffre) return 0;
			y++;
		}
		y -=3;
		x++;
	}
	return 1;
}

void Fermer_Case(int chiffre, int grille[9][9],T_Case Case, L_Candidats LC[9][9])
{
/*
	Fonction qui prend en paramètre le chiffre à mettre dans la case donnée. on passe également la grille qui sera modifié dans la fonction.
	On appelle la fonction que quand on est sur de vouloir fermer la case, les vérifications ne sont donc pas obligatoire.
	La fonction supprime d'abord de tous les listes candidats des cases de la ligne ainsi que de la colonne et de du carré de la case donné.
	Enfin la fonction affecte à la case (via la grille) le chiffre donné.
*/
	int i;//Index de parcours
	int x;//Index de parcours colonne
	int y;//Index de parcours ligne
	//Suppression du chiffre dans la listes de candidats des cases voisines et de la case
		//Suppression dans la ligne
		

		
		for(i=0;i<9;i++)
		{
			suppr_element_Candidats(&LC[i][Case.colonne],chiffre);
			suppr_element_Candidats(&LC[Case.ligne][i],chiffre);
		}
		//Suppression dans le carré et dans la case
		x = Case.ligne-Case.ligne%3;
		int val_x = x;
		y = Case.colonne-Case.colonne%3;
		int val_y = y;

		while(x < val_x+3)
		{
			while(y < val_y+3)
			{
				suppr_element_Candidats(&LC[x][y],chiffre);
				y++;
			}
			y -=3;
			x++;
		}
	//Ajout de la valeur dans la grille
	grille[Case.ligne][Case.colonne] = chiffre;
	
}

void Ouvrir_Case(int chiffre, int grille[9][9],T_Case Case, L_Candidats LC[9][9], L_Cases LO)
{
/*
	Fonction qui prend en paramètre le chiffre à mettre dans la case donnée. on passe également la grille qui sera modifié dans la fonction.
	On appelle la fonction que quand on est sur de vouloir fermer la case, les vérifications ne sont donc pas obligatoire.
	La fonction supprime d'abord de tous les listes candidats des cases de la ligne ainsi que de la colonne et de du carré de la case donné.
	Enfin la fonction affecte à la case (via la grille) le chiffre donné.
*/
	int i;//Index de parcours
	int x;//Index de parcours colonne
	int y;//Index de parcours ligne
	//Suppression du chiffre dans la listes de candidats des cases voisines et de la case
		//Suppression dans la ligne
	grille[Case.ligne][Case.colonne] = 0;
		
		for(i=0;i<9;i++)
		{
			if(appartient_liste_case(LO, (T_Case){i,Case.colonne}))
			{
				
				if(Est_Candidat(chiffre, (T_Case){i, Case.colonne}, grille))
				{
					ajout_element_Candidats(&LC[i][Case.colonne], chiffre);
				}
			}
		}
		
		for(i=0;i<9;i++)
		{
			
			if(appartient_liste_case(LO, (T_Case){Case.ligne, i}))
			{/*printf("---%d %d\n", Case.ligne, i);*/
				if(Est_Candidat(chiffre, (T_Case){Case.ligne, i}, grille))
				{
					ajout_element_Candidats(&LC[Case.ligne][i], chiffre);
				}	
			}
		}
		
		
		//Suppression dans le carré et dans la case
		x = Case.ligne-Case.ligne%3;
		int val_x = x;
		y = Case.colonne-Case.colonne%3;
		int val_y = y;

		while(x < val_x+3)
		{
			while(y < val_y+3)
			{
				if(Est_Candidat(chiffre, (T_Case){x, y}, grille))
				{
					ajout_element_Candidats(&LC[x][y], chiffre);
				}
				y++;
			}
			y -=3;
			x++;
		}
	//Ajout de la valeur dans la grille

	
}
