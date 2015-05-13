/* 
 * File:   redukce.h
 * Author: Lukáš Junek
 *
 * Created on 8. březen 2014, 18:49
 */
using namespace std;

#ifndef REDUKCE_H
#define	REDUKCE_H
#include <iostream>
#include <stack>
#include "tab/data.h"
#include "tab/lrtab.h"
#include "tab/lrtab_b.h"
#include "vlakno.h"

class Redukce {
private:
    LRtabulka *tb_alfa;
    LRtabulka_beta *tb_beta;
    
public:
    Redukce();
    ~Redukce();
    int reduce(Vlakno *p_vlakno, int p_pravidlo);


};

#endif	/* REDUKCE_H */

