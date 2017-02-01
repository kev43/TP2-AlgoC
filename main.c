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

#define TAILLE_DICO 50
#define TAILLE_MAX_PHRASE 1000
/*

David Vivier et Kévin Varagnat
01/02/2017
*/


typedef struct mot mot ;
struct mot{
	char libelle[10];
	int type;
};




void remplir_table_transition(int table_transitions[][6]) {
	int i = 0, j = 0;

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
}

int verifier_syntaxe_phrase(char phrase[], mot dictionnaire[], int table_transitions[][6]) {

	int i = 0;

	const char separateur[] = " ,;";
	int nb_mots = 0;


	// pointe le mot courant
	char *pt = NULL;
   	
   	// le type du mot courant
   	int type_mot = 0;

   	// l'état de l'automate
   	int etat = 0;


   	if (strlen(phrase) == 0) {
   		printf("Phrase vide.\n");
   		return 8;
   	}

	// on cherche le premier point de la chaîne
	for (i = 0; i < strlen(phrase);i++) {
		if (phrase[i] == '.') {
			if (i > TAILLE_MAX_PHRASE - 3) {
				// la phrase est trop longue pour insérer une espace
				printf("\nLa phrase est trop longue.\n");
				return 8;
			}
			// on insère une espace pour que le point soit reconnu comme un mot
			// et on tronque le reste de la phrase
			phrase[i] = ' ';
			phrase[i+1] = '.';
			phrase[i+2] = '\0';
			break;
		}
	}
	if (i == strlen(phrase)) {
		// on n'a pas trouvé de point
		return 8;
	}

	pt = strtok(phrase, separateur); // pt pointe sur le premier morceau

	while( pt != NULL && etat != 8 && etat != 9) //tant qu'il reste des mots, et que 
	{
		
       // printf( " %s\n", pt );
      //strcpy(tab_mots[i] , pt);
      

      // on détermine la classe grammaticale du mot
      for (i = 0; i < TAILLE_DICO; i++) {
      	if (strcmp(dictionnaire[i].libelle, pt) == 0) {
      		// on a trouvé le mot
      		type_mot = dictionnaire[i].type;
      		// printf("type_mot=%d\n", type_mot);
      		break;
      	}
      }
      if (i == TAILLE_DICO) {
      	// si on a parcouru tout le dico
      	// sans trouver le mot : la phrase est incorrecte
      	etat = 8;
      	// printf("mot inconnu\n");
      	break;
      }

      // détermination du nouvel état
      etat = table_transitions[etat][type_mot];
      // printf("nouvel état = %d\n", etat);

      // on récupère le mot suivant
      pt = strtok(NULL, separateur);
      nb_mots++ ;
	}
	
	return etat;
}


void afficherSortie(etat) {
	if (etat == 8) {
		printf("Phrase syntaxiquement incorrecte.\n");
	} else if (etat == 9) {
		printf("Phrase syntaxiquement correcte.\n");
	} else {
		printf("Erreur - etat = %d\n", etat);
	}
}

int main() {
	
	mot dictionnaire[TAILLE_DICO]={{"le",0},{"chat",2},{"souris",2},{"mange",3},{"la",0},{"petit",1},{".",5},{"bleu",1},{"dort",3},{"julie",4},{"joue",3},{"joli",1},{"grosse", 1}, {"verte", 1}, {"Jean", 4}, {"Martin", 4}};
	int i = 0, j = 0;
	
	char phrases[][TAILLE_MAX_PHRASE] = {
		"le joli chat joue.",
		"le ,joli chat ; joue.",
		"la grosse souris verte mange le joli petit chat blanc.",
		"la grosse souris verte mange Jean.",
		"Jean joue.",
		"Jean mange Martin.",
		"Jean mange le chat.",
		"la verte souris grosse petit mange le blanc verte chat petit.",
		".",
		"",
		"le joli chat joue",
		"le joli chat miaule.",
	};

	// phrases correctes
	// char phrase[TAILLE_MAX_PHRASE] = "le joli chat joue.";
	// char phrase[TAILLE_MAX_PHRASE] = "le ,joli chat ; joue.";
	// char phrase[TAILLE_MAX_PHRASE] = "la grosse souris verte mange le joli petit chat blanc.";
	// char phrase[TAILLE_MAX_PHRASE] = "la grosse souris verte mange Jean.";
	// char phrase[TAILLE_MAX_PHRASE] = "Jean joue.";
	// char phrase[TAILLE_MAX_PHRASE] = "Jean mange Martin.";
	// char phrase[TAILLE_MAX_PHRASE] = "Jean mange le chat.";
	// char phrase[TAILLE_MAX_PHRASE] = "la verte souris grosse petit mange le blanc verte chat petit.";

	// phrases incorrectes
	// char phrase[TAILLE_MAX_PHRASE] = ".";
	// char phrase[TAILLE_MAX_PHRASE] = "";
	// char phrase[TAILLE_MAX_PHRASE] = "le joli chat joue";
	// char phrase[TAILLE_MAX_PHRASE] = "le joli chat miaule.";
	
	int table_transitions[8][6] = {};

	remplir_table_transition(table_transitions);


	int etat = 0;

	char* phrase;

	for (i = 0; i < 12; i++) {
		etat = 0;
		phrase = phrases[i];
		printf("\nPhrase = %s\n", phrase);
		etat = verifier_syntaxe_phrase(phrase, dictionnaire, table_transitions);
		afficherSortie(etat);
	}

	char phraseSaisie[TAILLE_MAX_PHRASE];
	printf("\nSaisir une phrase :\n");
	gets(phraseSaisie);
	// printf("%s\n", phraseSaisie);
	etat = verifier_syntaxe_phrase(phraseSaisie, dictionnaire, table_transitions);
	afficherSortie(etat);

	return 0;
}
