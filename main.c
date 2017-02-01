/********************************************************************/
/*** VIVIER David													*/
/*** VARAGNAT Kévin													*/
/*** 31/01/2017											            */
/*** Exécuter ./tp1-ex4 pour utiliser le programme 					*/
/*** 																*/
/********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*

David Vivier et Kévin Varagnat
01/02/2017
*/


typedef struct mots mots ;
struct mots{
	char libelle_mot[10];
	int type_mot;
};


                           

int main() {
	
	mots dictionnaire[10]={{"le",0},{"chat",2},{"souris",2},{"mange",3},{"la",0},{"petite",1},{".",5},{"bleu",1},{"dort",3},{"julie",4}};
	int i = 0, j = 0;
	char phrase[1000] = "le ,joli chat joue.";
	char *tab_mots[50] ;
	
	const char separateur[] = " ,;";
	char *pt;
   
	pt = strtok(phrase, separateur); // pt pointe sur le premier morceau
   	

	int table_transitions[8][6] = {};

	// remplissage de la table de transition
	for (j = 0; j < 8; j++) {
		for (i = 0; i < 6; i++) {
			table_transitions[j][i] = 8;
		}
	}

	table_transitions[0][0] = 1;
	table_transitions[0][4] = 4;

	table_transitions[1][1] = 1;
	table_transitions[1][2] = 2;

	table_transitions[2][1] = 2;
	table_transitions[2][3] = 3;

	table_transitions[3][0] = 5;
	table_transitions[3][4] = 7;
	table_transitions[3][5] = 9;

	table_transitions[4][3] = 3;
	
	table_transitions[5][1] = 5;
	table_transitions[5][2] = 6;

	table_transitions[6][1] = 6;
	table_transitions[6][5] = 9;

	table_transitions[7][5] = 9;


	while( pt != NULL ) //tant qu'il reste des mots
	{
		
      printf( " %s\n", pt );
      //strcpy(tab_mots[i] , pt);
      
      pt = strtok(NULL, separateur);
      i++ ;
	}
	
	
	

	return 0;
}
