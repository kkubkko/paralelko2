/* 
 * File:   lrtab.cpp
 * Author: Lukáš Junek
 *
 * Created on 26. říjen 2013, 19:50
 */
#include "lrtab.h"

/*
 * Funkce naplní tabulku - její akční část 
 */
void LRtabulka::naplTabulku() {
    for (int i = 0; i < RADKY; i++) {
        for (int j = 0; j < SLP_ALFA; j++) {
            LRtab_a[i][j].poc_pravidel = 1;
            LRtab_a[i][j].tab_akce = NONE;
            LRtab_a[i][j].tab_n_stav = zd_stav;
            LRtab_a[i][j].pravidlo1 = zd_pravidlo;
            LRtab_a[i][j].pravidlo2 = zd_pravidlo;
            LRtab_a[i][j].pravidlo3 = zd_pravidlo;
            LRtab_a[i][j].konflikt = false;
        }
    }
    // 1. radek - emp ----------------------------------------------------------
    LRtab_a[st_emp][vs_d].tab_akce = SHIFT;  LRtab_a[st_emp][vs_d].tab_n_stav = st_d;
    LRtab_a[st_emp][vs_f].tab_akce = SHIFT;  LRtab_a[st_emp][vs_f].tab_n_stav = st_f;
    
    // 2. radek - a ------------------------------------------------------------
    LRtab_a[st_a][vs_a].tab_akce = REDUCE;   LRtab_a[st_a][vs_a].pravidlo1 = A_a;
    LRtab_a[st_a][vs_b].tab_akce = REDUCE;   LRtab_a[st_a][vs_b].pravidlo1 = A_a;
    LRtab_a[st_a][vs_c].tab_akce = REDUCE;   LRtab_a[st_a][vs_c].pravidlo1 = A_a;
    LRtab_a[st_a][vs_d].tab_akce = REDUCE;   LRtab_a[st_a][vs_d].pravidlo1 = A_a;
    LRtab_a[st_a][vs_e].tab_akce = REDUCE;   LRtab_a[st_a][vs_e].pravidlo1 = A_a;
    LRtab_a[st_a][vs_f].tab_akce = REDUCE;   LRtab_a[st_a][vs_f].pravidlo1 = A_a;
    LRtab_a[st_a][vs_g].tab_akce = REDUCE;   LRtab_a[st_a][vs_g].pravidlo1 = A_a;
    LRtab_a[st_a][vs_h].tab_akce = REDUCE;   LRtab_a[st_a][vs_h].pravidlo1 = A_a;
    LRtab_a[st_a][vs_end].tab_akce = REDUCE; LRtab_a[st_a][vs_end].pravidlo1 = A_a;
    
    // 3. radek - b ------------------------------------------------------------
    LRtab_a[st_b][vs_a].tab_akce = REDUCE;   LRtab_a[st_b][vs_a].pravidlo1 = B_b;
    LRtab_a[st_b][vs_b].tab_akce = REDUCE;   LRtab_a[st_b][vs_b].pravidlo1 = B_b;
    LRtab_a[st_b][vs_c].tab_akce = REDUCE;   LRtab_a[st_b][vs_c].pravidlo1 = B_b;
    LRtab_a[st_b][vs_d].tab_akce = REDUCE;   LRtab_a[st_b][vs_d].pravidlo1 = B_b;
    LRtab_a[st_b][vs_e].tab_akce = REDUCE;   LRtab_a[st_b][vs_e].pravidlo1 = B_b;
    LRtab_a[st_b][vs_f].tab_akce = REDUCE;   LRtab_a[st_b][vs_f].pravidlo1 = B_b;
    LRtab_a[st_b][vs_g].tab_akce = REDUCE;   LRtab_a[st_b][vs_g].pravidlo1 = B_b;
    LRtab_a[st_b][vs_h].tab_akce = REDUCE;   LRtab_a[st_b][vs_h].pravidlo1 = B_b;
    LRtab_a[st_b][vs_end].tab_akce = REDUCE; LRtab_a[st_b][vs_end].pravidlo1 = B_b;
            
    // 4. radek - c ------------------------------------------------------------
    LRtab_a[st_c][vs_a].tab_akce = REDUCE;   LRtab_a[st_c][vs_a].pravidlo1 = C_c;
    LRtab_a[st_c][vs_b].tab_akce = REDUCE;   LRtab_a[st_c][vs_b].pravidlo1 = C_c;
    LRtab_a[st_c][vs_c].tab_akce = REDUCE;   LRtab_a[st_c][vs_c].pravidlo1 = C_c;
    LRtab_a[st_c][vs_d].tab_akce = REDUCE;   LRtab_a[st_c][vs_d].pravidlo1 = C_c;
    LRtab_a[st_c][vs_e].tab_akce = REDUCE;   LRtab_a[st_c][vs_e].pravidlo1 = C_c;
    LRtab_a[st_c][vs_f].tab_akce = REDUCE;   LRtab_a[st_c][vs_f].pravidlo1 = C_c;
    LRtab_a[st_c][vs_g].tab_akce = REDUCE;   LRtab_a[st_c][vs_g].pravidlo1 = C_c;
    LRtab_a[st_c][vs_h].tab_akce = REDUCE;   LRtab_a[st_c][vs_h].pravidlo1 = C_c;
    LRtab_a[st_c][vs_end].tab_akce = REDUCE; LRtab_a[st_c][vs_end].pravidlo1 = C_c;
    
    // 5. radek - d ------------------------------------------------------------        
    LRtab_a[st_d][vs_a].tab_akce = REDUCE;   LRtab_a[st_d][vs_a].pravidlo1 = D_d;
    LRtab_a[st_d][vs_b].tab_akce = REDUCE;   LRtab_a[st_d][vs_b].pravidlo1 = D_d;
    LRtab_a[st_d][vs_c].tab_akce = REDUCE;   LRtab_a[st_d][vs_c].pravidlo1 = D_d;
    LRtab_a[st_d][vs_d].tab_akce = REDUCE;   LRtab_a[st_d][vs_d].pravidlo1 = D_d;
    LRtab_a[st_d][vs_e].tab_akce = REDUCE;   LRtab_a[st_d][vs_e].pravidlo1 = D_d;
    LRtab_a[st_d][vs_f].tab_akce = REDUCE;   LRtab_a[st_d][vs_f].pravidlo1 = D_d;
    LRtab_a[st_d][vs_g].tab_akce = REDUCE;   LRtab_a[st_d][vs_g].pravidlo1 = D_d;
    LRtab_a[st_d][vs_h].tab_akce = REDUCE;   LRtab_a[st_d][vs_h].pravidlo1 = D_d;
    LRtab_a[st_d][vs_end].tab_akce = REDUCE; LRtab_a[st_d][vs_end].pravidlo1 = D_d;
    
    // 6. radek - e ------------------------------------------------------------            
    LRtab_a[st_e][vs_a].tab_akce = REDUCE;   LRtab_a[st_e][vs_a].pravidlo1 = E_e;
    LRtab_a[st_e][vs_b].tab_akce = REDUCE;   LRtab_a[st_e][vs_b].pravidlo1 = E_e;
    LRtab_a[st_e][vs_c].tab_akce = REDUCE;   LRtab_a[st_e][vs_c].pravidlo1 = E_e;
    LRtab_a[st_e][vs_d].tab_akce = REDUCE;   LRtab_a[st_e][vs_d].pravidlo1 = E_e;
    LRtab_a[st_e][vs_e].tab_akce = REDUCE;   LRtab_a[st_e][vs_e].pravidlo1 = E_e;
    LRtab_a[st_e][vs_f].tab_akce = REDUCE;   LRtab_a[st_e][vs_f].pravidlo1 = E_e;
    LRtab_a[st_e][vs_g].tab_akce = REDUCE;   LRtab_a[st_e][vs_g].pravidlo1 = E_e;
    LRtab_a[st_e][vs_h].tab_akce = REDUCE;   LRtab_a[st_e][vs_h].pravidlo1 = E_e;
    LRtab_a[st_e][vs_end].tab_akce = REDUCE; LRtab_a[st_e][vs_end].pravidlo1 = E_e;
    
    // 7. radek - f ------------------------------------------------------------            
    LRtab_a[st_f][vs_a].tab_akce = REDUCE;   LRtab_a[st_f][vs_a].pravidlo1 = F_f;
    LRtab_a[st_f][vs_b].tab_akce = REDUCE;   LRtab_a[st_f][vs_b].pravidlo1 = F_f;
    LRtab_a[st_f][vs_c].tab_akce = REDUCE;   LRtab_a[st_f][vs_c].pravidlo1 = F_f;
    LRtab_a[st_f][vs_d].tab_akce = REDUCE;   LRtab_a[st_f][vs_d].pravidlo1 = F_f;
    LRtab_a[st_f][vs_e].tab_akce = REDUCE;   LRtab_a[st_f][vs_e].pravidlo1 = F_f;
    LRtab_a[st_f][vs_f].tab_akce = REDUCE;   LRtab_a[st_f][vs_f].pravidlo1 = F_f;
    LRtab_a[st_f][vs_g].tab_akce = REDUCE;   LRtab_a[st_f][vs_g].pravidlo1 = F_f;
    LRtab_a[st_f][vs_h].tab_akce = REDUCE;   LRtab_a[st_f][vs_h].pravidlo1 = F_f;
    LRtab_a[st_f][vs_end].tab_akce = REDUCE; LRtab_a[st_f][vs_end].pravidlo1 = F_f;
    
    // 8. radek - g ------------------------------------------------------------            
    LRtab_a[st_g][vs_a].tab_akce = REDUCE;   LRtab_a[st_g][vs_a].pravidlo1 = G_g;
    LRtab_a[st_g][vs_b].tab_akce = REDUCE;   LRtab_a[st_g][vs_b].pravidlo1 = G_g;
    LRtab_a[st_g][vs_c].tab_akce = REDUCE;   LRtab_a[st_g][vs_c].pravidlo1 = G_g;
    LRtab_a[st_g][vs_d].tab_akce = REDUCE;   LRtab_a[st_g][vs_d].pravidlo1 = G_g;
    LRtab_a[st_g][vs_e].tab_akce = REDUCE;   LRtab_a[st_g][vs_e].pravidlo1 = G_g;
    LRtab_a[st_g][vs_f].tab_akce = REDUCE;   LRtab_a[st_g][vs_f].pravidlo1 = G_g;
    LRtab_a[st_g][vs_g].tab_akce = REDUCE;   LRtab_a[st_g][vs_g].pravidlo1 = G_g;
    LRtab_a[st_g][vs_h].tab_akce = REDUCE;   LRtab_a[st_g][vs_h].pravidlo1 = G_g;
    LRtab_a[st_g][vs_end].tab_akce = REDUCE; LRtab_a[st_g][vs_end].pravidlo1 = G_g;
    
    // 9. radek - h ------------------------------------------------------------            
    LRtab_a[st_h][vs_a].tab_akce = REDUCE;   LRtab_a[st_h][vs_a].pravidlo1 = H_h;
    LRtab_a[st_h][vs_b].tab_akce = REDUCE;   LRtab_a[st_h][vs_b].pravidlo1 = H_h;
    LRtab_a[st_h][vs_c].tab_akce = REDUCE;   LRtab_a[st_h][vs_c].pravidlo1 = H_h;
    LRtab_a[st_h][vs_d].tab_akce = REDUCE;   LRtab_a[st_h][vs_d].pravidlo1 = H_h;
    LRtab_a[st_h][vs_e].tab_akce = REDUCE;   LRtab_a[st_h][vs_e].pravidlo1 = H_h;
    LRtab_a[st_h][vs_f].tab_akce = REDUCE;   LRtab_a[st_h][vs_f].pravidlo1 = H_h;
    LRtab_a[st_h][vs_g].tab_akce = REDUCE;   LRtab_a[st_h][vs_g].pravidlo1 = H_h;
    LRtab_a[st_h][vs_h].tab_akce = REDUCE;   LRtab_a[st_h][vs_h].pravidlo1 = H_h;
    LRtab_a[st_h][vs_end].tab_akce = REDUCE; LRtab_a[st_h][vs_end].pravidlo1 = H_h;
            
     // 10. radek - A ----------------------------------------------------------
    LRtab_a[st_A][vs_a].tab_akce = SHIFT;     LRtab_a[st_A][vs_a].tab_n_stav = st_a;
    LRtab_a[st_A][vs_b].tab_akce = REDUCE;    LRtab_a[st_A][vs_b].pravidlo1 = s_A;
    LRtab_a[st_A][vs_c].tab_akce = REDUCE;    LRtab_a[st_A][vs_c].pravidlo1 = s_A;
    LRtab_a[st_A][vs_d].tab_akce = REDUCE;    LRtab_a[st_A][vs_d].pravidlo1 = s_A;
    LRtab_a[st_A][vs_e].tab_akce = REDUCE;    LRtab_a[st_A][vs_e].pravidlo1 = s_A;
    LRtab_a[st_A][vs_f].tab_akce = REDUCE;    LRtab_a[st_A][vs_f].pravidlo1 = s_A;
    LRtab_a[st_A][vs_g].konflikt = true;
    LRtab_a[st_A][vs_g].tab_akce = SHIFT;     LRtab_a[st_A][vs_g].tab_n_stav = st_g;  
    LRtab_a[st_A][vs_g].pravidlo1 = s_A;
    LRtab_a[st_A][vs_h].tab_akce = REDUCE;    LRtab_a[st_A][vs_h].pravidlo1 = s_A;
    LRtab_a[st_A][vs_end].tab_akce = REDUCE;  LRtab_a[st_A][vs_end].pravidlo1 = s_A;
    
    // 11. radek - B -----------------------------------------------------------
    LRtab_a[st_B][vs_b].tab_akce = SHIFT;  LRtab_a[st_B][vs_b].tab_n_stav = st_b;
    
    // 12. radek - C -----------------------------------------------------------
    LRtab_a[st_C][vs_a].tab_akce = SHIFT;   LRtab_a[st_C][vs_a].tab_n_stav = st_a;
    LRtab_a[st_C][vs_b].tab_akce = SHIFT;   LRtab_a[st_C][vs_b].tab_n_stav = st_b;
    LRtab_a[st_C][vs_c].tab_akce = SHIFT;   LRtab_a[st_C][vs_c].tab_n_stav = st_c;
    LRtab_a[st_C][vs_e].tab_akce = SHIFT;   LRtab_a[st_C][vs_e].tab_n_stav = st_e;
    LRtab_a[st_C][vs_g].tab_akce = SHIFT;   LRtab_a[st_C][vs_g].tab_n_stav = st_g;
            
    // 13. radek - D -----------------------------------------------------------
    LRtab_a[st_D][vs_a].tab_akce = SHIFT;   LRtab_a[st_D][vs_a].tab_n_stav = st_a;
    LRtab_a[st_D][vs_b].tab_akce = SHIFT;   LRtab_a[st_D][vs_b].tab_n_stav = st_b;
    LRtab_a[st_D][vs_d].tab_akce = SHIFT;   LRtab_a[st_D][vs_d].tab_n_stav = st_d;
    LRtab_a[st_D][vs_f].tab_akce = SHIFT;   LRtab_a[st_D][vs_f].tab_n_stav = st_f;
    LRtab_a[st_D][vs_h].tab_akce = SHIFT;   LRtab_a[st_D][vs_h].tab_n_stav = st_h;
    
    // 14. radek - E -----------------------------------------------------------        
    LRtab_a[st_E][vs_a].konflikt = true;
    LRtab_a[st_E][vs_a].tab_akce = SHIFT;    LRtab_a[st_E][vs_a].tab_n_stav = st_a;
    LRtab_a[st_E][vs_a].pravidlo1 = d_E;
    
    LRtab_a[st_E][vs_b].tab_akce = REDUCE;   LRtab_a[st_E][vs_b].pravidlo1 = d_E;
    
    LRtab_a[st_E][vs_c].konflikt = true;
    LRtab_a[st_E][vs_c].tab_akce = SHIFT;    LRtab_a[st_E][vs_c].tab_n_stav = st_c;
    LRtab_a[st_E][vs_c].pravidlo1 = d_E;
    
    LRtab_a[st_E][vs_d].tab_akce = SHIFT;    LRtab_a[st_E][vs_d].tab_n_stav = st_d;
    LRtab_a[st_E][vs_e].tab_akce = SHIFT;    LRtab_a[st_E][vs_e].tab_n_stav = st_e;
    LRtab_a[st_E][vs_f].tab_akce = REDUCE;   LRtab_a[st_E][vs_f].pravidlo1 = d_E;
    LRtab_a[st_E][vs_g].tab_akce = SHIFT;   LRtab_a[st_E][vs_g].tab_n_stav = st_g;
    
    LRtab_a[st_E][vs_h].konflikt = true;
    LRtab_a[st_E][vs_h].tab_akce = SHIFT;    LRtab_a[st_E][vs_h].tab_n_stav = st_h;
    LRtab_a[st_E][vs_h].pravidlo1 = d_E;
    
    LRtab_a[st_E][vs_end].tab_akce = REDUCE; LRtab_a[st_E][vs_end].pravidlo1 = d_E;
    
    // 15. radek - F -----------------------------------------------------------            
    LRtab_a[st_F][vs_b].tab_akce = SHIFT;   LRtab_a[st_F][vs_b].tab_n_stav = st_b;
    LRtab_a[st_F][vs_c].tab_akce = SHIFT;   LRtab_a[st_F][vs_c].tab_n_stav = st_c;
    LRtab_a[st_F][vs_f].tab_akce = SHIFT;   LRtab_a[st_F][vs_f].tab_n_stav = st_f;
    LRtab_a[st_F][vs_h].tab_akce = SHIFT;   LRtab_a[st_F][vs_h].tab_n_stav = st_h;
    
    // 16. radek - G -----------------------------------------------------------            
    LRtab_a[st_G][vs_g].tab_akce = SHIFT;  LRtab_a[st_G][vs_g].tab_n_stav = st_g;
    
    // 17. radek - H -----------------------------------------------------------            
    LRtab_a[st_H][vs_a].tab_akce = SHIFT;   LRtab_a[st_H][vs_a].tab_n_stav = st_a;
    LRtab_a[st_H][vs_c].tab_akce = SHIFT;   LRtab_a[st_H][vs_c].tab_n_stav = st_c;
    LRtab_a[st_H][vs_e].tab_akce = SHIFT;   LRtab_a[st_H][vs_e].tab_n_stav = st_e;
    LRtab_a[st_H][vs_h].tab_akce = SHIFT;   LRtab_a[st_H][vs_h].tab_n_stav = st_h;
    
    // 18. radek - AA ----------------------------------------------------------            
    LRtab_a[st_AA][vs_a].tab_akce = REDUCE;   LRtab_a[st_AA][vs_a].pravidlo1 = A_AA;
    LRtab_a[st_AA][vs_b].tab_akce = REDUCE;   LRtab_a[st_AA][vs_b].pravidlo1 = A_AA;
    LRtab_a[st_AA][vs_c].tab_akce = REDUCE;   LRtab_a[st_AA][vs_c].pravidlo1 = A_AA;
    LRtab_a[st_AA][vs_d].tab_akce = REDUCE;   LRtab_a[st_AA][vs_d].pravidlo1 = A_AA;
    LRtab_a[st_AA][vs_e].tab_akce = REDUCE;   LRtab_a[st_AA][vs_e].pravidlo1 = A_AA;
    LRtab_a[st_AA][vs_f].tab_akce = REDUCE;   LRtab_a[st_AA][vs_f].pravidlo1 = A_AA;
    LRtab_a[st_AA][vs_g].tab_akce = REDUCE;   LRtab_a[st_AA][vs_g].pravidlo1 = A_AA;
    LRtab_a[st_AA][vs_h].tab_akce = REDUCE;   LRtab_a[st_AA][vs_h].pravidlo1 = A_AA;
    LRtab_a[st_AA][vs_end].tab_akce = REDUCE; LRtab_a[st_AA][vs_end].pravidlo1 = A_AA;
    
    // 19. radek - BB ----------------------------------------------------------            
    LRtab_a[st_BB][vs_a].tab_akce = REDUCE;   LRtab_a[st_BB][vs_a].pravidlo1 = B_BB;
    LRtab_a[st_BB][vs_b].tab_akce = REDUCE;   LRtab_a[st_BB][vs_b].pravidlo1 = B_BB;
    LRtab_a[st_BB][vs_c].tab_akce = REDUCE;   LRtab_a[st_BB][vs_c].pravidlo1 = B_BB;
    LRtab_a[st_BB][vs_d].tab_akce = REDUCE;   LRtab_a[st_BB][vs_d].pravidlo1 = B_BB;
    LRtab_a[st_BB][vs_e].tab_akce = REDUCE;   LRtab_a[st_BB][vs_e].pravidlo1 = B_BB;
    LRtab_a[st_BB][vs_f].tab_akce = REDUCE;   LRtab_a[st_BB][vs_f].pravidlo1 = B_BB;
    LRtab_a[st_BB][vs_g].tab_akce = REDUCE;   LRtab_a[st_BB][vs_g].pravidlo1 = B_BB;
    LRtab_a[st_BB][vs_h].tab_akce = REDUCE;   LRtab_a[st_BB][vs_h].pravidlo1 = B_BB;
    LRtab_a[st_BB][vs_end].tab_akce = REDUCE; LRtab_a[st_BB][vs_end].pravidlo1 = B_BB;
    
    // 20. radek - CC ----------------------------------------------------------            
    LRtab_a[st_CC][vs_a].tab_akce = REDUCE;   LRtab_a[st_CC][vs_a].pravidlo1 = C_CC;
    LRtab_a[st_CC][vs_b].tab_akce = REDUCE;   LRtab_a[st_CC][vs_b].pravidlo1 = C_CC;
    LRtab_a[st_CC][vs_c].tab_akce = REDUCE;   LRtab_a[st_CC][vs_c].pravidlo1 = C_CC;
    LRtab_a[st_CC][vs_d].tab_akce = REDUCE;   LRtab_a[st_CC][vs_d].pravidlo1 = C_CC;
    LRtab_a[st_CC][vs_e].tab_akce = REDUCE;   LRtab_a[st_CC][vs_e].pravidlo1 = C_CC;
    LRtab_a[st_CC][vs_f].tab_akce = REDUCE;   LRtab_a[st_CC][vs_f].pravidlo1 = C_CC;
    LRtab_a[st_CC][vs_g].tab_akce = REDUCE;   LRtab_a[st_CC][vs_g].pravidlo1 = C_CC;
    LRtab_a[st_CC][vs_h].tab_akce = REDUCE;   LRtab_a[st_CC][vs_h].pravidlo1 = C_CC;
    LRtab_a[st_CC][vs_end].tab_akce = REDUCE; LRtab_a[st_CC][vs_end].pravidlo1 = C_CC;
    
    // 21. radek - DD ----------------------------------------------------------            
    LRtab_a[st_DD][vs_a].tab_akce = REDUCE;   LRtab_a[st_DD][vs_a].pravidlo1 = D_DD;
    LRtab_a[st_DD][vs_b].tab_akce = REDUCE;   LRtab_a[st_DD][vs_b].pravidlo1 = D_DD;
    LRtab_a[st_DD][vs_c].tab_akce = REDUCE;   LRtab_a[st_DD][vs_c].pravidlo1 = D_DD;
    LRtab_a[st_DD][vs_d].tab_akce = REDUCE;   LRtab_a[st_DD][vs_d].pravidlo1 = D_DD;
    LRtab_a[st_DD][vs_e].tab_akce = REDUCE;   LRtab_a[st_DD][vs_e].pravidlo1 = D_DD;
    LRtab_a[st_DD][vs_f].tab_akce = REDUCE;   LRtab_a[st_DD][vs_f].pravidlo1 = D_DD;
    LRtab_a[st_DD][vs_g].tab_akce = REDUCE;   LRtab_a[st_DD][vs_g].pravidlo1 = D_DD;
    LRtab_a[st_DD][vs_h].tab_akce = REDUCE;   LRtab_a[st_DD][vs_h].pravidlo1 = D_DD;
    LRtab_a[st_DD][vs_end].tab_akce = REDUCE; LRtab_a[st_DD][vs_end].pravidlo1 = D_DD;
    
    // 22. radek - EE ----------------------------------------------------------            
    LRtab_a[st_EE][vs_a].tab_akce = REDUCE;   LRtab_a[st_EE][vs_a].pravidlo1 = E_EE;
    LRtab_a[st_EE][vs_b].tab_akce = REDUCE;   LRtab_a[st_EE][vs_b].pravidlo1 = E_EE;
    LRtab_a[st_EE][vs_c].tab_akce = REDUCE;   LRtab_a[st_EE][vs_c].pravidlo1 = E_EE;
    LRtab_a[st_EE][vs_d].tab_akce = REDUCE;   LRtab_a[st_EE][vs_d].pravidlo1 = E_EE;
    LRtab_a[st_EE][vs_e].tab_akce = REDUCE;   LRtab_a[st_EE][vs_e].pravidlo1 = E_EE;
    LRtab_a[st_EE][vs_f].tab_akce = REDUCE;   LRtab_a[st_EE][vs_f].pravidlo1 = E_EE;
    LRtab_a[st_EE][vs_g].tab_akce = REDUCE;   LRtab_a[st_EE][vs_g].pravidlo1 = E_EE;
    LRtab_a[st_EE][vs_h].tab_akce = REDUCE;   LRtab_a[st_EE][vs_h].pravidlo1 = E_EE;
    LRtab_a[st_EE][vs_end].tab_akce = REDUCE; LRtab_a[st_EE][vs_end].pravidlo1 = E_EE;
    
    // 23. radek - FF ----------------------------------------------------------            
    LRtab_a[st_FF][vs_a].tab_akce = REDUCE;   LRtab_a[st_FF][vs_a].pravidlo1 = F_FF;
    LRtab_a[st_FF][vs_b].tab_akce = REDUCE;   LRtab_a[st_FF][vs_b].pravidlo1 = F_FF;
    LRtab_a[st_FF][vs_c].tab_akce = REDUCE;   LRtab_a[st_FF][vs_c].pravidlo1 = F_FF;
    LRtab_a[st_FF][vs_d].tab_akce = REDUCE;   LRtab_a[st_FF][vs_d].pravidlo1 = F_FF;
    LRtab_a[st_FF][vs_e].tab_akce = REDUCE;   LRtab_a[st_FF][vs_e].pravidlo1 = F_FF;
    LRtab_a[st_FF][vs_f].tab_akce = REDUCE;   LRtab_a[st_FF][vs_f].pravidlo1 = F_FF;
    LRtab_a[st_FF][vs_g].tab_akce = REDUCE;   LRtab_a[st_FF][vs_g].pravidlo1 = F_FF;
    LRtab_a[st_FF][vs_h].tab_akce = REDUCE;   LRtab_a[st_FF][vs_h].pravidlo1 = F_FF;
    LRtab_a[st_FF][vs_end].tab_akce = REDUCE; LRtab_a[st_FF][vs_end].pravidlo1 = F_FF;
    
    // 24. radek - GG ----------------------------------------------------------            
    LRtab_a[st_GG][vs_a].tab_akce = REDUCE;   LRtab_a[st_GG][vs_a].pravidlo1 = G_GG;
    LRtab_a[st_GG][vs_b].tab_akce = REDUCE;   LRtab_a[st_GG][vs_b].pravidlo1 = G_GG;
    LRtab_a[st_GG][vs_c].tab_akce = REDUCE;   LRtab_a[st_GG][vs_c].pravidlo1 = G_GG;
    LRtab_a[st_GG][vs_d].tab_akce = REDUCE;   LRtab_a[st_GG][vs_d].pravidlo1 = G_GG;
    LRtab_a[st_GG][vs_e].tab_akce = REDUCE;   LRtab_a[st_GG][vs_e].pravidlo1 = G_GG;
    LRtab_a[st_GG][vs_f].tab_akce = REDUCE;   LRtab_a[st_GG][vs_f].pravidlo1 = G_GG;
    LRtab_a[st_GG][vs_g].tab_akce = REDUCE;   LRtab_a[st_GG][vs_g].pravidlo1 = G_GG;
    LRtab_a[st_GG][vs_h].tab_akce = REDUCE;   LRtab_a[st_GG][vs_h].pravidlo1 = G_GG;
    LRtab_a[st_GG][vs_end].tab_akce = REDUCE; LRtab_a[st_GG][vs_end].pravidlo1 = G_GG;
    
    // 25. radek - HH ----------------------------------------------------------            
    LRtab_a[st_HH][vs_a].tab_akce = REDUCE;   LRtab_a[st_HH][vs_a].pravidlo1 = H_HH;
    LRtab_a[st_HH][vs_b].tab_akce = REDUCE;   LRtab_a[st_HH][vs_b].pravidlo1 = H_HH;
    LRtab_a[st_HH][vs_c].tab_akce = REDUCE;   LRtab_a[st_HH][vs_c].pravidlo1 = H_HH;
    LRtab_a[st_HH][vs_d].tab_akce = REDUCE;   LRtab_a[st_HH][vs_d].pravidlo1 = H_HH;
    LRtab_a[st_HH][vs_e].tab_akce = REDUCE;   LRtab_a[st_HH][vs_e].pravidlo1 = H_HH;
    LRtab_a[st_HH][vs_f].tab_akce = REDUCE;   LRtab_a[st_HH][vs_f].pravidlo1 = H_HH;
    LRtab_a[st_HH][vs_g].tab_akce = REDUCE;   LRtab_a[st_HH][vs_g].pravidlo1 = H_HH;
    LRtab_a[st_HH][vs_h].tab_akce = REDUCE;   LRtab_a[st_HH][vs_h].pravidlo1 = H_HH;
    LRtab_a[st_HH][vs_end].tab_akce = REDUCE; LRtab_a[st_HH][vs_end].pravidlo1 = H_HH;
    
    // 26. radek - 1 ----------------------------------------------------------- 
    LRtab_a[st_1][vs_c].tab_akce = SHIFT;   LRtab_a[st_1][vs_c].tab_n_stav = st_c;
    LRtab_a[st_1][vs_d].tab_akce = SHIFT;   LRtab_a[st_1][vs_d].tab_n_stav = st_d;
    LRtab_a[st_1][vs_e].tab_akce = SHIFT;   LRtab_a[st_1][vs_e].tab_n_stav = st_e;
    //LRtab_a[st_1][vs_f].tab_akce = SHIFT;   LRtab_a[st_1][vs_f].tab_n_stav = st_f;
    LRtab_a[st_1][vs_g].tab_akce = SHIFT;   LRtab_a[st_1][vs_g].tab_n_stav = st_g;
    LRtab_a[st_1][vs_h].tab_akce = SHIFT;   LRtab_a[st_1][vs_h].tab_n_stav = st_h;
    
    // 27. radek - 3 -----------------------------------------------------------
    LRtab_a[st_3][vs_c].tab_akce = SHIFT;   LRtab_a[st_3][vs_c].tab_n_stav = st_c;
    LRtab_a[st_3][vs_h].tab_akce = SHIFT;   LRtab_a[st_3][vs_h].tab_n_stav = st_h;
    
    // 28. radek - 4 -----------------------------------------------------------
    LRtab_a[st_4][vs_a].tab_akce = SHIFT;   LRtab_a[st_4][vs_a].tab_n_stav = st_a;
    LRtab_a[st_4][vs_c].tab_akce = SHIFT;   LRtab_a[st_4][vs_c].tab_n_stav = st_c;
    LRtab_a[st_4][vs_e].tab_akce = SHIFT;   LRtab_a[st_4][vs_e].tab_n_stav = st_e;
    LRtab_a[st_4][vs_f].tab_akce = SHIFT;   LRtab_a[st_4][vs_f].tab_n_stav = st_f;
    LRtab_a[st_4][vs_h].tab_akce = SHIFT;   LRtab_a[st_4][vs_h].tab_n_stav = st_h;
    
    // 29. radek - 6 -----------------------------------------------------------
    LRtab_a[st_6][vs_g].tab_akce = SHIFT;   LRtab_a[st_6][vs_g].tab_n_stav = st_g;
    
    // 30. radek - 8 -----------------------------------------------------------
    LRtab_a[st_8][vs_e].tab_akce = SHIFT;   LRtab_a[st_8][vs_e].tab_n_stav = st_e;
    
    // 31. radek - P -----------------------------------------------------------
    LRtab_a[st_P][vs_b].tab_akce = SHIFT;   LRtab_a[st_P][vs_b].tab_n_stav = st_b;
    LRtab_a[st_P][vs_c].tab_akce = SHIFT;   LRtab_a[st_P][vs_c].tab_n_stav = st_c;
    LRtab_a[st_P][vs_e].tab_akce = SHIFT;   LRtab_a[st_P][vs_e].tab_n_stav = st_e;
    LRtab_a[st_P][vs_h].tab_akce = SHIFT;   LRtab_a[st_P][vs_h].tab_n_stav = st_h;
    
    // 32. radek - R -----------------------------------------------------------
    LRtab_a[st_9][vs_c].tab_akce = SHIFT;   LRtab_a[st_9][vs_c].tab_n_stav = st_c;
    
    // 33. radek - U -----------------------------------------------------------
    LRtab_a[st_U][vs_e].tab_akce = SHIFT;   LRtab_a[st_U][vs_e].tab_n_stav = st_e;
    LRtab_a[st_U][vs_h].tab_akce = SHIFT;   LRtab_a[st_U][vs_h].tab_n_stav = st_h;    
    
    // 34. radek - X -----------------------------------------------------------
    LRtab_a[st_X][vs_c].tab_akce = SHIFT;   LRtab_a[st_X][vs_c].tab_n_stav = st_c;
    LRtab_a[st_X][vs_h].tab_akce = SHIFT;   LRtab_a[st_X][vs_h].tab_n_stav = st_h;
    
    // 35. radek - DB ----------------------------------------------------------
    LRtab_a[st_DB][vs_a].tab_akce = REDUCE;   LRtab_a[st_DB][vs_a].pravidlo1 = j_DB;
    LRtab_a[st_DB][vs_b].tab_akce = SHIFT;    LRtab_a[st_DB][vs_b].tab_n_stav = st_b;
    LRtab_a[st_DB][vs_c].tab_akce = REDUCE;   LRtab_a[st_DB][vs_c].pravidlo1 = j_DB;
    LRtab_a[st_DB][vs_d].tab_akce = REDUCE;   LRtab_a[st_DB][vs_d].pravidlo1 = j_DB;
    LRtab_a[st_DB][vs_e].tab_akce = REDUCE;   LRtab_a[st_DB][vs_e].pravidlo1 = j_DB;
    LRtab_a[st_DB][vs_f].tab_akce = REDUCE;   LRtab_a[st_DB][vs_f].pravidlo1 = j_DB;
    LRtab_a[st_DB][vs_g].tab_akce = REDUCE;   LRtab_a[st_DB][vs_g].pravidlo1 = j_DB;
    LRtab_a[st_DB][vs_h].konflikt = true;    
    LRtab_a[st_DB][vs_h].tab_akce = SHIFT;    LRtab_a[st_DB][vs_h].tab_n_stav = st_h;
    LRtab_a[st_DB][vs_h].pravidlo1 = j_DB;
    LRtab_a[st_DB][vs_end].tab_akce = REDUCE; LRtab_a[st_DB][vs_end].pravidlo1 = j_DB;
    
    // 36. radek - FB ----------------------------------------------------------
    /*
    LRtab_a[st_FB][vs_a].tab_akce = REDUCE;   LRtab_a[st_FB][vs_a].pravidlo1 = j_FB;
    LRtab_a[st_FB][vs_b].tab_akce = SHIFT;    LRtab_a[st_FB][vs_b].tab_n_stav = st_b;
    LRtab_a[st_FB][vs_c].konflikt = true;
    LRtab_a[st_FB][vs_c].tab_akce = SHIFT;    LRtab_a[st_FB][vs_c].tab_n_stav = st_c;
    LRtab_a[st_FB][vs_c].pravidlo1 = j_FB;
    LRtab_a[st_FB][vs_d].tab_akce = REDUCE;   LRtab_a[st_FB][vs_d].pravidlo1 = j_FB;
    LRtab_a[st_FB][vs_e].tab_akce = REDUCE;   LRtab_a[st_FB][vs_e].pravidlo1 = j_FB;
    LRtab_a[st_FB][vs_f].tab_akce = REDUCE;   LRtab_a[st_FB][vs_f].pravidlo1 = j_FB;
    LRtab_a[st_FB][vs_g].tab_akce = REDUCE;   LRtab_a[st_FB][vs_g].pravidlo1 = j_FB;
    LRtab_a[st_FB][vs_h].konflikt = true;
    LRtab_a[st_FB][vs_h].tab_akce = SHIFT;    LRtab_a[st_FB][vs_h].tab_n_stav = st_h;
    LRtab_a[st_FB][vs_h].pravidlo1 = j_FB;
    LRtab_a[st_FB][vs_end].tab_akce = REDUCE; LRtab_a[st_FB][vs_end].pravidlo1 = j_FB;
    */ 
    LRtab_a[st_FB][vs_b].tab_akce = SHIFT;    LRtab_a[st_FB][vs_b].tab_n_stav = st_b;
    LRtab_a[st_FB][vs_c].tab_akce = SHIFT;    LRtab_a[st_FB][vs_c].tab_n_stav = st_c;
    LRtab_a[st_FB][vs_h].tab_akce = SHIFT;    LRtab_a[st_FB][vs_h].tab_n_stav = st_h;
    
    
    // 37. radek - DF ----------------------------------------------------------
    LRtab_a[st_DF][vs_a].tab_akce = REDUCE;   LRtab_a[st_DF][vs_a].pravidlo1 = P_DF;
    LRtab_a[st_DF][vs_a].poc_pravidel = 2;    LRtab_a[st_DF][vs_a].pravidlo2 = F_DF;
    
    LRtab_a[st_DF][vs_b].konflikt = true;     LRtab_a[st_DF][vs_b].poc_pravidel = 2;  
    LRtab_a[st_DF][vs_b].tab_akce = SHIFT;    LRtab_a[st_DF][vs_b].tab_n_stav = st_b;
    LRtab_a[st_DF][vs_b].pravidlo1 = P_DF;    LRtab_a[st_DF][vs_b].pravidlo2 = F_DF;
    
    LRtab_a[st_DF][vs_c].tab_akce = REDUCE;   LRtab_a[st_DF][vs_c].pravidlo1 = P_DF;
    LRtab_a[st_DF][vs_c].poc_pravidel = 2;    LRtab_a[st_DF][vs_c].pravidlo2 = F_DF;
    LRtab_a[st_DF][vs_d].tab_akce = REDUCE;   LRtab_a[st_DF][vs_d].pravidlo1 = P_DF;
    LRtab_a[st_DF][vs_d].poc_pravidel = 2;    LRtab_a[st_DF][vs_d].pravidlo2 = F_DF;
    LRtab_a[st_DF][vs_e].tab_akce = REDUCE;   LRtab_a[st_DF][vs_e].pravidlo1 = P_DF;
    LRtab_a[st_DF][vs_e].poc_pravidel = 2;    LRtab_a[st_DF][vs_e].pravidlo2 = F_DF;
    
    LRtab_a[st_DF][vs_f].konflikt = true;     LRtab_a[st_DF][vs_f].poc_pravidel = 2;
    LRtab_a[st_DF][vs_f].tab_akce = SHIFT;    LRtab_a[st_DF][vs_f].tab_n_stav = st_f;
    LRtab_a[st_DF][vs_f].pravidlo1 = P_DF;    LRtab_a[st_DF][vs_f].pravidlo2 = F_DF;
    
    LRtab_a[st_DF][vs_g].tab_akce = REDUCE;   LRtab_a[st_DF][vs_g].pravidlo1 = P_DF;
    LRtab_a[st_DF][vs_g].poc_pravidel = 2;    LRtab_a[st_DF][vs_g].pravidlo2 = F_DF;
    LRtab_a[st_DF][vs_h].konflikt = true;     LRtab_a[st_DF][vs_h].poc_pravidel = 2;
    LRtab_a[st_DF][vs_h].tab_akce = SHIFT;    LRtab_a[st_DF][vs_h].tab_n_stav = st_h;
    LRtab_a[st_DF][vs_h].pravidlo1 = P_DF;    LRtab_a[st_DF][vs_h].pravidlo2 = F_DF;
    LRtab_a[st_DF][vs_end].tab_akce = REDUCE; LRtab_a[st_DF][vs_end].pravidlo1 = P_DF;
    LRtab_a[st_DF][vs_end].poc_pravidel = 2;  LRtab_a[st_DF][vs_end].pravidlo2 = F_DF;
    
    // 38. radek - DH ----------------------------------------------------------
    LRtab_a[st_DH][vs_a].tab_akce = REDUCE;   LRtab_a[st_DH][vs_a].pravidlo1 = c_DH;
    LRtab_a[st_DH][vs_b].tab_akce = SHIFT;    LRtab_a[st_DH][vs_b].tab_n_stav = st_b;
    LRtab_a[st_DH][vs_c].tab_akce = REDUCE;   LRtab_a[st_DH][vs_c].pravidlo1 = c_DH;
    LRtab_a[st_DH][vs_d].tab_akce = REDUCE;   LRtab_a[st_DH][vs_d].pravidlo1 = c_DH;
    LRtab_a[st_DH][vs_e].tab_akce = REDUCE;   LRtab_a[st_DH][vs_e].pravidlo1 = c_DH;
    LRtab_a[st_DH][vs_f].tab_akce = REDUCE;   LRtab_a[st_DH][vs_f].pravidlo1 = c_DH;
    LRtab_a[st_DH][vs_g].tab_akce = REDUCE;   LRtab_a[st_DH][vs_g].pravidlo1 = c_DH;
    LRtab_a[st_DH][vs_h].tab_akce = SHIFT;    LRtab_a[st_DH][vs_h].tab_n_stav = st_h;
    LRtab_a[st_DH][vs_end].tab_akce = REDUCE; LRtab_a[st_DH][vs_end].pravidlo1 = c_DH;
    
    // 39. radek - HE ----------------------------------------------------------
    LRtab_a[st_HE][vs_a].tab_akce = REDUCE;   LRtab_a[st_HE][vs_a].pravidlo1 = d_HE;
    LRtab_a[st_HE][vs_a].poc_pravidel = 2;    LRtab_a[st_HE][vs_a].pravidlo2 = x_HE;
    LRtab_a[st_HE][vs_b].tab_akce = REDUCE;   LRtab_a[st_HE][vs_b].pravidlo1 = d_HE;
    LRtab_a[st_HE][vs_b].poc_pravidel = 2;    LRtab_a[st_HE][vs_b].pravidlo2 = x_HE;
    LRtab_a[st_HE][vs_c].tab_akce = REDUCE;   LRtab_a[st_HE][vs_c].pravidlo1 = d_HE;
    LRtab_a[st_HE][vs_c].poc_pravidel = 2;    LRtab_a[st_HE][vs_c].pravidlo2 = x_HE;;
    LRtab_a[st_HE][vs_d].tab_akce = REDUCE;   LRtab_a[st_HE][vs_d].pravidlo1 = d_HE;
    LRtab_a[st_HE][vs_d].poc_pravidel = 2;    LRtab_a[st_HE][vs_d].pravidlo2 = x_HE;
    LRtab_a[st_HE][vs_e].tab_akce = SHIFT;    LRtab_a[st_HE][vs_e].tab_n_stav = st_e;
    LRtab_a[st_HE][vs_f].tab_akce = REDUCE;   LRtab_a[st_HE][vs_f].pravidlo1 = d_HE;
    LRtab_a[st_HE][vs_f].poc_pravidel = 2;    LRtab_a[st_HE][vs_f].pravidlo2 = x_HE;
    LRtab_a[st_HE][vs_g].tab_akce = REDUCE;   LRtab_a[st_HE][vs_g].pravidlo1 = d_HE;
    LRtab_a[st_HE][vs_g].poc_pravidel = 2;    LRtab_a[st_HE][vs_g].pravidlo2 = x_HE;
    LRtab_a[st_HE][vs_h].tab_akce = REDUCE;   LRtab_a[st_HE][vs_h].pravidlo1 = d_HE;
    LRtab_a[st_HE][vs_h].poc_pravidel = 2;    LRtab_a[st_HE][vs_h].pravidlo2 = x_HE;
    LRtab_a[st_HE][vs_end].tab_akce = REDUCE; LRtab_a[st_HE][vs_end].pravidlo1 = d_HE;
    LRtab_a[st_HE][vs_end].poc_pravidel = 2;  LRtab_a[st_HE][vs_end].pravidlo2 = x_HE;
            
    // 40. radek - CE ----------------------------------------------------------
    LRtab_a[st_CE][vs_a].konflikt =true;      LRtab_a[st_CE][vs_a].poc_pravidel = 2;
    LRtab_a[st_CE][vs_a].tab_akce = SHIFT;    LRtab_a[st_CE][vs_a].tab_n_stav = st_a;
    LRtab_a[st_CE][vs_a].pravidlo1 = M_CE;    LRtab_a[st_CE][vs_a].pravidlo2 = d_CE;
    LRtab_a[st_CE][vs_b].tab_akce = REDUCE;   LRtab_a[st_CE][vs_b].pravidlo1 = d_CE;
    LRtab_a[st_CE][vs_b].poc_pravidel = 2;    LRtab_a[st_CE][vs_b].pravidlo2 = M_CE;
    LRtab_a[st_CE][vs_c].tab_akce = REDUCE;   LRtab_a[st_CE][vs_c].pravidlo1 = d_CE;
    LRtab_a[st_CE][vs_c].poc_pravidel = 2;    LRtab_a[st_CE][vs_c].pravidlo2 = M_CE;
    LRtab_a[st_CE][vs_d].tab_akce = REDUCE;   LRtab_a[st_CE][vs_d].pravidlo1 = d_CE;
    LRtab_a[st_CE][vs_d].poc_pravidel = 2;    LRtab_a[st_CE][vs_d].pravidlo2 = M_CE;
    LRtab_a[st_CE][vs_e].tab_akce = SHIFT;    LRtab_a[st_CE][vs_e].tab_n_stav = st_e;    
    LRtab_a[st_CE][vs_f].tab_akce = REDUCE;   LRtab_a[st_CE][vs_f].pravidlo1 = d_CE;
    LRtab_a[st_CE][vs_f].poc_pravidel = 2;    LRtab_a[st_CE][vs_f].pravidlo2 = M_CE;
    LRtab_a[st_CE][vs_g].konflikt = true;     LRtab_a[st_CE][vs_g].poc_pravidel = 2;
    LRtab_a[st_CE][vs_g].tab_akce = SHIFT;    LRtab_a[st_CE][vs_g].tab_n_stav = st_g;
    LRtab_a[st_CE][vs_g].pravidlo1 = M_CE;    LRtab_a[st_CE][vs_g].pravidlo2 = d_CE;
    LRtab_a[st_CE][vs_h].tab_akce = REDUCE;   LRtab_a[st_CE][vs_h].pravidlo1 = d_CE;
    LRtab_a[st_CE][vs_h].poc_pravidel = 2;    LRtab_a[st_CE][vs_h].pravidlo2 = M_CE;
    LRtab_a[st_CE][vs_end].tab_akce = REDUCE; LRtab_a[st_CE][vs_end].pravidlo1 = d_CE;
    LRtab_a[st_CE][vs_end].poc_pravidel = 2;  LRtab_a[st_CE][vs_end].pravidlo2 = M_CE;
    
    // 41. radek - HC ----------------------------------------------------------
    LRtab_a[st_HC][vs_a].tab_akce = SHIFT;   LRtab_a[st_HC][vs_a].tab_n_stav = st_a;
    LRtab_a[st_HC][vs_b].tab_akce = SHIFT;   LRtab_a[st_HC][vs_b].tab_n_stav = st_b;
    LRtab_a[st_HC][vs_c].tab_akce = SHIFT;   LRtab_a[st_HC][vs_c].tab_n_stav = st_c;
    LRtab_a[st_HC][vs_e].tab_akce = SHIFT;   LRtab_a[st_HC][vs_e].tab_n_stav = st_e;
    
    // 42. radek - CA ----------------------------------------------------------
    LRtab_a[st_CA][vs_a].tab_akce = SHIFT;    LRtab_a[st_CA][vs_a].tab_n_stav = st_a;
    LRtab_a[st_CA][vs_b].tab_akce = REDUCE;   LRtab_a[st_CA][vs_b].pravidlo1 = t_CA;
    LRtab_a[st_CA][vs_b].poc_pravidel = 2;    LRtab_a[st_CA][vs_b].pravidlo2 = s_CA;
    LRtab_a[st_CA][vs_c].tab_akce = REDUCE;   LRtab_a[st_CA][vs_c].pravidlo1 = t_CA;
    LRtab_a[st_CA][vs_c].poc_pravidel = 2;    LRtab_a[st_CA][vs_c].pravidlo2 = s_CA;
    LRtab_a[st_CA][vs_d].tab_akce = REDUCE;   LRtab_a[st_CA][vs_d].pravidlo1 = t_CA;
    LRtab_a[st_CA][vs_d].poc_pravidel = 2;    LRtab_a[st_CA][vs_d].pravidlo2 = s_CA;
    LRtab_a[st_CA][vs_e].tab_akce = REDUCE;   LRtab_a[st_CA][vs_e].pravidlo1 = t_CA;
    LRtab_a[st_CA][vs_e].poc_pravidel = 2;    LRtab_a[st_CA][vs_e].pravidlo2 = s_CA;
    LRtab_a[st_CA][vs_f].tab_akce = REDUCE;   LRtab_a[st_CA][vs_f].pravidlo1 = t_CA;
    LRtab_a[st_CA][vs_f].poc_pravidel = 2;    LRtab_a[st_CA][vs_f].pravidlo2 = s_CA;
    LRtab_a[st_CA][vs_g].konflikt = true;     LRtab_a[st_CA][vs_g].poc_pravidel = 2;
    LRtab_a[st_CA][vs_g].tab_akce = SHIFT;    LRtab_a[st_CA][vs_g].tab_n_stav = st_g;
    LRtab_a[st_CA][vs_g].pravidlo1 = t_CA;    LRtab_a[st_CA][vs_g].pravidlo2 = s_CA;
    LRtab_a[st_CA][vs_h].tab_akce = REDUCE;   LRtab_a[st_CA][vs_h].pravidlo1 = t_CA;
    LRtab_a[st_CA][vs_h].poc_pravidel = 2;    LRtab_a[st_CA][vs_h].pravidlo2 = s_CA;
    LRtab_a[st_CA][vs_end].tab_akce = REDUCE; LRtab_a[st_CA][vs_end].pravidlo1 = t_CA;
    LRtab_a[st_CA][vs_end].poc_pravidel = 2;  LRtab_a[st_CA][vs_end].pravidlo2 = s_CA;
    
    // 43. radek - HA ----------------------------------------------------------
    LRtab_a[st_HA][vs_a].tab_akce = SHIFT;    LRtab_a[st_HA][vs_a].tab_n_stav = st_a;
    LRtab_a[st_HA][vs_b].tab_akce = REDUCE;   LRtab_a[st_HA][vs_b].pravidlo1 = p_HA;
    LRtab_a[st_HA][vs_c].tab_akce = REDUCE;   LRtab_a[st_HA][vs_c].pravidlo1 = p_HA;
    LRtab_a[st_HA][vs_d].tab_akce = REDUCE;   LRtab_a[st_HA][vs_d].pravidlo1 = p_HA;
    LRtab_a[st_HA][vs_e].tab_akce = REDUCE;   LRtab_a[st_HA][vs_e].pravidlo1 = p_HA;
    LRtab_a[st_HA][vs_f].tab_akce = REDUCE;   LRtab_a[st_HA][vs_f].pravidlo1 = p_HA;
    LRtab_a[st_HA][vs_g].tab_akce = REDUCE;   LRtab_a[st_HA][vs_g].pravidlo1 = p_HA;
    LRtab_a[st_HA][vs_h].tab_akce = REDUCE;   LRtab_a[st_HA][vs_h].pravidlo1 = p_HA;
    LRtab_a[st_HA][vs_end].tab_akce = REDUCE; LRtab_a[st_HA][vs_end].pravidlo1 = p_HA;
    
    // 44. radek - CG ----------------------------------------------------------
    LRtab_a[st_CG][vs_a].tab_akce = REDUCE;   LRtab_a[st_CG][vs_a].pravidlo1 = o_CG;
    LRtab_a[st_CG][vs_b].tab_akce = REDUCE;   LRtab_a[st_CG][vs_b].pravidlo1 = o_CG;
    LRtab_a[st_CG][vs_c].tab_akce = REDUCE;   LRtab_a[st_CG][vs_c].pravidlo1 = o_CG;
    LRtab_a[st_CG][vs_d].tab_akce = REDUCE;   LRtab_a[st_CG][vs_d].pravidlo1 = o_CG;
    LRtab_a[st_CG][vs_e].tab_akce = REDUCE;   LRtab_a[st_CG][vs_e].pravidlo1 = o_CG;
    LRtab_a[st_CG][vs_f].tab_akce = REDUCE;   LRtab_a[st_CG][vs_f].pravidlo1 = o_CG;
    LRtab_a[st_CG][vs_g].tab_akce = SHIFT;    LRtab_a[st_CG][vs_g].tab_n_stav = st_g;
    LRtab_a[st_CG][vs_h].tab_akce = REDUCE;   LRtab_a[st_CG][vs_h].pravidlo1 = o_CG;
    LRtab_a[st_CG][vs_end].tab_akce = REDUCE; LRtab_a[st_CG][vs_end].pravidlo1 = o_CG;
    
    // 45. radek - FH ----------------------------------------------------------
    LRtab_a[st_FH][vs_a].tab_akce = REDUCE;   LRtab_a[st_FH][vs_a].pravidlo1 = k_FH;
    LRtab_a[st_FH][vs_b].tab_akce = REDUCE;   LRtab_a[st_FH][vs_b].pravidlo1 = k_FH;         
    LRtab_a[st_FH][vs_c].tab_akce = SHIFT;    LRtab_a[st_FH][vs_c].tab_n_stav = st_c;
    LRtab_a[st_FH][vs_d].tab_akce = REDUCE;   LRtab_a[st_FH][vs_d].pravidlo1 = k_FH;
    LRtab_a[st_FH][vs_e].tab_akce = REDUCE;   LRtab_a[st_FH][vs_e].pravidlo1 = k_FH;
    LRtab_a[st_FH][vs_f].tab_akce = REDUCE;   LRtab_a[st_FH][vs_f].pravidlo1 = k_FH;
    LRtab_a[st_FH][vs_g].tab_akce = REDUCE;   LRtab_a[st_FH][vs_g].pravidlo1 = k_FH;
    LRtab_a[st_FH][vs_h].tab_akce = SHIFT;    LRtab_a[st_FH][vs_h].tab_n_stav = st_h;
    LRtab_a[st_FH][vs_end].tab_akce = REDUCE; LRtab_a[st_FH][vs_end].pravidlo1 = k_FH;

    
    // 46. radek - FC ----------------------------------------------------------
    LRtab_a[st_FC][vs_a].tab_akce = REDUCE;   LRtab_a[st_FC][vs_a].pravidlo1 = h_FC;
    LRtab_a[st_FC][vs_b].tab_akce = REDUCE;   LRtab_a[st_FC][vs_b].pravidlo1 = h_FC;
    LRtab_a[st_FC][vs_c].tab_akce = SHIFT;    LRtab_a[st_FC][vs_c].tab_n_stav = st_c;
    LRtab_a[st_FC][vs_d].tab_akce = REDUCE;   LRtab_a[st_FC][vs_d].pravidlo1 = h_FC;
    LRtab_a[st_FC][vs_e].tab_akce = REDUCE;   LRtab_a[st_FC][vs_e].pravidlo1 = h_FC;
    LRtab_a[st_FC][vs_f].tab_akce = REDUCE;   LRtab_a[st_FC][vs_f].pravidlo1 = h_FC;
    LRtab_a[st_FC][vs_g].tab_akce = REDUCE;   LRtab_a[st_FC][vs_g].pravidlo1 = h_FC;
    LRtab_a[st_FC][vs_h].tab_akce = REDUCE;   LRtab_a[st_FC][vs_h].pravidlo1 = h_FC;
    LRtab_a[st_FC][vs_end].tab_akce = REDUCE; LRtab_a[st_FC][vs_end].pravidlo1 = h_FC;
    
    // 47. radek - CB ----------------------------------------------------------
    LRtab_a[st_CB][vs_a].tab_akce = REDUCE;   LRtab_a[st_CB][vs_a].pravidlo1 = J_CB;
    LRtab_a[st_CB][vs_b].tab_akce = SHIFT;    LRtab_a[st_CB][vs_b].tab_n_stav = st_b;
    LRtab_a[st_CB][vs_c].tab_akce = REDUCE;   LRtab_a[st_CB][vs_c].pravidlo1 = J_CB;
    LRtab_a[st_CB][vs_d].tab_akce = REDUCE;   LRtab_a[st_CB][vs_d].pravidlo1 = J_CB;
    LRtab_a[st_CB][vs_e].tab_akce = REDUCE;   LRtab_a[st_CB][vs_e].pravidlo1 = J_CB;
    LRtab_a[st_CB][vs_f].tab_akce = REDUCE;   LRtab_a[st_CB][vs_f].pravidlo1 = J_CB;
    LRtab_a[st_CB][vs_g].tab_akce = REDUCE;   LRtab_a[st_CB][vs_g].pravidlo1 = J_CB;
    LRtab_a[st_CB][vs_h].tab_akce = REDUCE;   LRtab_a[st_CB][vs_h].pravidlo1 = J_CB;
    LRtab_a[st_CB][vs_end].tab_akce = REDUCE; LRtab_a[st_CB][vs_end].pravidlo1 = J_CB;
    
    // 48. radek - DA ----------------------------------------------------------
    LRtab_a[st_DA][vs_a].tab_akce = SHIFT;    LRtab_a[st_DA][vs_a].tab_n_stav = st_a;
    LRtab_a[st_DA][vs_b].tab_akce = REDUCE;   LRtab_a[st_DA][vs_b].pravidlo1 = K_DA;
    LRtab_a[st_DA][vs_c].tab_akce = REDUCE;   LRtab_a[st_DA][vs_c].pravidlo1 = K_DA;
    LRtab_a[st_DA][vs_d].tab_akce = REDUCE;   LRtab_a[st_DA][vs_d].pravidlo1 = K_DA;
    LRtab_a[st_DA][vs_e].tab_akce = REDUCE;   LRtab_a[st_DA][vs_e].pravidlo1 = K_DA;
    LRtab_a[st_DA][vs_f].tab_akce = REDUCE;   LRtab_a[st_DA][vs_f].pravidlo1 = K_DA;
    LRtab_a[st_DA][vs_g].tab_akce = REDUCE;   LRtab_a[st_DA][vs_g].pravidlo1 = K_DA;
    LRtab_a[st_DA][vs_h].tab_akce = REDUCE;   LRtab_a[st_DA][vs_h].pravidlo1 = K_DA;
    LRtab_a[st_DA][vs_end].tab_akce = REDUCE; LRtab_a[st_DA][vs_end].pravidlo1 = K_DA;
    
    // 49. radek - AG ----------------------------------------------------------
    LRtab_a[st_AG][vs_a].tab_akce = REDUCE;   LRtab_a[st_AG][vs_a].pravidlo1 = W_AG;
    LRtab_a[st_AG][vs_b].tab_akce = REDUCE;   LRtab_a[st_AG][vs_b].pravidlo1 = W_AG;
    LRtab_a[st_AG][vs_c].tab_akce = REDUCE;   LRtab_a[st_AG][vs_c].pravidlo1 = W_AG;
    LRtab_a[st_AG][vs_d].tab_akce = REDUCE;   LRtab_a[st_AG][vs_d].pravidlo1 = W_AG;
    LRtab_a[st_AG][vs_e].tab_akce = REDUCE;   LRtab_a[st_AG][vs_e].pravidlo1 = W_AG;
    LRtab_a[st_AG][vs_f].tab_akce = REDUCE;   LRtab_a[st_AG][vs_f].pravidlo1 = W_AG;
    LRtab_a[st_AG][vs_g].tab_akce = SHIFT;    LRtab_a[st_AG][vs_g].tab_n_stav = st_g;
    LRtab_a[st_AG][vs_h].tab_akce = REDUCE;   LRtab_a[st_AG][vs_h].pravidlo1 = W_AG;
    LRtab_a[st_AG][vs_end].tab_akce = REDUCE; LRtab_a[st_AG][vs_end].pravidlo1 = W_AG;
    
    // 50. radek - ED ----------------------------------------------------------
    LRtab_a[st_ED][vs_a].tab_akce = REDUCE;    LRtab_a[st_ED][vs_a].pravidlo1 = Z_ED;
    LRtab_a[st_ED][vs_b].tab_akce = REDUCE;    LRtab_a[st_ED][vs_b].pravidlo1 = Z_ED;
    LRtab_a[st_ED][vs_c].tab_akce = REDUCE;    LRtab_a[st_ED][vs_c].pravidlo1 = Z_ED;
    LRtab_a[st_ED][vs_d].tab_akce = SHIFT;     LRtab_a[st_ED][vs_d].tab_n_stav = st_d;
    LRtab_a[st_ED][vs_e].tab_akce = REDUCE;    LRtab_a[st_ED][vs_d].pravidlo1 = Z_ED;
    LRtab_a[st_ED][vs_f].tab_akce = REDUCE;    LRtab_a[st_ED][vs_e].pravidlo1 = Z_ED;
    LRtab_a[st_ED][vs_g].tab_akce = REDUCE;    LRtab_a[st_ED][vs_f].pravidlo1 = Z_ED;
    LRtab_a[st_ED][vs_h].tab_akce = REDUCE;    LRtab_a[st_ED][vs_g].pravidlo1 = Z_ED;
    LRtab_a[st_ED][vs_end].tab_akce = REDUCE;  LRtab_a[st_ED][vs_h].pravidlo1 = Z_ED;
    
    // 51. radek - EH ----------------------------------------------------------
    LRtab_a[st_EH][vs_a].tab_akce = SHIFT;    LRtab_a[st_EH][vs_a].tab_n_stav = st_a;
    LRtab_a[st_EH][vs_h].tab_akce = SHIFT;    LRtab_a[st_EH][vs_h].tab_n_stav = st_h;
    
    // 52. radek - 11 ----------------------------------------------------------
    LRtab_a[st_11][vs_c].tab_akce = SHIFT;    LRtab_a[st_11][vs_c].tab_n_stav = st_c;
    LRtab_a[st_11][vs_h].tab_akce = SHIFT;    LRtab_a[st_11][vs_h].tab_n_stav = st_h;
    
    // 53. radek - 33 ----------------------------------------------------------
    LRtab_a[st_33][vs_d].tab_akce = SHIFT;    LRtab_a[st_33][vs_d].tab_n_stav = st_d;
    
    // 54. radek - EG ----------------------------------------------------------
    LRtab_a[st_EG][vs_a].tab_akce = REDUCE;   LRtab_a[st_EG][vs_a].pravidlo1 = O_EG;
    LRtab_a[st_EG][vs_b].tab_akce = REDUCE;   LRtab_a[st_EG][vs_b].pravidlo1 = O_EG;
    LRtab_a[st_EG][vs_c].tab_akce = REDUCE;   LRtab_a[st_EG][vs_c].pravidlo1 = O_EG;
    LRtab_a[st_EG][vs_d].tab_akce = SHIFT;    LRtab_a[st_EG][vs_d].tab_n_stav = st_d;
    LRtab_a[st_EG][vs_e].tab_akce = REDUCE;   LRtab_a[st_EG][vs_e].pravidlo1 = O_EG;
    LRtab_a[st_EG][vs_f].tab_akce = REDUCE;   LRtab_a[st_EG][vs_f].pravidlo1 = O_EG;
    LRtab_a[st_EG][vs_g].tab_akce = SHIFT;    LRtab_a[st_EG][vs_g].tab_n_stav = st_g;
    LRtab_a[st_EG][vs_h].tab_akce = REDUCE;   LRtab_a[st_EG][vs_h].pravidlo1 = O_EG;
    LRtab_a[st_EG][vs_end].tab_akce = REDUCE; LRtab_a[st_EG][vs_end].pravidlo1 = O_EG;
    
    // 55. radek - 6G ----------------------------------------------------------
    LRtab_a[st_6G][vs_a].tab_akce = REDUCE;   LRtab_a[st_6G][vs_a].pravidlo1 = ss_6G;
    LRtab_a[st_6G][vs_b].tab_akce = REDUCE;   LRtab_a[st_6G][vs_b].pravidlo1 = ss_6G;
    LRtab_a[st_6G][vs_c].tab_akce = REDUCE;   LRtab_a[st_6G][vs_c].pravidlo1 = ss_6G;
    LRtab_a[st_6G][vs_d].tab_akce = REDUCE;   LRtab_a[st_6G][vs_d].pravidlo1 = ss_6G;
    LRtab_a[st_6G][vs_e].tab_akce = REDUCE;   LRtab_a[st_6G][vs_e].pravidlo1 = ss_6G;
    LRtab_a[st_6G][vs_f].tab_akce = REDUCE;   LRtab_a[st_6G][vs_f].pravidlo1 = ss_6G;
    LRtab_a[st_6G][vs_g].tab_akce = SHIFT;    LRtab_a[st_6G][vs_g].tab_n_stav = st_g;
    LRtab_a[st_6G][vs_h].tab_akce = REDUCE;   LRtab_a[st_6G][vs_h].pravidlo1 = ss_6G;
    LRtab_a[st_6G][vs_end].tab_akce = REDUCE; LRtab_a[st_6G][vs_end].pravidlo1 = ss_6G;
    
    // 56. radek - EA ----------------------------------------------------------
    LRtab_a[st_EA][vs_a].tab_akce = SHIFT;    LRtab_a[st_EA][vs_a].tab_n_stav = st_a;
    LRtab_a[st_EA][vs_b].tab_akce = REDUCE;   LRtab_a[st_EA][vs_b].pravidlo1 = Q_EA;
    LRtab_a[st_EA][vs_c].tab_akce = REDUCE;   LRtab_a[st_EA][vs_c].pravidlo1 = Q_EA;
    LRtab_a[st_EA][vs_d].tab_akce = SHIFT;    LRtab_a[st_EA][vs_d].tab_n_stav = st_d;
    LRtab_a[st_EA][vs_e].tab_akce = REDUCE;   LRtab_a[st_EA][vs_e].pravidlo1 = Q_EA;
    LRtab_a[st_EA][vs_f].tab_akce = REDUCE;   LRtab_a[st_EA][vs_f].pravidlo1 = Q_EA;
    LRtab_a[st_EA][vs_g].tab_akce = SHIFT;    LRtab_a[st_EA][vs_g].tab_n_stav = st_g;
    LRtab_a[st_EA][vs_h].tab_akce = REDUCE;   LRtab_a[st_EA][vs_h].pravidlo1 = Q_EA;
    LRtab_a[st_EA][vs_end].tab_akce = REDUCE; LRtab_a[st_EA][vs_end].pravidlo1 = Q_EA;
    
    // 57. radek - D9 ----------------------------------------------------------
    LRtab_a[st_D9][vs_a].tab_akce = REDUCE;   LRtab_a[st_D9][vs_a].pravidlo1 = R_D9;
    LRtab_a[st_D9][vs_b].tab_akce = REDUCE;   LRtab_a[st_D9][vs_b].pravidlo1 = R_D9;
    LRtab_a[st_D9][vs_c].tab_akce = REDUCE;   LRtab_a[st_D9][vs_c].pravidlo1 = R_D9;
    LRtab_a[st_D9][vs_d].tab_akce = REDUCE;   LRtab_a[st_D9][vs_d].pravidlo1 = R_D9;
    LRtab_a[st_D9][vs_e].tab_akce = REDUCE;   LRtab_a[st_D9][vs_e].pravidlo1 = R_D9;
    LRtab_a[st_D9][vs_f].tab_akce = REDUCE;   LRtab_a[st_D9][vs_f].pravidlo1 = R_D9;
    LRtab_a[st_D9][vs_g].tab_akce = REDUCE;   LRtab_a[st_D9][vs_g].pravidlo1 = R_D9;
    LRtab_a[st_D9][vs_h].tab_akce = REDUCE;   LRtab_a[st_D9][vs_h].pravidlo1 = R_D9;
    LRtab_a[st_D9][vs_end].tab_akce = REDUCE; LRtab_a[st_D9][vs_end].pravidlo1 = R_D9;
    
    // 58. radek - 8E ----------------------------------------------------------
    LRtab_a[st_8E][vs_a].tab_akce = REDUCE;   LRtab_a[st_8E][vs_a].pravidlo1 = T_8E;
    LRtab_a[st_8E][vs_b].tab_akce = REDUCE;   LRtab_a[st_8E][vs_b].pravidlo1 = T_8E;
    LRtab_a[st_8E][vs_c].tab_akce = REDUCE;   LRtab_a[st_8E][vs_c].pravidlo1 = T_8E;
    LRtab_a[st_8E][vs_d].tab_akce = REDUCE;   LRtab_a[st_8E][vs_d].pravidlo1 = T_8E;
    LRtab_a[st_8E][vs_e].tab_akce = SHIFT;    LRtab_a[st_8E][vs_e].tab_n_stav = st_e;
    LRtab_a[st_8E][vs_f].tab_akce = REDUCE;   LRtab_a[st_8E][vs_f].pravidlo1 = T_8E;
    LRtab_a[st_8E][vs_g].tab_akce = REDUCE;   LRtab_a[st_8E][vs_g].pravidlo1 = T_8E;
    LRtab_a[st_8E][vs_h].tab_akce = REDUCE;   LRtab_a[st_8E][vs_h].pravidlo1 = T_8E;
    LRtab_a[st_8E][vs_end].tab_akce = REDUCE; LRtab_a[st_8E][vs_end].pravidlo1 = T_8E;
    
    // 59. radek - PB ----------------------------------------------------------
    LRtab_a[st_PB][vs_a].tab_akce = REDUCE;   LRtab_a[st_PB][vs_a].pravidlo1 = U_PB;
    LRtab_a[st_PB][vs_b].tab_akce = SHIFT;    LRtab_a[st_PB][vs_b].tab_n_stav = st_b;
    LRtab_a[st_PB][vs_c].tab_akce = REDUCE;   LRtab_a[st_PB][vs_c].pravidlo1 = U_PB;
    LRtab_a[st_PB][vs_d].tab_akce = REDUCE;   LRtab_a[st_PB][vs_d].pravidlo1 = U_PB;
    LRtab_a[st_PB][vs_e].tab_akce = REDUCE;   LRtab_a[st_PB][vs_e].pravidlo1 = U_PB;
    LRtab_a[st_PB][vs_f].tab_akce = REDUCE;   LRtab_a[st_PB][vs_f].pravidlo1 = U_PB;
    LRtab_a[st_PB][vs_g].tab_akce = REDUCE;   LRtab_a[st_PB][vs_g].pravidlo1 = U_PB;
    LRtab_a[st_PB][vs_h].tab_akce = REDUCE;   LRtab_a[st_PB][vs_h].pravidlo1 = U_PB;
    LRtab_a[st_PB][vs_end].tab_akce = REDUCE; LRtab_a[st_PB][vs_end].pravidlo1 = U_PB;
    
    // 60. radek - 12 ----------------------------------------------------------
    LRtab_a[st_12][vs_h].tab_akce = SHIFT;    LRtab_a[st_12][vs_h].tab_n_stav = st_h;
    LRtab_a[st_12][vs_end].tab_akce = REDUCE; LRtab_a[st_12][vs_end].pravidlo1 = S_12;
    
    // 61. radek - 42 ----------------------------------------------------------
    LRtab_a[st_42][vs_end].tab_akce = REDUCE; LRtab_a[st_42][vs_end].pravidlo1 = S_42;
    
    // 62. radek - 46 ----------------------------------------------------------
    LRtab_a[st_46][vs_g].tab_akce = SHIFT;    LRtab_a[st_46][vs_g].tab_n_stav = st_g;
    LRtab_a[st_46][vs_end].tab_akce = REDUCE; LRtab_a[st_46][vs_end].pravidlo1 = S_46;
    
    // 63. radek - 14 ----------------------------------------------------------
    LRtab_a[st_14][vs_e].tab_akce = SHIFT;    LRtab_a[st_14][vs_e].tab_n_stav = st_e;
    
    // 64. radek - 49 ----------------------------------------------------------
    LRtab_a[st_4k][vs_e].tab_akce = SHIFT;    LRtab_a[st_4k][vs_e].tab_n_stav = st_e;
    
    // 65. radek - 48 ----------------------------------------------------------
    LRtab_a[st_48][vs_end].tab_akce = REDUCE; LRtab_a[st_48][vs_end].pravidlo1 = S_48;
    
    // 66. radek - PM ----------------------------------------------------------
    LRtab_a[st_PM][vs_end].tab_akce = REDUCE; LRtab_a[st_PM][vs_end].pravidlo1 = S_PM;
    
    // 67. radek - 13 ----------------------------------------------------------
    LRtab_a[st_13][vs_c].tab_akce = SHIFT;    LRtab_a[st_13][vs_c].tab_n_stav = st_c;
    LRtab_a[st_13][vs_d].tab_akce = SHIFT;    LRtab_a[st_13][vs_d].tab_n_stav = st_d;
    LRtab_a[st_13][vs_h].tab_akce = SHIFT;    LRtab_a[st_13][vs_h].tab_n_stav = st_h;
    LRtab_a[st_13][vs_end].tab_akce = REDUCE; LRtab_a[st_13][vs_end].pravidlo1 = S_13;    
    
    // 68. radek - XY ----------------------------------------------------------
    LRtab_a[st_XY][vs_end].tab_akce = REDUCE; LRtab_a[st_XY][vs_end].pravidlo1 = S_XY;
    
    // 69. radek - 47 ----------------------------------------------------------
    LRtab_a[st_47][vs_g].tab_akce = SHIFT;    LRtab_a[st_47][vs_g].tab_n_stav = st_g;
    LRtab_a[st_47][vs_end].tab_akce = REDUCE; LRtab_a[st_47][vs_end].pravidlo1 = S_47;
    
    // 70. radek - 4M ----------------------------------------------------------
    LRtab_a[st_4M][vs_end].tab_akce = REDUCE; LRtab_a[st_4M][vs_end].pravidlo1 = S_4M;
    
    // 71. radek - P8 ----------------------------------------------------------
    LRtab_a[st_P8][vs_end].tab_akce = REDUCE; LRtab_a[st_P8][vs_end].pravidlo1 = S_P8;
    
    // 72. radek - P2 ----------------------------------------------------------
    LRtab_a[st_U2][vs_end].tab_akce = REDUCE; LRtab_a[st_U2][vs_end].pravidlo1 = S_U2;
    
    // 73. radek - UV ----------------------------------------------------------
    LRtab_a[st_UV][vs_a].tab_akce = SHIFT;    LRtab_a[st_UV][vs_a].tab_n_stav = st_a;
    
    // 74. radek - 1J ----------------------------------------------------------
    LRtab_a[st_1J][vs_c].tab_akce = SHIFT;    LRtab_a[st_1J][vs_c].tab_n_stav = st_c;
    LRtab_a[st_1J][vs_h].tab_akce = SHIFT;    LRtab_a[st_1J][vs_h].tab_n_stav = st_h;
    
    // 75. radek - 15 ----------------------------------------------------------
    LRtab_a[st_15][vs_c].tab_akce = SHIFT;    LRtab_a[st_15][vs_c].tab_n_stav = st_c;
    
    // 76. radek - 4* ----------------------------------------------------------
    LRtab_a[st_4h][vs_e].tab_akce = SHIFT;    LRtab_a[st_4h][vs_e].tab_n_stav = st_e;
    
    // 77. radek - RT ----------------------------------------------------------
    LRtab_a[st_9T][vs_end].tab_akce = REDUCE; LRtab_a[st_9T][vs_end].pravidlo1 = S_9T;
    
    // 78. radek - PJ ----------------------------------------------------------
    LRtab_a[st_PJ][vs_e].tab_akce = SHIFT;    LRtab_a[st_PJ][vs_e].tab_n_stav = st_e;
    
    // 79. radek - DFB ---------------------------------------------------------
    LRtab_a[st_DFB][vs_a].tab_akce = REDUCE;   LRtab_a[st_DFB][vs_a].pravidlo1 = j_DFB;
    LRtab_a[st_DFB][vs_a].poc_pravidel = 2;    LRtab_a[st_DFB][vs_a].pravidlo2 = P_DFB;
    LRtab_a[st_DFB][vs_b].tab_akce = SHIFT;    LRtab_a[st_DFB][vs_b].tab_n_stav = st_b;
    LRtab_a[st_DFB][vs_c].tab_akce = REDUCE;   LRtab_a[st_DFB][vs_c].pravidlo1 = j_DFB;
    LRtab_a[st_DFB][vs_c].poc_pravidel = 2;    LRtab_a[st_DFB][vs_c].pravidlo2 = P_DFB;
    LRtab_a[st_DFB][vs_d].tab_akce = REDUCE;   LRtab_a[st_DFB][vs_d].pravidlo1 = j_DFB;
    LRtab_a[st_DFB][vs_c].poc_pravidel = 2;    LRtab_a[st_DFB][vs_d].pravidlo2 = P_DFB;
    LRtab_a[st_DFB][vs_e].tab_akce = REDUCE;   LRtab_a[st_DFB][vs_e].pravidlo1 = j_DFB;
    LRtab_a[st_DFB][vs_e].poc_pravidel = 2;    LRtab_a[st_DFB][vs_e].pravidlo2 = P_DFB;
    LRtab_a[st_DFB][vs_f].tab_akce = REDUCE;   LRtab_a[st_DFB][vs_f].pravidlo1 = j_DFB;
    LRtab_a[st_DFB][vs_f].poc_pravidel = 2;    LRtab_a[st_DFB][vs_f].pravidlo2 = P_DFB;
    LRtab_a[st_DFB][vs_g].tab_akce = REDUCE;   LRtab_a[st_DFB][vs_g].pravidlo1 = j_DFB;
    LRtab_a[st_DFB][vs_g].poc_pravidel = 2;    LRtab_a[st_DFB][vs_g].pravidlo2 = P_DFB;
    LRtab_a[st_DFB][vs_h].konflikt = true;
    LRtab_a[st_DFB][vs_h].tab_akce = SHIFT;    LRtab_a[st_DFB][vs_h].tab_n_stav = st_h;
    LRtab_a[st_DFB][vs_h].poc_pravidel = 2;    LRtab_a[st_DFB][vs_h].pravidlo2 = P_DFB;
    LRtab_a[st_DFB][vs_h].pravidlo1 = j_DFB;
    LRtab_a[st_DFB][vs_end].tab_akce = REDUCE; LRtab_a[st_DFB][vs_end].pravidlo1 = j_DFB;
    LRtab_a[st_DFB][vs_end].poc_pravidel = 2;  LRtab_a[st_DFB][vs_end].pravidlo2 = P_DFB;
    
    // 80. radek - DHB ---------------------------------------------------------
    LRtab_a[st_DHB][vs_a].tab_akce = REDUCE;   LRtab_a[st_DHB][vs_a].pravidlo1 = j_DHB;
    LRtab_a[st_DHB][vs_a].poc_pravidel = 2;    LRtab_a[st_DHB][vs_a].pravidlo2 = c_DHB;
    LRtab_a[st_DHB][vs_b].tab_akce = SHIFT;    LRtab_a[st_DHB][vs_b].tab_n_stav = st_b;
    LRtab_a[st_DHB][vs_c].tab_akce = REDUCE;   LRtab_a[st_DHB][vs_c].pravidlo1 = j_DHB;
    LRtab_a[st_DHB][vs_c].poc_pravidel = 2;    LRtab_a[st_DHB][vs_c].pravidlo2 = c_DHB;
    LRtab_a[st_DHB][vs_d].tab_akce = REDUCE;   LRtab_a[st_DHB][vs_d].pravidlo1 = j_DHB;
    LRtab_a[st_DHB][vs_d].poc_pravidel = 2;    LRtab_a[st_DHB][vs_d].pravidlo2 = c_DHB;
    LRtab_a[st_DHB][vs_e].tab_akce = REDUCE;   LRtab_a[st_DHB][vs_e].pravidlo1 = j_DHB;
    LRtab_a[st_DHB][vs_e].poc_pravidel = 2;    LRtab_a[st_DHB][vs_e].pravidlo2 = c_DHB;
    LRtab_a[st_DHB][vs_f].tab_akce = REDUCE;   LRtab_a[st_DHB][vs_f].pravidlo1 = j_DHB;
    LRtab_a[st_DHB][vs_f].poc_pravidel = 2;    LRtab_a[st_DHB][vs_f].pravidlo2 = c_DHB;
    LRtab_a[st_DHB][vs_g].tab_akce = REDUCE;   LRtab_a[st_DHB][vs_g].pravidlo1 = j_DHB;
    LRtab_a[st_DHB][vs_g].poc_pravidel = 2;    LRtab_a[st_DHB][vs_g].pravidlo2 = c_DHB;
    LRtab_a[st_DHB][vs_h].tab_akce = REDUCE;   LRtab_a[st_DHB][vs_h].pravidlo1 = j_DHB;
    LRtab_a[st_DHB][vs_h].poc_pravidel = 2;    LRtab_a[st_DHB][vs_h].pravidlo2 = c_DHB;
    LRtab_a[st_DHB][vs_end].tab_akce = REDUCE; LRtab_a[st_DHB][vs_end].pravidlo1 = j_DHB;
    LRtab_a[st_DHB][vs_end].poc_pravidel = 2;  LRtab_a[st_DHB][vs_end].pravidlo2 = c_DHB;
    
    // 81. radek - HCE ---------------------------------------------------------
    LRtab_a[st_HCE][vs_a].konflikt = true;     LRtab_a[st_HCE][vs_a].poc_pravidel = 3;
    LRtab_a[st_HCE][vs_a].tab_akce = SHIFT;    LRtab_a[st_HCE][vs_a].tab_n_stav = st_a;
    LRtab_a[st_HCE][vs_a].pravidlo1 = d_HCE;   LRtab_a[st_HCE][vs_a].pravidlo2 = V_HCE;
    LRtab_a[st_HCE][vs_a].pravidlo3 = x_HCE;    
    LRtab_a[st_HCE][vs_b].tab_akce = REDUCE;   LRtab_a[st_HCE][vs_b].pravidlo1 = d_HCE;
    LRtab_a[st_HCE][vs_b].poc_pravidel = 3;    LRtab_a[st_HCE][vs_b].pravidlo2 = V_HCE;
    LRtab_a[st_HCE][vs_b].pravidlo3 = x_HCE;
    LRtab_a[st_HCE][vs_c].tab_akce = REDUCE;   LRtab_a[st_HCE][vs_c].pravidlo1 = d_HCE;
    LRtab_a[st_HCE][vs_c].poc_pravidel = 3;    LRtab_a[st_HCE][vs_c].pravidlo2 = V_HCE;
    LRtab_a[st_HCE][vs_c].pravidlo3 = x_HCE;
    LRtab_a[st_HCE][vs_d].tab_akce = REDUCE;   LRtab_a[st_HCE][vs_d].pravidlo1 = d_HCE;
    LRtab_a[st_HCE][vs_d].poc_pravidel = 3;    LRtab_a[st_HCE][vs_d].pravidlo2 = V_HCE;
    LRtab_a[st_HCE][vs_d].pravidlo3 = x_HCE;
    LRtab_a[st_HCE][vs_e].tab_akce = SHIFT;    LRtab_a[st_HCE][vs_e].tab_n_stav = st_e;
    LRtab_a[st_HCE][vs_f].tab_akce = REDUCE;   LRtab_a[st_HCE][vs_f].pravidlo1 = d_HCE;
    LRtab_a[st_HCE][vs_f].poc_pravidel = 3;    LRtab_a[st_HCE][vs_f].pravidlo2 = V_HCE;
    LRtab_a[st_HCE][vs_f].pravidlo3 = x_HCE;    
    LRtab_a[st_HCE][vs_g].tab_akce = REDUCE;   LRtab_a[st_HCE][vs_g].pravidlo1 = d_HCE;
    LRtab_a[st_HCE][vs_g].poc_pravidel = 3;    LRtab_a[st_HCE][vs_g].pravidlo2 = V_HCE;
    LRtab_a[st_HCE][vs_g].pravidlo3 = x_HCE;
    LRtab_a[st_HCE][vs_h].tab_akce = REDUCE;   LRtab_a[st_HCE][vs_h].pravidlo1 = d_HCE;
    LRtab_a[st_HCE][vs_h].poc_pravidel = 3;    LRtab_a[st_HCE][vs_h].pravidlo2 = V_HCE;
    LRtab_a[st_HCE][vs_h].pravidlo3 = x_HCE;
    LRtab_a[st_HCE][vs_end].tab_akce = REDUCE; LRtab_a[st_HCE][vs_end].pravidlo1 = d_HCE;
    LRtab_a[st_HCE][vs_end].poc_pravidel = 3;  LRtab_a[st_HCE][vs_end].pravidlo2 = V_HCE;
    LRtab_a[st_HCE][vs_end].pravidlo3 = x_HCE;
    
    // 82. radek - HCA ---------------------------------------------------------
    LRtab_a[st_HCA][vs_a].tab_akce = SHIFT;    LRtab_a[st_HCA][vs_a].tab_n_stav = st_a;
    LRtab_a[st_HCA][vs_b].tab_akce = REDUCE;   LRtab_a[st_HCA][vs_b].pravidlo1 = t_HCA;
    LRtab_a[st_HCA][vs_b].poc_pravidel = 2;    LRtab_a[st_HCA][vs_b].pravidlo2 = p_HCA;
    LRtab_a[st_HCA][vs_c].tab_akce = REDUCE;   LRtab_a[st_HCA][vs_c].pravidlo1 = t_HCA;
    LRtab_a[st_HCA][vs_c].poc_pravidel = 2;    LRtab_a[st_HCA][vs_c].pravidlo2 = p_HCA;
    LRtab_a[st_HCA][vs_d].tab_akce = REDUCE;   LRtab_a[st_HCA][vs_d].pravidlo1 = t_HCA;
    LRtab_a[st_HCA][vs_d].poc_pravidel = 2;    LRtab_a[st_HCA][vs_d].pravidlo2 = p_HCA;
    LRtab_a[st_HCA][vs_e].tab_akce = REDUCE;   LRtab_a[st_HCA][vs_e].pravidlo1 = t_HCA;
    LRtab_a[st_HCA][vs_e].poc_pravidel = 2;    LRtab_a[st_HCA][vs_e].pravidlo2 = p_HCA;
    LRtab_a[st_HCA][vs_f].tab_akce = REDUCE;   LRtab_a[st_HCA][vs_f].pravidlo1 = t_HCA;
    LRtab_a[st_HCA][vs_f].poc_pravidel = 2;    LRtab_a[st_HCA][vs_f].pravidlo2 = p_HCA;    
    LRtab_a[st_HCA][vs_g].tab_akce = REDUCE;   LRtab_a[st_HCA][vs_g].pravidlo1 = t_HCA;
    LRtab_a[st_HCA][vs_g].poc_pravidel = 2;    LRtab_a[st_HCA][vs_g].pravidlo2 = p_HCA;
    LRtab_a[st_HCA][vs_h].tab_akce = REDUCE;   LRtab_a[st_HCA][vs_h].pravidlo1 = t_HCA;
    LRtab_a[st_HCA][vs_h].poc_pravidel = 2;    LRtab_a[st_HCA][vs_h].pravidlo2 = p_HCA;
    LRtab_a[st_HCA][vs_end].tab_akce = REDUCE; LRtab_a[st_HCA][vs_end].pravidlo1 = t_HCA;
    LRtab_a[st_HCA][vs_end].poc_pravidel = 2;  LRtab_a[st_HCA][vs_end].pravidlo2 = p_HCA;
    
    // 83. radek - CEA ---------------------------------------------------------
    LRtab_a[st_CEA][vs_a].tab_akce = SHIFT;    LRtab_a[st_CEA][vs_a].tab_n_stav = st_a;
    LRtab_a[st_CEA][vs_b].tab_akce = REDUCE;   LRtab_a[st_CEA][vs_b].pravidlo1 = t_CEA;
    LRtab_a[st_CEA][vs_b].poc_pravidel = 2;    LRtab_a[st_CEA][vs_b].pravidlo2 = s_CEA;
    LRtab_a[st_CEA][vs_c].tab_akce = REDUCE;   LRtab_a[st_CEA][vs_c].pravidlo1 = t_CEA;
    LRtab_a[st_CEA][vs_c].poc_pravidel = 2;    LRtab_a[st_CEA][vs_c].pravidlo2 = s_CEA;
    LRtab_a[st_CEA][vs_d].tab_akce = REDUCE;   LRtab_a[st_CEA][vs_d].pravidlo1 = t_CEA;
    LRtab_a[st_CEA][vs_d].poc_pravidel = 2;    LRtab_a[st_CEA][vs_d].pravidlo2 = s_CEA;
    LRtab_a[st_CEA][vs_e].tab_akce = REDUCE;   LRtab_a[st_CEA][vs_e].pravidlo1 = t_CEA;
    LRtab_a[st_CEA][vs_e].poc_pravidel = 2;    LRtab_a[st_CEA][vs_e].pravidlo2 = s_CEA;
    LRtab_a[st_CEA][vs_f].tab_akce = REDUCE;   LRtab_a[st_CEA][vs_f].pravidlo1 = t_CEA;
    LRtab_a[st_CEA][vs_f].poc_pravidel = 2;    LRtab_a[st_CEA][vs_f].pravidlo2 = s_CEA;
    LRtab_a[st_CEA][vs_g].konflikt = true;     LRtab_a[st_CEA][vs_g].poc_pravidel = 2;
    LRtab_a[st_CEA][vs_g].tab_akce = SHIFT;    LRtab_a[st_CEA][vs_g].tab_n_stav = st_g;
    LRtab_a[st_CEA][vs_g].pravidlo1 = t_CEA;   LRtab_a[st_CEA][vs_g].pravidlo2 = s_CEA;
    LRtab_a[st_CEA][vs_h].tab_akce = REDUCE;   LRtab_a[st_CEA][vs_h].pravidlo1 = t_CEA;
    LRtab_a[st_CEA][vs_h].poc_pravidel = 2;    LRtab_a[st_CEA][vs_h].pravidlo2 = s_CEA;
    LRtab_a[st_CEA][vs_end].tab_akce = REDUCE; LRtab_a[st_CEA][vs_end].pravidlo1 = t_CEA;
    LRtab_a[st_CEA][vs_end].poc_pravidel = 2;  LRtab_a[st_CEA][vs_end].pravidlo2 = s_CEA;
    
    // 84. radek - DBH --------------------------------------------------------- 
    LRtab_a[st_DBH][vs_a].tab_akce = REDUCE;   LRtab_a[st_DBH][vs_a].pravidlo1 = c_DBH;
    LRtab_a[st_DBH][vs_b].tab_akce = REDUCE;   LRtab_a[st_DBH][vs_b].pravidlo1 = c_DBH;
    LRtab_a[st_DBH][vs_c].tab_akce = REDUCE;   LRtab_a[st_DBH][vs_c].pravidlo1 = c_DBH;
    LRtab_a[st_DBH][vs_d].tab_akce = REDUCE;   LRtab_a[st_DBH][vs_d].pravidlo1 = c_DBH;
    LRtab_a[st_DBH][vs_e].tab_akce = REDUCE;   LRtab_a[st_DBH][vs_e].pravidlo1 = c_DBH;
    LRtab_a[st_DBH][vs_f].tab_akce = REDUCE;   LRtab_a[st_DBH][vs_f].pravidlo1 = c_DBH;
    LRtab_a[st_DBH][vs_g].tab_akce = REDUCE;   LRtab_a[st_DBH][vs_g].pravidlo1 = c_DBH;
    LRtab_a[st_DBH][vs_h].tab_akce = SHIFT;    LRtab_a[st_DBH][vs_h].tab_n_stav = st_h;
    LRtab_a[st_DBH][vs_end].tab_akce = REDUCE; LRtab_a[st_DBH][vs_end].pravidlo1 = c_DBH;
    
    // 85. radek - DFH ---------------------------------------------------------
    LRtab_a[st_DFH][vs_a].tab_akce = REDUCE;   LRtab_a[st_DFH][vs_a].pravidlo1 = c_DFH;
    LRtab_a[st_DFH][vs_a].poc_pravidel = 2;    LRtab_a[st_DFH][vs_a].pravidlo2 = dd_DFH;        
    LRtab_a[st_DFH][vs_b].tab_akce = REDUCE;   LRtab_a[st_DFH][vs_b].pravidlo1 = c_DFH;
    LRtab_a[st_DFH][vs_b].poc_pravidel = 2;    LRtab_a[st_DFH][vs_b].pravidlo2 = dd_DFH;    
    LRtab_a[st_DFH][vs_c].tab_akce = REDUCE;   LRtab_a[st_DFH][vs_c].pravidlo1 = c_DFH;
    LRtab_a[st_DFH][vs_c].poc_pravidel = 2;    LRtab_a[st_DFH][vs_c].pravidlo2 = dd_DFH;    
    LRtab_a[st_DFH][vs_d].tab_akce = REDUCE;   LRtab_a[st_DFH][vs_d].pravidlo1 = c_DFH;
    LRtab_a[st_DFH][vs_d].poc_pravidel = 2;    LRtab_a[st_DFH][vs_d].pravidlo2 = dd_DFH;    
    LRtab_a[st_DFH][vs_e].tab_akce = REDUCE;   LRtab_a[st_DFH][vs_e].pravidlo1 = c_DFH;
    LRtab_a[st_DFH][vs_e].poc_pravidel = 2;    LRtab_a[st_DFH][vs_e].pravidlo2 = dd_DFH;    
    LRtab_a[st_DFH][vs_f].tab_akce = REDUCE;   LRtab_a[st_DFH][vs_f].pravidlo1 = c_DFH;
    LRtab_a[st_DFH][vs_f].poc_pravidel = 2;    LRtab_a[st_DFH][vs_f].pravidlo2 = dd_DFH;    
    LRtab_a[st_DFH][vs_g].tab_akce = REDUCE;   LRtab_a[st_DFH][vs_g].pravidlo1 = c_DFH;
    LRtab_a[st_DFH][vs_g].poc_pravidel = 2;    LRtab_a[st_DFH][vs_g].pravidlo2 = dd_DFH;    
    LRtab_a[st_DFH][vs_h].tab_akce = SHIFT;    LRtab_a[st_DFH][vs_h].tab_n_stav = st_h;
    LRtab_a[st_DFH][vs_end].tab_akce = REDUCE; LRtab_a[st_DFH][vs_end].pravidlo1 = c_DFH;
    LRtab_a[st_DFH][vs_end].poc_pravidel = 2;  LRtab_a[st_DFH][vs_end].pravidlo2 = dd_DFH;
    
    // 86. radek - CEG ---------------------------------------------------------
    LRtab_a[st_CEG][vs_a].tab_akce = REDUCE;   LRtab_a[st_CEG][vs_a].pravidlo1 = o_CEG;
    LRtab_a[st_CEG][vs_b].tab_akce = REDUCE;   LRtab_a[st_CEG][vs_b].pravidlo1 = o_CEG;
    LRtab_a[st_CEG][vs_c].tab_akce = REDUCE;   LRtab_a[st_CEG][vs_c].pravidlo1 = o_CEG;
    LRtab_a[st_CEG][vs_d].tab_akce = REDUCE;   LRtab_a[st_CEG][vs_d].pravidlo1 = o_CEG;
    LRtab_a[st_CEG][vs_e].tab_akce = REDUCE;   LRtab_a[st_CEG][vs_e].pravidlo1 = o_CEG;
    LRtab_a[st_CEG][vs_f].tab_akce = REDUCE;   LRtab_a[st_CEG][vs_f].pravidlo1 = o_CEG;
    LRtab_a[st_CEG][vs_g].tab_akce = SHIFT;    LRtab_a[st_CEG][vs_g].tab_n_stav = st_g;
    LRtab_a[st_CEG][vs_h].tab_akce = REDUCE;   LRtab_a[st_CEG][vs_h].pravidlo1 = o_CEG;
    LRtab_a[st_CEG][vs_end].tab_akce = REDUCE; LRtab_a[st_CEG][vs_end].pravidlo1 = o_CEG;
    
    // 87. radek - CAG ---------------------------------------------------------
    LRtab_a[st_CAG][vs_a].tab_akce = REDUCE;   LRtab_a[st_CAG][vs_a].pravidlo1 = o_CAG;
    LRtab_a[st_CAG][vs_b].tab_akce = REDUCE;   LRtab_a[st_CAG][vs_b].pravidlo1 = o_CAG;
    LRtab_a[st_CAG][vs_c].tab_akce = REDUCE;   LRtab_a[st_CAG][vs_c].pravidlo1 = o_CAG;
    LRtab_a[st_CAG][vs_d].tab_akce = REDUCE;   LRtab_a[st_CAG][vs_d].pravidlo1 = o_CAG;
    LRtab_a[st_CAG][vs_e].tab_akce = REDUCE;   LRtab_a[st_CAG][vs_e].pravidlo1 = o_CAG;
    LRtab_a[st_CAG][vs_f].tab_akce = REDUCE;   LRtab_a[st_CAG][vs_f].pravidlo1 = o_CAG;
    LRtab_a[st_CAG][vs_g].tab_akce = SHIFT;    LRtab_a[st_CAG][vs_g].tab_n_stav = st_g;
    LRtab_a[st_CAG][vs_h].tab_akce = REDUCE;   LRtab_a[st_CAG][vs_h].pravidlo1 = o_CAG;
    LRtab_a[st_CAG][vs_end].tab_akce = REDUCE; LRtab_a[st_CAG][vs_end].pravidlo1 = o_CAG;
    
    // 88. radek - FBH ---------------------------------------------------------
    LRtab_a[st_FBH][vs_a].tab_akce = REDUCE;    LRtab_a[st_FBH][vs_a].pravidlo1 = k_FBH;
    LRtab_a[st_FBH][vs_b].tab_akce = REDUCE;    LRtab_a[st_FBH][vs_b].pravidlo1 = k_FBH;
    LRtab_a[st_FBH][vs_c].tab_akce = SHIFT;     LRtab_a[st_FBH][vs_c].tab_n_stav = st_c;
    LRtab_a[st_FBH][vs_d].tab_akce = REDUCE;    LRtab_a[st_FBH][vs_d].pravidlo1 = k_FBH;
    LRtab_a[st_FBH][vs_e].tab_akce = REDUCE;    LRtab_a[st_FBH][vs_e].pravidlo1 = k_FBH;
    LRtab_a[st_FBH][vs_f].tab_akce = REDUCE;    LRtab_a[st_FBH][vs_f].pravidlo1 = k_FBH;
    LRtab_a[st_FBH][vs_e].tab_akce = REDUCE;    LRtab_a[st_FBH][vs_g].pravidlo1 = k_FBH;
    LRtab_a[st_FBH][vs_h].tab_akce = SHIFT;     LRtab_a[st_FBH][vs_h].tab_n_stav = st_h;
    LRtab_a[st_FBH][vs_end].tab_akce = REDUCE;  LRtab_a[st_FBH][vs_end].pravidlo1 = k_FBH;
    
    // 89. radek - FBC ---------------------------------------------------------
    LRtab_a[st_FBC][vs_a].tab_akce = REDUCE;   LRtab_a[st_FBC][vs_a].pravidlo1 = h_FBC;
    LRtab_a[st_FBC][vs_b].tab_akce = REDUCE;   LRtab_a[st_FBC][vs_b].pravidlo1 = h_FBC;
    LRtab_a[st_FBC][vs_c].tab_akce = SHIFT;    LRtab_a[st_FBC][vs_c].tab_n_stav = st_c;
    LRtab_a[st_FBC][vs_d].tab_akce = REDUCE;   LRtab_a[st_FBC][vs_d].pravidlo1 = h_FBC;
    LRtab_a[st_FBC][vs_e].tab_akce = REDUCE;   LRtab_a[st_FBC][vs_e].pravidlo1 = h_FBC;
    LRtab_a[st_FBC][vs_f].tab_akce = REDUCE;   LRtab_a[st_FBC][vs_f].pravidlo1 = h_FBC;
    LRtab_a[st_FBC][vs_g].tab_akce = REDUCE;   LRtab_a[st_FBC][vs_g].pravidlo1 = h_FBC;
    LRtab_a[st_FBC][vs_h].tab_akce = REDUCE;   LRtab_a[st_FBC][vs_h].pravidlo1 = h_FBC;
    LRtab_a[st_FBC][vs_end].tab_akce = REDUCE; LRtab_a[st_FBC][vs_end].pravidlo1 = h_FBC;
    
    // 90. radek - FHC ---------------------------------------------------------
    LRtab_a[st_FHC][vs_a].tab_akce = REDUCE;   LRtab_a[st_FHC][vs_a].pravidlo1 = h_FHC;
    LRtab_a[st_FHC][vs_b].tab_akce = REDUCE;   LRtab_a[st_FHC][vs_b].pravidlo1 = h_FHC;
    LRtab_a[st_FHC][vs_c].tab_akce = SHIFT;    LRtab_a[st_FHC][vs_c].tab_n_stav = st_c;
    LRtab_a[st_FHC][vs_d].tab_akce = REDUCE;   LRtab_a[st_FHC][vs_d].pravidlo1 = h_FHC;
    LRtab_a[st_FHC][vs_e].tab_akce = REDUCE;   LRtab_a[st_FHC][vs_e].pravidlo1 = h_FHC;
    LRtab_a[st_FHC][vs_f].tab_akce = REDUCE;   LRtab_a[st_FHC][vs_f].pravidlo1 = h_FHC;
    LRtab_a[st_FHC][vs_g].tab_akce = REDUCE;   LRtab_a[st_FHC][vs_g].pravidlo1 = h_FHC;
    LRtab_a[st_FHC][vs_h].tab_akce = REDUCE;   LRtab_a[st_FHC][vs_h].pravidlo1 = h_FHC;
    LRtab_a[st_FHC][vs_end].tab_akce = REDUCE; LRtab_a[st_FHC][vs_end].pravidlo1 = h_FHC;
    
    // 91. radek - HEG ---------------------------------------------------------
    LRtab_a[st_HEG][vs_e].tab_akce = SHIFT;    LRtab_a[st_HEG][vs_e].tab_n_stav = st_e;
    LRtab_a[st_HEG][vs_g].tab_akce = SHIFT;    LRtab_a[st_HEG][vs_g].tab_n_stav = st_g;
    
    // 92. radek - EDA ---------------------------------------------------------
    LRtab_a[st_ZA][vs_a].tab_akce = SHIFT;    LRtab_a[st_ZA][vs_a].tab_n_stav = st_a;
    LRtab_a[st_ZA][vs_b].tab_akce = REDUCE;   LRtab_a[st_ZA][vs_b].pravidlo1 = L_ZA;
    LRtab_a[st_ZA][vs_c].tab_akce = REDUCE;   LRtab_a[st_ZA][vs_c].pravidlo1 = L_ZA;
    LRtab_a[st_ZA][vs_d].tab_akce = REDUCE;   LRtab_a[st_ZA][vs_d].pravidlo1 = L_ZA;
    LRtab_a[st_ZA][vs_e].tab_akce = REDUCE;   LRtab_a[st_ZA][vs_e].pravidlo1 = L_ZA;
    LRtab_a[st_ZA][vs_f].tab_akce = REDUCE;   LRtab_a[st_ZA][vs_f].pravidlo1 = L_ZA;
    LRtab_a[st_ZA][vs_g].tab_akce = REDUCE;   LRtab_a[st_ZA][vs_g].pravidlo1 = L_ZA;
    LRtab_a[st_ZA][vs_h].tab_akce = REDUCE;   LRtab_a[st_ZA][vs_h].pravidlo1 = L_ZA;
    LRtab_a[st_ZA][vs_end].tab_akce = REDUCE; LRtab_a[st_ZA][vs_end].pravidlo1 = L_ZA;
    
    // 93. radek - EHA ---------------------------------------------------------
    LRtab_a[st_EHA][vs_a].tab_akce = SHIFT;    LRtab_a[st_EHA][vs_a].tab_n_stav = st_a;
    LRtab_a[st_EHA][vs_b].tab_akce = REDUCE;   LRtab_a[st_EHA][vs_b].pravidlo1 = N_EHA;
    LRtab_a[st_EHA][vs_c].tab_akce = REDUCE;   LRtab_a[st_EHA][vs_c].pravidlo1 = N_EHA;
    LRtab_a[st_EHA][vs_d].tab_akce = REDUCE;   LRtab_a[st_EHA][vs_d].pravidlo1 = N_EHA;
    LRtab_a[st_EHA][vs_e].tab_akce = REDUCE;   LRtab_a[st_EHA][vs_e].pravidlo1 = N_EHA;
    LRtab_a[st_EHA][vs_f].tab_akce = REDUCE;   LRtab_a[st_EHA][vs_f].pravidlo1 = N_EHA;
    LRtab_a[st_EHA][vs_g].tab_akce = REDUCE;   LRtab_a[st_EHA][vs_g].pravidlo1 = N_EHA;
    LRtab_a[st_EHA][vs_h].tab_akce = REDUCE;   LRtab_a[st_EHA][vs_h].pravidlo1 = N_EHA;
    LRtab_a[st_EHA][vs_end].tab_akce = REDUCE; LRtab_a[st_EHA][vs_end].pravidlo1 = N_EHA;
    
    // 94. radek - 11J ---------------------------------------------------------
    LRtab_a[st_11J][vs_a].tab_akce = REDUCE;   LRtab_a[st_11J][vs_a].pravidlo1 = X_11J;
    LRtab_a[st_11J][vs_b].tab_akce = REDUCE;   LRtab_a[st_11J][vs_b].pravidlo1 = X_11J;
    LRtab_a[st_11J][vs_c].tab_akce = REDUCE;   LRtab_a[st_11J][vs_c].pravidlo1 = X_11J;
    LRtab_a[st_11J][vs_d].tab_akce = REDUCE;   LRtab_a[st_11J][vs_d].pravidlo1 = X_11J;
    LRtab_a[st_11J][vs_e].tab_akce = REDUCE;   LRtab_a[st_11J][vs_e].pravidlo1 = X_11J;
    LRtab_a[st_11J][vs_f].tab_akce = REDUCE;   LRtab_a[st_11J][vs_f].pravidlo1 = X_11J;
    LRtab_a[st_11J][vs_g].tab_akce = REDUCE;   LRtab_a[st_11J][vs_g].pravidlo1 = X_11J;
    LRtab_a[st_11J][vs_h].tab_akce = REDUCE;   LRtab_a[st_11J][vs_h].pravidlo1 = X_11J;
    LRtab_a[st_11J][vs_end].tab_akce = REDUCE; LRtab_a[st_11J][vs_end].pravidlo1 = X_11J;
    
    // 95. radek - 33K ---------------------------------------------------------
    LRtab_a[st_33K][vs_a].tab_akce = REDUCE;   LRtab_a[st_33K][vs_a].pravidlo1 = Y_33K;
    LRtab_a[st_33K][vs_b].tab_akce = REDUCE;   LRtab_a[st_33K][vs_b].pravidlo1 = Y_33K;
    LRtab_a[st_33K][vs_c].tab_akce = REDUCE;   LRtab_a[st_33K][vs_c].pravidlo1 = Y_33K;
    LRtab_a[st_33K][vs_d].tab_akce = REDUCE;   LRtab_a[st_33K][vs_d].pravidlo1 = Y_33K;
    LRtab_a[st_33K][vs_e].tab_akce = REDUCE;   LRtab_a[st_33K][vs_e].pravidlo1 = Y_33K;
    LRtab_a[st_33K][vs_f].tab_akce = REDUCE;   LRtab_a[st_33K][vs_f].pravidlo1 = Y_33K;
    LRtab_a[st_33K][vs_g].tab_akce = REDUCE;   LRtab_a[st_33K][vs_g].pravidlo1 = Y_33K;
    LRtab_a[st_33K][vs_h].tab_akce = REDUCE;   LRtab_a[st_33K][vs_h].pravidlo1 = Y_33K;
    LRtab_a[st_33K][vs_end].tab_akce = REDUCE; LRtab_a[st_33K][vs_end].pravidlo1 = Y_33K;
    
    // 96. radek - 12I ---------------------------------------------------------
    LRtab_a[st_12I][vs_end].tab_akce = REDUCE; LRtab_a[st_12I][vs_end].pravidlo1 = S_12I;
    
    // 97. radek - 14L ---------------------------------------------------------
    LRtab_a[st_14L][vs_end].tab_akce = REDUCE; LRtab_a[st_14L][vs_end].pravidlo1 = S_14L;
    
    // 98. radek - 49N ---------------------------------------------------------
    LRtab_a[st_4kN][vs_end].tab_akce = REDUCE; LRtab_a[st_4kN][vs_end].pravidlo1 = S_4kN;
    
    // 99. radek - UVW ---------------------------------------------------------
    LRtab_a[st_UVW][vs_end].tab_akce = REDUCE; LRtab_a[st_UVW][vs_end].pravidlo1 = S_UVW;
    
    // 100. radek - 133 ---------------------------------------------------------
    LRtab_a[st_133][vs_end].tab_akce = REDUCE; LRtab_a[st_133][vs_end].pravidlo1 = S_133;
    
    // 101. radek - 1J3 --------------------------------------------------------
    LRtab_a[st_1J3][vs_end].tab_akce = REDUCE; LRtab_a[st_1J3][vs_end].pravidlo1 = S_1J3;
    
    // 102. radek - 13K --------------------------------------------------------
    LRtab_a[st_13K][vs_end].tab_akce = REDUCE; LRtab_a[st_13K][vs_end].pravidlo1 = S_13K;
    
    // 103. radek - 113 --------------------------------------------------------
    LRtab_a[st_113][vs_end].tab_akce = REDUCE; LRtab_a[st_113][vs_end].pravidlo1 = S_113;
    
    // 104. radek - 158 --------------------------------------------------------
    LRtab_a[st_158][vs_end].tab_akce = REDUCE; LRtab_a[st_158][vs_end].pravidlo1 = S_158;
    
    // 105. radek - 4*O --------------------------------------------------------
    LRtab_a[st_4hO][vs_end].tab_akce = REDUCE; LRtab_a[st_4hO][vs_end].pravidlo1 = S_4hO;
    
    // 106. radek - PJQ --------------------------------------------------------
    LRtab_a[st_PJQ][vs_end].tab_akce = REDUCE; LRtab_a[st_PJQ][vs_end].pravidlo1 = S_PJQ;
    
    // 107. radek - HCEA -------------------------------------------------------
    LRtab_a[st_HCEA][vs_a].tab_akce = SHIFT;    LRtab_a[st_HCEA][vs_a].tab_n_stav = st_a;
    LRtab_a[st_HCEA][vs_b].tab_akce = REDUCE;   LRtab_a[st_HCEA][vs_b].pravidlo1 = t_HCEA;
    LRtab_a[st_HCEA][vs_b].poc_pravidel = 3;    LRtab_a[st_HCEA][vs_b].pravidlo2 = p_HCEA;
    LRtab_a[st_HCEA][vs_b].pravidlo3 = x_HCEA;
    LRtab_a[st_HCEA][vs_c].tab_akce = REDUCE;   LRtab_a[st_HCEA][vs_c].pravidlo1 = t_HCEA;
    LRtab_a[st_HCEA][vs_c].poc_pravidel = 3;    LRtab_a[st_HCEA][vs_c].pravidlo2 = p_HCEA;
    LRtab_a[st_HCEA][vs_c].pravidlo3 = x_HCEA;
    LRtab_a[st_HCEA][vs_d].tab_akce = REDUCE;   LRtab_a[st_HCEA][vs_d].pravidlo1 = t_HCEA;
    LRtab_a[st_HCEA][vs_d].poc_pravidel = 3;    LRtab_a[st_HCEA][vs_d].pravidlo2 = p_HCEA;
    LRtab_a[st_HCEA][vs_d].pravidlo3 = x_HCEA;
    LRtab_a[st_HCEA][vs_e].tab_akce = REDUCE;   LRtab_a[st_HCEA][vs_e].pravidlo1 = t_HCEA;
    LRtab_a[st_HCEA][vs_e].poc_pravidel = 3;    LRtab_a[st_HCEA][vs_e].pravidlo2 = p_HCEA;
    LRtab_a[st_HCEA][vs_e].pravidlo3 = x_HCEA;
    LRtab_a[st_HCEA][vs_f].tab_akce = REDUCE;   LRtab_a[st_HCEA][vs_f].pravidlo1 = t_HCEA;
    LRtab_a[st_HCEA][vs_f].poc_pravidel = 3;    LRtab_a[st_HCEA][vs_f].pravidlo2 = p_HCEA; 
    LRtab_a[st_HCEA][vs_f].pravidlo3 = x_HCEA;
    LRtab_a[st_HCEA][vs_g].tab_akce = REDUCE;   LRtab_a[st_HCEA][vs_g].pravidlo1 = t_HCEA;
    LRtab_a[st_HCEA][vs_g].poc_pravidel = 3;    LRtab_a[st_HCEA][vs_g].pravidlo2 = p_HCEA;
    LRtab_a[st_HCEA][vs_g].pravidlo3 = x_HCEA;
    LRtab_a[st_HCEA][vs_h].tab_akce = REDUCE;   LRtab_a[st_HCEA][vs_h].pravidlo1 = t_HCEA;
    LRtab_a[st_HCEA][vs_h].poc_pravidel = 3;    LRtab_a[st_HCEA][vs_h].pravidlo2 = p_HCEA;
    LRtab_a[st_HCEA][vs_h].pravidlo3 = x_HCEA;
    LRtab_a[st_HCEA][vs_end].tab_akce = REDUCE; LRtab_a[st_HCEA][vs_end].pravidlo1 = t_HCEA;
    LRtab_a[st_HCEA][vs_end].poc_pravidel = 3;  LRtab_a[st_HCEA][vs_end].pravidlo2 = p_HCEA;
    LRtab_a[st_HCEA][vs_end].pravidlo3 = x_HCEA;
    
    // 108. radek - DFBH -------------------------------------------------------
    LRtab_a[st_DFBH][vs_a].tab_akce = REDUCE;   LRtab_a[st_DFBH][vs_a].pravidlo1 = c_DFBH;
    LRtab_a[st_DFBH][vs_a].poc_pravidel = 3;    LRtab_a[st_DFBH][vs_a].pravidlo2 = dd_DFBH; 
    LRtab_a[st_DFBH][vs_a].pravidlo3 = P_DFBH;
    LRtab_a[st_DFBH][vs_b].tab_akce = REDUCE;   LRtab_a[st_DFBH][vs_b].pravidlo1 = c_DFBH;
    LRtab_a[st_DFBH][vs_b].poc_pravidel = 3;    LRtab_a[st_DFBH][vs_b].pravidlo2 = dd_DFBH; 
    LRtab_a[st_DFBH][vs_b].pravidlo3 = P_DFBH;
    LRtab_a[st_DFBH][vs_c].tab_akce = REDUCE;   LRtab_a[st_DFBH][vs_c].pravidlo1 = c_DFBH;
    LRtab_a[st_DFBH][vs_c].poc_pravidel = 3;    LRtab_a[st_DFBH][vs_c].pravidlo2 = dd_DFBH;
    LRtab_a[st_DFBH][vs_c].pravidlo3 = P_DFBH;    
    LRtab_a[st_DFBH][vs_d].tab_akce = REDUCE;   LRtab_a[st_DFBH][vs_d].pravidlo1 = c_DFBH;
    LRtab_a[st_DFBH][vs_d].poc_pravidel = 3;    LRtab_a[st_DFBH][vs_d].pravidlo2 = dd_DFBH;
    LRtab_a[st_DFBH][vs_d].pravidlo3 = P_DFBH;    
    LRtab_a[st_DFBH][vs_e].tab_akce = REDUCE;   LRtab_a[st_DFBH][vs_e].pravidlo1 = c_DFBH;
    LRtab_a[st_DFBH][vs_e].poc_pravidel = 3;    LRtab_a[st_DFBH][vs_e].pravidlo2 = dd_DFBH;
    LRtab_a[st_DFBH][vs_e].pravidlo3 = P_DFBH;    
    LRtab_a[st_DFBH][vs_f].tab_akce = REDUCE;   LRtab_a[st_DFBH][vs_f].pravidlo1 = c_DFBH;
    LRtab_a[st_DFBH][vs_f].poc_pravidel = 3;    LRtab_a[st_DFBH][vs_f].pravidlo2 = dd_DFBH; 
    LRtab_a[st_DFBH][vs_f].pravidlo3 = P_DFBH;
    LRtab_a[st_DFBH][vs_g].tab_akce = REDUCE;   LRtab_a[st_DFBH][vs_g].pravidlo1 = c_DFBH;
    LRtab_a[st_DFBH][vs_g].poc_pravidel = 3;    LRtab_a[st_DFBH][vs_g].pravidlo2 = dd_DFBH;
    LRtab_a[st_DFBH][vs_g].pravidlo3 = P_DFBH;    
    LRtab_a[st_DFBH][vs_h].tab_akce = SHIFT;    LRtab_a[st_DFBH][vs_h].tab_n_stav = st_h;
    LRtab_a[st_DFBH][vs_end].tab_akce = REDUCE; LRtab_a[st_DFBH][vs_end].pravidlo1 = c_DFBH;
    LRtab_a[st_DFBH][vs_end].poc_pravidel = 3;  LRtab_a[st_DFBH][vs_end].pravidlo2 = dd_DFBH;
    LRtab_a[st_DFBH][vs_end].pravidlo3 = P_DFBH;
    
    // 109. radek - CEAG -------------------------------------------------------
    LRtab_a[st_CEAG][vs_a].tab_akce = REDUCE;   LRtab_a[st_CEAG][vs_a].pravidlo1 = o_CEAG;
    LRtab_a[st_CEAG][vs_b].tab_akce = REDUCE;   LRtab_a[st_CEAG][vs_b].pravidlo1 = o_CEAG;
    LRtab_a[st_CEAG][vs_c].tab_akce = REDUCE;   LRtab_a[st_CEAG][vs_c].pravidlo1 = o_CEAG;
    LRtab_a[st_CEAG][vs_d].tab_akce = REDUCE;   LRtab_a[st_CEAG][vs_d].pravidlo1 = o_CEAG;
    LRtab_a[st_CEAG][vs_e].tab_akce = REDUCE;   LRtab_a[st_CEAG][vs_e].pravidlo1 = o_CEAG;
    LRtab_a[st_CEAG][vs_f].tab_akce = REDUCE;   LRtab_a[st_CEAG][vs_f].pravidlo1 = o_CEAG;
    LRtab_a[st_CEAG][vs_g].tab_akce = SHIFT;    LRtab_a[st_CEAG][vs_g].tab_n_stav = st_g;
    LRtab_a[st_CEAG][vs_h].tab_akce = REDUCE;   LRtab_a[st_CEAG][vs_h].pravidlo1 = o_CEAG;
    LRtab_a[st_CEAG][vs_end].tab_akce = REDUCE; LRtab_a[st_CEAG][vs_end].pravidlo1 = o_CEAG;
    
    // 110. radek - FBHC -------------------------------------------------------
    LRtab_a[st_FBHC][vs_a].tab_akce = REDUCE;   LRtab_a[st_FBHC][vs_a].pravidlo1 = h_FBHC;
    LRtab_a[st_FBHC][vs_b].tab_akce = REDUCE;   LRtab_a[st_FBHC][vs_b].pravidlo1 = h_FBHC;
    LRtab_a[st_FBHC][vs_c].tab_akce = SHIFT;    LRtab_a[st_FBHC][vs_c].tab_n_stav = st_c;
    LRtab_a[st_FBHC][vs_d].tab_akce = REDUCE;   LRtab_a[st_FBHC][vs_d].pravidlo1 = h_FBHC;
    LRtab_a[st_FBHC][vs_e].tab_akce = REDUCE;   LRtab_a[st_FBHC][vs_e].pravidlo1 = h_FBHC;
    LRtab_a[st_FBHC][vs_f].tab_akce = REDUCE;   LRtab_a[st_FBHC][vs_f].pravidlo1 = h_FBHC;
    LRtab_a[st_FBHC][vs_g].tab_akce = REDUCE;   LRtab_a[st_FBHC][vs_g].pravidlo1 = h_FBHC;
    LRtab_a[st_FBHC][vs_h].tab_akce = REDUCE;   LRtab_a[st_FBHC][vs_h].pravidlo1 = h_FBHC;
    LRtab_a[st_FBHC][vs_end].tab_akce = REDUCE; LRtab_a[st_FBHC][vs_end].pravidlo1 = h_FBHC;
    
    // 111. radek - xGE -------------------------------------------------------
    LRtab_a[st_xGE][vs_a].tab_akce = REDUCE;   LRtab_a[st_xGE][vs_a].pravidlo1 = I_xGE;
    LRtab_a[st_xGE][vs_b].tab_akce = REDUCE;   LRtab_a[st_xGE][vs_b].pravidlo1 = I_xGE;
    LRtab_a[st_xGE][vs_c].tab_akce = REDUCE;   LRtab_a[st_xGE][vs_c].pravidlo1 = I_xGE;
    LRtab_a[st_xGE][vs_d].tab_akce = REDUCE;   LRtab_a[st_xGE][vs_d].pravidlo1 = I_xGE;
    LRtab_a[st_xGE][vs_e].tab_akce = SHIFT;    LRtab_a[st_xGE][vs_e].tab_n_stav = st_e;
    LRtab_a[st_xGE][vs_f].tab_akce = REDUCE;   LRtab_a[st_xGE][vs_f].pravidlo1 = I_xGE;
    LRtab_a[st_xGE][vs_g].tab_akce = REDUCE;   LRtab_a[st_xGE][vs_g].pravidlo1 = I_xGE;
    LRtab_a[st_xGE][vs_h].tab_akce = REDUCE;   LRtab_a[st_xGE][vs_h].pravidlo1 = I_xGE;
    LRtab_a[st_xGE][vs_end].tab_akce = REDUCE; LRtab_a[st_xGE][vs_end].pravidlo1 = I_xGE;
    
    // 112. radek - S ----------------------------------------------------------
    LRtab_a[st_END][vs_end].tab_akce = REDUCE; LRtab_a[st_END][vs_end].pravidlo1 = S_S;
    
    // 113. radel - x ----------------------------------------------------------
    LRtab_a[st_x][vs_g].tab_akce = SHIFT;  LRtab_a[st_x][vs_g].tab_n_stav = st_g;
    
    // 114. radek - xG ---------------------------------------------------------
    LRtab_a[st_xG][vs_e].tab_akce = SHIFT;  LRtab_a[st_xG][vs_e].tab_n_stav = st_e;
    LRtab_a[st_xG][vs_g].tab_akce = SHIFT;  LRtab_a[st_xG][vs_g].tab_n_stav = st_g;
    
    // 115. radek - Z ----------------------------------------------------------
    LRtab_a[st_Z][vs_a].tab_akce = SHIFT;  LRtab_a[st_Z][vs_a].tab_n_stav = st_a;
    
    // 116. radek - EAD --------------------------------------------------------
    LRtab_a[st_EAD][vs_a].tab_akce = REDUCE;   LRtab_a[st_EAD][vs_a].pravidlo1 = Z_EAD;
    LRtab_a[st_EAD][vs_b].tab_akce = REDUCE;   LRtab_a[st_EAD][vs_b].pravidlo1 = Z_EAD;
    LRtab_a[st_EAD][vs_c].tab_akce = REDUCE;   LRtab_a[st_EAD][vs_c].pravidlo1 = Z_EAD;
    LRtab_a[st_EAD][vs_d].tab_akce = SHIFT;    LRtab_a[st_EAD][vs_d].tab_n_stav = st_d;
    LRtab_a[st_EAD][vs_e].tab_akce = REDUCE;   LRtab_a[st_EAD][vs_e].pravidlo1 = Z_EAD;
    LRtab_a[st_EAD][vs_f].tab_akce = REDUCE;   LRtab_a[st_EAD][vs_f].pravidlo1 = Z_EAD;
    LRtab_a[st_EAD][vs_g].tab_akce = REDUCE;   LRtab_a[st_EAD][vs_g].pravidlo1 = Z_EAD;
    LRtab_a[st_EAD][vs_h].tab_akce = REDUCE;   LRtab_a[st_EAD][vs_h].pravidlo1 = Z_EAD;
    LRtab_a[st_EAD][vs_end].tab_akce = REDUCE; LRtab_a[st_EAD][vs_end].pravidlo1 = Z_EAD;
    
    // 117. radek - EGD --------------------------------------------------------
    LRtab_a[st_EGD][vs_a].tab_akce = REDUCE;   LRtab_a[st_EGD][vs_a].pravidlo1 = Z_EGD;
    LRtab_a[st_EGD][vs_b].tab_akce = REDUCE;   LRtab_a[st_EGD][vs_b].pravidlo1 = Z_EGD;
    LRtab_a[st_EGD][vs_c].tab_akce = REDUCE;   LRtab_a[st_EGD][vs_c].pravidlo1 = Z_EGD;
    LRtab_a[st_EGD][vs_d].tab_akce = SHIFT;    LRtab_a[st_EGD][vs_d].tab_n_stav = st_d;
    LRtab_a[st_EGD][vs_e].tab_akce = REDUCE;   LRtab_a[st_EGD][vs_e].pravidlo1 = Z_EGD;
    LRtab_a[st_EGD][vs_f].tab_akce = REDUCE;   LRtab_a[st_EGD][vs_f].pravidlo1 = Z_EGD;
    LRtab_a[st_EGD][vs_g].tab_akce = REDUCE;   LRtab_a[st_EGD][vs_g].pravidlo1 = Z_EGD;
    LRtab_a[st_EGD][vs_h].tab_akce = REDUCE;   LRtab_a[st_EGD][vs_h].pravidlo1 = Z_EGD;
    LRtab_a[st_EGD][vs_end].tab_akce = REDUCE; LRtab_a[st_EGD][vs_end].pravidlo1 = Z_EGD;
    
    // 118. radek - EAG --------------------------------------------------------
    LRtab_a[st_EAG][vs_a].tab_akce = REDUCE;   LRtab_a[st_EAG][vs_a].pravidlo1 = O_EAG;
    LRtab_a[st_EAG][vs_b].tab_akce = REDUCE;   LRtab_a[st_EAG][vs_b].pravidlo1 = O_EAG;
    LRtab_a[st_EAG][vs_c].tab_akce = REDUCE;   LRtab_a[st_EAG][vs_c].pravidlo1 = O_EAG;
    LRtab_a[st_EAG][vs_d].tab_akce = SHIFT;    LRtab_a[st_EAG][vs_d].tab_n_stav = st_d;
    LRtab_a[st_EAG][vs_e].tab_akce = REDUCE;   LRtab_a[st_EAG][vs_e].pravidlo1 = O_EAG;
    LRtab_a[st_EAG][vs_f].tab_akce = REDUCE;   LRtab_a[st_EAG][vs_f].pravidlo1 = O_EAG;
    LRtab_a[st_EAG][vs_g].tab_akce = SHIFT;    LRtab_a[st_EAG][vs_g].tab_n_stav = st_g;
    LRtab_a[st_EAG][vs_h].tab_akce = REDUCE;   LRtab_a[st_EAG][vs_h].pravidlo1 = O_EAG;
    LRtab_a[st_EAG][vs_end].tab_akce = REDUCE; LRtab_a[st_EAG][vs_end].pravidlo1 = O_EAG;
    
    // 119. radek - EAGD -------------------------------------------------------
    LRtab_a[st_EAGD][vs_a].tab_akce = REDUCE;   LRtab_a[st_EAGD][vs_a].pravidlo1 = Z_EAGD;
    LRtab_a[st_EAGD][vs_b].tab_akce = REDUCE;   LRtab_a[st_EAGD][vs_b].pravidlo1 = Z_EAGD;
    LRtab_a[st_EAGD][vs_c].tab_akce = REDUCE;   LRtab_a[st_EAGD][vs_c].pravidlo1 = Z_EAGD;
    LRtab_a[st_EAGD][vs_d].tab_akce = SHIFT;    LRtab_a[st_EAGD][vs_d].tab_n_stav = st_d;
    LRtab_a[st_EAGD][vs_e].tab_akce = REDUCE;   LRtab_a[st_EAGD][vs_e].pravidlo1 = Z_EAGD;
    LRtab_a[st_EAGD][vs_f].tab_akce = REDUCE;   LRtab_a[st_EAGD][vs_f].pravidlo1 = Z_EAGD;
    LRtab_a[st_EAGD][vs_g].tab_akce = REDUCE;   LRtab_a[st_EAGD][vs_g].pravidlo1 = Z_EAGD;
    LRtab_a[st_EAGD][vs_h].tab_akce = REDUCE;   LRtab_a[st_EAGD][vs_h].pravidlo1 = Z_EAGD;
    LRtab_a[st_EAGD][vs_end].tab_akce = REDUCE; LRtab_a[st_EAGD][vs_end].pravidlo1 = Z_EAGD;
    
    // 120. radek - HCB --------------------------------------------------------
    LRtab_a[st_HCB][vs_a].tab_akce = REDUCE;   LRtab_a[st_HCB][vs_a].pravidlo1 = J_HCB;
    LRtab_a[st_HCB][vs_b].tab_akce = SHIFT;    LRtab_a[st_HCB][vs_b].tab_n_stav = st_b;
    LRtab_a[st_HCB][vs_c].tab_akce = REDUCE;   LRtab_a[st_HCB][vs_c].pravidlo1 = J_HCB;
    LRtab_a[st_HCB][vs_d].tab_akce = REDUCE;   LRtab_a[st_HCB][vs_d].pravidlo1 = J_HCB;
    LRtab_a[st_HCB][vs_e].tab_akce = REDUCE;   LRtab_a[st_HCB][vs_e].pravidlo1 = J_HCB;
    LRtab_a[st_HCB][vs_f].tab_akce = REDUCE;   LRtab_a[st_HCB][vs_f].pravidlo1 = J_HCB;
    LRtab_a[st_HCB][vs_g].tab_akce = REDUCE;   LRtab_a[st_HCB][vs_g].pravidlo1 = J_HCB;
    LRtab_a[st_HCB][vs_h].tab_akce = REDUCE;   LRtab_a[st_HCB][vs_h].pravidlo1 = J_HCB;
    LRtab_a[st_HCB][vs_end].tab_akce = REDUCE; LRtab_a[st_HCB][vs_end].pravidlo1 = J_HCB;
    
    // 121. radek - GD ---------------------------------------------------------
    LRtab_a[st_GD][vs_a].tab_akce = SHIFT;    LRtab_a[st_GD][vs_a].tab_n_stav = st_a;
    LRtab_a[st_GD][vs_d].tab_akce = SHIFT;    LRtab_a[st_GD][vs_d].tab_n_stav = st_d;
    
    // 122. radek - GDA --------------------------------------------------------
    LRtab_a[st_GDA][vs_a].tab_akce = SHIFT;    LRtab_a[st_GDA][vs_a].tab_n_stav = st_a;
    LRtab_a[st_GDA][vs_b].tab_akce = REDUCE;   LRtab_a[st_GDA][vs_b].pravidlo1 = K_GDA;
    LRtab_a[st_GDA][vs_c].tab_akce = REDUCE;   LRtab_a[st_GDA][vs_c].pravidlo1 = K_GDA;
    LRtab_a[st_GDA][vs_d].tab_akce = REDUCE;   LRtab_a[st_GDA][vs_d].pravidlo1 = K_GDA;
    LRtab_a[st_GDA][vs_e].tab_akce = REDUCE;   LRtab_a[st_GDA][vs_e].pravidlo1 = K_GDA;
    LRtab_a[st_GDA][vs_f].tab_akce = REDUCE;   LRtab_a[st_GDA][vs_f].pravidlo1 = K_GDA;
    LRtab_a[st_GDA][vs_g].tab_akce = REDUCE;   LRtab_a[st_GDA][vs_g].pravidlo1 = K_GDA;
    LRtab_a[st_GDA][vs_h].tab_akce = REDUCE;   LRtab_a[st_GDA][vs_h].pravidlo1 = K_GDA;
    LRtab_a[st_GDA][vs_end].tab_akce = REDUCE; LRtab_a[st_GDA][vs_end].pravidlo1 = K_GDA;
    
    // 123. radek - EC ---------------------------------------------------------
    LRtab_a[st_EC][vs_c].tab_akce = SHIFT;     LRtab_a[st_EC][vs_c].tab_n_stav = st_c;
    LRtab_a[st_EC][vs_h].tab_akce = SHIFT;     LRtab_a[st_EC][vs_h].tab_n_stav = st_h;
    
    // 124. radek - ECH --------------------------------------------------------
    LRtab_a[st_ECH][vs_a].tab_akce = SHIFT;     LRtab_a[st_ECH][vs_a].tab_n_stav = st_a;
    LRtab_a[st_ECH][vs_h].tab_akce = SHIFT;     LRtab_a[st_ECH][vs_h].tab_n_stav = st_h;
    
    // 125. radek - GDA --------------------------------------------------------
    LRtab_a[st_ECHA][vs_a].tab_akce = SHIFT;    LRtab_a[st_ECHA][vs_a].tab_n_stav = st_a;
    LRtab_a[st_ECHA][vs_b].tab_akce = REDUCE;   LRtab_a[st_ECHA][vs_b].pravidlo1 = N_ECHA;
    LRtab_a[st_ECHA][vs_c].tab_akce = REDUCE;   LRtab_a[st_ECHA][vs_c].pravidlo1 = N_ECHA;
    LRtab_a[st_ECHA][vs_d].tab_akce = REDUCE;   LRtab_a[st_ECHA][vs_d].pravidlo1 = N_ECHA;
    LRtab_a[st_ECHA][vs_e].tab_akce = REDUCE;   LRtab_a[st_ECHA][vs_e].pravidlo1 = N_ECHA;
    LRtab_a[st_ECHA][vs_f].tab_akce = REDUCE;   LRtab_a[st_ECHA][vs_f].pravidlo1 = N_ECHA;
    LRtab_a[st_ECHA][vs_g].tab_akce = REDUCE;   LRtab_a[st_ECHA][vs_g].pravidlo1 = N_ECHA;
    LRtab_a[st_ECHA][vs_h].tab_akce = REDUCE;   LRtab_a[st_ECHA][vs_h].pravidlo1 = N_ECHA;
    LRtab_a[st_ECHA][vs_end].tab_akce = REDUCE; LRtab_a[st_ECHA][vs_end].pravidlo1 = N_ECHA;
}
/*
 * Konstruktor LR tabulky
 */
LRtabulka::LRtabulka() {
    naplTabulku();    
}
/*
 * Funkce vrací pro aktuální stav a vstup dostupnou akci
 */
tab_polozka LRtabulka::vratHodTabulky(int p_radek, int p_sloupec){
    return LRtab_a[p_radek][p_sloupec];
}
