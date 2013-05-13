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
	
	while(i->suivant != L) i= i->suivant;
	
	L_Cases tmp = creer_liste(elt);
	tmp->suivant = L;
	i->suivant = tmp;

}

void eleve_element(L_Cases L, T_Case elt)
{
	L_Cases i = L;
	
	if(est_egal(L->courant, elt))
	{
		L->courant = L->suivant->courant;
		L->suivant = L->suivant->suivant;
		free(i->suivant);
	}
	while(i->suivant != L && !est_egal(i->suivant->courant,elt)) i = i->suivant;
	
	if(est_egal(i->suivant->courant,elt))
	{
		L_Cases tmp = i->suivant;
		i->suivant = i->suivant->suivant;
		free(tmp);
	}
}

int est_egal(T_Case a, T_Case b)
{
	return (a.ligne == b.ligne && a.colonne == b.colonne);
}

// main()
// {
// 		T_Case c;
// 		c.ligne = 5;
// 		c.colonne =8;
// 		L_Cases a = NULL;
// 		a = creer_liste(c);
// 
// 		ajout_element(a, (T_Case){0,5});
// 		ajout_element(a, (T_Case){0,6});
// 		ajout_element(a, (T_Case){0,7});
// 		ajout_element(a, (T_Case){1,2});
// 		ajout_element(a, (T_Case){1,3});
// 		ajout_element(a, (T_Case){1,4});
// 		ajout_element(a, (T_Case){1,6});
// 		eleve_element(a, (T_Case){1,6});
// 		
// 		printf("affiche\n");
// 		affiche_liste(a);
// }