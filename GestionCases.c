#include <stdio.h>
#include <stdlib.h>
#include "GestionCases.h"

L_Cases creer_liste(T_Case elt)
{
	L_Cases L;
	L= (L_Cases) malloc(sizeof(Cases));
	L->courant = elt;
	L->suivant = L;
	
	return L;
}

void affiche_liste(L_Cases L)
{
	L_Cases it;
	printf("ligne: %d, colonne: %d\n", L->courant.ligne, L->courant.colonne);
	for ( it = L->suivant; it != L; it = it->suivant )
	{
			printf("ligne: %d, colonne: %d\n", it->courant.ligne, it->courant.colonne);
	}
}

void ajout_element(L_Cases L, T_Case elt)
{
	L_Cases i = L;

	if(L->suivant == L)
	{
		printf("debut = fin\n");
		if(L->courant.ligne > elt.ligne)
		{
			printf("ajout\n");
			L_Cases n = creer_liste(L->courant);
			L->courant = elt;
			n->suivant = L;
			L->suivant = n;
		}
		else
		{
			if(L->courant.colonne > elt.colonne)
			{
				L_Cases n = creer_liste(L->courant);
				n->suivant = L;
				L->courant = elt;
				L->suivant = n;
			}
		}
		return ;
	}
	
	
	do
	{
		if (i->suivant == L)
		{
			printf("dernier element\n");
			if(i->courant.colonne > elt.colonne)
			{
				L_Cases n = creer_liste(i->courant);
				n->suivant = n->suivant;
				i->suivant = n;
				i->courant = elt;
				break;
			}
			else
			{
				L_Cases n = creer_liste(elt);
				n->suivant = L;
				i->suivant = n;
				break;	
			}
		}
		else if(i->courant.ligne == elt.ligne)
		{
				printf("même ligne \n");
			if(i->suivant->courant.ligne == elt.ligne)
			{
				printf("suivant même ligne\n");
				if(elt.colonne > i->courant.colonne && elt.colonne < i->suivant->courant.colonne)
				{
					printf("entre deux\n");
					L_Cases n = creer_liste(elt);
					n->suivant = i->suivant;
					i->suivant = n;
					break;
				}
				else if(elt.colonne < i->courant.colonne)
				{
					printf("colonne suivante plus grande que elt.colonne %d %d\n", elt.ligne, elt.colonne);
					L_Cases n = creer_liste(i->courant);
					i->courant = elt;
					n->suivant = i->suivant;
					i->suivant = n;
					break;
				}
				else
				{
						printf("ou suis je ?===================================\n");
				}
			}
			else
			{
				printf("ouh ouh !!!!!!\n");
				L_Cases n = creer_liste(i->courant);
				i->courant = elt;
				n->suivant = i->suivant;
				i->suivant = n;
				break;
			}
		}
		else if(elt.ligne > i->courant.ligne && elt.ligne < i->suivant->courant.ligne)
		{
			printf("je suis la ===><<<<<<<<<\n");
			L_Cases n = creer_liste(elt);
			n->suivant = i->suivant;
			i->suivant = n;
				
			break;
		}
	}while((i = i->suivant) != L);

}



main()
{
		T_Case c;
		c.ligne = 5;
		c.colonne =8;
		L_Cases a = NULL;
		a = creer_liste(c);

		ajout_element(a, (T_Case){0,0});
		printf("debut\n");
		ajout_element(a, (T_Case){0,1});		
		printf("\n\n\naffiche\n");
		affiche_liste(a);
	return;
		ajout_element(a, (T_Case){0,5});
		ajout_element(a, (T_Case){0,6});
		ajout_element(a, (T_Case){0,7});
		ajout_element(a, (T_Case){1,2});
		ajout_element(a, (T_Case){1,3});
		ajout_element(a, (T_Case){1,4});
		ajout_element(a, (T_Case){1,6});
		
		ajout_element(a, (T_Case){1,8});
		ajout_element(a, (T_Case){2,1});
		ajout_element(a, (T_Case){2,2});
		ajout_element(a, (T_Case){2,3});
		ajout_element(a, (T_Case){2,5});
		ajout_element(a, (T_Case){2,6});
		ajout_element(a, (T_Case){3,0});
		ajout_element(a, (T_Case){3,2});
		ajout_element(a, (T_Case){3,6});
		
		
		printf("affiche\n");
		affiche_liste(a);
}