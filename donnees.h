#ifndef DONNEES_H_INCLUDED
#define DONNEES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

void lecture(int *pouls[100], int *millis[100], int *pouls2[100],int *millis2[100],int ligne);//prototype fonction lecture du fichier et remplissage des tableaux pouls et temps
void compteur(int *ligne);// prototype fonction compteur de ligne du fichier
#endif // DONNEES_H_INCLUDED
