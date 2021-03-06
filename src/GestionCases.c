#include <stdio.h>
#include <stdlib.h>
#include "GestionCases.h"

L_Cases creer_liste_vide()
{
        L_Cases L = (L_Cases) malloc(sizeof(Cases));
        L->suivant = L;
        L->pred = L;
        return L;
}

L_Cases creer_liste(T_Case elt)
{
        L_Cases L = (L_Cases) malloc(sizeof(Cases));
        L_Cases tmp = creer_liste_vide();
        L->suivant = tmp;
        L->pred = tmp;
        tmp->suivant = L;
        tmp->pred = L;
        tmp->courant = elt;
        return L;
}

int est_vide(L_Cases L)
{
        return L->suivant == L->pred;
}


void affiche_liste_case(L_Cases L)
{
        printf("Affiche\n");
        if(L != NULL)
        {
                L_Cases tmp;
                for(tmp = L->suivant; tmp != L; tmp = tmp->suivant)printf("%d %d\n",tmp->courant.ligne, tmp->courant.colonne);
        }
        printf("Fin affiche \n");
}

void affiche_liste_case_reverse(L_Cases L)
{
        printf("Affiche reverse\n");
        if(L != NULL)
        {
                L_Cases tmp;
                for(tmp = L->pred; tmp != L; tmp = tmp->pred)printf("ligne %d  colonne %d\n",tmp->courant.ligne, tmp->courant.colonne);
        }
        printf("Fin affiche \n");
}


void ajout_elt_case(L_Cases *L, T_Case elt)
{
        if((*L) != NULL)
        {
                L_Cases tmp = (L_Cases) malloc(sizeof(Cases));
                (*L)->pred->suivant = tmp;
                tmp->courant = elt;
                tmp->pred = (*L)->pred;
                tmp->suivant = (*L);
                (*L)->pred = tmp;
        }
}

void enleve_elt_case(L_Cases *L, T_Case elt)
{
        L_Cases i = (*L)->suivant;
        while(i != (*L) && est_inf(i->courant, elt)) 
        {
              
                i = i->suivant;
        }
        if(est_egal(i->courant, elt))
        {
                L_Cases tmp = i;
                i->pred->suivant = tmp->suivant;
                tmp->suivant->pred = tmp->pred;
                free(tmp);
        }
}

int est_egal(T_Case a, T_Case b)
{
        return (a.ligne == b.ligne && a.colonne == b.colonne);
}

int est_inf(T_Case a, T_Case b)
{
        return a.ligne < b.ligne || (a.ligne == b.ligne && a.colonne < b.colonne);
}

int appartient_liste_case(L_Cases L, T_Case elt)
{
	if(!L) return 0;
		L_Cases tmp = L->suivant;
		
		while(!est_egal(elt, tmp->courant) && tmp != L) tmp = tmp->suivant;
		if(est_egal(elt, tmp->courant)) return 1;
		else return 0;
		
}

L_Cases donne_prochaine_ligne(L_Cases L)
{
	L_Cases tmp = L;
	while(tmp && tmp->courant.ligne == L->courant.ligne) tmp = tmp->suivant;
	return tmp;
}
