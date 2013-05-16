/*
 * 	Gestion de la liste chaînée représentant les candidats d'un case donnée.
 * 	Les éléments sont rangés dans l'ordre croissant
 * 
 * 	@author Mattthieu Clin
 * 	@version 1.0.0
 * 	@date 08/05/2013
 * 
 */

// Structure représentant un nombre candidats pour une case
typedef struct candidat
{
	int courant;
	struct candidat * suivant;
} Candidat;

typedef Candidat * L_Candidats;

/*
 * 	Creer une liste contenant un seul élément
 */
L_Candidats creer_element(int elt);

/*
 * Affiche l'ensemble des candidats 
 */
void affiche_liste(L_Candidats L);

/*
 * 	Ajout un élément dans la liste dans l'ordre croissant
 */
void ajout_element(L_Candidats L, int elt);

/*
 * 	Supprime l'élément de la liste
 */
void supprimer_element(L_Candidats L, int elt);

/*
 * 	Renvoit 1 si l'élément appartient à la liste, 0 sinon
 */
int appartient_liste(L_Candidats L, int elt);

/*
 * 	Renvoit la longueur de la chaine
 */
int longueur_liste(L_Candidats L);

