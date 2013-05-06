/*
* Fonction pour projet C Quentin Vecchio
* Fonction Est_Candidat et Fermer_Case
*/
int Est_Candidat(int chiffre, int colonne, int ligne, L_Candidats LC)
{


}

void Fermer_Case(int chiffre, int grille[][], int colonne, int ligne, L_Candidats LC[][])
{
	int i;//Index de parcours
	T_Case case;
	case.ligne = ligne;
	case.colonne = colonne;
	//Suppression du chiffre dans la listes de candidats des cases voisines
		//Suppression dans la ligne 
		for(i=0;i<9;i++)
		{
			if(Est_Candidat(chiffre,colonne,i, LC)
			{
				Supprimer_Candidat(L_Candidats[colonne][i],chiffre);
			}
		}
		//Suppression dans la colonne
		for(i=0;i<9;i++)
		{
                        if(Est_Candidat(chiffre,i,ligne, LC)
			{
				Supprimer_Candidat(L_Candidats[i][colonne],chiffre);
			}
                }
		//Suppression dans le carré
	//Suppression de la case dans la liste des cases ouvertes
	Supprimer_Case_Liste(case);
	//Ajout de la valeur dans la grille
	grille[ligne][colonne] = chiffre;
}
