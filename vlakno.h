/* 
 * File:   Vlakno.h
 * Author: Lukáš Junek
 *
 * Created on 8. březen 2014, 21:01
 */
using namespace std;

#ifndef VLAKNO_H
#define	VLAKNO_H
#include <iostream>
#include <stack>
#include "tab/data.h"
#include "tab/lrtab.h"
#include "tab/lrtab_b.h"

class Vlakno {
public:
    stack<int> m_st_st;
    stack<int> m_st_trm;
    int m_akt_stav;
    int m_akt_vstup;
    int m_vzdalenost;    
    tab_polozka m_polozka;
    string m_vysledek;
    int m_cis_vysl;
    bool m_prvni;
    bool m_oprava;
    bool m_konec;
    int m_err_stav;
    bool m_konflikt;
    
    Vlakno();
    Vlakno(const Vlakno *p_puvodni);
    stack<int> copyStateStack(const Vlakno *p_puvodni);
    stack<int> copyTermStack(const Vlakno *p_puvodni);
    ~Vlakno();
    


};

#endif	/* VLAKNO_H */

