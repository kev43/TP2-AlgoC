/********************************************************************/
/*** VIVIER David													*/
/*** VARAGNAT Kévin													*/
/*** 31/01/2017											            */
/*** Exécuter ./tp1-ex4 pour utiliser le programme 					*/
/*** 																*/
/********************************************************************/
#include <stdio.h>
/*

David Vivier et Kévin Varagnat
01/02/2017
*/


#define TAILLE 50

typedef struct mots mots ;
struct mots{
	char libelle_mot[10];
	int type_mot;
}


int main() {
	
	mots dictionnaire[10]={{"le",0},{"chat",2},{"souris",2},{"mange",3},{"la",0},{"petite",1},{".",5},{"bleu",1},{"dort",3},{"julie",4},};

	return 0;
}
