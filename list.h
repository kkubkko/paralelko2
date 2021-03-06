/* 
 * File:   list.h
 * Author: Lukáš Junek
 *
 * Created on 8. březen 2014, 22:11
 */

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstdlib>
#include "tab/data.h"
#include "vlakno.h"

using namespace std;

struct polozka {
    Vlakno *vlakno;
    polozka *left;
    polozka *right;
};

class List {
private:
    polozka *m_first;
    polozka *m_last;
    polozka *m_akt;
    int m_poc_polozkek;
    int m_act_pozice;
    
public:
    List();
    ~List();
    void pridejNaKonec(Vlakno *p_vlakno);
    void pridejNaZacatek(Vlakno *p_vlakno);
    void smazAkt();
    void smazPrv(polozka* prv);
    void smazFirst();
    void smazLast();
    void nastavAktNaFirst();
    Vlakno* vratPrvni();
    Vlakno* vratPosledni();
    Vlakno* vratAkt();
    polozka* vratAktPrv();
    void aktLeft();
    void aktRight();
    bool aktFirst();
    bool aktLast();
    bool akt();
    bool isEmpty();
    int vratPocPolozek();
    int vratAktualniPozici();
    void smazVse();
    
    void aktVstupVlakna(int p_vstup);
    int vratVstupVlakna();
    void aktStavVlakna(int p_stav);
    int vratStavVlakna();
};

#endif	/* LIST_H */

