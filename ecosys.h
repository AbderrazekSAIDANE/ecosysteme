/******************************************************************************/
/* Fichier ecosys.h                                                           */
/* cree le 27/10/2019par Alix Munier Kordon                                   */
/* Ce fichier contient la declaration des fonctions des gestion d'une liste   */
/*******************************************************************************/
#define SIZEX 10
#define SIZEY 10
#define INITENERGY 10
#define COUTENERGYPROIES 0.5
#define COUTENERGYPREDATEUR 2
#define PROBAREPRODPROIES 0.3
#define PROBAREPRODPRED 0.05
#define PROBARELIMINATION 0.9



typedef struct animal {
	int		x,y; 	/* coordonnes de l animal */
	float	energie ;	/* energi de l animal */
	int 	dir[2]; /* direction de l'animal */
    struct 	animal* suiv;  /* adresse du suivant */
}animal;

typedef 	animal	ANIMAL;	  /* type d'une  element */
typedef		ANIMAL*	    PTRANIMAL;  	/* adresse d'un animal */

/******************************************************************************/
/* PTRANIMAL creationAnimal(int,int,float);                                   */
/* Creation d'un ANIMAL                                                       */
/* Renvoie l'adresse de ANIMAL cree, NULL sinon                               */
/*******************************************************************************/
PTRANIMAL creationAnimal(int,int,float);

/******************************************************************************/
/* PTRANIMAL ajouterTete(PTRANIMAL,PTRANIMAL);                                */
/* ajoute un animal en tete et retourne l'adresse de la liste                 */
/* Renvoie l'adresse de ANIMAL cree, NULL sinon                               */
/*******************************************************************************/
PTRANIMAL ajouterTete(PTRANIMAL,PTRANIMAL);

/******************************************************************************/
/* PTRANIMAL intListe (int)                                                   */
/* cree une liste de nb animaux aleatoires                                    */
/* Retoourne l'adresse de la liste triee si OK                                */
/*******************************************************************************/
PTRANIMAL initListe (int);


/******************************************************************************/
/* int compteAnimal(PTRANIMAL);                                              */
/* fonction recursive qui compte le nombre d'animal dans la liste            */
/******************************************************************************/

int compteAnimal(PTRANIMAL);

/******************************************************************************/
/* float EnergieTotale(PTRANIMAL);                                            */
/* fonction recursive qui renvoie l'enerfie totale d'une liste                */
/******************************************************************************/

float EnergieTotale(PTRANIMAL);

/******************************************************************************/
/* void affiche(PTRANIMAL,PTRANIMAL);                                         */
/* affichage des proies et des predateurs                                     */
/******************************************************************************/

void affiche(PTRANIMAL,PTRANIMAL);

/******************************************************************************/
/* PTRANIMAL detruireListe(PTRANIMAL);                                         */
/* destruction de la liste                                                     */
/******************************************************************************/

PTRANIMAL detruireListe(PTRANIMAL);

/******************************************************************************/
/* PTANIMAL reproduction(PTRANIMAL tete, int probaReproduction)                */
/* reproduction aavec un probabilite passe en parametre                        */
/******************************************************************************/

PTRANIMAL reproduction(PTRANIMAL, float);

/******************************************************************************/
/* void enleverAnimal(PTRANIMAL*,PTRANIMAL);                                  */
/* retire l'animal de  la liste  chainee                                      */
/******************************************************************************/

int enleverAnimal(PTRANIMAL*,PTRANIMAL);

/******************************************************************************/
/* PTRANIMAL deplacement (PTRANIMAL tete, double coutEnergie)                   */
/*calculle le deplacement et l'enercgie de tous les animaux de la liste.      */
/* Un animal d'energie negative est retiree                                   */
/******************************************************************************/

PTRANIMAL deplacement (PTRANIMAL, float);

/******************************************************************************/
/*int eliminationProies(PTRANIMAL teteProies, PTRANIMAL teteProies,           */
/* float probaelimination);                                                   */
/* elimination des proies par les predateurs                                  */
/******************************************************************************/

int eliminationProies(PTRANIMAL*, PTRANIMAL, float );


