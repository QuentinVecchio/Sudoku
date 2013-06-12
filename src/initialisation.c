#include <stdio.h>

#include "GestionCandidats.h"
#include "GestionCases.h"
#include "resolution.h"
#include "initialisation.h"



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
	{
		printf("Le fichier n'existe pas\n");
		exit(1);
	}
}



void Init_Data(L_Candidats  LC[9][9], L_Cases LO, int Grille[9][9],char lien[] )
{
	
	
	int ligne, colonne; //index de parcours du tableau 'LC'
	
	//int Grille[9][9]={0}; //tableau de valeur du fichier
	int nb; //varis de 1 à 9 pour remplire la liste des candidats dans le tableau LC
	
	int possible = 0; //booleen qui défini si 'nb' est un candidat possible pour la case LC[][]

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
						ajout_element_Candidats(&LC[ligne][colonne], nb);
					}
					
				}
				//on ajoute la case courrante a la liste des cases ouvert
				ajout_elt_case(&LO, (T_Case){ligne, colonne});
			}
		}
	}
}




