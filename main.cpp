/* 
 * File:   main.cpp
 * Author: Lukáš Junek
 *
 * Created on 26. říjen 2013, 15:34
 */


#include <cstdlib>
#include <iostream>
#include <cstdio>
#include "tab/lrtab.h"
#include "tab/lrtab_b.h"
#include "parser.h"
#include "vlakno.h"


using namespace std;

/*
TESTOVACÍ ŘETĚZCE:
U testovacích řetězců se projevují vlastnosti popsané v mé práci.

trojúhelník:
-nedeformované:
dbe dhe dha
-deformované, otočené:
bed dhea beag fbca dhce dhag fha fhca dfbhca dfbhce

čtverec:
-nedeformované:
dbca
-deformované, otočené:
fheg dfbcag dfbceag fbheg fheag dbhcag fbhceag

osmiúhelník:
-nedeformované:
dfbhceag 
-deformované:
dbhceag fbhceag dbhcag dbhceg

kříž:
-nedeformované:
dbdbcbcacada
-deformované, otočené:
fgfhfhehegeg dbfdbcbceacada fdgfhfhechegeg dbfdbfcbcaeceadag

šipka:
-nedeformované:
dbehege dbdheda dhfheha
-deformované, otočené:
fgbcgcg fhfhceagfg dfbdbheda dfbfdbhedag

rovnoběžník:
-nedeformované:
dhcg dfce
-deformované, otočené:
fbea fbcea dfbcea dfbhceag dfbcea dfcea dhcag

lichoběžník:
-nedeformované:
dhce dhag dfcg dfbe
-deformované, otočené:
fbha dfhcea bhcag dfbhcag beag bceag bhcg

L-tvar:
-nedeformované:
dbcaca dbcbca dbdbca dbcada
-deformované, otočené:
fgfheg fbhcecheg dfbhchbceag dfbhcada

dvojtá šipka:
-nedeformované:
dbhacg dhfceg dfcbea dhfcge
-deformované, otočené:
fbhag fhag fgbhcea fbcehcag
 */
int main(int argc, char** argv) {
    string vstup;
    bool zrychlovac = false;
    
    if (argc > 1) {
        string arg(argv[1]);
        //cout << "arguments: " << arg << endl;
        if (arg == "-fast") {
            zrychlovac = true;
        }
    }
    //Parser *prekladac = new Parser(zrychlovac);
    int vysledek;
    string vysledek_src;
    vstup = "fgbhcea";
    
    //while (!cin.eof()) {
    //    cout << "Zadejte vstupni retezec: ";
    //    cin >> vstup;
        
        Parser *prekladac = new Parser(zrychlovac);
        vysledek = prekladac->provedPreklad(vstup); 
        delete prekladac;
        if (vysledek == -2) {
            cout << "Retezec obsahuje spatne znaky" << endl;
        } 
        if (vysledek == -1) {
            cout << "Program nenalezl v pozadovane toleranci zadny objekt" << endl;
        }
        switch (vysledek){
            case 1:
                vysledek_src = "trojuhelnik";
                break;
            case 2:
                vysledek_src = "ctverec";
                break;
            case 3:
                vysledek_src = "rovnobeznik";
                break;
            case 4:
                vysledek_src = "lichobeznik";
                break;
            case 5:
                vysledek_src = "sipka";
                break;
            case 6:
                vysledek_src = "dvojita sipka";
                break;
            case 7:
                vysledek_src = "kriz";
                break;
            case 8:
                vysledek_src = "L-tvar";
                break;
            case 9:
                vysledek_src = "osmiuhelnik";
                break;
            case -1:
                vysledek_src = "CHYBA - pro danou toleranci program nenasel vysledek";
                break;
            case -2:
                vysledek_src = "CHYBA - chybny znak na vstupu";
                break;
        }
        cout << "vysledkek prekladu je: " << vysledek_src << endl;
       
        
    //}
    //delete prekladac;       
    return 0;
}

