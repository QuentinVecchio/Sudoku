#include <stdio.h>
#include "GestionCases.h"
#include "GestionCandidats.h"
#include "resolution.h"

#include "initialisation.h"

#include "methodeResolution.h"
#include "../tui/affiche.h"
int fermerGrille(int grille[9][9], L_Cases LO, L_Candidats LC[9][9])
{
	Affiche_Grille(grille);
	L_Cases parcours=LO->suivant;
	int res_Admet_Unique;
	int colonne;
/*	for(colonne = 0; colonne < 9; colonne++)*/
	

	int a_modifie =1;
	while (parcours!=parcours->suivant && a_modifie==1)
	{
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

int Backtrack(int grille[9][9], L_Cases LO, L_Candidats LC[9][9])
{
	L_Cases tmp = LO->suivant;
	//Affiche_Grille(grille);
	
	int l = 0;
	return resolve_ligne(grille, LO, tmp, LC, l);
// 	for(l=0; l <1; l++)
// 	{
// 		printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!LANCEMENT !!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
// 		if(resolve_ligne(grille, LO, tmp, LC, l) == 0)
// 		{
// 				printf("ERREUR !\n");
// 				break;
// 		}else{
// 			tmp = donne_prochaine_ligne(tmp);
// 		}
// 		
// 		
// 	}
	

	//printf("valeur!!!: %d\n",appartient_liste(LC[0][0], 54));

}

int resolve_ligne(int grille[9][9], L_Cases origine, L_Cases L, L_Candidats LC[9][9], int ligne)
{
// 	printf("Appel de fonction !\n");
// 	Affiche_Grille(grille);
	int l = ligne;
	int colonne;

// 	for(colonne = 0; colonne < 9; colonne++)
// 	{
// 		printf("###Affichage de la ligne %d colonne %d\n", l, colonne);
// 		affiche_liste_Candidats(LC[l][colonne]);
// 	}
	if(L == origine) return 1;
	else{
// 		printf("Case %d %d \n",L->courant.ligne,L->courant.colonne);
		L_Candidats c = LC[L->courant.ligne][L->courant.colonne];
		int res;
// 		printf("Etude de:");
// 		affiche_liste_Candidats(c);
// 		printf("\n");

		do{
// 			printf("boucle\n");
			if(c == NULL) return 0;
// 			printf("%d\n\n", c->courant);
			int valeur_courant = c->courant;
			Fermer_Case(c->courant,grille, L->courant, LC);
			res=resolve_ligne(grille,origine, (L->suivant), LC, ligne);
// 			printf("Retour de resolve avec %d Case %d %d\n", res, L->courant.ligne,L->courant.colonne);
			if(!res)
			{

				Ouvrir_Case(valeur_courant,grille,L->courant, LC,origine);
				
				c = LC[L->courant.ligne][L->courant.colonne]; 
				while(c->suivant && c->courant != valeur_courant) 
				{
					c = c->suivant;
				}
// 				for(colonne = 0; colonne < 9; colonne++)
// 				{
// 					printf("###Affichage de la ligne %d colonne %d\n", l, colonne);
// 					affiche_liste_Candidats(LC[l][colonne]);
// 				}
// 				printf("---------------------------------------------------------------------");
// 				printf("---------------------------------------------------------------------");
// 				printf("%d %d\n",valeur_courant, c->courant);

				c = c->suivant;
			}else{
					//Fermer_Case
// 					printf("€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€€e€");
					return res;
			}
		}while(c);
// 		printf("Retour fin \n");
		return 0;
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