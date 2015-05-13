/* 
 * File:   redukce.cpp
 * Author: Luky
 * 
 * Created on 8. březen 2014, 18:49
 */

#include "redukce.h"
/*
 * Konstruktor
 */
Redukce::Redukce() { 
    tb_alfa = new LRtabulka();
    tb_beta = new LRtabulka_beta();
}
/*
 * Destruktor
 */
Redukce::~Redukce() {
    delete tb_alfa;
    delete tb_beta;
}
/*
 * Na základě pravidla z LR tabulky provádí funkce redukci tokenů na zásobníku
 */
int Redukce::reduce(Vlakno *p_vlakno, int p_pravidlo){
    int pravidlo;
    bool chyba = false;
    int zas, zas2, zas3, zas4, newSt;
    switch (p_pravidlo){
        case 1:
            // odebrání tokenu ze zásobníku
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas == vs_a){ // kontrola tokenu
                newSt = p_vlakno->m_st_st.top();
                // nahrazení tokenu nonterminálem
                p_vlakno->m_st_trm.push(nt_A);
                // vyhledání nového stavu
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_A);
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
        case 2:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas == vs_b){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_B);                
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_B);
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
        case 3:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas == vs_c){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_C);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_C);
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
        case 4:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas == vs_d){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_D);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_D);
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
        case 5:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas == vs_e){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_E);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_E); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
        case 6:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas == vs_f){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_F);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_F);
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;            
        case 7:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas == vs_g){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_G);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_G);
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
        case 8:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas == vs_h){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_H);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_H); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
        case 9:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas == nt_A && zas2 == nt_A){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_A);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_A); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
        case 10:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas == nt_B && zas2 == nt_B){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_B);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_B); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
        case 11:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas == nt_C && zas2 == nt_C){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_C);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_C); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
        case 12:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas == nt_D && zas2 == nt_D){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_D);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_D);
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
        case 13:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas == nt_E && zas2 == nt_E){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_E);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_E);
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
        case 14:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_F && zas == nt_F){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_F);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_F); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
        case 15:
           zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_G && zas == nt_G){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_G);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_G); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
        case 16:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_H && zas == nt_H){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_H);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_H); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
        case 17:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_D && zas == nt_B){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_1);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_1); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
        case 18:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_F && zas == nt_B){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_1);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_1); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1; 
            } else {
                chyba = true;
            }
            break;
        case 19:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_D && zas2 == nt_F && zas == nt_B){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_1);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_1); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break;
        case 20:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_D && zas2 == nt_H && zas == nt_B){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_1);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_1); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break;  
        case 21:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas == nt_E) {
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_2);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_2);
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);                
            } else {
                chyba = true;
            }
            break;
        case 22:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_H && zas == nt_E){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_2);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_2); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break;
            
        case 23:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_C && zas == nt_E){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_2);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_2); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break;
            
        case 24:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_H && zas2 == nt_C && zas == nt_E){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_2);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_2); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 2;
            } else {
                chyba = true;
            }
            break;
            
        case 25:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_C && zas == nt_A){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_3);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_3); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
            
        case 26:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_H && zas2 == nt_C && zas == nt_A){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_3);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_3); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break;
            
        case 27:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_C && zas2 == nt_E && zas == nt_A){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_3);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_3); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break;
            
        case 28:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas4 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas4 == nt_H && zas3 == nt_C && zas2 == nt_E && zas == nt_A){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_3);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_3); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 2;
            } else {
                chyba = true;
            }
            break;
            
        case 29:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_D && zas == nt_H){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_4);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_4); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
            
        case 30:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_D && zas2 == nt_B && zas == nt_H){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_4);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_4); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break;
            
        case 31:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_D && zas2 == nt_F && zas == nt_H){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_4);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_4); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break;
            
        case 32:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas4 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas4 == nt_D && zas3 == nt_F && zas2 == nt_B && zas == nt_H){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_4);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_4); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 2;
            } else {
                chyba = true;
            }
            break;
            
        case 33:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_H && zas == nt_A){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_5);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_5); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
            
        case 34:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_H && zas2 == nt_C && zas == nt_A){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_5);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_5); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break;
            
        case 35:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas4 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas4 == nt_H && zas3 == nt_C && zas2 == nt_E && zas == nt_A){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_5);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_5); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 2;
            } else {
                chyba = true;
            }
            break;
            
        case 36:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas == nt_A) {
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_6);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_6);
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);                
            } else {
                chyba = true;
            }
            break;
            
        case 37:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_C && zas == nt_A){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_6);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_6); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break;
            
        case 38:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_C && zas2 == nt_E && zas == nt_A){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_6);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_6); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 2;
            } else {
                chyba = true;
            }
            break;
            
        case 39:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_C && zas == nt_G){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_8);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_8); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
            
        case 40:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_C && zas2 == nt_E && zas == nt_G){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_8);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_8); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break;
            
        case 41:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_C && zas2 == nt_A && zas == nt_G){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_8);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_8); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break; 
            
        case 42:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas4 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas4 == nt_C && zas3 == nt_E && zas2 == nt_A && zas == nt_G){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_8);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_8); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 2;
            } else {
                chyba = true;
            }
            break;
            
        case 43:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_D && zas2 == nt_F && zas == nt_H){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_9);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_9); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break; 
            
        case 44:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas4 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas4 == nt_D && zas3 == nt_F && zas2 == nt_B && zas == nt_H){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_9);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_9); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break;
            
        case 45:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_F && zas == nt_C){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_h);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_h); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
            
        case 46:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_F && zas2 == nt_B && zas == nt_C){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_h);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_h); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break;
            
        case 47:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_F && zas2 == nt_H && zas == nt_C){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_h);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_h); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break;
            
        case 48:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas4 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas4 == nt_F && zas3 == nt_B && zas2 == nt_H && zas == nt_C){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_h);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_h); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 2;
            } else {
                chyba = true;
            }
            break;
            
        case 49:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_x && zas2 == nt_G && zas == nt_E){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_I);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_I); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
            
        case 50:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_C && zas == nt_B){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_J);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_J); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
            
        case 51:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_D && zas == nt_A){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_K);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_K); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
            
        case 52:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_A && zas == nt_G){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_W);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_W); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
            
        case 53:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_Z && zas == nt_A){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_L);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_L); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
            
        case 54:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_C && zas == nt_E){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_M);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_M); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
            
        case 55:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_E && zas2 == nt_H && zas == nt_A){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_N);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_N); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
            
        case 56:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_6 && zas == nt_G){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_7);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_7); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
            
        case 57:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_1 && zas2 == nt_1 && zas == nt_J){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_X);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_X); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
            
        case 58:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_3 && zas2 == nt_3 && zas == nt_K){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_Y);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_Y); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
            
        case 59:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_E && zas == nt_G){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_O);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_O); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
            
        case 60:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_D && zas == nt_F){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_F);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_F); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break;
            
        case 61:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_D && zas == nt_F){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_P);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_P); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
            
        case 62:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_E && zas == nt_A){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_Q);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_Q); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
            
        case 63:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_D && zas == nt_9){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_R);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_R); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
            
        case 64:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_8 && zas == nt_E){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_T);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_T); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
            
        case 65:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_P && zas == nt_B){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_U);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_U); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
            
        case 66:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_H && zas2 == nt_C && zas == nt_E){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_V);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_V); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
            
        case 67:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_1 && zas == nt_2){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_S);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_S); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vysledek = "Objekt je trojuhelnik! - 12\n";
                p_vlakno->m_cis_vysl = 1;
                p_vlakno->m_konec = true;
            } else {
                chyba = true;
            }
            break;
            
        case 68:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_4 && zas == nt_2){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_S);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_S); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vysledek = "Objekt je trojuhelnik! - 42\n";
                p_vlakno->m_cis_vysl = 1;
                p_vlakno->m_konec = true;
            } else {
                chyba = true;
            }
            break;
            
        case 69:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_4 && zas == nt_6){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_S);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_S); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vysledek = "Objekt je trojuhelnik! - 46\n";
                p_vlakno->m_cis_vysl = 1;
                p_vlakno->m_konec = true;
            } else {
                chyba = true;
            }
            break;
            
        case 70:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_1 && zas2 == nt_2 && zas == nt_I){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_S);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_S); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vysledek = "Objekt je sipka! - 12I\n";
                p_vlakno->m_cis_vysl = 5;
                p_vlakno->m_konec = true;
            } else {
                chyba = true;
            }
            break;
            
        case 71:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_1 && zas2 == nt_4 && zas == nt_L){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_S);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_S); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vysledek = "Objekt je sipka! - 14L\n";
                p_vlakno->m_cis_vysl = 5;
                p_vlakno->m_konec = true;
            } else {
                chyba = true;
            }
            break;
            
        case 72:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_4 && zas2 == nt_k && zas == nt_N){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_S);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_S); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vysledek = "Objekt je sipka! - 4kN\n";
                p_vlakno->m_cis_vysl = 5;
                p_vlakno->m_konec = true;
            } else {
                chyba = true;
            }
            break;
            
        case 73:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_4 && zas == nt_8){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_S);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_S); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vysledek = "Objekt je rovnobeznik! - 48\n";
                p_vlakno->m_cis_vysl = 3;
                p_vlakno->m_konec = true;
            } else {
                chyba = true;
            }
            break;
            
        case 74:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_P && zas == nt_M){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_S);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_S); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vysledek = "Objekt je rovnobeznik! - PM\n";
                p_vlakno->m_cis_vysl = 3;
                p_vlakno->m_konec = true;
            } else {
                chyba = true;
            }
            break;
            
        case 75:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_1 && zas == nt_3){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_S);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_S); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vysledek = "Objekt je ctverec! - 13\n";
                p_vlakno->m_cis_vysl = 2;
                p_vlakno->m_konec = true;
            } else {
                chyba = true;
            }
            break;
            
        case 76:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_X && zas == nt_Y){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_S);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_S); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vysledek = "Objekt je kriz! - XY\n";
                p_vlakno->m_cis_vysl = 7;
                p_vlakno->m_konec = true;
            } else {
                chyba = true;
            }
            break;
            
        case 77:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_4 && zas == nt_7){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_S);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_S); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vysledek = "Objekt je lichobeznik! - 47\n";
                p_vlakno->m_cis_vysl = 4;
                p_vlakno->m_konec = true;
            } else {
                chyba = true;
            }
            break;
            
        case 78:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_4 && zas == nt_M){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_S);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_S); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vysledek = "Objekt je lichobeznik! - 4M\n";
                p_vlakno->m_cis_vysl = 4;
                p_vlakno->m_konec = true;
            } else {
                chyba = true;
            }
            break;
            
        case 79:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_P && zas == nt_8){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_S);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_S); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vysledek = "Objekt je lichobeznik! - P8\n";
                p_vlakno->m_cis_vysl = 4;
                p_vlakno->m_konec = true;
            } else {
                chyba = true;
            }
            break;
            
        case 80:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_U && zas == nt_2){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_S);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_S); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vysledek = "Objekt je lichobeznik! - P2\n";
                p_vlakno->m_cis_vysl = 4;
                p_vlakno->m_konec = true;
            } else {
                chyba = true;
            }
            break;
            
        case 81:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_U && zas2 == nt_V && zas == nt_W){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_S);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_S); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vysledek = "Objekt je osmiuhelnik! - UVW\n";
                p_vlakno->m_cis_vysl = 9;
                p_vlakno->m_konec = true;
            } else {
                chyba = true;
            }
            break;
            
        case 82:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_1 && zas2 == nt_3 && zas == nt_3){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_S);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_S); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vysledek = "Objekt je L-tvar! - 133\n";
                p_vlakno->m_cis_vysl = 8;
                p_vlakno->m_konec = true;
            } else {
                chyba = true;
            }
            break;
            
        case 83:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_1 && zas2 == nt_J && zas == nt_3){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_S);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_S); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vysledek = "Objekt je L-tvar! - 1J3\n";
                p_vlakno->m_cis_vysl = 8;
                p_vlakno->m_konec = true;
            } else {
                chyba = true;
            }
            break;
            
        case 84:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_1 && zas2 == nt_3 && zas == nt_K){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_S);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_S); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vysledek = "Objekt je L-tvar! - 13K\n";
                p_vlakno->m_cis_vysl = 8;
                p_vlakno->m_konec = true;
            } else {
                chyba = true;
            }
            break;
            
        case 85:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_1 && zas2 == nt_1 && zas == nt_3){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_S);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_S); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vysledek = "Objekt je L-tvar! - 113\n";
                p_vlakno->m_cis_vysl = 8;
                p_vlakno->m_konec = true;
            } else {
                chyba = true;
            }
            break;
            
        case 86:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_1 && zas2 == nt_5 && zas == nt_8){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_S);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_S); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vysledek = "Objekt je dvojita sipka! - 158\n";
                p_vlakno->m_cis_vysl = 6;
                p_vlakno->m_konec = true;
            } else {
                chyba = true;
            }
            break;
            
        case 87:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_4 && zas2 == nt_h && zas == nt_O){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_S);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_S); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vysledek = "Objekt je dvojita sipka! - 4*O\n";
                p_vlakno->m_cis_vysl = 6;
                p_vlakno->m_konec = true;
            } else {
                chyba = true;
            }
            break;
            
        case 88:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_9 && zas == nt_T){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_S);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_S); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vysledek = "Objekt je dvojita sipka! - 9T\n";
                p_vlakno->m_cis_vysl = 6;
                p_vlakno->m_konec = true;
            } else {
                chyba = true;
            }
            break;
        
        case 89:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_P && zas2 == nt_J && zas == nt_Q){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_S);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_S); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vysledek = "Objekt je dvojita sipka! - PJQ\n";
                p_vlakno->m_cis_vysl = 6;
                p_vlakno->m_konec = true;
            } else {
                chyba = true;
            }
            break;
         
        case 90:
            p_vlakno->m_err_stav = END;
            //p_vlakno->m_vzdalenost +=
            return 1;
            break;
            
        case 91:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_F && zas == nt_H){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_k);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_k); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
            
        case 92:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_F && zas2 == nt_B && zas == nt_H){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_k);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_k); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break;
         
        case 93:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_H && zas == nt_E){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_x);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_x); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;   
            
        case 94:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_H && zas2 == nt_C && zas == nt_E){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_x);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_x); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break; 
            
        case 95:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas2 == nt_E && zas == nt_D){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_Z);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_Z); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
            } else {
                chyba = true;
            }
            break;
            
        case 96:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_E && zas2 == nt_A && zas == nt_D){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_Z);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_Z); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break; 
            
        case 97:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_E && zas2 == nt_G && zas == nt_D){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_Z);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_Z); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break;
            
        case 98:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas4 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas4 == nt_E && zas3 == nt_A && zas2 == nt_G && zas == nt_D){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_Z);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_Z); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 2;
            } else {
                chyba = true;
            }
            break; 
            
        case 99:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_E && zas2 == nt_A && zas == nt_G){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_O);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_O); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break;    
            
        case 100:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas4 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas4 == nt_H && zas3 == nt_C && zas2 == nt_E && zas == nt_A){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_x);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_x); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 2;
            } else {
                chyba = true;
            }
            break;     
            
        case 101:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_H && zas2 == nt_C && zas == nt_B){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_J);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_J); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break;
        
        case 102:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_G && zas2 == nt_D && zas == nt_A){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_K);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_K); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break; 
            
        case 103:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas4 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas4 == nt_E && zas3 == nt_C && zas2 == nt_H && zas == nt_A){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_N);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_N); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break;  
            
        case 104:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_D && zas2 == nt_H && zas == nt_B){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_4);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_4); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break;
            
        case 105:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas3 == nt_D && zas2 == nt_F && zas == nt_B){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_P);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_P); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 1;
            } else {
                chyba = true;
            }
            break;
            
        case 106:
            zas = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas2 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas3 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            zas4 = p_vlakno->m_st_trm.top();
            p_vlakno->m_st_trm.pop();
            p_vlakno->m_st_st.pop();
            
            if (zas4 == nt_D && zas3 == nt_F && zas2 == nt_B && zas == nt_H){
                newSt = p_vlakno->m_st_st.top();
                p_vlakno->m_st_trm.push(nt_P);
                p_vlakno->m_akt_stav = tb_beta->vratHodTabulky(newSt, nt_P); 
                p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
                p_vlakno->m_vzdalenost += 2;
            } else {
                chyba = true;
            }
            break; 
        default:
            p_vlakno->m_akt_stav = zd_stav;
    }
    //cout << "novSt je: " << newSt << "\nnovy stav: " << p_vlakno->m_akt_stav << endl;
    //cout << "velikost zasobniku: " << p_vlakno->m_st_st.size() << endl << endl;
    if (chyba) {
        return -1;
    } else {
        return 0;
    }

}
    

