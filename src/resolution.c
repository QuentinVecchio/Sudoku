/*
 	CODE SOURCE des fonctions de résolutions
	QUENTIN VECCHIO
	17 mai 2013
*/
#include "GestionCases.h"
#include "GestionCandidats.h"
#include <stdio.h>
#include <stdlib.h>

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

	int i;//Index de parcours
	int x;//Index de parcours colonne
	int y;//Index de parcours ligne
	int v;
	L_Candidats tmp;

		
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
			if( x != Case.ligne )
			{
				while(y < val_y+3)
				{
					suppr_element_Candidats(&LC[x][y],chiffre);
					y++;
				}
				y -=3;
			}
			x++;
		}
	//Ajout de la valeur dans la grille
	grille[Case.ligne][Case.colonne] = chiffre;
	
}

void Ouvrir_Case(int chiffre, int grille[9][9],T_Case Case, L_Candidats LC[9][9], L_Cases LO)
{
	int i;//Index de parcours
	int x;//Index de parcours colonne
	int y;//Index de parcours ligne
	//Suppression du chiffre dans la listes de candidats des cases voisines et de la case
		//Suppression dans la ligne
	T_Case current1, current2;
	
	current1.colonne = Case.colonne;
	current2.ligne = Case.ligne;
	
	grille[Case.ligne][Case.colonne] = 0;
		
		for(i=0;i<9;i++)
		{
			current1.ligne = i;
			current2.colonne = i;
			if(appartient_liste_case(LO, current1))
			{
				
				if(Est_Candidat(chiffre, current1, grille))
				{
					ajout_element_Candidats(&LC[i][Case.colonne], chiffre);
				}
			}
			if(appartient_liste_case(LO, current2))
			{
				if(Est_Candidat(chiffre, current2, grille))
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
			if(x != Case.ligne)
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
			}
			x++;
		}
}


int Admet_Unique(L_Candidats LC[9][9], T_Case Case)
{
	int res = 0;
	L_Candidats c = LC[Case.ligne][Case.colonne];
	if(c == NULL) return 0;
	
	res = Admet_Unique_liste(c);
	if(res) return res;	


	int i = 0;
	int est_dans_colonne, est_dans_ligne, est_dans_carre;
	int j = 0;
	int limit_i, limit_j;
	do{
		est_dans_carre = 0;
		i = Case.ligne-Case.ligne%3;
		limit_i = i;
		j = Case.colonne-Case.colonne%3;
		limit_j = j;
		while(est_dans_carre == 0 && i < (limit_i+3))
		{
			while(est_dans_carre == 0 &&j < (limit_j+3))
			{
				if(j == Case.colonne && i == Case.ligne)
				{
					j++;
					continue;
					
				}
				if(appartient_liste(LC[i][j],c->courant)) est_dans_carre = 1;
				j++;
			}
			j -=3;
			i++;
		}
		if(!est_dans_carre)
		{
			return c->courant;
		}
		est_dans_colonne = 0;
		est_dans_ligne = 0;
		for(i = 0; i < 9; i++)
		{
			if(i != Case.ligne && appartient_liste(LC[i][Case.colonne],c->courant))
			{
				est_dans_colonne = 1;
			}
			if(i != Case.colonne && appartient_liste(LC[Case.ligne][i],c->courant))
			{
				est_dans_ligne = 1;
			}
		}

		if(!est_dans_colonne)
		{
			return c->courant;
			
		}
		if(!est_dans_ligne)
		{
			return c->courant;
			
		}
		c= c->suivant;
		
	}while(c);	
	return 0;
}

