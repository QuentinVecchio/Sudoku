#include <stdio.h>

#include "GestionCandidats.h"
#include "GestionCases.h"

#include "initialisation.h"

main()

{
	printf("hello world\n");
	return 0;
}

/*
 * @param: LC est un tableau [9][9] qui contient soit NULL soit une liste de candidats
 */
void Init_Data(L_Candidats  LC[9][9])
{
	//SPECIFICATION
	
	T_Case index; //index de parcours du tableau 'LC'
	
	int Grille[9][9]={0}; //tableau de valeur du fichier
	int nb; //varis de 1 à 9 pour remplire la liste des candidats dans le tableau LC
	
	int possible = 0; //booleen qui défini si 'nb' est un candidat possible pour la case LC[][]
	
	
	
	//CORPS
	
	
	/*
	 * on ferme les cases qui sont dans le fichier txt
	 * et on leur attribut NULL 
	 */
	
	/*
	 * on ouvre les cases qui ne sont pas dans le fichier txt
	 * on attribut a la case un pointeur sur la liste des candidats de la case
	 */
	
	//Initialisation da la variable Init avec la fonction lireGrille
	lireGrille(Grille);
	
	
	
	for(index.ligne = 0; index.ligne < 9; index.ligne ++)
	{
		for(index.colonne = 0; index.colonne < 9; index.colonne ++)
		{
			if(Grille[index.ligne][index.colonne] != 0) LC[index.ligne][index.colonne] = NULL;
			else
			{
				for(nb = 1; nb <= 9; nb ++)
				{
					possible = Est_Candidat(nb, index, Grille);
					if(possible)
					{
						//on ajout 'nb' a la liste des candidats!
					}
				}
			}
		}
	}
}


/*
 * une fonction qui retourne un tableau de valeur correspondant au fichier txt fourni
 */
void lireGrille(int Grille[9][9])
{
	//Fonction écrit par Cindy!!!
}
