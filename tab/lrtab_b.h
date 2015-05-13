/* 
 * File:   lrtab_b.h
 * Author: Lukáš Junek
 *
 * Created on 2. listopad 2013, 14:16
 */

#ifndef LRTAB_B_H
#define	LRTAB_B_H

#include <cstdlib>
#include <iostream>
#include "data.h"

class LRtabulka_beta {
private:
    int LRtab_b[RADKY][SLP_BETA];
    void naplnTabulku();
public:
    LRtabulka_beta();
    int vratHodTabulky(int p_radek, int p_sloupec);    
};


#endif	/* LRTAB_B_H */

