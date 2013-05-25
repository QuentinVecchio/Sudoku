#include <stdio.h>
#include <stdlib.h>
#include "GestionCandidats.h"


L_Candidats  creer_element(int elt)
{
	L_Candidats L;
	L= (L_Candidats) malloc(sizeof(Candidat));
	L->courant = elt;
	L->suivant = NULL;
	
	return L;
}

void affiche_liste_Candidats(L_Candidats L)
{
	if(L != NULL)
	{
		printf("%d ", L->courant);
		if(L->suivant != NULL)	affiche_liste_Candidats(L->suivant);
		else printf("\n");
	}
}

void ajout_element_Candidats( L_Candidats *L, int elt)
{
	if((*L) == NULL)
	{
		(*L) = (L_Candidats) malloc(sizeof(Candidat));
		(*L)->courant = elt;
		(*L)->suivant = NULL;
	}else{
		L_Candidats i = (*L);
		while(i->courant < elt && i->suivant) i = i->suivant;
		
		if(i == (*L))
		{
			if(i->courant > elt)
			{
				L_Candidats tmp = creer_liste(elt);
				tmp->suivant = i;
				(*L) = tmp;
			}else{
				L_Candidats tmp = creer_liste(elt);
				tmp->suivant = i->suivant;
				i->suivant = tmp;
			}
		}
		else
		{
			if(i->courant > elt)
			{
				L_Candidats tmp = creer_liste(i->courant);
				i->courant = elt;
				tmp->suivant = i->suivant;
				i->suivant = tmp;
			}else
			{
				L_Candidats tmp = creer_liste(elt);
				i->suivant = tmp;
			}
		}
	}
}

void suppr_element_Candidats( L_Candidats *L, int elt)
{
	if((*L) != NULL)
	{
		L_Candidats i = (*L);
		while(i->courant != elt && i->suivant && i->suivant->courant != elt) i = i->suivant;
		
		if(i == (*L))
		{
			L_Candidats tmp = (*L);
			(*L) = (*L)->suivant;
			free(tmp);
		}
		else
		{
			if(i && i->suivant)
			{
				printf("oui %d \n", i->courant);
				L_Candidats tmp = i->suivant;
				i->suivant = tmp->suivant;
				free(tmp);
			}
		}
	}
}

int appartient_liste(L_Candidats L, int elt)
{
	if(L != NULL)
	{
		if(L->courant == elt) return 1;
		// si il existe un suivant et que l'élément est plus petit (si plus grand alors élément n'existe pas
		else if(L->suivant != NULL && L->suivant->courant <= elt) return appartient_liste(L->suivant, elt);
		else return 0;	
	}
}

int longueur_liste(L_Candidats L)
{
	int l = 0;
	
	if(L != NULL)
	{
		while(L)
		{
			l++;
			L = L->suivant;
		}		
	}

	return l;
}