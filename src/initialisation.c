#include <stdio.h>

#include "GestionCandidats.h"
#include "GestionCases.h"
#include "resolution.h"
#include "../tui/affiche.h"
#include "initialisation.h"


/*
 * une fonction qui retourne un tableau de valeur correspondant au fichier txt fourni
 */
void lireGrille(int Grille[9][9],char lien[])
{
	FILE *f=NULL;
	int ligne,colonne,var;
	f=fopen(lien,"r");
	if (f!=NULL)
	{
		while (fscanf(f,"%d %d %d",&ligne,&colonne,&var)!=EOF)
		Grille[ligne][colonne] = var;
		
	}
	else
	{printf("Le fichier n'existe pas");
	}
}



/*
 * @param: LC est un tableau [9][9] qui contient soit NULL soit une liste de candidats
 */
void Init_Data(L_Candidats  LC[9][9], L_Cases LO, int Grille[9][9],char lien[] )
{
	//SPECIFICATION
	
	int ligne, colonne; //index de parcours du tableau 'LC'
	
	//int Grille[9][9]={0}; //tableau de valeur du fichier
	int nb; //varis de 1 à 9 pour remplire la liste des candidats dans le tableau LC
	
	int possible = 0; //booleen qui défini si 'nb' est un candidat possible pour la case LC[][]
	
	LO = creer_liste_vide();
	
	
	
	//CORPS
	
	/*lireGrille(Grille,"../res/g1.txt");
	Affiche_Grille(Grille);
	 * on ferme les cases qui sont dans le fichier txt	lireGrille(Grille,"../res/g1.txt");
	 * et on leur attribut NULL 
	 */
	
	/*
	 * on ouvre les cases qui ne sont pas dans le fichier txt
	 * on attribut a la case un pointeur sur la liste des candidats de la case
	 */
	
	//Initialisation da la variable Init avec la fonction lireGrille
	lireGrille(Grille,lien);
	
	
	for(ligne = 0; ligne < 9; ligne ++)
	{
		for(colonne = 0; colonne < 9; colonne ++)
		{
			if(Grille[ligne][colonne] != 0) LC[ligne][colonne] = NULL;
			else
			{
				for(nb = 1; nb <= 9; nb ++)
				{
					possible = Est_Candidat(nb, (T_Case){ligne,colonne}, Grille);
					if(possible)
					{
						ajout_element_Candidats(LC[ligne][colonne], nb);
					}
				}
				lireGrille(Grille,"../res/g1.txt");
				//on ajoute la case courrante a la liste des cases ouvert
				ajout_element_Case(LO, (T_Case){ligne, colonne});
				
			}
		}
	}
}




