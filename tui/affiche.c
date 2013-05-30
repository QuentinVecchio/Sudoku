#include <stdio.h>

void Affiche_Grille(int Grille[9][9])
{
	int i,j;
	for (i=0;i<9;i++)
	{
		if(i%3 ==0) printf("-----------------------------\n");
		for (j=0;j<9;j++)
		{
			if(j%3 ==0) printf("| %d ",Grille[i][j]);
			else printf(" %d ",Grille[i][j]);
		}
			if(j%3 ==0)printf("|\n");
			else printf("\n");
		
		
	}
	 printf("-----------------------------\n");
}