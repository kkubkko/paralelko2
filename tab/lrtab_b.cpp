/* 
 * File:   lrtab_b.cpp
 * Author: Lukáš Junek
 *
 * Created on 2. listopad 2013, 14:16
 */
#include "lrtab_b.h"
#include "lrtab.h"

/*
 * Funkce naplní tabulku - její přechodovou část 
 */
void LRtabulka_beta::naplnTabulku(){
    for (int i = 0; i < RADKY; i++) {
        for (int j = 0; j < SLP_BETA; j++){
            LRtab_b[i][j] = zd_stav;
        }
    }
    
    // 1. radek - EMP ----------------------------------------------------------
    LRtab_b[st_emp][nt_S-10] = st_END;
    LRtab_b[st_emp][nt_D-10] = st_D;
    LRtab_b[st_emp][nt_F-10] = st_F;
    LRtab_b[st_emp][nt_1-10] = st_1;
    LRtab_b[st_emp][nt_4-10] = st_4;
    LRtab_b[st_emp][nt_P-10] = st_P;
    LRtab_b[st_emp][nt_9-10] = st_9;
    LRtab_b[st_emp][nt_U-10] = st_U;
    LRtab_b[st_emp][nt_X-10] = st_X;
    
    // 2. - 9. radek -----------------------------------------------------------
    // nema nic...
    
    // 10. radek ---------------------------------------------------------------
    LRtab_b[st_A][nt_A-10] = st_AA;
    LRtab_b[st_A][nt_G-10] = st_AG;
    
    // 11. radek ---------------------------------------------------------------
    LRtab_b[st_B][nt_B-10] = st_BB;
    
    // 12. radek ---------------------------------------------------------------
    LRtab_b[st_C][nt_A-10] = st_CA;
    LRtab_b[st_C][nt_B-10] = st_CB;
    LRtab_b[st_C][nt_C-10] = st_CC;
    LRtab_b[st_C][nt_E-10] = st_CE;
    LRtab_b[st_C][nt_G-10] = st_CG;
    
    // 13 radek ----------------------------------------------------------------
    LRtab_b[st_D][nt_A-10] = st_DA;
    LRtab_b[st_D][nt_B-10] = st_DB;
    LRtab_b[st_D][nt_D-10] = st_DD;
    LRtab_b[st_D][nt_F-10] = st_DF; // pozor nejednoznacnost LRtab_b[st_D][nt_F-10] = st_F;
    LRtab_b[st_D][nt_H-10] = st_DH;
    LRtab_b[st_D][nt_9-10] = st_D9;
    
    // 14. radek ---------------------------------------------------------------
    LRtab_b[st_E][nt_A-10] = st_EA;
    LRtab_b[st_E][nt_C-10] = st_EC;
    LRtab_b[st_E][nt_D-10] = st_ED;
    LRtab_b[st_E][nt_E-10] = st_EE;
    LRtab_b[st_E][nt_G-10] = st_EG;
    LRtab_b[st_E][nt_H-10] = st_EH;;
    
    // 15. radek ---------------------------------------------------------------
    LRtab_b[st_F][nt_B-10] = st_FB;
    LRtab_b[st_F][nt_C-10] = st_FC;
    LRtab_b[st_F][nt_F-10] = st_FF;
    LRtab_b[st_F][nt_H-10] = st_FH;
    
    // 16. radek ---------------------------------------------------------------
    LRtab_b[st_G][nt_G-10] = st_GG;
    
    // 17. radek ---------------------------------------------------------------
    LRtab_b[st_H][nt_A-10] = st_HA;
    LRtab_b[st_H][nt_C-10] = st_HC;
    LRtab_b[st_H][nt_E-10] = st_HE;
    LRtab_b[st_H][nt_H-10] = st_HH;
    
    // 18. - 25. radek ---------------------------------------------------------
    // nema nic...
    
    // 26. radek - 1 -----------------------------------------------------------
    LRtab_b[st_1][nt_C-10] = st_C;
    LRtab_b[st_1][nt_D-10] = st_D;
    LRtab_b[st_1][nt_E-10] = st_E;
    LRtab_b[st_1][nt_F-10] = st_F;
    LRtab_b[st_1][nt_G-10] = st_G;
    LRtab_b[st_1][nt_H-10] = st_H;
    LRtab_b[st_1][nt_1-10] = st_11;
    LRtab_b[st_1][nt_2-10] = st_12;
    LRtab_b[st_1][nt_3-10] = st_13;
    LRtab_b[st_1][nt_4-10] = st_14;
    LRtab_b[st_1][nt_5-10] = st_15;
    LRtab_b[st_1][nt_J-10] = st_1J;
    
    // 27. radek - 3 -----------------------------------------------------------
    LRtab_b[st_3][nt_C-10] = st_C;
    LRtab_b[st_3][nt_H-10] = st_H;
    LRtab_b[st_3][nt_3-10] = st_33;
    
    // 28. radek - 4 -----------------------------------------------------------
    LRtab_b[st_4][nt_A-10] = st_A;
    LRtab_b[st_4][nt_C-10] = st_C;
    LRtab_b[st_4][nt_E-10] = st_E;
    LRtab_b[st_4][nt_F-10] = st_F;
    LRtab_b[st_4][nt_H-10] = st_H;
    LRtab_b[st_4][nt_2-10] = st_42;
    LRtab_b[st_4][nt_6-10] = st_46;
    LRtab_b[st_4][nt_7-10] = st_47;
    LRtab_b[st_4][nt_8-10] = st_48;
    LRtab_b[st_4][nt_k-10] = st_4k;
    LRtab_b[st_4][nt_h-10] = st_4h;
    LRtab_b[st_4][nt_M-10] = st_4M;
    
    // 29. radek - 6 -----------------------------------------------------------
    LRtab_b[st_6][nt_G-10] = st_6G;
    
    // 30. radek - 8 -----------------------------------------------------------
    LRtab_b[st_8][nt_E-10] = st_8E;
    
    // 31. radek - P -----------------------------------------------------------
    LRtab_b[st_P][nt_B-10] = st_PB;
    LRtab_b[st_P][nt_C-10] = st_C;
    LRtab_b[st_P][nt_E-10] = st_E;
    LRtab_b[st_P][nt_H-10] = st_H;
    //LRtab_b[st_P][nt_2-10] = st_P2;
    LRtab_b[st_P][nt_8-10] = st_P8;
    LRtab_b[st_P][nt_J-10] = st_PJ;
    LRtab_b[st_P][nt_M-10] = st_PM;
    
    // 32. radek - R -----------------------------------------------------------
    LRtab_b[st_9][nt_C-10] = st_C;
    LRtab_b[st_9][nt_8-10] = st_8;
    LRtab_b[st_9][nt_T-10] = st_9T;
    
    // 33. radek - U -----------------------------------------------------------
    LRtab_b[st_U][nt_E-10] = st_E;
    LRtab_b[st_U][nt_H-10] = st_H;
    LRtab_b[st_U][nt_2-10] = st_U2;
    LRtab_b[st_U][nt_V-10] = st_UV;
    
    // 34. radek - X -----------------------------------------------------------
    LRtab_b[st_X][nt_C-10] = st_C;
    LRtab_b[st_X][nt_H-10] = st_H;
    LRtab_b[st_X][nt_3-10] = st_3;
    LRtab_b[st_X][nt_Y-10] = st_XY;
    
    // 35. radek - DB ----------------------------------------------------------
    LRtab_b[st_DB][nt_B-10] = st_BB;
    LRtab_b[st_DB][nt_H-10] = st_DBH;
    
    // 36. radek - FB ----------------------------------------------------------
    LRtab_b[st_FB][nt_B-10] = st_BB;
    LRtab_b[st_FB][nt_C-10] = st_FBC;
    LRtab_b[st_FB][nt_H-10] = st_FBH;
    
    // 37. radek - DF ----------------------------------------------------------
    LRtab_b[st_DF][nt_B-10] = st_DFB;
    LRtab_b[st_DF][nt_F-10] = st_FF;
    LRtab_b[st_DF][nt_H-10] = st_DFH;
    
    // 38. radek - DH ----------------------------------------------------------
    LRtab_b[st_DH][nt_B-10] = st_DHB;
    LRtab_b[st_DH][nt_H-10] = st_HH;
    
    // 39. radek - HE ----------------------------------------------------------
    LRtab_b[st_HE][nt_E-10] = st_EE;
    //LRtab_b[st_HE][nt_G-10] = st_HEG;
    
    // 40. radek - CE ----------------------------------------------------------
    LRtab_b[st_CE][nt_A-10] = st_CEA;
    LRtab_b[st_CE][nt_E-10] = st_EE;
    LRtab_b[st_CE][nt_G-10] = st_CEG;
    
    // 41. radek - HC ----------------------------------------------------------
    LRtab_b[st_HC][nt_A-10] = st_HCA;
    LRtab_b[st_HC][nt_B-10] = st_HCB;
    LRtab_b[st_HC][nt_C-10] = st_CC;
    LRtab_b[st_HC][nt_E-10] = st_HCE;
    
    // 42. radek - CA ----------------------------------------------------------
    LRtab_b[st_CA][nt_A-10] = st_AA;
    LRtab_b[st_CA][nt_G-10] = st_CAG;
    
    // 43. radek - HA ----------------------------------------------------------
    LRtab_b[st_HA][nt_A-10] = st_AA;
    
    // 44. radek - CG ----------------------------------------------------------
    LRtab_b[st_CG][nt_G-10] = st_GG;
    
    // 45. radek - FH ----------------------------------------------------------
    LRtab_b[st_FH][nt_C-10] = st_FHC;
    LRtab_b[st_FH][nt_H-10] = st_HH;
    
    // 46. radek - FC ----------------------------------------------------------
    LRtab_b[st_FC][nt_C-10] = st_CC;
    
    // 47. radek - CB ----------------------------------------------------------
    LRtab_b[st_CB][nt_B-10] = st_BB;
    
    // 48. radek - DA ----------------------------------------------------------
    LRtab_b[st_DA][nt_A-10] = st_AA;
    
    // 49. radek - AG ----------------------------------------------------------
    LRtab_b[st_AG][nt_G-10] = st_GG;
    
    // 50. radeK - ED ----------------------------------------------------------
    //LRtab_b[st_ED][nt_A-10] = st_EDA;
    LRtab_b[st_ED][nt_D-10] = st_DD;
    
    // 51. radek - EH ----------------------------------------------------------
    LRtab_b[st_EH][nt_A-10] = st_EHA;
    LRtab_b[st_EH][nt_H-10] = st_HH;
    
    // 52. radek - 11 ----------------------------------------------------------
    LRtab_b[st_11][nt_C-10] = st_C;
    LRtab_b[st_11][nt_H-10] = st_H;
    LRtab_b[st_11][nt_3-10] = st_113;
    LRtab_b[st_11][nt_J-10] = st_11J;
    
    // 53. radek - 33 ----------------------------------------------------------
    LRtab_b[st_33][nt_D-10] = st_D;
    LRtab_b[st_33][nt_G-10] = st_G;
    LRtab_b[st_33][nt_K-10] = st_33K;
    
    // 54. radek - EG ----------------------------------------------------------
    LRtab_b[st_EG][nt_G-10] = st_GG;
    LRtab_b[st_EG][nt_D-10] = st_EGD;
    
    // 55. radek - 6G ----------------------------------------------------------
    LRtab_b[st_6G][nt_G-10] = st_GG;
    
    // 56. radek - EA ----------------------------------------------------------
    LRtab_b[st_EA][nt_A-10] = st_AA;
    LRtab_b[st_EA][nt_D-10] = st_EAD;
    LRtab_b[st_EA][nt_G-10] = st_EAG;
    
    // 57. radek - D9 ----------------------------------------------------------
    // nema nic...
    
    // 58. radek - 8E ----------------------------------------------------------
    LRtab_b[st_8E][nt_E-10] = st_EE;
    
    // 59. radek - PB ----------------------------------------------------------
    LRtab_b[st_PB][nt_B-10] = st_BB;
    
    // 60. radek - 12 ----------------------------------------------------------
    LRtab_b[st_12][nt_H-10] = st_H;
    LRtab_b[st_12][nt_I-10] = st_12I;
    LRtab_b[st_12][nt_x-10] = st_x;
    
    // 61. radek - 42 ----------------------------------------------------------
    // nema nic...
    
    LRtab_b[st_46][nt_G-10] = st_6G;
    
    // 63. radek - 14 ----------------------------------------------------------
    LRtab_b[st_14][nt_E-10] = st_E;
    LRtab_b[st_14][nt_Z-10] = st_Z;
    LRtab_b[st_14][nt_L-10] = st_14L;
    
    // 64. radek - 49 ----------------------------------------------------------
    LRtab_b[st_4k][nt_E-10] = st_E;
    LRtab_b[st_4k][nt_N-10] = st_4kN;
    
    // 65. a 66. radek - 48, PM  -----------------------------------------------
    // nema nic...
    LRtab_b[st_47][nt_G-10] = st_GG;
    
    // 67. radek - 13 ----------------------------------------------------------
    LRtab_b[st_13][nt_C-10] = st_C;
    LRtab_b[st_13][nt_D-10] = st_D;
    LRtab_b[st_13][nt_G-10] = st_G;
    LRtab_b[st_13][nt_H-10] = st_H;
    LRtab_b[st_13][nt_3-10] = st_133;
    LRtab_b[st_13][nt_K-10] = st_13K;
    
    // 68. - 72. radek - XY, 4M, P8 a P2 ---------------------------------------
    // nema nic...
    
    // 73. radek - UV ----------------------------------------------------------
    LRtab_b[st_UV][nt_A-10] = st_A;
    LRtab_b[st_UV][nt_W-10] = st_UVW;    
    
    // 74. radek - 1J ----------------------------------------------------------
    LRtab_b[st_1J][nt_C-10] = st_C;
    LRtab_b[st_1J][nt_H-10] = st_H;
    LRtab_b[st_1J][nt_3-10] = st_1J3;
    
    // 75. radek - 15 ----------------------------------------------------------
    LRtab_b[st_15][nt_C-10] = st_C;
    LRtab_b[st_15][nt_8-10] = st_158;
    
    // 76. radek - 4* ----------------------------------------------------------
    LRtab_b[st_4h][nt_E-10] = st_E;
    LRtab_b[st_4h][nt_O-10] = st_4hO;
    
    // 77. radek - RT ----------------------------------------------------------
    // nema nic...
    
    // 78. radek - PJ ----------------------------------------------------------
    LRtab_b[st_PJ][nt_E-10] = st_E;
    LRtab_b[st_PJ][nt_Q-10] = st_PJQ;
    
    // 79. radek - DFB ---------------------------------------------------------
    LRtab_b[st_DFB][nt_B-10] = st_BB;
    LRtab_b[st_DFB][nt_H-10] = st_DFBH;
    
    // 80. radek - DHB ---------------------------------------------------------
    LRtab_b[st_DHB][nt_B-10] = st_BB;
    
    // 81. radek - HCE ---------------------------------------------------------
    LRtab_b[st_HCE][nt_A-10] = st_HCEA;
    LRtab_b[st_HCE][nt_E-10] = st_EE;
    
    // 82. radek - HCA ---------------------------------------------------------
    LRtab_b[st_HCA][nt_A-10] = st_AA;
    
    // 83. radek - CEA ---------------------------------------------------------
    LRtab_b[st_CEA][nt_A-10] = st_AA;
    LRtab_b[st_CEA][nt_G-10] = st_CEAG;
    
    // 84. radek - DBH ---------------------------------------------------------
    LRtab_b[st_DBH][nt_H-10] = st_HH;
    
    // 85. radek - DFH ---------------------------------------------------------
    LRtab_b[st_DFH][nt_H-10] = st_HH;
    
    // 86. radek - CEG ---------------------------------------------------------
    LRtab_b[st_CEG][nt_G-10] = st_GG;
    
    // 87. radek - CAG ---------------------------------------------------------
    LRtab_b[st_CAG][nt_G-10] = st_GG;
    
    // 88. radek - FBH ---------------------------------------------------------
    LRtab_b[st_FBH][nt_C-10] = st_FBHC;
    LRtab_b[st_FBH][nt_H-10] = st_HH;
    
    // 89. radek - FBC ---------------------------------------------------------
    LRtab_b[st_FBC][nt_C-10] = st_CC;
    
    // 90. radek - FHC ---------------------------------------------------------
    LRtab_b[st_FHC][nt_C-10] = st_CC;
    
    // 91. radek - HEG ---------------------------------------------------------
    //LRtab_b[st_HEG][nt_E-10] = st_HEGE;
    LRtab_b[st_HEG][nt_C-10] = st_GG;
    
    // 92. radek - ZA ---------------------------------------------------------
    LRtab_b[st_ZA][nt_A-10] = st_AA;
    
    // 93. radek - EHA ---------------------------------------------------------
    LRtab_b[st_EHA][nt_A-10] = st_AA;
    
    // 94. - 106. radek --------------------------------------------------------
    // nema nic...
    
    // 107. radek - HCEA -------------------------------------------------------
    LRtab_b[st_HCEA][nt_A-10] = st_AA;
    
    // 108. radek - DFBH -------------------------------------------------------
    LRtab_b[st_DFBH][nt_H-10] = st_HH;
    
    // 109. radek - CEAG -------------------------------------------------------
    LRtab_b[st_CEAG][nt_G-10] = st_GG;
    
    // 110. radek - FBHC -------------------------------------------------------
    LRtab_b[st_FBHC][nt_C-10] = st_CC;
    
    // 111. radek - HEGE -------------------------------------------------------
    LRtab_b[st_xGE][nt_E-10] = st_EE;
    
    // 112. radek - S ----------------------------------------------------------
    LRtab_b[st_END][nt_S-10] = st_END;  
    
    // 113. radek - x ----------------------------------------------------------
    LRtab_b[st_x][nt_G-10] = st_xG;
    
    // 114. radek - xG ---------------------------------------------------------
    LRtab_b[st_xG][nt_G-10] = st_GG;
    LRtab_b[st_xG][nt_E-10] = st_xGE;
    
    // 115. radek - Z ----------------------------------------------------------
    LRtab_b[st_Z][nt_A-10] = st_ZA;
    
    // 116. radek - EAD --------------------------------------------------------
    LRtab_b[st_EAD][nt_D-10] = st_DD;
    
    // 117. radek - EGD --------------------------------------------------------
    LRtab_b[st_EGD][nt_D-10] = st_DD;
    
    // 118. radek - EAG --------------------------------------------------------
    LRtab_b[st_EAG][nt_D-10] = st_EAGD;
    LRtab_b[st_EAG][nt_G-10] = st_GG;
    
    // 119. radek - EAGD -------------------------------------------------------
    LRtab_b[st_EAGD][nt_D-10] = st_DD;
    
    // 120. radek - HCB --------------------------------------------------------
    LRtab_b[st_HCB][nt_B-10] = st_BB;
    
    // 121. radek - GD ---------------------------------------------------------
    LRtab_b[st_GD][nt_A-10] = st_GDA;
    LRtab_b[st_GD][nt_D-10] = st_DD;
    
    // 122. radek - GDA --------------------------------------------------------
    LRtab_b[st_GDA][nt_A-10] = st_AA;
    
    // 123. radek - EC ---------------------------------------------------------
    LRtab_b[st_EC][nt_C-10] = st_CC;
    LRtab_b[st_EC][nt_H-10] = st_ECH;
    
    // 124. radek - ECH --------------------------------------------------------
    LRtab_b[st_ECH][nt_H-10] = st_HH;
    LRtab_b[st_ECH][nt_A-10] = st_ECHA;
    
    // 125. radek - ECHA -------------------------------------------------------
    LRtab_b[st_ECHA][nt_A-10] = st_AA;
}

/*
 * Konstruktor LR tabulky
 */
LRtabulka_beta::LRtabulka_beta() {
    naplnTabulku();
}
/*
 * Funkce vrací nový stav po provedené redukci
 */
int LRtabulka_beta::vratHodTabulky(int p_radek, int p_sloupec) {
    return LRtab_b[p_radek][p_sloupec-10];
}