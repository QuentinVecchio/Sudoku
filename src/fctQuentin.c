/*
* Fonction pour projet C Quentin Vecchio
* Fonction Est_Candidat et Fermer_Case
*/
int Est_Candidat(int chiffre,T_Case Case , L_Candidats LC[][])
{
	return (appartient_liste(LC[Case.ligne][Case.Colonne],chiffre));
}

void Fermer_Case(int chiffre, int grille[][],T_Case Case, L_Candidats LC[][])
{
	int i;//Index de parcours
	int x;//Index de parcours colonne
	int y;//Index de parcours ligne
	//Suppression du chiffre dans la listes de candidats des cases voisines et de la case
		//Suppression dans la ligne
		for(i=0;i<9;i++)
		{
			if(Est_Candidat(LC[Case.ligne][Case.colonne],chiffre))
			{
				supprimer_element(L_Candidats[i][Case.colonne],chiffre);
			}
		}
		//Suppression dans la colonne
		for(i=0;i<9;i++)
		{
                        if(appartient_liste(LC[Case.ligne][Case.colonne],chiffre))
			{
				supprimer_element(L_Candidats[Case.ligne][i],chiffre);
			}
                }
		//Suppression dans le carré et dans la case
		x = Case.colonne-Case.colonne%3;
		y = Case.ligne-Case.ligne%3;
		while(x != x+3)
		{
			while(y != y+3)
			{
				supprimer_element(L_Candidats[x][y],chiffre);
				y++;
			}
			y -=3;
			x++;
		}
	//Ajout de la valeur dans la grille
	grille[Case.ligne][Case.colonne] = chiffre;
}
