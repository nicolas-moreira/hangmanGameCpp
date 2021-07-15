//
// Created by nicolas on 26/02/2020.
//
#include <string>
using namespace std;
extern string motChoisis;
extern string motCache;
extern string lettre;
extern string messageErreurJoueur;
extern int code;
extern char derniereLettreTape;
extern int nombreDessaisActuel;
extern int nombreDeRatesMaximum;
extern int nombreDeRatesActuel;
extern int nombreDeReussisActuel;
extern bool boucleJeu;
extern char lettresMauvaises[26];
extern char lettresBonnes[26];
extern char potencetab[6][15];


#ifndef PENDU_FONCTIONS_H
#define PENDU_FONCTIONS_H
int handler(int);
int choisirUnMot();
int cacherLeMot();
int aleatoire();
int saisie();
int verificationLettre();
int VerifEtatDujeu();
int verifierSiDansMot();
int bonneLettre();
int mauvaiseLettre();
int gagne();
int perdu();
int potence();


#endif //PENDU_FONCTIONS_H


