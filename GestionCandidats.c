#include <stdio.h>
#include <stdlib.h>
#include "GestionCandidats.h"


Liste creer_element(int elt)
{
	Liste L;
	L= (Liste) malloc(sizeof(Candidat));
	L->courant = elt;
	L->suivant = NULL;
	
	return L;
}

void affiche_liste(Liste L)
{
	if(L != NULL)
	{
		printf("%d ", L->courant);
		if(L->suivant != NULL)	affiche_liste(L->suivant);
		else printf("\n");
	}
}

void ajout_element(Liste L, int elt)
{
	if(L != NULL)
	{
		// Pour la tête de liste, insertion en tête de liste
		if(L->courant > elt)
		{
			Liste tmp;
			tmp = (Liste) malloc(sizeof(Candidat));
			tmp->suivant = L->suivant;
			tmp->courant = L->courant;
			L->courant = elt;
			L->suivant = tmp;
		}
		else
		{
			if(L->suivant != NULL)
			{
				// Si le suivant est plus grand, on insère avant
				if(L->suivant->courant > elt)
				{
					Liste tmp = creer_element(elt);
					tmp->suivant = L->suivant;
					L->suivant = tmp;
				}
				// Element suivant de la chaîne
				else ajout_element(L->suivant, elt);
			}
			// Arrivé en fin de liste, on insère
			else L->suivant = creer_element(elt);	
		}
	}
}

void supprimer_element(Liste L, int elt)
{
	if(L != NULL)
	{
		// Pour la tête de liste
		if(L->courant == elt)
		{
			Liste tmp = L->suivant;
			L->courant = tmp->courant;
			L->suivant = tmp->suivant;	
			free(tmp);
		}
		else if(L->suivant != NULL)
		{
			//Si c'est élément suivant, on le supprime
			if(L->suivant->courant == elt)
			{
				Liste tmp = L->suivant;
				L->suivant = tmp->suivant;
				free(tmp);
			}
			// test du prochain élément, si > elt alors l'elt a supprimer n'existe pas
			else if(L->suivant->courant <= elt)	supprimer_element(L->suivant, elt);
		}
	}
}

int appartient_liste(Liste L, int elt)
{
	if(L != NULL)
	{
		if(L->courant == elt) return 1;
		// si il existe un suivant et que l'élément est plus petit (si plus grand alors élément n'existe pas
		else if(L->suivant != NULL && L->suivant->courant <= elt) return appartient_liste(L->suivant, elt);
		else return 0;	
	}
}

int longueur_liste(Liste L)
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

main()
{
		return 1;
}