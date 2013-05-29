#include <stdio.h>

void Affiche_Grille(int Grille[9][9])
{
	int i,j;
	for (i=0;i<9;i++)
	{
		for (j=0;j<9;j++)
		{
			printf(" %d ",Grille[i][j]);
		}
		printf("\n");	
	}
}