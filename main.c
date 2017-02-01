/********************************************************************/
/*** VIVIER David													*/
/*** VARAGNAT Kévin													*/
/*** 31/01/2017											            */
/*** Exécuter ./tp1-ex4 pour utiliser le programme 					*/
/*** 																*/
/********************************************************************/
#include <stdio.h>
/*
Ce programme prend en entrée un numérateur et un dénominateur,
	et affiche l'irrégularité du quotient
David Vivier et Kévin Varagnat
31/01/2016
*/


#define TAILLE 50


/*
entrée : numérateur, dénominateur, tableau vide
sortie : indice du début de la période
	+ le tableau digits contient les premiers digits jusqu'à la 
		fin de la première période, puis -1
*/
int determine_irr_quotient(int N, int D, int digits[]) {
	

	int a = N;
	int b = D;

	int i = 0, j = 0;

	int quotient = 0, reste = 0;

	int restes[D];

	int i_debut_periode = 0;
	int i_fin_periode = 0;

	// indique si on a trouvé un reste déjà trouvé précédemment
	int resteTrouve = 0;

	if (a < b) a *= 10;

	while (resteTrouve != 1 && reste != 1 && i < D) {

		quotient = a / b;
		reste = a % b;

		// on regarde si on a déjà vu ce reste
		j = 0;
		for (j = 0; j < i; j++) {
			if (reste == restes[j]) {
				// le reste a déjà été trouvé précédemment, à l'index j
				i_debut_periode = j+1;
				i_fin_periode = i;
				resteTrouve = 1;
				break;
			}
		}

		//printf("\nq=%d r=%d", quotient, reste);
		digits[i] = quotient;
		restes[i] = reste;
		a = reste*10;
		i++;
	}

	digits[i] = -1;


	return i_debut_periode;
}


int main() {

	
	int N = 123;
	int D = 456;


	int digits[D];

	int i_debut_periode = determine_irr_quotient(N, D, digits);

	int i = 0, n = 0;;

	printf("\n %d/%d ", N, D);

	printf("\nirrégularité : ");

	for (i = 0; i < i_debut_periode; i++) {
		printf("%d", digits[i]);
	}
	printf(" - longueur %d",i_debut_periode);

	printf("\npériode : ");
	i = i_debut_periode;
	while (digits[i] != -1) {
		printf("%d", digits[i]);
		n++;
		i++;
	}
	printf(" - longueur %d", n);

	printf("\n");

	return 0;
}
