#ifndef GESTIONCASE_H
#define GESTIONCASE_H
/*
 *  Gestion des cases ouvertes sous forme de liste circulaire
 * 
 * 	@author Mattthieu Clin
 * 	@version 1.0.1
 * 	@date 14/05/2013
 * 
 */

typedef struct T_Case
{
	int ligne;
	int colonne;
} T_Case;


typedef struct cases
{
	struct cases *  pred;
	T_Case          courant;
	struct cases *  suivant;
} Cases;

typedef Cases* L_Cases;

/*
 * Creer une liste vide (null)
 */
L_Cases creer_liste_vide();

/*
 * 	Permet de creer une liste contenant un élément
 */
L_Cases creer_liste(T_Case elt);

/*
 *  Renvoit 1 si vide, 0 sinon
 */
int est_vide(L_Cases L);


/*
 * 	Affiche les éléments de la liste
 */
void affiche_liste_Case(L_Cases L);


void affiche_liste_case_reverse(L_Cases L);


/*
 * 	Ajoute un élément en fin de liste
 */
void ajout_elt_case(L_Cases *L, T_Case elt);

/*
 *	Enlève un élément de la liste
 */ 
void enleve_elt_case(L_Cases *L, T_Case elt);

/*
 * 	Compare deux cases, renvoit 1 si égal, 0 sinon
 */
int est_egal(T_Case a, T_Case b);

int est_inf(T_Case a, T_Case b);

int appartient_liste_case(L_Cases L, T_Case elt);

L_Cases donne_prochaine_ligne(L_Cases L);
#endif

