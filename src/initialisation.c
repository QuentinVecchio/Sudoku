#include <stdio.h>

#include "GestionCandidats.h"
#include "GestionCases.h"
#include "resolution.h"

#include "initialisation.h"

main()

{
	printf("hello world\n");
	return 0;
}

/*
 * @param: LC est un tableau [9][9] qui contient soit NULL soit une liste de candidats
 */
void Init_Data(L_Candidats  LC[9][9], L_Cases LO)
{
	//SPECIFICATION
	
	int ligne, colonne; //index de parcours du tableau 'LC'
	
	int Grille[9][9]={0}; //tableau de valeur du fichier
	int nb; //varis de 1 à 9 pour remplire la liste des candidats dans le tableau LC
	
	int possible = 0; //booleen qui défini si 'nb' est un candidat possible pour la case LC[][]
	
	LO = creer_liste_vide();
	
	
	
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
	
	
	
	for(ligne = 0; ligne < 9; ligne ++)
	{
		for(colonne = 0; colonne < 9; colonne ++)
		{
			if(Grille[ligne][colonne] != 0) LC[ligne][colonne] = NULL;
			else
			{
				
				for(nb = 1; nb <= 9; nb ++)
				{
					possible = Est_Candidat(nb, (T_Case){ligne, colonne}, Grille);
					if(possible)
					{
						ajout_element_Candidats(LC[ligne][colonne], nb);
					}
				}
				
				//on ajoute la case courrante a la liste des cases ouvert
				ajout_element_Case(LO, (T_Case){ligne, colonne});
				
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
