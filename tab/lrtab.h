/* 
 * File:   lrtab.h
 * Author: Lukáš Junek
 *
 * Created on 26. říjen 2013, 19:50
 */

#ifndef LRTAB_H
#define	LRTAB_H

#include <cstdlib>
#include <iostream>
#include "data.h"


class LRtabulka {
private:
    tab_polozka LRtab_a[RADKY][SLP_ALFA];
    void naplTabulku();
public:
    LRtabulka();
    tab_polozka vratHodTabulky(int p_radek, int p_sloupec);    
};



#endif	/* LRTAB_H */

