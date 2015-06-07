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
 * 
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
    //vstup = "";
    
    while (!cin.eof()) {
        cout << "Zadejte vstupni retezec: ";
        cin >> vstup;
        
        /*
        using namespace std::chrono;
        milliseconds start = duration_cast< milliseconds >(
                                                        system_clock::now().time_since_epoch()
                                                        );
         */
        
        Parser *prekladac = new Parser(zrychlovac);
        vysledek = prekladac->provedPreklad(vstup); 
        delete prekladac;
        
        /*
        milliseconds end = duration_cast< milliseconds >(
                                                        system_clock::now().time_since_epoch()
                                                        );
        
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
         */
        
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
       
        
    }
    //delete prekladac;       
    return 0;
}

