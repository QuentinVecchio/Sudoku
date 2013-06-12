#include <stdio.h>
#include "GestionCases.h"
#include "GestionCandidats.h"
#include "resolution.h"

#include "initialisation.h"

#include "methodeResolution.h"
#include <stdlib.h>
#include <string.h>
int fermerGrille(int grille[9][9], L_Cases LO, L_Candidats LC[9][9])
{
        Affiche_Grille(grille);
        L_Cases parcours=LO->suivant;
        int res_Admet_Unique;
        int colonne;
	int v;
        
		
        int a_modifie =1;
        while (parcours!=parcours->suivant && a_modifie==1)
        {
                a_modifie=0;
                do
                {
                       res_Admet_Unique=Admet_Unique(LC, parcours->courant);
						
                        if (res_Admet_Unique!=0)
                        {
				Fermer_Case(res_Admet_Unique,grille,parcours->courant,LC);

				if(longueur_liste(LC[parcours->courant.ligne][parcours->courant.colonne]) > 0)
				{

					for(v=1; v<10; v++)	
					{
						suppr_element_Candidats( &LC[parcours->courant.ligne][parcours->courant.colonne], v);
					}

				}
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

        resoud(grille, LO, tmp, LC);
	int i,j;
	for(i=0;i<9;i++)
		for(j=0;j<9;j++)
			grille[i][j] = solution[i][j];
        return nbr_solution;
}

void resoud(int grille[9][9], L_Cases origine, L_Cases L, L_Candidats LC[9][9])
{
        if(L == origine) {
                nbr_solution++;
                if(nbr_solution == 1)
                {
                        memcpy(solution, grille, sizeof solution);
                }
                return;
        }
        else
	{
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


