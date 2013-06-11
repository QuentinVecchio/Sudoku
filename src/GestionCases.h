#ifndef GESTIONCASE_H
#define GESTIONCASE_H
/**
 *  Gestion des cases ouvertes sous forme de liste circulaire
 * 
 * 	@author Mattthieu Clin
 * 	@version 1.0.0
 * 	@date 10/06/2013
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

/**
 * 	Creer une liste vide (null)
 * 	@return L_case, un liste de cases vide
 */
L_Cases creer_liste_vide();

/**
 * 	Permet de creer une liste contenant un élément
 * 	@param elt, un element de type T_case
 * 	@return L_Cases, une liste non vide contenant un seul element : 'elt'
 */
L_Cases creer_liste(T_Case elt);

/**
 * 	Fonction verifie si la liste est vide ou non
 * 	@param L, une liste de Cases
 * 	@return int, 1 si vide, 0 sinon
 */
int est_vide(L_Cases L);


/**
 * 	fonction d'affichage des éléments de la liste
 * 	@param L, la lsite de Cases
 */
void affiche_liste_Case(L_Cases L);

/**
 * 	Affiche une liste a de la fin au début
 * 	@param L, la liste de Cases
 */
void affiche_liste_case_reverse(L_Cases L);


/**
 * 	Ajoute un élément en fin de liste
 * 	@param *L, Liste de cases
 * 	@param elt, element a ajouter dans la liste
 */
void ajout_elt_case(L_Cases *L, T_Case elt);

/**
 *	Enlève un élément de la liste
 * 	@param *L, Liste de Cases
 * 	@param elt, element a supprimer dans la liste
 */ 
void enleve_elt_case(L_Cases *L, T_Case elt);

/**
 * 	Fonction qui verifie que 2 Listes de cases soient egaux
 * 	@param a, Liste de Cases 1
 * 	@param b, Liste de Cases 2
 * 	@return int, 1 si les listes sont égaux, 0 sinon
 */
int est_egal(T_Case a, T_Case b);

/**
 * 	Fonction qui verifie qu'une liste soit inferieur à l'autre
 * 	@param a, Liste de Cases 1
 * 	@param b, Liste de Cases 2
 * 	@return int, 1 si la premiere est inferieur à la seconde, 0 sinon
 * 	
 */
int est_inf(T_Case a, T_Case b);

/**
 * 	Fonction qui verifie l'appartenance d'un element à la liste
 * 	@param L, Liste de Cases
 * 	@param elt, element à trouver
 * 	@return int, 1 si l'element a ete trouvé, 0 sinon
 */
int appartient_liste_case(L_Cases L, T_Case elt);

/**
 * 	Fonction renvoit les cases de la ligne suivante
 * 	@param L, Liste des Cases
 * 	@return L_Cases, renvoit une liste de la ligne suivante
 */
L_Cases donne_prochaine_ligne(L_Cases L);
#endif

