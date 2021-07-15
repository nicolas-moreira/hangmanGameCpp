//
// Created by nicolas on 26/02/2020.
//

//###############################################################//
                        #include <string>
                        #include <iostream>
                        #include <fstream>
                        #include <time.h>
                        #include <cstring>
                        #include "fonctions.h"
//###############################################################//

                        using namespace std;

//###############################################################//

int handler(int code){

    switch(code) {
        case 01:
            choisirUnMot();
            cacherLeMot();
            nombreDeRatesMaximum  = 6;
            nombreDessaisActuel   = 0;
            nombreDeRatesActuel   = 0;
            nombreDeReussisActuel = 0;
            code = saisie();
            break;
        case 10:
            cout << endl << messageErreurJoueur << endl;
            messageErreurJoueur = " ";
            code = saisie();
            break;
        case 11:
            code = verifierSiDansMot();
            break;
        case 13:
            code = saisie();
            break;
        case 14:
            code = verificationLettre();
            break;
        case 21:
            code = bonneLettre();
            break;
        case 22:
            code = mauvaiseLettre();
            break;
        case 42:
            code = gagne();
            break;
        case 43:
            code = perdu();
            break;
    }
    return code;
}

int saisie(){

    potence();
    cout << endl << motCache << " : Saississez une lettre sauf " << lettresMauvaises << " : ";
    cin >> lettre;

    code = 14;
    return code;
}

int choisirUnMot(){

    int LINE = 0;
    LINE = aleatoire();

    std::ifstream fichier("../sources/mots.txt");
    std::string buffer;

    for (int i = 1; i <= LINE; i++) {
        std::getline(fichier, buffer);
    }

    fichier.close();
    motChoisis = buffer;

    return 02;
}

int aleatoire(){

    srand(time(NULL));

    int result = (rand() %80);

    if(result < 0 | result > 80 ){
        result = 1;
    }

    return result;
}


int cacherLeMot() {

    string mot = motChoisis;

    for (int i = 0; i < motChoisis.length(); i++){
        mot[i] = '-';
    }

    motCache = mot;

    return 02;
}

int verificationLettre(){

    // Verification 1 : Verifie que la saisie est unique (Une seule lettre)
    if(lettre.length() > 1){
        code = 10; // 2 lettres
        messageErreurJoueur = "UNE SEULE LETTRE, IMBECILE !!! ";

    }else if(lettre.length() == 1){
        derniereLettreTape = tolower(lettre[0]);
        code = 11; // rien a dire saisie
        messageErreurJoueur = " ";

    }

    // Verification 2 : Verifie que la lettre tapé n'est pas dans le tableau lettresBonnes ni dans le tableau lettresMauvaises
    for (int i = 0; i < 6; i++) {
        if (lettresBonnes[i] == derniereLettreTape | lettresMauvaises[i] == derniereLettreTape) {
            code = 10; // deja tape
            messageErreurJoueur += "DEJA ESSAYE, IMBECILE !!! ";
            }
    }

    return code;
}

int verifierSiDansMot(){

    int counter = 0;

    for (int i = 0; i < motChoisis.length(); i++) {
        if(motChoisis[i] == derniereLettreTape) {
            counter ++;
        }
    }

    if(counter > 0) {
        // si la lettre est presente dans le mot
        code = 21;
    }else{
        // la lettre n'est pas presente dans le mot
        code = 22;
    }

    return code;
}

int bonneLettre(){


        for (int i = 0; i < motChoisis.length(); i++) {
            if(char(motChoisis[i]) == derniereLettreTape) {
                motCache[i] = derniereLettreTape;
                lettresBonnes[i] = derniereLettreTape;
            }
        }

        nombreDeReussisActuel ++;

    code = 13;
    return code;
}

int mauvaiseLettre(){

    lettresMauvaises[nombreDeRatesActuel] = derniereLettreTape;
    nombreDeRatesActuel ++;

    code = 13;
    return code;
}

int VerifEtatDujeu(){


    if(nombreDeRatesActuel == nombreDeRatesMaximum){
        code = 43;

    }

    if(motChoisis == motCache){
        code = 42;

    }

    return code;
}

int gagne(){

    boucleJeu = false;

    // ############################################ //
    // Affiche sur le console :

    potence();
    cout << endl << motCache << " : " << "GAGNE !!!!!!!!!!!!!!!!!";

    // ############################################ //
    // Ouvre s'il existe sinon creer le fichier gagne.txt, Puis insere les informations de la partie entamé.
    ofstream myfile;
    myfile.open ("../gagne.txt");
    myfile << "GAGNE\n";
    myfile << "Le mot a trouver etait : " << motChoisis << "\n";
    myfile << "Etat du mot trouve : " << motCache << "\n";
    myfile << "Nombre d'essais : " << (nombreDeRatesActuel + nombreDeReussisActuel) << "\n";
    myfile.close();
    // ############################################ //
    return 02;
}

int perdu(){

    // A la fin de cette fonction, La boucle est cassé.
    boucleJeu = false;


    // ############################################ //
    // Affiche sur le console :

    potence();
    cout << "PENDU!!!!!";
    cout << endl << "Le mot cache etait : " << motChoisis;

    // ############################################ //
    // Ouvre s'il existe sinon creer le fichier perdu.txt, Puis insere les informations de la partie entamé.

    ofstream myfile;
    myfile.open ("../perdu.txt");
    myfile << "PERDU\n";
    myfile << "Le mot a trouver etait : " << motChoisis << "\n";
    myfile << "Etat du mot trouve : " << motCache << "\n";
    myfile << "Nombre d'essais : " << (nombreDeRatesActuel + nombreDeReussisActuel) << "\n";
    myfile.close();

    // ############################################ //
    return 02;

}

int potence(){

//    char potencetab[6][15];

    // Dessine et affiche la ligne du haut
    for (int i = 0; i < 16; ++i) {
        potencetab[0][i] = 95;
        cout << potencetab[0][i];
    }

    // Dessine la potence complete

    potencetab[1][0] = ' ';
    potencetab[1][1] = '|';
    potencetab[2][0] = ' ';
    potencetab[2][1] = '|';
    potencetab[3][1] = ' ';
    potencetab[3][2] = 'O';
    potencetab[4][0] = '/';
    potencetab[4][1] = '|';
    potencetab[4][2] = 92;
    potencetab[5][0] = '/';
    potencetab[5][1] = ' ';
    potencetab[5][2] = 92;

    // Affiche les deux tires vers le bas
    cout << endl << potencetab[1][0];
    cout << potencetab[1][1];
    cout << endl << potencetab[2][0];
    cout << potencetab[2][1];


    // Par rapport aux nombre de rates la potence affiche de plus en plus de characteres.
    if (nombreDeRatesActuel >= 1) {

        cout << endl << potencetab[3][1];
        cout << potencetab[3][2];

        if (nombreDeRatesActuel >= 2) {
            cout << endl << potencetab[4][0];
        }

        if (nombreDeRatesActuel >= 3) {
            cout << potencetab[4][1];
        }

        if (nombreDeRatesActuel >= 4) {
            cout << potencetab[4][2] << endl;
        }

        if (nombreDeRatesActuel >= 5) {
            cout << potencetab[5][0];
        }

        if (nombreDeRatesActuel >= 6) {
            cout << potencetab[5][1];
            cout << potencetab[5][2];
        }
    }

    return 02;
}
