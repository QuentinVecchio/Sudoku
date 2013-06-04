#include <stdio.h>
#include "GestionCases.h"
#include "GestionCandidats.h"
#include "resolution.h"

#include "initialisation.h"

#include "methodeResolution.h"
#include "../tui/affiche.h"
#include "time.h"
#include <stdlib.h>
#include <string.h>
int fermerGrille(int grille[9][9], L_Cases LO, L_Candidats LC[9][9])
{
	Affiche_Grille(grille);
	L_Cases parcours=LO->suivant;
	int res_Admet_Unique;
	int colonne;
	

	int a_modifie =1;
	while (parcours!=parcours->suivant && a_modifie==1)
	{
		printf("Boucle\n");
		a_modifie=0;
		do
		{
			res_Admet_Unique=Admet_Unique(LC[parcours->courant.ligne][parcours->courant.colonne]);	
			if (res_Admet_Unique!=0)
			{
				Fermer_Case(res_Admet_Unique,grille,parcours->courant,LC);
				enleve_elt_case(&LO,parcours->courant);
				grille[parcours->courant.ligne][parcours->courant.colonne] = res_Admet_Unique;
				a_modifie=1;
			}
		
			parcours=parcours->suivant;

			if (parcours==LO)parcours = parcours->suivant;
			
		}while (parcours!=parcours->suivant && parcours!=LO->suivant);
	}
	
	if (a_modifie==0)return 0;
	else return 1;
}

int nbr_solution = 0;
int solution[9][9];

int Backtrack(int grille[9][9], L_Cases LO, L_Candidats LC[9][9])
{
	L_Cases tmp = LO->suivant;
	clock_t a,b;
	double c;
	a = clock();
	resoud(grille, LO, tmp, LC);
	b = clock();
	c = (double)(b-a)/CLOCKS_PER_SEC;
	Affiche_Grille(solution);
	printf("Temps écoulé :%2.5f\n", c);
	return nbr_solution;

}

resoud(int grille[9][9], L_Cases origine, L_Cases L, L_Candidats LC[9][9])
{
	if(L == origine) {
		nbr_solution++;
		if(nbr_solution == 1)
		{
			memcpy(solution, grille, sizeof solution);
		}
		return;
	}else{
		L_Candidats c = LC[L->courant.ligne][L->courant.colonne];
		int res;
		int valeur_courant;
		do{
			if(c == NULL) return ;

			valeur_courant = c->courant;
			Fermer_Case(c->courant,grille, L->courant, LC);
			resoud(grille,origine, (L->suivant), LC);

			Ouvrir_Case(valeur_courant,grille,L->courant, LC,origine);
			
			c = LC[L->courant.ligne][L->courant.colonne]; 
			while(c->suivant && c->courant != valeur_courant) 
			{
				c = c->suivant;
			}
			c = c->suivant;
		}while(c);

	}
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