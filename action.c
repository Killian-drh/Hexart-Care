#include <stdio.h>
#include <stdlib.h>
#include "action.h"
#include "menu.h"
#include "donnees.h"
char a =  0x285;
char e =  0x282;
//======== Fonction trie du pouls dans l'odre croissant ====================================
void croissantp(int *pouls[100],int *millis[100],int *pouls2[100],int *millis2[100], int ligne)
{
    int i;
    int max;
    int j;
// implémentation d'un algorithme de tri selection
   for (i=0; i < ligne  ;i++)
   {
    for (j = i+1 ; j < ligne ;j++)
       {
        if(pouls[j] < pouls[i]) // grace à cette comparaison arithmétique nous pouvons trié les valeurs du tableau dans l'odre croissant
           {
            max = pouls[j] ;
            pouls[j] = pouls[i];
            pouls[i] = max;
           }
       }
   }

for (i=0; i<ligne ; i++)
{
//affichage du tableau trié
    for (j=0; j<ligne;j++)
    {
        if (pouls[i]==pouls2[j])
        {
            printf("%d bpm ; %d ms\n", pouls[i], millis2[j]);
        }
    }
}


}

//======== Fonction trie du pouls dans l'odre décroissant ====================================
void decroissantp(int *pouls[100],int *millis[100],int *pouls2[100],int *millis2[100], int ligne)
{
    int i;
    int max;
    int j;
// implémentation d'un algorithme de tri selection
   for (i=0; i < ligne  ;i++)
   {
    for (j = i+1 ; j < ligne ;j++)
       {
        if(pouls[j] > pouls[i]) // grace à cette comparaison arithmétique nous pouvons trié les valeurs du tableau dans l'odre décroissant
           {
            max = pouls[j] ;
            pouls[j] = pouls[i];
            pouls[i] = max;
           }
       }
   }


for (i=0; i<ligne ; i++)
{
//affichage du tableau trié
    for (j=0; j<ligne;j++)
    {
        if (pouls[i]==pouls2[j])
        {
            printf("%d bpm ; %d ms\n", pouls[i], millis2[j]);
        }
    }
}

}

//======== Fonction trie du temps dans l'odre croissant ====================================
void croissantm(int *pouls[100],int *millis[100],int *pouls2[100], int *millis2[100], int ligne)
{
    int i;
    int max;
    int j;
// implémentation d'un algorithme de tri selection
   for (i=0; i < ligne  ;i++)
   {
    for (j = i+1 ; j < ligne ;j++)
       {
        if(millis[j] < millis[i])// grace à cette comparaison arithmétique nous pouvons trié les valeurs du tableau dans l'odre croissant
           {
            max = millis[j] ;
            millis[j] = millis[i];
            millis[i] = max;
           }
       }
   }


for (i=0; i<ligne ; i++)
{
    //affichage du tableau trié
    for (j=0; j<ligne;j++)
    {
        if (millis[i]==millis2[j])
        {
            printf("%d ms ; %d bpm\n", millis[i],pouls2[j]);
        }
    }
}


}


//======== Fonction trie du temps dans l'odre décroissant ====================================
void decroissantm(int *pouls[100],int *millis[100], int *millis2[100],int *pouls2[100], int ligne)
{
    int i;
    int max;
    int j;
// implémentation d'un algorithme de tri selection
   for (i=0; i < ligne  ;i++)
   {
    for (j = i+1 ; j < ligne ;j++)
       {
        if(millis[j] > millis[i])// grace à cette comparaison arithmétique nous pouvons trié les valeurs du tableau dans l'odre décroissant
           {
            max = millis[j] ;
            millis[j] = millis[i];
            millis[i] = max;
           }
       }
   }


for (i=0; i<ligne ; i++)
{
//affichage du tableau trié
    for (j=0; j<ligne;j++)
    {
        if (millis[i]==millis2[j])
        {
            printf("%d ms ; %d bpm\n", millis[i],pouls2[j]);
        }
    }
}

}

//======== Affichage du pouls minimale et maximale  ====================================

void intervallep(int *pouls,int *millis2, int ligne)
{
    int i;
    int max;
    int j;
// implémentation d'un algorithme de tri selection
   for (i=0; i < ligne  ;i++)
   {
    for (j = i+1 ; j < ligne ;j++)
       {
        if(pouls[j] < pouls[i])// grace à cette comparaison arithmétique nous pouvons trié les valeurs du tableau dans l'odre croissant
           {
            max = pouls[j] ;
            pouls[j] = pouls[i];
            pouls[i] = max;
           }
       }
   }
// algorithme permettant d'afficher les valeurs minimale et maximale du pouls (avec le temps associé) dans le tableau trié précédement
   for (i=0; i<ligne;i++)
   {
       if (i==0)
       {
           printf("Pouls minimale : %d BPM  temps : %d ms\n",pouls[i], millis2[i]);
       }
       else if (i== (ligne-1))
       {
           printf("Pouls maximale : %d BPM  temps : %d ms\n\n",pouls[i], millis2[i]);
       }
   }
}

//======== Fonction recherche d'un temps précis et association à son pouls ====================================
void recherche(int *millis2, int *pouls2,int ligne)
{
int nbrRecherche;
int i;
int p;
nbrRecherche = choicerech();
printf("\n");

//implémentation algorithme de recherche séquentielle permettant de rechercher le temps saisie dans le tableau du temps.

for(i=0; i<ligne; i++)
        {

        if(millis2[i]==nbrRecherche)
                {

                p=i;
                i=2*ligne;// réassignation de la valeur de la variable i pour la prochaine condition
                break;
                }


        }
// condition permettant de savoir si le temps recherché est bien dans le tableau
if(i==(2*ligne))
{
    // affichage du temps associé a son pouls
    printf("Le temps %d ms est bien dans le tableau associ%c au pouls : %d BPM\n\n", nbrRecherche,e,pouls2[p]);

}
else
{
    // le temps ne se trouve pas dans le tableau
    printf("Le temps %d ms ne se trouve pas dans le tableau\n\n", nbrRecherche);
}

}
//======== Fonction calcul de la moyenne du pouls sur un intervalle de temps précis ====================================
void moyenne(int *pouls, int ligne, int *millis)
{
    int i;
    int somme=0;
    int moyenne;
    int min;
    int max;
    int cmin;
    int cmax;

// saisie de la valeur minimale de l'intervalle
    min = choicemin();
// saisie de la valeur maximale de l'intervalle
    max = choicemax();

    while (min > max)
    {
        printf("La valeur minimale ne peut pas etre plus elev%ce que la valeur maximale, veuillez rentrer des valeurs valables : \n",e);
        min = choicemin();
        max = choicemax();
    }
    // algorithme permettant de définir les valeurs min et max du temps en fonction des valeurs saisie souhaité par l'utilisateur (permet d'arrondir à la valeur supérieur ou inférieur en fonction des)
    for (i=0; i<ligne;i++)
    {
        if (millis[i]== min)
        {
            min = millis[i];
            cmin=i;
            break;
        }

        else if (millis[i]>min)
        {
            min = millis[i];
            cmin=i;
            break;
        }
    }

    for (i=0 ; i<ligne;i++)
    {
        if (millis[i]== max)
        {
            max = millis[i];
            cmax=i;
            break;
        }

        else if (millis[i] > max)
        {


            max = millis[i];
            cmax=i;
            break;
        }

        else if (i==(ligne-1) && millis[(ligne-1)] < max )
        {
                max = millis[(ligne-1)];
                cmax=i;
                break;
        }
    }

    printf("intervalle de temps choisit (en ms): [%d ; %d]\n", min,max);
// calcule de la moyenne du pouls dans l'intervalle de temps choisit puis affichage de celui-ci
for(i=cmin; i<cmax+1; i++)
    {

        somme=somme+pouls[i];
    }
    moyenne = somme / ((cmax - cmin)+1);
    printf("moyenne du pouls : %d BPM\n\n", moyenne);
}

//======== Sécurité et saisie du choix du menu ====================================
int choice(void)
{
    char chaine1[20];
    int test;
    int choix;

    // saisie du choix puis conversion de char a int du choix, si la conversion fonctionne cela veut dire que l'utilisateur a bien rentré un chiffre de 0à 9, si elle échoue l'utilisateur a rentré des lettres donc il doit recommencer
    do
    {
    printf("Entrez la valeur correspondante %c votre choix\n", a);
    fgets(chaine1, sizeof chaine1, stdin);

    clean(chaine1);

    test = sscanf(chaine1, "%d", &choix);
    }while (test != 1);

    while (choix < 0 || choix > 9)
    {
        do
    {
    printf("Entrez la valeur correspondante %c votre choix\n", a);
    fgets(chaine1, sizeof chaine1, stdin);

    clean(chaine1);

    test = sscanf(chaine1, "%d", &choix);
    }while (test != 1);

    }

    return choix;

}

// fonction permettant de purgé la chaine des '\n'
void purger(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
    {}
}

//permet de vider la mémoire tampon
void clean (char *chaine)
{
    char *p = strchr(chaine, '\n');

    if (p)
    {
        *p = 0;
    }

    else
    {
        purger();
    }
}
//======== Sécurité et choix de la valeur minimale du temps pour la moyenne ====================================

// saisie de la valeur min de l'intervale puis conversion de char a int de cette valeur, si la conversion fonctionne cela veut dire que l'utilisateur a bien rentré un chiffre, si elle échoue l'utilisateur a rentré des lettres donc il doit recommencer

int choicemin(void)
{
    char chaine1[20];
    int test;
    int choix;

    do
    {
    printf("Rentrez le temps (en ms) minimale de l'intervalle : ");
    fgets(chaine1, sizeof chaine1, stdin);

    clean(chaine1);

    test = sscanf(chaine1, "%d", &choix);
    }while (test != 1);





    return choix;

}
//======== Sécurité et choix de la valeur maximale du temps pour la moyenne ====================================
// saisie de la valeur max de l'intervale puis conversion de char a int de cette valeur, si la conversion fonctionne cela veut dire que l'utilisateur a bien rentré un chiffre, si elle échoue l'utilisateur a rentré des lettres donc il doit recommencer

int choicemax(void)
{
    char chaine1[20];
    int test;
    int choix;

    do
    {
    printf("Rentrez le temps maximale de l'intervalle : ");
    fgets(chaine1, sizeof chaine1, stdin);

    clean(chaine1);

    test = sscanf(chaine1, "%d", &choix);
    }while (test != 1);





    return choix;

}
//======== Sécurité et choix de la valeur à rechercher dans le tableau ====================================
// saisie de la valeur rechercher par l'utilisateur puis conversion de char a int de cette valeur, si la conversion fonctionne cela veut dire que l'utilisateur a bien rentré un chiffre, si elle échoue l'utilisateur a rentré des lettres donc il doit recommencer

int choicerech(void)
{
    char chaine1[20];
    int test;
    int choix;

    do
    {
    printf("Rentrez le temps (en ms) souhaitez : ");
    fgets(chaine1, sizeof chaine1, stdin);

    clean(chaine1);

    test = sscanf(chaine1, "%d", &choix);
    }while (test != 1);


    return choix;

}
