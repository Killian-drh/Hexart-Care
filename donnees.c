#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "action.h"
#include "donnees.h"

void compteur(int *ligne) // fonction permettant de compter le nombre de ligne inscrit dans mon fichier
{
    FILE* fichier=NULL;
    int c=0;
    int compteur=0;

    fichier = fopen("C:\\Users\\killi\\Desktop\\sketch_171117a\\Battements.csv", "r");

    if (fichier !=NULL)
    {
        do                        // boucle do while permettant de compter le nombre de ligne max
        {
            c = fgetc(fichier);
                if (c=='\n')
                {
                    compteur++;
                }
        }while(c != EOF);
    }

*ligne = compteur;
fclose(fichier);
}


void lecture(int *pouls[100], int *millis[100], int *pouls2[100],int *millis2[100],int ligne) // fonction permettant de lire le fichier .csv et retranscrire les valeurs dans 2 tableaux, 1 pour le pouls, l'autre pour le temps
{
   FILE* fichier=NULL;
   int i;

   fichier = fopen("C:\\Users\\killi\\Desktop\\sketch_171117a\\Battements.csv", "r");

    if (fichier !=NULL)
    {
        for (i=0;i<ligne;i++)
        {
          fscanf(fichier,"%d;%d", &pouls[i], &millis[i]);
          pouls2[i] = pouls[i];
          millis2[i]= millis[i];
        }

    }

fclose(fichier);
}
