#ifndef RESOUDRE_H
#define RESOUDRE_H
/*********************************************************************************************************************************************
*       Partie graphique Resoudre Header												     *
*       Prototypes															     *
*       Fait par Quentin Vecchio                                                                                                             *
*       19 mai 2013															     *
*********************************************************************************************************************************************/
void choisirFichier(GtkWidget *widget, gpointer data);
void dialogBoxChoixFichier(GtkWidget *widget, gpointer data);
void affiche(int grille1[9][9], int grille2[9][9], float tps, int niv,int nbSolution);
void retourMenu();
#endif




