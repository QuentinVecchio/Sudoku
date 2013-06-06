#ifndef JEUX_H
#define JEUX_H
/*********************************************************************************************************************************************
*       Partie graphique Jeux Header               	                                                                                     *
*       Prototypes                                                                                                                           *
*       Fait par Quentin Vecchio                                                                                                             *
*       25 mai 2013                                                                                                                          *
*********************************************************************************************************************************************/
void jouer(GtkWidget *widget, gpointer data);
void fin();
int fctCharChif(const gchar *str);
void* compteur(void *data);
void retourMenuJeux();
void retourMenuJeux2();
#endif
