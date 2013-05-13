/*

 * 
 * 	@author Mattthieu Clin
 * 	@version 1.0.0
 * 	@date 11/05/2013
 * 
 */

typedef struct T_Case
{
	int ligne;
	int colonne;
} T_Case;

typedef struct cases
{
	T_Case 		courant;
	struct cases * 	suivant;
} Cases;

typedef Cases* L_Cases;

L_Cases creer_liste(T_Case elt);

void affiche_liste(L_Cases L);

void ajout_element(L_Cases L, T_Case elt);

void eleve_element(L_Cases L, T_Case elt);

int est_egal(T_Case a, T_Case b);