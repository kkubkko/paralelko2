/* 
 * File:   scanner.cpp
 * Author: Lukáš Junek
 * 
 * Created on 5. listopad 2013, 18:00
 */

#include "scanner.h"

Scanner::Scanner() {
    m_vstup = "";
}
/*
 * Funkce načítá vstupní řetězec.
 */
void Scanner::vstupniRetezec(string p_vstup) {
    string pom, c;
    stringstream ss;
    char c1 = 'p'; char c2 = 'p';
    
    
    for (int i = 0; i < p_vstup.length(); i++){
        c1 = p_vstup[i];
        if (c1 != c2){
            pom.append(1, c1);
            c2 = c1;
        }        
    }
    //cout << "pom_vstup: " << pom << endl;
    
   m_vstup = pom;
   // m_vstup = p_vstup;
}
/*
 * Funkce rozhoduje, zda dojde k otočení objektu doprava, nebo doleva.
 */
bool Scanner::tocilVlevo() {
    char vstup = m_vstup[0];
    if (vstup == 'a' || vstup == 'g' || vstup == 'e') {
        return true;        
    } else {
        return false;
    }
}
/*
 * Funkce otáčí objekt o stupňů doleva. 
 */
int Scanner::otocVlevo() {
    char vstup, pom;
    for (int i = 0; i < m_vstup.length(); i++) {
        vstup = m_vstup[i];
        switch (vstup) {
            case 'a':
                pom = 'g';
                break;
            case 'g':
                pom = 'd';
                break;
            case 'd':
                pom = 'f';
                break;
            case 'f':
                pom = 'b';
                break;
            case 'b':
                pom = 'h';
                break;
            case 'h':
                pom = 'c';
                break;
            case 'c':
                pom = 'e';
                break;
            case 'e':
                pom = 'a';
                break;
            default:
                return -1;
        }
        m_vstup[i] = pom;
    }
    return 0;
}
/*
 * Funkce otáčí objekt o stupňů doprava. 
 */
int Scanner::otocVpravo() {
    char vstup, pom;
    for (int i = 0; i < m_vstup.length(); i++) {
        vstup = m_vstup[i];
        switch (vstup) {
            case 'a':
                pom = 'e';
                break;
            case 'g':
                pom = 'a';
                break;
            case 'd':
                pom = 'g';
                break;
            case 'f':
                pom = 'd';
                break;
            case 'b':
                pom = 'f';
                break;
            case 'h':
                pom = 'b';
                break;
            case 'c':
                pom = 'h';
                break;
            case 'e':
                pom = 'c';
                break;
            default:
                return -1;
        }
        m_vstup[i] = pom;
    }
    return 0;
}
/*
 * Funkce převádí vstupní znak do vnitřní reprezentace.
 */
int Scanner::charToToken(char p_vstup){ 
    int term;
    switch (p_vstup){
        case 'a':
            term = vs_a;
            break;
        case 'b':
            term = vs_b;
            break;
        case 'c':
            term = vs_c;
            break;
        case 'd':
            term = vs_d;
            break;
        case 'e':
            term = vs_e;
            break;
        case 'f':
            term = vs_f;
            break;                   
        case 'g':
            term = vs_g;
            break;
        case 'h':
            term = vs_h;
            break;
        default:
            term = vs_end;
    }
    return term;
}
/*
 * Funkce posílá aktuální token do parseru a odebírá ho ze vstupu.
 */
int Scanner::nactiDalsi() {
    char vstup;
    vstup = m_vstup[0];
    if (m_vstup.length() > 0) m_vstup = m_vstup.substr(1);
    else return vs_end;
    return charToToken(vstup);
}
/*
 * Fukce vrací aktuální token (ale neodebírá jej ze vstupu).
 */
int Scanner::dalsiToken(){
    char vstup;
    if (m_vstup.length() > 0) {
        vstup = m_vstup[0];
        return charToToken(vstup); 
    } else {
        return vs_end;
    }    
}
/*
 * Funkce vrací zbylý vstupní řetězec - aktuálně nevyužíváno.
 */
string Scanner::vratZbytek(){
    return m_vstup;
}
/*
 * Funkce vrací token, který se nachází za tokenem v parametru.
 */
int Scanner::nactiTokenZa(int p_token){
    char vstup;
    int pom_i = 0;
    if (m_vstup.length() > 0) {
        vstup = m_vstup[pom_i];
        pom_i++;
        while (charToToken(vstup) == p_token && pom_i != m_vstup.length()) {
            vstup = m_vstup[pom_i];
            pom_i++;
        }
        if (charToToken(vstup) != p_token) {
            return charToToken(vstup);
        } else {
            return vs_end;
        }
    } else {
        return vs_end;
    }
}
/*
 * Kontrola prázdnosti vstupního řetězce.
 */
bool Scanner::jeKonec(){
    if (m_vstup.length() == 0) {
        return true;
    } else {
        return false;
    }
}
/*
 * Kontrola počáteční hrany.
 */
bool Scanner::pocatecniHrana(){
    if (m_vstup[0] == 'd') {
        return true;
    } else {
        return false;
    }    
}
/*
 * Provedení posunutí začátku řetězce nahoru doprava.
 */
void Scanner::orotuj(int p_pocet){
    char pom;
    //int delka = m_vstup.length();
    for (int i = 0; i < p_pocet + 1; i++) {
        for (int j = 0; j < m_vstup.length()-1; j++){
            pom = m_vstup[j];
            m_vstup[j] = m_vstup[j+1];
            m_vstup[j+1] = pom;
        }
    }    
}
/*
 * Kontrola, zda se začátek řetězce nachází vpravo nahoře.
 */
bool Scanner::jeNahore(){
    bool prv = true; char c;
    int pulka = m_vstup.length()/2;
    for (int i = 0; i < pulka; i++){
        if (m_vstup[i] == 'a' || /*m_vstup[i] == 'e' ||*/ m_vstup[i] == 'g' || !prv) {
            if (prv) {
                c = m_vstup[i];
                prv = false;
            }
            if (c == m_vstup[i]) {
                continue;
            } else {
                orotuj(i-1);
                //cout << "vysledek rotace je: " << m_vstup << endl;
                return false;
            }
        }
    }
    return true;    
}
/*
 * Hlavní funkce řídí posunutí řetězce do výchozího tvaru.
 */
int Scanner::nastavNaZacatek() {
    //cout << "sem tu\n";
    if (m_vstup == "") {
        return -1;
    }
    do {
        jeNahore();
        if (!pocatecniHrana()) {
            if (tocilVlevo()) {
                do {
                    if (otocVlevo() == -1) {
                        return -1;
                    }
                    //cout << "aktualni vystup je: " << m_vstup << endl;
                } while (!pocatecniHrana());
            } else {
                do {
                    if (otocVpravo() == -1) {
                        return -1;
                    }
                    //cout << "aktualni vystup je: " << m_vstup << endl;
                } while (!pocatecniHrana());
            }
        }
    } while (!jeNahore());
    //cout << "Posledni uprava: " << m_vstup << endl;
    return 0;
}
/*
 * Vrací údaj o délce zbylého řetězce.
 */
int Scanner::vratPocZbRetezce() {
    if (m_vstup.length() > 0) {
        return m_vstup.length() - 1;
    } else {
        return 0;
    }
}






