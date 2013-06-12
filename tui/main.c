#include <stdio.h>
#include "../src/GestionCandidats.h"
#include "../src/GestionCases.h"
#include "../src/initialisation.h"
#include "affiche.h"
#include "time.h"



/**
 * 	Fichier main, contient la fonction main
 * 
 * 	@author Cindy Binder, Matthieu Clin, Quentin Vecchio, Nicolas Weissenbach
 * 	@version 1.0.0
 * 	@date 12/06/2013
 */

int main()
{
	printf("Bienvenue dans le logiciel de résolution de sudoku\n");
	int Grille[9][9]={{0}};
	L_Candidats  LC[9][9]= {{NULL}};
	L_Cases LO = creer_liste_vide();
	char lien[] = "res/g2.txt";
	int nb;
	int z;
	double c;
	
	do
	{
		printf("entrez le numéro de la grille (1-9):\t");
		z = scanf("%d", &nb);
	}while(nb > 10 && nb < 0);
	lien[5]=nb+48;
	printf("Vous avez choisis la grille : %s\n\n", lien);
	
	Init_Data(LC, LO, Grille, lien);
	
	clock_t a,b;
        
        a = clock();
	
	int grille_simple=fermerGrille(Grille, LO, LC);
	if (grille_simple)
	{
		printf("Grille facile :\n");
		Affiche_Grille(Grille);
		
	}
	
	else
	{

		printf("Lancement du backtracking\n");
		int grille_possible=Backtrack(Grille,LO,LC);

		if (grille_possible){
			printf("Il y a %d grilles possibles\n", grille_possible);
			if(grille_possible == 1) printf("C'est une grille difficile !\n");
			else printf("C'est une grille terrible !\n");
			Affiche_Grille(Grille);
		}else printf("Grille impossible\n");
	}
	b = clock();		
        c = (double)(b-a)/CLOCKS_PER_SEC;
	printf("Temps écoulé :%2.3fs\n", c);
	return 0;
}