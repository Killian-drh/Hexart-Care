#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "action.h"
#include "donnees.h"
#include "generationCode.h"

void menu()
{
// initialisation des variables
int ligne=0;
int millis[100];
int pouls[100];
int i;
int pouls2[100];
int millis2[100];
int choix;
int mode;
char a =  0x282;


printf("             ================================================\n");
printf("            |                                                |\n");
printf("            |         Bienvenue dans le gestionnaire         |\n");
printf("            |      de donn%ces de votre rythme cardiaque      |\n", a);
printf("            |                                                |\n");
printf("             ================================================\n\n");

do
{
// affichage du menu et des possibilités
printf("0 => sortir\n");
printf("1 => afficher les donn%ces en sortie du fichier.csv\n",a);
printf("2 => afficher les donn%ces dans l'ordre croissant en fonction du pouls\n",a);
printf("3 => afficher les donn%ces dans l'ordre decroissant en fonction du pouls\n",a);
printf("4 => afficher les donn%ces dans l'ordre croissant en fonction du temps\n",a);
printf("5 => afficher les donn%ces dans l'ordre decroissant en fonction du temps\n",a);
printf("6 => afficher la valeur minimale et maximale du pouls\n");
printf("7 => Recherche d'un temps pr%ccis\n");
printf("8 => afficher la moyenne du pouls sur un intervalle de temps\n");
printf("9 => afficher le nombre de ligne du fichier\n");

// choix du mode
choix = choice();

//switch case permettant d'executer ce qui est demandé précédement par l'utilisateur
switch (choix)
{
case 1:
    // affichage des données en sortie du .csv
    compteur(&ligne);// appel de la fonction permettant de compter le nombre de ligne inscrit dans le fichier
    lecture(&pouls, &millis ,&pouls2, &millis2,ligne);// appel de la fonction permettant de lire le fichier .csv et remplir les tableaux de valeurs
    printf("Valeur en sortie du fichier.csv :\n");
    // affichage des valeurs en sortie du fichier
    for (i=0; i<ligne ; i++)
    {
        printf("Pouls : %d BPM; Temps : %d ms\n",pouls2[i],millis2[i]);
    }
    printf("\n");
    break;

case 2:
    compteur(&ligne);// appel de la fonction permettant de compter le nombre de ligne inscrit dans le fichier
    lecture(&pouls, &millis ,&pouls2, &millis2,ligne);// appel de la fonction permettant de lire le fichier .csv et remplir les tableaux de valeurs
    printf("trie dans l'ordre croissant du pouls:\n");
    croissantp(&pouls, &millis, &pouls2,&millis2,ligne);// appel de la fonction permettant de trié le pouls dans l'ordre croissant et affiché le tableau trié
    printf("\n");

    break;

case 3:
    compteur(&ligne);// appel de la fonction permettant de compter le nombre de ligne inscrit dans le fichier
    lecture(&pouls, &millis ,&pouls2, &millis2,ligne);// appel de la fonction permettant de lire le fichier .csv et remplir les tableaux de valeurs
    printf("trie dans l'ordre d%ccroissant du pouls:\n",a);
    decroissantp(&pouls, &millis,&pouls2,&millis2, ligne);// appel de la fonction permettant de trié le pouls dans l'ordre décroissant et affiché le tableau trié
    printf("\n");
    break;

case 4:
    compteur(&ligne);// appel de la fonction permettant de compter le nombre de ligne inscrit dans le fichier
    lecture(&pouls, &millis ,&pouls2, &millis2,ligne);// appel de la fonction permettant de lire le fichier .csv et remplir les tableaux de valeurs
    printf("trie dans l'ordre croissant du temps:\n");
    croissantm(&pouls,&millis,&pouls2,&millis2,ligne);// appel de la fonction permettant de trié le temps dans l'ordre croissant et affiché le tableau trié
    printf("\n");
    break;

case 5:
    compteur(&ligne);// appel de la fonction permettant de compter le nombre de ligne inscrit dans le fichier
    lecture(&pouls, &millis ,&pouls2, &millis2,ligne);// appel de la fonction permettant de lire le fichier .csv et remplir les tableaux de valeurs
    printf("trie dans l'ordre d%ccroissant du temps:\n", a);
    decroissantm(&pouls, &millis,&millis2,&pouls2,ligne);// appel de la fonction permettant de trié le pouls dans l'ordre décroissant et affiché le tableau trié
    printf("\n");
    break;

case 6:
    compteur(&ligne);// appel de la fonction permettant de compter le nombre de ligne inscrit dans le fichier
    lecture(&pouls, &millis ,&pouls2, &millis2,ligne);// appel de la fonction permettant de lire le fichier .csv et remplir les tableaux de valeurs
    intervallep(&pouls,&millis2,ligne);// appel de la fonction permettant d'afficher la valeur min et max du pouls avec le temps associée
    break;

case 7:
    compteur(&ligne);// appel de la fonction permettant de compter le nombre de ligne inscrit dans le fichier
    lecture(&pouls, &millis ,&pouls2, &millis2,ligne);// appel de la fonction permettant de lire le fichier .csv et remplir les tableaux de valeurs
    recherche(&millis2, &pouls2,ligne);//appel de la fonction permettant de rechercher un temps bien précis dans le tableau et affichage de celui ci avec son pouls associé
    break;

case 8:
    compteur(&ligne);// appel de la fonction permettant de compter le nombre de ligne inscrit dans le fichier
    lecture(&pouls, &millis ,&pouls2, &millis2,ligne);// appel de la fonction permettant de lire le fichier .csv et remplir les tableaux de valeurs
    printf("liste temps possible :\n");
    croissantm(&pouls,&millis,&pouls2,&millis2,ligne);// appel de la fonction trie croissant du temps ( cela facilite la recherche suivante )
    moyenne(&pouls2,ligne,&millis);// fonction permettant de calculer la moyenne du pouls sur un intervalle de temps défini par l'utilisateur
    break;
case 9:
    compteur(&ligne);// appel de la fonction permettant de compter le nombre de ligne inscrit dans le fichier
    printf("Nombre de ligne %d\n", ligne);// affichage du nombre de ligne
    printf("\n");
    break;

}


}while (choix!=0);

}
