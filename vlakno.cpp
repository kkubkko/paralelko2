/* 
 * File:   Vlakno.cpp
 * Author: Lukáš Junek
 * 
 * Created on 8. březen 2014, 21:01
 */

#include "vlakno.h"
/*
 * Konstruktor
 */
Vlakno::Vlakno() {
    m_st_st.push(st_emp);
    m_st_trm.push(st_emp);
    m_akt_stav = st_emp;
    m_err_stav = OK;
    m_vzdalenost = 0;
    m_prvni = false;
    m_oprava = false;
    m_vysledek = "";
    m_cis_vysl = -1;
    m_akt_vstup = vs_end;
    m_konec = false; 
    m_konflikt = false;
}
/*
 * Kopírovací konstruktor zásobníku stavů.
 */
stack<int> Vlakno::copyStateStack(const Vlakno *p_puvodni){
    stack<int> zasobnik (p_puvodni->m_st_st);
    return zasobnik;
}
/*
 * Kopírovací konstruktor zásobníku tokenů.
 */
stack<int> Vlakno::copyTermStack(const Vlakno *p_puvodni){
    stack<int> zasobnik (p_puvodni->m_st_trm);
    return zasobnik;
}
/*
 * Kopírovací konstruktor samotného vlákna.
 */
Vlakno::Vlakno(const Vlakno *p_puvodni) {
    m_st_st = copyStateStack(p_puvodni);
    m_st_trm = copyTermStack(p_puvodni);
    m_akt_stav = p_puvodni->m_akt_stav;
    m_akt_vstup = p_puvodni->m_akt_vstup;
    m_vzdalenost = p_puvodni->m_vzdalenost;    
    m_polozka = p_puvodni->m_polozka;
    m_vysledek = p_puvodni->m_vysledek;
    m_cis_vysl = p_puvodni->m_cis_vysl;
    m_prvni = p_puvodni->m_prvni;
    m_oprava = p_puvodni->m_oprava;
    m_konec = p_puvodni->m_konec;
    m_err_stav = p_puvodni->m_err_stav;
    m_konflikt = p_puvodni->m_konflikt;
}

Vlakno::~Vlakno() {
}


