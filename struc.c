struct T_Case
{
	int ligne;
	int colonne;
};

typedef struct T_Case T_Case;

struct L_Cases 
{
	T_Case 		courant;
	struct L_Cases * 	suivant;
};

typedef struct L_Cases L_Cases;

int Grille[9][9];

//L_Candidats LC[9][9];

struct L_Case
{
		T_Case		caseCourante;
		struct L_Case * 	suivant;
};

typedef struct L_Case L_Case;