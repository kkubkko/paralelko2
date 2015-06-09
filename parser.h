/* 
 * File:   parser.h
 * Author: Lukáš Junek
 *
 * Created on 2. listopad 2013, 19:51
 */
//using namespace std;

#ifndef PARSER_H
#define	PARSER_H
#include <stack>
#include <list>
#include <iostream>
#include <mutex>
#include "redukce.h"
#include "tab/data.h"
#include "tab/lrtab.h"
#include "tab/lrtab_b.h"
#include "scanner.h"
#include "vlakno.h"
#include "list.h"


using namespace std;

class Parser {
private:
    Redukce m_redukce;
    List m_list;

    int m_vstup;
    int m_poc_vlaken;
    bool m_urychleni;
    bool m_konec;
    bool m_posun;
    
    mutex sem_a;
    mutex sem_b;
    mutex sem_c;
    mutex barier_1;
    mutex barier_2;
    int barier_1_count;
    int barier_2_count;
    bool pokrac_v_cyklu;
    
    Vlakno *vlakno;
    LRtabulka *tb_alfa;
    LRtabulka_beta *tb_beta;
    Scanner *scan;
    
    
    void shiftuj(Vlakno *p_vlakno);
    int redukuj(Vlakno *p_vlakno);
    bool chyba(Vlakno *p_vlakno);
    void krokPrekladu(Vlakno *p_vlakno);
    
    void smazErrStavy();
    void posun();
    void posunVstup();
    void jeKonec();
    
    bool prebytek(Vlakno *p_vlakno);
    bool chybyVstup(Vlakno *p_vlakno,akce p_akce[SLP_ALFA], int p_vstupy[SLP_ALFA], int p_poc_res);
    bool rozdel(Vlakno *p_vlakno,akce p_akce[SLP_ALFA], int p_vstupy[SLP_ALFA], int p_stavy[SLP_ALFA], int p_poc_res);
public:
    Parser(bool p_urychlovac);
    int nastavRetezec(string p_vstup_string);
    void provedPreklad();
    int zjistiVysledky();
    ~Parser();


};

#endif	/* PARSER_H */

