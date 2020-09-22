/******************************************************************************/
/* Fichier principal.c                                                        */
/* cree le 07/01/12 par Alix Munier Kordon                                    */
/* Ce fichier contient le programme principal du TP sur l'ecosysteme          */
/*******************************************************************************/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "ecosys.h"
#include "aleatoire.h"

void afficheListe (PTRANIMAL Tete)
{
	PTRANIMAL temp;
	int i = 0;
	temp = Tete;
	while (temp->suiv)
	{
		printf("[%i]\npos x,y : %i %i\nenergie : %f \ndir : [%i][%i]\n\n",i,temp->x,temp->y,temp->energie,temp->dir[0],temp->dir[1]);
		i++;
		temp = temp->suiv;
	}
	printf("[%i]\npos x,y : %i %i\nenergie : %f \ndir : [%i][%i]\n\n",i,temp->x,temp->y,temp->energie,temp->dir[0],temp->dir[1]);
}


int main(int argc, char *argv[]){

	//time_t t;
	//srand((unsigned) time(&t));

	PTRANIMAL teteProies;
	PTRANIMAL tetePredateurs;

	teteProies = initListe(10);
	tetePredateurs = initListe(10);

	// Tests de l'exercice 1
	printf("Tests de l'exercice 1\n");
	enleverAnimal(&teteProies, teteProies->suiv->suiv->suiv);
	enleverAnimal(&teteProies, teteProies->suiv->suiv->suiv->suiv->suiv->suiv);
	enleverAnimal(&teteProies, teteProies);
	afficheListe(teteProies);
	afficheListe(tetePredateurs);
	detruireListe(tetePredateurs);
	tetePredateurs = initListe(10);
	
	// Tests de l'exercice 2
	printf("\n\nTests de l'exercice 2\n");
	printf("Nombre de Proies : %i\n",compteAnimal(teteProies));
	printf("Total d'énergie des Proies : %f\n",EnergieTotale(teteProies));
	
	printf("Nombre de Predateurs : %i\n",compteAnimal(tetePredateurs));
	printf("Total d'énergie des Predateurs: %f\n",EnergieTotale(tetePredateurs));
	
	affiche(teteProies,tetePredateurs);
	
	// Tests de l'exercice 3
	printf("\n\nTests de l'exercice 3\n");
	teteProies = initListe(10);
	tetePredateurs = initListe(10);
	
	int nbTour = 1;
	
	while(teteProies && tetePredateurs)
	{
		system("clear");
	
		affiche(teteProies, tetePredateurs);
		
		teteProies = deplacement(teteProies, 2);
		tetePredateurs = deplacement(tetePredateurs, 2);
		
		teteProies = reproduction(teteProies, 0.1);
		tetePredateurs = reproduction(tetePredateurs, 0.1);
		
		printf("Nombre de tour : %i\n", nbTour);
		printf("Nombre de proies restant : %i\n",compteAnimal(teteProies));
		printf("Nombre de prédateurs restant: %i\n",compteAnimal(tetePredateurs));

		nbTour++;
		usleep(1000000);
	}
	
	affiche(teteProies, tetePredateurs);
    
	if (!teteProies)
	{
		printf("Plus de proies");
	}
	else
	{
		printf("Plus de prédateurs");
	}
    return 0;
	
}





