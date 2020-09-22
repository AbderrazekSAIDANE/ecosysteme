/******************************************************************************/
/* Fichier ecosys.c                                                          */
/* cree le 27/10/2019par Alix Munier Kordon                                   */
/* Ce fichier contient la declaration des fonctions des gestion d'une liste   */
/*******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "ecosys.h"
#include "aleatoire.h"
/******************************************************************************/
/* PTRANIMAL creationAnimal(int,int,float);                                   */
/* Creation d'un ANIMAL                                                       */
/* Renvoie l'adresse de ANIMAL cree, NULL sinon                               */
/*******************************************************************************/
PTRANIMAL creationAnimal(int x,int y,float energie)
{

	PTRANIMAL new = (PTRANIMAL)malloc(sizeof(ANIMAL));
		
	if (!new) {
		return NULL;
	}
	
	new->x = x;
	new->y = y;
	
	new->energie = energie;
	
	int rand = rand_limite(2);
	if (rand>1) 
	{
		new->dir[0] = -1;
	}
	else
	{
		new->dir[0] = rand;
	}
	
	rand = rand_limite(2);
	if (rand>1) 
	{
		new->dir[1] = -1;
	}
	else
	{
		new->dir[1] = rand;
	}
	
	new->suiv = NULL;
	
	return new;
	
}

/******************************************************************************/
/* PTRANIMAL ajouterTete(PTRANIMAL,PTRANIMAL);                                */
/* ajoute un animal en tete et retourne l'adresse de la liste                 */
/* Renvoie l'adresse de ANIMAL cree, NULL sinon                               */
/*******************************************************************************/

PTRANIMAL ajouterTete(PTRANIMAL tete,PTRANIMAL ptAnimal)
{

	if (!tete)
	{
		return ptAnimal;
	}
	
	ptAnimal->suiv = tete;
	
	return ptAnimal;
}

/******************************************************************************/
/* PTRANIMAL intListe (int)                                                   */
/* cree une liste de nb animaux aleatoires                                    */
/* Retoourne l'adresse de la liste triee si OK                                */
/*******************************************************************************/

PTRANIMAL initListe (int nbAnimaux)
{

	PTRANIMAL new;
	
	if (!nbAnimaux)
	{
		return NULL;
	}
	
	new = creationAnimal(rand_limite(SIZEX-1), rand_limite(SIZEY-1), INITENERGY);
	return(ajouterTete(initListe(nbAnimaux-1), new));
}

/******************************************************************************/
/* int compteAnimal(PTRANIMAL);                                              */
/* fonction recursive qui compte le nombre d'animal dans la liste            */
/******************************************************************************/

int compteAnimal(PTRANIMAL tete)
{

	if (tete)
		return 1 + compteAnimal(tete->suiv);
	else
		return 0;
}

/******************************************************************************/
/* int EnergieTotale(PTRANIMAL);                                              */
/* fonction recursive qui renvoie l'enerfie totale d'une liste                */
/******************************************************************************/

float EnergieTotale(PTRANIMAL tete)
{
	if (tete)
		return tete->energie + EnergieTotale(tete->suiv);
	else
		return 0.0;
}

/******************************************************************************/
/* void afficheLigne(int);                                                    */
/* affichage une ligne de nb caractere                                        */
/******************************************************************************/

void afficheLigne(int nb)
{
	int i;
	printf("+");
	for(i=0;i<nb;i++)
		printf("-");
	printf("+");
	printf("\n");
}
/******************************************************************************/
/* void affiche(PTRANIMAL,PTRANIMAL);                                         */
/* affichage des proies et des predateurs                                     */
/******************************************************************************/


void affiche(PTRANIMAL teteProies, PTRANIMAL tetePredateurs)
{
	char carte[SIZEX][SIZEY];
	
	int i,j;
	
	PTRANIMAL predateur,proie;
    //création de la carte
    for (i=0;i<SIZEX;i++)
	{
		for(j=0;j<SIZEY;j++)
		{
			carte[j][i] = ' ';
		}
	}
	//ajout prédateurs
	predateur = tetePredateurs;
	while (predateur)
	{
		carte[predateur->x][predateur->y] = '0';
		predateur = predateur->suiv;
	}
	//ajout proies
	proie = teteProies;
	while (proie)
	{
		if (carte[proie->x][proie->y] == '0')
		{
			carte[proie->x][proie->y] = '@';
		}
		else
		{
			carte[proie->x][proie->y] = '*';
		}
		proie = proie->suiv;
	}
	//affichage
	afficheLigne(SIZEX);
	for (i=0;i<SIZEX;i++)
	{
		printf("|");
		
		for(j=0;j<SIZEY;j++) 
		{
			printf("%c",carte[j][i]);
		}
		
		printf("|\n");
	}
	afficheLigne(SIZEX);
}

/******************************************************************************/
/* PTRANIMAL detruireListe(PTRANIMAL);                                         */
/* destruction de la liste  et retourne NULL                                   */
/******************************************************************************/

PTRANIMAL detruireListe(PTRANIMAL tete)
{

	PTRANIMAL cour, suiv;
	
	cour = tete;
	
	while (cour)
	{
		suiv = cour->suiv;
		free(cour);
		cour = suiv;
	}
	
	return NULL;
}


/******************************************************************************/
/* PTANIMAL reproduction(PTRANIMAL tete, int probaReproduction)                */
/* reproduction aavec un probabilite passe en parametre                        */
/******************************************************************************/
PTRANIMAL reproduction(PTRANIMAL tete, float probaReproduction)
{
	PTRANIMAL cour=tete;
	
	while (cour)
	{
		int probabilite = rand_limite(99)+1;

		if ((int)(probaReproduction*100)>probabilite)
        {
			tete = ajouterTete(tete, creationAnimal(cour->x, cour->y, INITENERGY));
		}
        
		cour = cour->suiv;
	}
	
	return tete;
}
/******************************************************************************/
/* void enleverAnimal(PTRANIMAL*,PTRANIMAL);                                  */
/* retire l'animal de  la liste  chainee                                      */
/* retourne 0 en cas de probleme, 1 sinon                                     */
/******************************************************************************/

int enleverAnimal(PTRANIMAL* ptTete, PTRANIMAL ptAnimal)
{

	PTRANIMAL prec = NULL, cour = (*ptTete);
	
	while (cour&&cour!=ptAnimal)
	{
		prec = cour;
		cour = cour->suiv;
	}
	
	if (!cour) 
	{
		return 0;
	}
	if (!prec)
	{
		(*ptTete) = cour->suiv;
		ptAnimal->suiv = NULL;
		if (ptAnimal)
			free(ptAnimal);
	}
	else
	{
		prec->suiv=cour->suiv;
		ptAnimal->suiv=NULL;
		if (ptAnimal)
			free(ptAnimal);
	}
	
	return 1;
}

/******************************************************************************/
/* PTRANIMAL deplacement (PTRANIMAL tete, int coutEnergie)                   */
/*calculle le deplacement et l'enercgie de tous les animaux de la liste.      */
/* Un animal d'energie negative est retiree                                   */
/******************************************************************************/

PTRANIMAL deplacement (PTRANIMAL tete, float coutEnergie)
{
	PTRANIMAL prec, cour=tete;
	
	while (cour){
        
		cour->energie = cour->energie - coutEnergie;
	
		if((cour->energie) >= 0)
		{
			cour->x = (cour->x + cour->dir[0]) % SIZEX;
			if(cour->x < 0) //Dans le cas ou cours->x = 0 et la direction est -1 alors cors->x devient -1 celle ci n'existe pas et on doit juste changé de coté
			{
				cour->x = SIZEX - 1;
			}
				
			cour->y = (cour->y + cour->dir[1]) % SIZEY; //
			if(cour->y < 0)//Dans le cas ou cours->y = 0 et la direction est -1 alors cors->x devient -1 celle ci n'existe pas et on doit juste changé de coté
			{
				cour->y = SIZEY -1;
			}
			
			prec = cour;
			cour=cour->suiv;
		}
		else
		{
			prec = cour;
			cour=cour->suiv;
			
			enleverAnimal(&tete, prec);
		}	
		
	}
	
	return tete;
}

/******************************************************************************/
/*int eliminationProies(PTRANIMAL teteProies, PTRANIMAL teteProies,           */
/* float probaelimination);                                                   */
/* elimination des proies par les predateurs                                  */
/******************************************************************************/

int eliminationProies(PTRANIMAL* pteteProies, PTRANIMAL tetePredateurs, float probaelimination)
{
	return 0;
}
