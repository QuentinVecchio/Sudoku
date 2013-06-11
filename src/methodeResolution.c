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
			printf("Boucle\n\n");
                a_modifie=0;
                do
                {
					printf("=> Case courante %d %d\n", parcours->courant.ligne, parcours->courant.colonne);
					affiche_liste_Candidats(LC[parcours->courant.ligne][parcours->courant.colonne]);
					//printf("=>Case %d %d\n", parcours->courant.ligne, parcours->courant.colonne);
                       res_Admet_Unique=Admet_Unique(LC, parcours->courant);
						
                        if (res_Admet_Unique!=0)
                        {
							printf("Case %d %d, valeur %d\n", parcours->courant.ligne, parcours->courant.colonne, res_Admet_Unique);
							Fermer_Case(res_Admet_Unique,grille,parcours->courant,LC);
							int v = 0;
							*LC[parcours->courant.ligne, parcours->courant.colonne] = NULL;
// 							for(v=0; v<10; v++)	suppr_element_Candidats(LC[parcours->courant.ligne, parcours->courant.colonne],v);
							//suppr_element_Candidats(&LC[parcours->courant.ligne, parcours->courant.colonne],res_Admet_Unique);
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


