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

#define TAILLE_DICO 10
/*

David Vivier et Kévin Varagnat
01/02/2017
*/


typedef struct mots mots ;
struct mots{
	char libelle[10];
	int type;
};


                           

int main() {
	
	mots dictionnaire[TAILLE_DICO]={{"le",0},{"chat",2},{"souris",2},{"mange",3},{"la",0},{"petite",1},{".",5},{"bleu",1},{"dort",3},{"julie",4},{"joue",3},{"joli",1}};
	int i = 0, j = 0;
	char phrase[1000] = "le ,joli chat joue.";
	char *tab_mots[50] ;
	
	const char separateur[] = " ,;";
	int nb_mots = 0;

	// pointe le mot courant
	char *pt = NULL;

	pt = strtok(phrase, separateur); // pt pointe sur le premier morceau
   	
   	// le type du mot courant
   	int type_mot = 0;

   	// l'état de l'automate
   	int etat = 0;

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
      
      // on détermine la classe grammaticale du mot
      for (i = 0; i < TAILLE_DICO; i++) {
      	if (strcmp(dictionnaire[i].libelle, pt) == 0) {
      		// on a trouvé le mot
      		type_mot = dictionnaire[i].type;
      		printf("type_mot=%d\n", type_mot);
      		break;
      	}
      }
      if (i == TAILLE_DICO) {
      	// si on a parcouru tout le dico
      	// sans trouver le mot : la phrase est incorrecte
      	etat = 8;
      	printf("mot inconnu\n");
      	break;
      }

      // détermination du nouvel état
      etat = table_transitions[etat][type_mot];
      printf("nouvel état = %d\n", etat);

      // on récupère le mot suivant
      pt = strtok(NULL, separateur);
      nb_mots++ ;
	}
	
	printf("fin - etat = %d\n", etat);
	

	return 0;
}
