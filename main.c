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
	int i=0 ;
	char phrase[1000] = "le ,joli chat joue.";
	char *tab_mots[50] ;
	
	const char separateur[] = " ,;";
	char *pt;
   
	pt = strtok(phrase, separateur); // pt pointe sur le premier morceau
   
	while( pt != NULL ) //tant qu'il reste des mots
	{
		
      printf( " %s\n", pt );
      //strcpy(tab_mots[i] , pt);
      
      pt = strtok(NULL, separateur);
      i++ ;
	}
	
	
	

	return 0;
}
