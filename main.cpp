#include <iostream>
#include "fonctions/fonctions.h"
#include <string>
using namespace std;


int code = 01;
string motChoisis = " ";
string motCache = " ";
string lettre = " ";
string messageErreurJoueur = " ";
int nombreDeRatesMaximum = 0;
int nombreDessaisActuel = 0;
int nombreDeRatesActuel = 0;
int nombreDeReussisActuel = 0;
char lettresMauvaises[26];
char lettresBonnes[26];
char derniereLettreTape = 97;
char potencetab[6][15];
bool boucleJeu = true;

int main() {

    while (boucleJeu) {
        handler(code);
        VerifEtatDujeu();
    }

    return 0;
}
