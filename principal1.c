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

/*void afficheListe (PTRANIMAL Tete)
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
*/

int main(int argc, char *argv[]){


	PTRANIMAL teteProies;
	PTRANIMAL tetePredateurs;

	teteProies = initListe(10);
	tetePredateurs = initListe(10);

	// Tests de l'exercice 1
	enleverAnimal(&teteProies, teteProies->suiv->suiv->suiv);
	enleverAnimal(&teteProies, teteProies->suiv->suiv->suiv->suiv->suiv->suiv);
	enleverAnimal(&teteProies, teteProies);
	//afficheListe(teteProies);
	//afficheListe(tetePredateurs);
	detruireListe(tetePredateurs);
	tetePredateurs = initListe(10);
	
	// Tests de l'exercice 2
    //Informations des Proies
	printf("Nombre de Proies  : %i\n",compteAnimal(teteProies));
	printf("Total d'énergie des Proies: %f\n",EnergieTotale(teteProies));
	
    //Informations des Predateurs
	printf("Nombre de Prédateurs : %i\n",compteAnimal(tetePredateurs));
	printf("Total d'énergie des prédateurs: %f\n",EnergieTotale(tetePredateurs));
	
	affiche(teteProies,tetePredateurs);

    return 0;
	
}





