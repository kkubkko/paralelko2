
/* 
 * File:   scanner.h
 * Author: Lukáš Junek
 *
 * Created on 5. listopad 2013, 18:00
 */
using namespace std;

#ifndef SCANNER_H
#define	SCANNER_H
#include "tab/data.h"
#include <iostream>
#include <string>
#include <sstream>

class Scanner {
private:
    string m_vstup;
    int charToToken(char p_vstup);
    bool tocilVlevo();
    int otocVpravo();
    int otocVlevo();
    bool pocatecniHrana();
    bool jeNahore();
    void orotuj(int p_pocet);
public:
    Scanner();
    int nactiDalsi();
    int dalsiToken();
    int nactiTokenZa(int p_token);
    string vratZbytek();
    bool jeKonec();    
    int nastavNaZacatek();
    int vratPocZbRetezce();
    void vstupniRetezec(string p_vstup);
    void newInit();
};

#endif	/* SCANNER_H */

