/* 
 * File:   list.cpp
 * Author: Lukáš Junek
 * 
 * Created on 8. březen 2014, 22:11
 */

#include "list.h"
/*
 * Dokument obsahuje triviální funkce pro obsluhu seznamu vláken,
 * které nejsou potřeba zvášť komentovat. 
 */


List::List() {
    m_poc_polozkek = 0;
    m_first = 0;
    m_last = 0;
    m_akt = 0;
}

List::~List() {
    polozka *pom;
    while (m_first != 0) {
        pom = m_first;
        m_first = m_first->left;
        delete pom;
    }
}

void List::smazVse() {
    while (!isEmpty()){
        smazFirst();
    }
}

void List::pridejNaZacatek(Vlakno* p_vlakno){
    polozka *pom = new polozka;
    pom->vlakno = p_vlakno;
    pom->left = 0;
    pom->right = m_first;
    if (m_first != 0) {
        m_first->left = pom;
    }
    m_first = pom;
    if (m_last == 0) {
        m_last = m_first;
    }
    m_poc_polozkek++;
}

void List::pridejNaKonec(Vlakno* p_vlakno){
    polozka *pom = new polozka;
    if (m_last == 0) {
        pridejNaZacatek(p_vlakno);
    } else {
        pom->vlakno = p_vlakno;
        pom->left = m_last;
        pom->right = 0;
        m_last->right = pom;
        m_last = pom;
        m_poc_polozkek++;
    }
}

Vlakno* List::vratPosledni(){
    if (m_last != 0) {
        return m_last->vlakno;
    } else {
        return 0;
    }    
}

Vlakno* List::vratPrvni() {
    if (m_first != 0) {
        return m_first->vlakno;
    } else {
        return 0;
    }
}

Vlakno* List::vratAkt() {
    if (m_akt != 0) {
        return m_akt->vlakno;
    } else {
        return 0;
    }
}

void List::nastavAktNaFirst() {
    m_akt = m_first;
}

void List::aktLeft() {
    if (m_akt != 0) {
        m_akt = m_akt->left;
    }
}

void List::aktRight() {
    if (m_akt != 0) {
        m_akt = m_akt->right;
    }
}

bool List::aktFirst() {
    if (m_akt == m_first) {
        return true;
    } else {
        return false;
    }
}

bool List::aktLast() {
    if (m_akt == m_last) {
        return true;
    } else {
        return false;
    }
}

bool List::akt() {
    if (m_akt != 0) {
        return true;
    } else {
        return false;
    }
}

void List::smazAkt() {
    polozka *pom;
    if (m_akt != 0) {
        if (m_akt == m_first) {
            m_first = m_akt->right;
        }
        if (m_akt == m_last) {
            m_last = m_akt->left;
        }
        pom = m_akt;
        m_akt = pom->right;
        if (!pom->right == 0) {
            pom->right->left = pom->left;
        }
        if (!pom->left == 0) {
            pom->left->right = pom->right;
        }
        delete pom;
        m_poc_polozkek--;
    }
}

void List::smazFirst() {
    polozka *pom;
    if (m_first != 0) {
        pom = m_first;
        m_first = pom->right;
        if (m_first != 0) m_first->left = 0;
        delete pom;
        m_poc_polozkek--;
    }
}

void List::smazLast() {
    polozka *pom;
    if (m_last != 0) {
        pom = m_last;
        m_last = pom->left;
        if (m_last != 0) m_last->right = 0;
        delete pom;
        m_poc_polozkek--;
    }
}

int List::vratPocPolozek(){
    return m_poc_polozkek;
}

bool List::isEmpty() {
    if (m_first == 0) {
        return true;
    } else {
        return false;
    }
}

void List::aktVstupVlakna(int p_vstup) {
    polozka *pom;
    if (m_akt != 0) {
        pom = m_akt;
        pom->vlakno->m_akt_vstup = p_vstup;
    }
}

int List::vratVstupVlakna() {
    if (m_akt != 0) {
        return m_akt->vlakno->m_akt_vstup;
    } else {
        return vs_end;
    }
}

void List::aktStavVlakna(int p_stav){
    if (m_akt != 0) {
        m_akt->vlakno->m_err_stav = p_stav;
    }
}

int List::vratStavVlakna() {
    if (m_akt != 0) {
        return m_akt->vlakno->m_err_stav;
    } else {
        return OK;
    }
}
