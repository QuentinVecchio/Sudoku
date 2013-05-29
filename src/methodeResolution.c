#include <stdio.h>
#include "GestionCases.h"
#include "GestionCandidats.h"
#include "resolution.h"

#include "initialisation.h"

#include "methodeResolution.h"
#include "../tui/affiche.h"
int fermerGrille(int grille[9][9], L_Cases LO, L_Candidats LC[9][9])
{
	L_Cases parcours=LO;
	int res_Admet_Unique;
	
	res_Admet_Unique=Admet_Unique(LC[LO->courant.ligne][parcours->courant.colonne]);
	while (parcours)
	{
	if (res_Admet_Unique!=0)Fermer_Case(res_Admet_Unique,grille,parcours->courant,LC);
	
		parcours=parcours->suivant;
	}
}

int Backtrack(int grille[9][9], L_Cases LO, L_Candidats LC[9][9])
{
	return 1;
}

// int main(){
// 	printf("Bienvenue !!!\n");
// 	int Grille[9][9]={{0}};
// 	L_Candidats  LC[9][9]= {{NULL}};
// 	L_Cases LO = creer_liste_vide();
// 	char lien[] = "../res/g1.txt";
// 
// 	Init_Data(LC, LO, Grille, lien);
// 	Affiche_Grille(Grille);
// }