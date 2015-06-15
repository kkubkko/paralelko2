/* 
 * File:   parser.cpp
 * Author: Lukáš Junek
 * 
 * Created on 2. listopad 2013, 19:51
 */

#include "parser.h"


int cykl_count;
/*
 * Konstruktor parseru,
 * v parametru dostává informaci, zda má urychlovat hledání nového stavu
 * pomocí procedur ošetřujících chybějící a přebývající token.
 */
Parser::Parser(bool p_urychlovac) {

    m_vstup = -1;
    m_konec = false;
    m_posun = true;
    tb_alfa = new LRtabulka();
    tb_beta = new LRtabulka_beta();
    scan = new Scanner();
    m_urychleni = p_urychlovac;
    
    barier_1_count = 0;
    barier_2_count = 0;
    cykl_count = 0;
    pokrac_v_cyklu = true;

}
/*
 * Destruktor parseru
 */
Parser::~Parser(){
    delete tb_alfa;
    delete tb_beta;
    delete scan;

}
/*
 * Fukce pro akci SHIFT,
 * přesouvá nonterminál vlákna na zásobník.
 */
void Parser::shiftuj(Vlakno *p_vlakno){
    p_vlakno->m_st_st.push(p_vlakno->m_akt_stav);
    p_vlakno->m_st_trm.push(m_vstup);    
    p_vlakno->m_akt_stav = p_vlakno->m_polozka.tab_n_stav;
}
/*
 * Funkce pro akci REDUCE,
 * pro aktuální vlákno redukuje tokeny na zásobníku.
 */
int Parser::redukuj(Vlakno *p_vlakno){
    
    Vlakno *pomVlakno, *pomVlakno2;
    int vysledek1, vysledek2, vysledek3;
    
    // vytváření nových vláken při konfilktu
    if (p_vlakno->m_polozka.poc_pravidel > 1) {
        pomVlakno = new Vlakno(p_vlakno);
    }
    
    if (p_vlakno->m_polozka.poc_pravidel > 2) {
        pomVlakno2 = new Vlakno(p_vlakno);
    }
    
    // provedení redukce
    int pravidlo = p_vlakno->m_polozka.pravidlo1;    
    vysledek1 = m_redukce.reduce(p_vlakno, pravidlo);
    if (vysledek1 == -1) {
        //cout << "chyba reduce pravidla 1!!\n";
        p_vlakno->m_err_stav = ERR_RED; 
    }
    if (vysledek1 == 1) {
        p_vlakno->m_vzdalenost += scan->vratPocZbRetezce();
    }
    
    // pokud konflikt, provede redukce i pro ostatní vlákna
    if (p_vlakno->m_polozka.poc_pravidel > 1){       
        
        pravidlo = pomVlakno->m_polozka.pravidlo2;
        vysledek2 = m_redukce.reduce(pomVlakno, pravidlo);
        
        sem_a.lock();
        m_list.pridejNaKonec(pomVlakno); 
//        cout << "pridavam REDUKUJ pomVlakno\n";
//        if ((m_list.vratPocPolozek() - m_list.vratAktualniPozici()) == 1) barier_1.unlock();
        sem_a.unlock();
        
        if (vysledek2 == -1) {
            //cout << "chyba reduce pravidla 2!!\n";
            pomVlakno->m_err_stav = ERR_RED; 
        } 
        if (vysledek2 == 1) {
            p_vlakno->m_vzdalenost += scan->vratPocZbRetezce();
        }
    } 
    if (p_vlakno->m_polozka.poc_pravidel > 2){        
        
        pravidlo = pomVlakno2->m_polozka.pravidlo3;
        vysledek3 = m_redukce.reduce(pomVlakno2, pravidlo);
        
        sem_a.lock();
        m_list.pridejNaKonec(pomVlakno2);
//        cout << "pridavam REDUKUJ pomVlakno2\n";
//        if ((m_list.vratPocPolozek() - m_list.vratAktualniPozici()) == 1) barier_1.unlock();
        sem_a.unlock();
        
        if (vysledek3 == -1) {
            //cout << "chyba reduce pravidla 3!!\n";
            pomVlakno2->m_err_stav = ERR_RED; 
        } 
        if (vysledek3 == 1) {
            p_vlakno->m_vzdalenost += scan->vratPocZbRetezce();
        }
    }
    
    return 1;   //TOTO SOM TU PRIDAL, CHÝBAL RETURN ????
}
/*
 * Funkce kontroluje, zda aktuální token na vstupu není navíc.
 */
bool Parser::prebytek(Vlakno *p_vlakno){
    int pom_vstup;
    pom_vstup = scan->nactiTokenZa(m_vstup);

    p_vlakno->m_polozka = tb_alfa->vratHodTabulky(p_vlakno->m_akt_stav, pom_vstup);
    if (p_vlakno->m_polozka.tab_akce != NONE){
        //m_vstup = scan->dalsiToken();
        p_vlakno->m_vzdalenost++;
        p_vlakno->m_akt_vstup = pom_vstup;
        // čekej na další vstupní token
        p_vlakno->m_err_stav = ERR_MISS;
        return true;
    } else {
        return false;
    }
}
/*
 * Funkce kontroluje, zda nechybí vstupní token pro aktuální stav,
 * funguje pouze pro shiftovací akci.
 */
bool Parser::chybyVstup(Vlakno *p_vlakno,akce p_akce[SLP_ALFA], int p_vstupy[SLP_ALFA],int p_poc_res) {
    bool ok = false;
    int pom_stav;
    for (int i = 0; i < p_poc_res; i++) {
        if (p_akce[i] == SHIFT) {            
            // nov. stav
            pom_stav = tb_beta->vratHodTabulky(p_vlakno->m_akt_stav,p_vstupy[i]+11);
            p_vlakno->m_polozka = tb_alfa->vratHodTabulky(pom_stav,m_vstup);
            if (p_vlakno->m_polozka.tab_akce != NONE && (pom_stav < 17 || pom_stav > 24)){
                p_vlakno->m_st_trm.push(p_vstupy[i]+11);
                p_vlakno->m_st_st.push(pom_stav);
                p_vlakno->m_err_stav = OK;
                p_vlakno->m_vzdalenost++;
                p_vlakno->m_akt_stav = pom_stav;
                ok = true;
                break;
            }                
        }
    }
    return ok;
}
/*
 * Při konfliktu na vstupu funkce rozdělí aktuální vlákno a pro každou možnost provede 
 * dostupnou akci.
 */
bool Parser::rozdel(Vlakno *p_vlakno,akce p_akce[SLP_ALFA], int p_vstupy[SLP_ALFA], int p_stavy[SLP_ALFA], int p_poc_res){

    bool ok = true; // pozůstatek jednoduchého LR parseru    
    Vlakno *pomVlakno;

    for (int i = 0; i < p_poc_res; i++) {
        // vytvoření nového vlákna
        pomVlakno = new Vlakno(p_vlakno);
        
        // provedení akce SHIFT
        if (p_akce[i] == SHIFT) {
            pomVlakno->m_st_trm.push(p_vstupy[i]);
            pomVlakno->m_st_st.push(pomVlakno->m_akt_stav);
            pomVlakno->m_vzdalenost++; // zvednutí počítadla chyb
            pomVlakno->m_akt_stav = p_stavy[i];
            
            pomVlakno->m_akt_vstup = p_vstupy[i];
            // čekej na další vstupní token
            pomVlakno->m_err_stav = ERR_WAIT;

        } 
        
        // provedení akce REDUCE
        if (p_akce[i] == REDUCE) {
            int pravidlo = pomVlakno->m_polozka.pravidlo1;
            int vysledek = m_redukce.reduce(pomVlakno, pravidlo);
            if (vysledek == -1) {
                //cout << "chyba reduce pravidla1 u err!!\n";
                pomVlakno->m_err_stav = ERR_RED; 
            }
            if (vysledek == 1) {
                // pokud poslední redukce - spočítání zbývajících znaků a přičtení k chybě
                pomVlakno->m_vzdalenost += scan->vratPocZbRetezce();
            } else {
                pomVlakno->m_vzdalenost++;
            }
            
            // pokud konflikt - vytvoření dalších vláken
            if (pomVlakno->m_polozka.poc_pravidel > 1) {
                Vlakno *pomVlakno2 = new Vlakno(p_vlakno);
                
                pravidlo = pomVlakno2->m_polozka.pravidlo2;
                vysledek = m_redukce.reduce(pomVlakno2, pravidlo);
                
                if (vysledek == -1) {
                    //cout << "chyba reduce pravidla 1 u err!!\n";
                    pomVlakno2->m_err_stav = ERR_RED; 
                } 
                if (vysledek == 1) {
                    pomVlakno2->m_vzdalenost += scan->vratPocZbRetezce();
                } else {
                    pomVlakno2->m_vzdalenost++;
                }

                sem_a.lock();
                m_list.pridejNaKonec(pomVlakno2);
//                cout << "pridavam ROZDEL pomVlakno2\n";
//                if ((m_list.vratPocPolozek() - m_list.vratAktualniPozici()) == 1) barier_1.unlock();
                sem_a.unlock();
            }  
            if (pomVlakno->m_polozka.poc_pravidel > 3) {
                Vlakno *pomVlakno3 = new Vlakno(p_vlakno);
                
                pravidlo = pomVlakno3->m_polozka.pravidlo2;
                vysledek = m_redukce.reduce(pomVlakno3, pravidlo);
                
                if (vysledek == -1) {
                    //cout << "chyba reduce pravidla 1 u err!!\n";
                    pomVlakno3->m_err_stav = ERR_RED; 
                }  
                if (vysledek == 1) {
                    pomVlakno3->m_vzdalenost += scan->vratPocZbRetezce();
                } else {
                    pomVlakno3->m_vzdalenost++;
                }

                sem_a.lock();
                m_list.pridejNaKonec(pomVlakno3);
//                cout << "pridavam ROZDEL pomVlakno3\n";
//                if ((m_list.vratPocPolozek() - m_list.vratAktualniPozici()) == 1) barier_1.unlock();
                sem_a.unlock();
            }
        }
        sem_a.lock();
        m_list.pridejNaKonec(pomVlakno);
//        cout << "pridavam ROZDEL pomVlakno\n";
//        if ((m_list.vratPocPolozek() - m_list.vratAktualniPozici()) == 1) barier_1.unlock();
        sem_a.unlock();
    }
    // smaž původní vlákno
    p_vlakno->m_err_stav = ERR_ERR;
    return ok;
}
/*
 * Funkce pro ošetření chyby na vstupu,
 * pokud nastaveno - dojde k spuštění funkcí na kontrolu chybějícího a přebývajícího znaku
 * 
 * Dojde k vyhledání všech možností v LR tabulce a odeslání vlákna do funkce rozděl.
 */
bool Parser::chyba(Vlakno *p_vlakno){
    int pom_stavy[SLP_ALFA];
    akce pom_akce[SLP_ALFA];
    int pom_vstupy[SLP_ALFA];
    int poc_reseni = 0;
    bool nasel = false; int oprava = false;
    bool token_navic = false;
    
    if (m_urychleni) {
        if (prebytek(p_vlakno)) token_navic = true;
    }
    if (!token_navic){
        for (int i = 0; i < SLP_ALFA; i++){
            p_vlakno->m_polozka = tb_alfa->vratHodTabulky(p_vlakno->m_akt_stav,i);
            if (p_vlakno->m_polozka.tab_akce != NONE) {
                for (int j = 0; j < poc_reseni; j++) {
                    if (pom_stavy[j] == p_vlakno->m_polozka.tab_n_stav) {
                        nasel = true;
                    }
                }
                if (!nasel) {
                    pom_stavy[poc_reseni] = p_vlakno->m_polozka.tab_n_stav;
                    pom_akce[poc_reseni] = p_vlakno->m_polozka.tab_akce;
                    pom_vstupy[poc_reseni] = i;
                    poc_reseni++;
                    //cout << "Reseni " << i << "." << endl;
                    //cout << "Navrhovana akce je: " << p_vlakno->m_polozka.tab_akce << endl;
                    //cout << "Navrhovany stav je: " << p_vlakno->m_polozka.tab_n_stav << endl << endl;
                }
            }
            nasel = false;
        }
        //cout << "--------------------------------------------------------------\n";
        if (m_urychleni) {
            oprava = chybyVstup(p_vlakno,pom_akce,pom_vstupy,poc_reseni);
        }
        if (!oprava){
            oprava = rozdel(p_vlakno,pom_akce,pom_vstupy,pom_stavy,poc_reseni);
        }
    } else {
        oprava = true;
    }
    return oprava;
}
/*
 * Funkce provádí pro aktuální vlákno jeden krok překladu na základě LR tabulky. 
 */
void Parser::krokPrekladu(Vlakno *p_vlakno){
    int vysledek; int opraveno;
    //cout << "Prave je stav: " << p_vlakno->m_akt_stav << endl;
    //cout << "prave je term na vstupu: " << m_vstup << endl;
    //cout << "aktualni chyba: " << p_vlakno->m_vzdalenost << endl << endl;
    /*if(p_vlakno->m_akt_stav == 55) {
        cout << "sem tu\n";
    } */
    // pokud není dostupný stav - chyba - smazání vlákna
    if (p_vlakno->m_akt_stav == zd_stav) {
        p_vlakno->m_err_stav = ERR_ERR;
        //cout << "chyba na vstupu - non beta2" << endl;
    } else {
        // zjisti akci pro aktuální vstup a stav 
        if (!p_vlakno->m_konflikt) p_vlakno->m_polozka = tb_alfa->vratHodTabulky(p_vlakno->m_akt_stav,m_vstup);
        
        // pokud konflikt SHIFT/REDUCE - vytvoř nové vlákno pro akci REDUCE
        if (p_vlakno->m_polozka.konflikt) {
            Vlakno *pomVlakno;
            pomVlakno = new Vlakno(p_vlakno);
            pomVlakno->m_polozka.tab_akce = REDUCE;
            pomVlakno->m_konflikt = true;
            pomVlakno->m_polozka.konflikt = false;
            sem_a.lock();
            m_list.pridejNaKonec(pomVlakno);
//            cout << "pridavam REDUCE/SHIFT\n";
//            if ((m_list.vratPocPolozek() - m_list.vratAktualniPozici()) == 1) barier_1.unlock();
            sem_a.unlock();
        }
        p_vlakno->m_konflikt = false;
        
        // na základě akce proveď
        switch (p_vlakno->m_polozka.tab_akce) {
            case SHIFT:
                // pokud vlákno nečeká na nový token - shiftuj
                if (p_vlakno->m_err_stav != WAIT_SHIFT && p_vlakno->m_err_stav != ERR_MISS && p_vlakno->m_err_stav != ERR_WAIT){
                    shiftuj(p_vlakno);
                    p_vlakno->m_err_stav = WAIT_SHIFT;
                }
                break;
            case REDUCE:
                // pokud vlákno nečeká na nový token - redukuj
                if (p_vlakno->m_err_stav != ERR_MISS && p_vlakno->m_err_stav != ERR_WAIT) {
                    vysledek = redukuj(p_vlakno);
                    if (p_vlakno->m_akt_stav == -1) {
                        //cout << "chyba na vstupu - non beta" << endl;
                        p_vlakno->m_err_stav = ERR_BETA_VSTUP;
                    }
                }
                break;
            case NONE:
                // pokud chyba - spusť funkci k nápravě chyby
                if (p_vlakno->m_err_stav != ERR_MISS && p_vlakno->m_err_stav != ERR_WAIT) {
                    //cout << "chyba na vstupu - pokus oprava" << endl;
                    opraveno = this->chyba(p_vlakno);
                    if (!opraveno) {
                        p_vlakno->m_err_stav = ERR_ALFA_VSTUP;
                    }
                }                    
                break;
        }
    }
}
/*
 * Funkce maže všechna chybová vlákna.
 */
void Parser::smazErrStavy(){
    Vlakno *pomVlakno;
    polozka* pomPrv;
//    cout << "jsem v smazErrStavy\n";
    while (pokrac_v_cyklu) {
        
        
        sem_a.lock();
        if (/*m_list.vratAktualniPozici() < m_list.vratPocPolozek()*/m_list.akt()) {
            pomVlakno = m_list.vratAkt(); 
            pomPrv = m_list.vratAktPrv();
            m_list.aktRight();
//            cout << "budu zamykat\n";
            if (!m_list.akt()) barier_1.lock();
//            cout << "zamknuto\n";
            sem_a.unlock();
            
            
            // smaž vlákna, která překročila danou toleranci
            if (pomVlakno->m_vzdalenost > max_vzdalenost) {
                pomVlakno->m_err_stav = ERR_ERR;
            }
            // samotné mazání
            if (pomVlakno->m_err_stav == ERR_ALFA_VSTUP || pomVlakno->m_err_stav == ERR_BETA_VSTUP 
                || pomVlakno->m_err_stav == ERR_RED || pomVlakno->m_err_stav == ERR_ERR) {
                sem_a.lock();
                m_list.smazPrv(pomPrv);
                sem_a.unlock();
            }
        } else {
            sem_a.unlock();
            
            sem_b.lock();
            if (cykl_count < (max_vlaken-1)) {
                cykl_count++;
            } else {
//                cykl_count++;
                cykl_count = 0;
                pokrac_v_cyklu = false;
                barier_2.lock();
                barier_1.unlock();
            }
            sem_b.unlock();
//            cout << "barier_1 count: " << barier_1_count << endl;
            barier_1.lock();
            barier_1.unlock(); 
//            cout << "jsem za barierou\n";
//            sem_b.lock();
//            cykl_count--;
//            sem_b.unlock();
        }        
    }
}
/*
 * Kontrola, zda je možné načíst nový token.
 */
void Parser::posun() {
    m_posun = true;
    Vlakno *pomVlakno;
    
    while (m_list.akt() && m_posun) {
        pomVlakno = m_list.vratAkt();
        if (pomVlakno->m_err_stav != WAIT_SHIFT) {
            if (pomVlakno->m_err_stav != ERR_MISS && pomVlakno->m_err_stav != ERR_WAIT && pomVlakno->m_err_stav != END) {
                m_posun = false;
            }           
        }
        m_list.aktRight();
    }
}
/*
 * Funkce načítající nový token ze scanneru. 
 */
void Parser::posunVstup() {
    Vlakno* pomVlakno;
    while (pokrac_v_cyklu) {
        
        
        sem_a.lock();
        if(m_posun && (/*m_list.vratAktualniPozici() < m_list.vratPocPolozek()*/m_list.akt())){// pokud je možné posunout vstup
            pomVlakno = m_list.vratAkt();
            m_list.aktRight();
            if (!m_list.akt()) barier_1.lock();
            sem_a.unlock();
            
            
            // pokud přebývající token - pokračuj až pro další hranu
            if (pomVlakno->m_err_stav == ERR_MISS) { 
                if (m_vstup == pomVlakno->m_akt_vstup){
                    pomVlakno->m_err_stav = OK;
                }
            // pokud oprava pomocí rozdělení vlákna - počkej až na další hranu
            } else if (pomVlakno->m_err_stav == ERR_WAIT) {
                if (m_vstup != pomVlakno->m_akt_vstup /*&& m_vstup != vs_end*/) {
                    pomVlakno->m_akt_vstup = m_vstup;
                    pomVlakno->m_err_stav = OK;
                }
            // pokud konečný stav - nic nedělej
            } else if (pomVlakno->m_err_stav == END) {
                pomVlakno->m_akt_vstup = m_vstup;
                pomVlakno->m_err_stav = END;
            // všechna ostatní vlákna připravena na další token
            } else {
                pomVlakno->m_akt_vstup = m_vstup;
                pomVlakno->m_err_stav = OK;
            }
        } else {
            sem_a.unlock();
            
            sem_b.lock();
            if (cykl_count < (max_vlaken-1)) {
                cykl_count++;
            } else {
                //cykl_count++;
                cykl_count = 0;
                pokrac_v_cyklu = false;
                barier_2.lock();
                barier_1.unlock();
            }
            sem_b.unlock();
            
            barier_1.lock();
            barier_1.unlock();
            
//            sem_b.lock();
//            cykl_count--;
//            sem_b.unlock();
        }
    }
}
/*
 * Funkce kontroluje, zda je možné ukončit analýzu - pokud jsou všechna zbývající vlákna
 * úspěšně ukončená.
 */
void Parser::jeKonec() {
    Vlakno *pomVlakno;
    while ((m_list.vratAktualniPozici() < m_list.vratPocPolozek()) && m_konec){
        pomVlakno = m_list.vratAkt();
        m_list.aktRight();
        if (pomVlakno->m_err_stav != END) {
            m_konec = false;
        }
    } 
}

void Parser::posunKonec(){
    Vlakno *pomVlakno;
    
    while (/*(m_list.vratAktualniPozici() < m_list.vratPocPolozek())*/ m_list.akt() && (m_konec || m_posun)){
        pomVlakno = m_list.vratAkt();
        m_list.aktRight();
        if (pomVlakno->m_err_stav != END) {
            m_konec = false;
        }
        if (pomVlakno->m_err_stav != WAIT_SHIFT) {
            if (pomVlakno->m_err_stav != ERR_MISS && pomVlakno->m_err_stav != ERR_WAIT && pomVlakno->m_err_stav != END) {
                m_posun = false;
            }           
        }
    }    
}

/*
 * Hlavní funkce parsru - řídí celý překlad.
 */
int Parser::nastavRetezec(string p_vstup_string){
    scan->vstupniRetezec(p_vstup_string);
    //cout << p_vstup_string << endl;
//    Vlakno *pomVlakno;
    
    // otoč vstup do požadované polohy
    if (scan->nastavNaZacatek() == -1) {
        return -2;
    }
    m_vstup = scan->nactiDalsi();
    
    // vytvoření výchozího vlákna
    vlakno = new Vlakno();
    vlakno->m_prvni = true;
    vlakno->m_akt_vstup = m_vstup;
    m_list.pridejNaZacatek(vlakno);
    m_list.nastavAktNaFirst();
    return 1;
}


void Parser::provedPreklad(){
    Vlakno *pomVlakno;
    
    // hlavní cyklus
    do {
//        cout << "na zacatku ---------------------------------------------------\n";
        // krok prekladu -------------------------------------------------------
        while (pokrac_v_cyklu) {
            
            
            sem_a.lock();
            if (/*m_list.vratAktualniPozici() < m_list.vratPocPolozek()) &&*/ m_list.vratAkt() != 0){
                pomVlakno = m_list.vratAkt();
                m_list.aktRight();
//                if (m_list.vratAktualniPozici() >= m_list.vratPocPolozek()) barier_1.lock();
                if (!m_list.akt()) barier_1.lock();
                sem_a.unlock();
                
                
//                cout << "jdu na preklad: " << pomVlakno << "\n";
                if (pomVlakno->m_err_stav != END) {
                    krokPrekladu(pomVlakno);
                }
            } else {
                sem_a.unlock();
                
                sem_b.lock();
                if (cykl_count < (max_vlaken-1)) {
                    cykl_count++;
                } else {
                    barier_1_count = 0;
                    //cykl_count++;
                    cykl_count = 0;
                    //cout << "bar_count: " << barier_1_count << endl;
                    pokrac_v_cyklu = false;
                    
                    m_list.nastavAktNaFirst();
                    m_konec = true; m_posun = true;
//            jeKonec();
                    this->posunKonec();
                    if (m_posun) m_vstup = scan->nactiDalsi();
                    m_list.nastavAktNaFirst();
                    
                    barier_2.lock();
                    barier_1.unlock();
                }
                sem_b.unlock();
                
                barier_1.lock();
                barier_1.unlock();
                
//                sem_b.lock();
//                cykl_count--;
//                sem_b.unlock();
            }
        }
//        cout << "konec vsech kroku\n";
// konec ---------------------------------------------------------------
/*
        sem_c.lock();
        if (barier_2_count == 0) {
            barier_2_count++;
            sem_c.unlock();
            m_list.nastavAktNaFirst();
            m_konec = true; m_posun = true;
//            jeKonec();
            this->posunKonec();
            if (m_posun) m_vstup = scan->nactiDalsi();
            m_list.nastavAktNaFirst();
        } else sem_c.unlock();
*/        
//        cout << "po jeKonec\n";
//        cout << "bar_count2: " << barier_1_count << endl;
        sem_b.lock();
        if (barier_1_count < (max_vlaken - 1)) {
            barier_1_count++;
        } else {
            pokrac_v_cyklu = true;
            barier_2_count = 0;
            barier_1_count = 0;
//            barier_1.lock();
            barier_2.unlock();
        }
        sem_b.unlock();
//        cout << "bar_count3: " << barier_1_count << endl;
//        cout << "cekam na 2.bariere\n";
        barier_2.lock();
        barier_2.unlock();
//        cout << "po 2.bariere\n";
//------------------------------------------------------------------------------
        smazErrStavy();
        
//        cout << "po 2.bariere2\n";
/*        
        sem_c.lock();
        if (barier_2_count == 0) {
            barier_2_count++;
            sem_c.unlock();
            m_list.nastavAktNaFirst();
            m_posun = true;
            this->posun();
            if (m_posun) m_vstup = scan->nactiDalsi();
            m_list.nastavAktNaFirst();
        } else sem_c.unlock();
*/        
 //       cout << "po posun\n";
        
        sem_b.lock();
//        cout << "bariera: " << barier_1_count << ", max vlaken: "<< max_vlaken << endl;
        if (barier_1_count < (max_vlaken-1)) {
            barier_1_count++;
        } else {
            m_list.nastavAktNaFirst();
            pokrac_v_cyklu = true;
            barier_2_count = 0;
            barier_1_count = 0;
//            barier_1.try_lock();
//            cout << "odemikam trojku\n";
            barier_2.unlock();
        }
        sem_b.unlock();
//        cout << "pred 3. barierou\n";
        
        barier_2.lock();
//        cout << "prochazim trojkou\n";
        barier_2.unlock();
        
//       cout << "po 3. bariere\n";
//------------------------------------------------------------------------------        
        if (m_posun) {
            posunVstup();

            sem_b.lock();
            if (barier_1_count < (max_vlaken-1)) {
                barier_1_count++;
            } else {
                pokrac_v_cyklu = true;
                m_list.nastavAktNaFirst();
                barier_2_count = 0;
                barier_1_count = 0;
                barier_2.unlock();
            }
            sem_b.unlock();

            barier_2.lock();
            barier_2.unlock();
//            cout << "po 4. bariere\n";
        }
        
    } while (!m_list.isEmpty() && !m_konec);
}


int Parser::zjistiVysledky(){
    // pokud konec - vypiš výsledky
    Vlakno *pomVlakno;
    if (m_konec) {
        int vysl, vzdal;
        bool prv = true;
        m_list.nastavAktNaFirst();
        while (m_list.akt()){
            pomVlakno = m_list.vratAkt();
            
            if (prv){            
                vysl = pomVlakno->m_cis_vysl;
                vzdal = pomVlakno->m_vzdalenost;
                prv = false;
            } else {
                if (vzdal > pomVlakno->m_vzdalenost){
                    vysl = pomVlakno->m_cis_vysl;
                    vzdal = pomVlakno->m_vzdalenost;
                }
            }            
            
            //cout << "Nalezene vlakno je: " << pomVlakno->m_vysledek << ", se vzdalenosti: " 
            //     << pomVlakno->m_vzdalenost << endl;
            m_list.aktRight();
        }
        m_list.smazVse();
        return vysl;
    } else {
        m_list.smazVse();
        return -1;
    }
}


