#include <stdio.h>

#include "GestionCandidats.h"
#include "GestionCases.h"

#include "initialisation.h"

main()
{
	printf("hello world\n");
	return 0;
}


void Init_Data(L_Candidats * LC)
{
	//SPECIFICATION
	
	int i, j; //index de parcours du tableau 'LC'
	
	int Grille[9][9]; //tableau de valeur du fichier
	int n; //index de parcours du tableau 'Init'
	
	
	//CORPS
	
	
	/*
	 * on ferme les cases qui sont dans le fichier txt
	 * et on leur attribut NULL 
	 */
	
	/*
	 * on ouvre les cases qui ne sont pas dans le fichier txt
	 * on attribut a la case un pointeur sur la liste des candidats de la case
	 */
	
	//Initialisation da la variable Init avec la fonctio lireGrille
	lireGrille(&n, Grille);
	
	
	
	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{

		}
	}
}


/*
 * une fonction qui retourne un tableau de valeur correspondant au fichier txt fourni
 */
void lireGrille(int *n, int Grille[9][9])
{
	n=0;
}
