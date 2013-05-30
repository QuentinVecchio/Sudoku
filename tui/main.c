#include <stdio.h>
#include "../src/GestionCandidats.h"
#include "../src/GestionCases.h"
#include "../src/initialisation.h"
#include "affiche.h"

void t(L_Cases i, L_Cases origine)
{
	printf("%d %d\n", i->courant.ligne, i->courant.colonne);
	if(i->suivant != origine) t(i->suivant, origine);
}


int main()
{
	printf("Bienvenue dans le logiciel de résolution de sudoku\n");
	int Grille[9][9]={{0}};
	L_Candidats  LC[9][9]= {{NULL}};
	L_Cases LO = creer_liste_vide();
	char lien[] = "res/g3.txt";

	Init_Data(LC, LO, Grille, lien);

	int ligne, colonne;

// 	for(ligne = 0; ligne <1; ligne ++)
// 	{
// 			for(colonne = 0; colonne < 9; colonne++)
// 			{
// 				printf("Affichage de la ligne %d colonne %d\n", ligne, colonne);
// 				affiche_liste_Candidats(LC[ligne][colonne]);
// 			}
// 	}
// 	Fermer_Case(3, Grille, (T_Case){0,0}, LC);
// 	
// 	//printf("valeur: %d\n",appartient_liste_case(LO, (T_Case){0,2}));
// 	//return;
// 	Ouvrir_Case(3, Grille, (T_Case){0,0}, LC,LO);
// 		printf("\n\n");
// 	for(ligne = 0; ligne <1; ligne ++)
// 	{
// 			for(colonne = 0; colonne < 9; colonne++)
// 			{
// 				printf("Affichage de la ligne %d colonne %d\n", ligne, colonne);
// 				affiche_liste_Candidats(LC[ligne][colonne]);
// 			}
// 	}
	
//	Affiche_Grille(Grille);
	/*Fermer_Case(3, Grille, (T_Case){0,0}, LC);
	printf("\n\nFermer !!!!!!!!!!!!!!!!!\n\n\n");
	for(ligne = 0; ligne <1; ligne ++)
	{
			for(colonne = 0; colonne < 9; colonne++)
			{
				printf("Affichage de la ligne %d colonne %d\n", ligne, colonne);
				affiche_liste_Candidats(LC[ligne][colonne]);
			}
	}
	Affiche_Grille(Grille);
	Ouvrir_Case(3, Grille, (T_Case){0,0}, LC);
	
	printf("\n\nOUVERT !!!!!!!!!!!!!!!!!\n\n\n");
	Affiche_Grille(Grille);
	for(ligne = 0; ligne <1; ligne ++)
	{
			for(colonne = 0; colonne < 9; colonne++)
			{
				printf("Affichage de la ligne %d colonne %d\n", ligne, colonne);
				affiche_liste_Candidats(LC[ligne][colonne]);
			}
	}*/
	
	
	
	
// 				printf("Affichage de la ligne %d colonne %d\n", 0, 0);
// 				affiche_liste_Candidats(LC[0][4]);
// 				suppr_element_Candidats(&LC[0][4], 3);
// 				printf("Affichage de la ligne %d colonne %d\n", 0, 0);
// 				affiche_liste_Candidats(LC[0][4]);

// 	L_Cases tmp = LO;
// 	t(tmp->suivant,LO);
// // 	
	//return;
	
	//affiche_liste_Candidats(LC[0][0]);

	//Fermer_Case(8, Grille, (T_Case){0,0}, LC);
	
	Backtrack(Grille, LO, LC);
	return 0;
}