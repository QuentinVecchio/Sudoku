#ifndef GestionCandidath
#define GestionCandidath

/*
 * 	Gestion de la liste chaînée représentant les candidats d'un case donnée.
 * 	Les éléments sont rangés dans l'ordre croissant
 * 
 * 	@author Mattthieu Clin
 * 	@version 1.0.0
 * 	@date 10/06/2013
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
 * 	@param elt, l'élément à ajouter dans la nouvelle liste crée
 * 	@return L_Candidats, la liste nouvellement crée avec l'élement elt dedans
 */
L_Candidats creer_element(int elt);

/*
 * 	Affiche l'ensemble des candidats 
 * 	@param L, la liste a afficher
 */
void affiche_liste_Candidats(L_Candidats L);

/*
 * 	Ajout un élément dans la liste dans l'ordre croissant
 * 	@param *L, une pointeur sur la liste ou l'on ajoute l'élément
 * 	@param elt, l'élément à ajouter dans la liste
 */
void ajout_element_Candidats( L_Candidats *L, int elt);



/*
 * 	Renvoit 1 si l'élément appartient à la liste, 0 sinon
 * 	@param L, la liste ou devrait se trouver la valeur
 * 	@param elt, l'élément dont on voudrait connaitre son appartenance à la grille
 * 	@return 1, si l'élément appartient à la liste
 * 	@return 0, si l'élément n'appartient pas à la liste
 */
int appartient_liste(L_Candidats L, int elt);


/*
 * 	Supprime l'élément de la liste
 * 	@param *L, un pointeur sur la liste ou l'on veut supprimer un élément
 * 	@param elt, l'élément a supprimer de la liste
 */
void suppr_element_Candidats( L_Candidats *L, int elt);

/*
 * 	Renvoit la longueur de la liste
 * 	@param L, la liste dont on veut connaitre la longueur
 * 	@return int, la longueur de la chaine.
 */
int longueur_liste(L_Candidats L);

/*
 * 	Renvoit la valeur contenu dans LC s'il n'y a qu'un seul element dans la liste, 0 sinon
 * 	@param L, la liste dont on veut l'element
 * 	@return int, le candidat unique de la liste
 */
int Admet_Unique_liste(L_Candidats L);


#endif