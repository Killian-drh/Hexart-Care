#ifndef ACTION_H_INCLUDED
#define ACTION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

void croissantp(int *pouls[100],int *millis[100],int *pouls2[100],int *millis2[100],int ligne); // prototype fonction pouls croissant
void decroissantp(int *pouls[100],int *millis[100],int *pouls2[100],int *millis2[100], int ligne);//prototype fonction pouls décroissant
void croissantm(int *pouls[100],int *millis[100],int *pouls2[100], int *millis2[100],  int ligne);//prototype fonction temps croissant
void decroissantm(int *pouls[100],int *millis[100], int *millis2[100],int *pouls2[100], int ligne);// prototype fonction temps décroissant
void intervallep(int *pouls,int *millis2, int ligne); // prototype valeur pouls maximale et minimale
void recherche(int *millis2, int *pouls2,int ligne);//prototype recherche du temps dans un tableau
void moyenne(int *pouls, int ligne, int *millis);//prototype moyenne du pouls
int choice(void);// prototype choix du menu
void purger(void);// prototype purge de la mémoire tempon
void clean (char *chaine);// prototype nettoyage de la chaine de caractere
int choicemin(void);// prototype valeur minimale de l'intervalle de temps
int choicemax(void);// prototype valeur maximale de l'intervalle de temps
int choicerech(void);// prototype valeur rechercher dans le tableau
#endif // ACTION_H_INCLUDED
