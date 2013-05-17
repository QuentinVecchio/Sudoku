/*
* Fonction pour projet C Quentin Vecchio
* Fonction Est_Candidat et Fermer_Case
*/
int Est_Candidat(int chiffre,T_Case Case , int grille[][])
{
/*
	Fonction qui prend en paramètre une case et qui cherche si le chiffre donné peut etre clé candidate pour la case.
	On cherche si le chiffre est dans la ligne de la case, ensuite de la colonne et enfin dans le carré. On s'aide de la grille qui est remplie.
	La fonction s'arrête directement si elle trouve dans la grille le chiffre. Si l'opération se déroule bien alors le chifffe peut être candidat de la case.
*/
	int i;
	//On cherche le chiffre dans la ligne
	for(i=0;i<9;i++)
        {
		if(grille[i][Case.colonne] == chiffre)
			return 0;
        }
        //On cherche le chiffre dans la colonne
        for(i=0;i<9;i++)
        {
                if(grille[Case.ligne][i] == chiffre)
			return 0;
        }
	//On cherche dans le carré
	x = Case.ligne-Case.ligne%3;
        y = Case.colonne-Case.colonne%3;
        while(x != x+3)
        {
        	while(y != y+3)
                {
                      	if(grille[x][y] == chiffre)
                        	return 0;
                }
                y -=3;
                x++;
         }

	return 1;
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
		x = Case.ligne-Case.ligne%3;
		y = Case.colonne-Case.colonne%3;
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
