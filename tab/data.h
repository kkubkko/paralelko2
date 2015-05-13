/* 
 * File:   data.h
 * Author: Lukáš Junek
 *
 * Created on 28. říjen 2013, 20:59
 */

#ifndef DATA_H
#define	DATA_H

#include <cstdlib>

// definovaní počtu řádků a sloupců LR tabulky
#define SLP_ALFA 9
#define SLP_BETA 35
#define RADKY 125

// definování akcí LR tabulky
 enum akce {
    SHIFT = 1,
    REDUCE = 2,
    NONE = 0
};

// definování jednotlivých stavů vláken
enum err_stavy {
    OK = 1,
    ERR_RED = -1,
    ERR_BETA_VSTUP = -3,
    ERR_ALFA_VSTUP = -2,
    WAIT_SHIFT = 2,
    ERR_MISS = 3,
    ERR_ERR = 4,
    ERR_WAIT = 5,
    END = 6            
};

// definování struktury tabulky
struct tab_polozka {
    int poc_pravidel;
    akce tab_akce;
    int tab_n_stav;
    int pravidlo1;
    int pravidlo2;
    int pravidlo3;
    bool konflikt;
};

// definování položky zásobníku
struct stack_polozka {
    int term;
    int stav;
};

const int zd_stav = -1;
const int zd_pravidlo = -1;

// definování maximální tolerance
const int max_vzdalenost = 5;

// definování jednotlivých stavů
enum stavy {
    st_emp = 0, st_a = 1, st_b = 2, st_c = 3, st_d = 4, st_e = 5, st_f = 6, st_g = 7, st_h = 8,
    st_A = 9, st_B = 10, st_C = 11, st_D = 12, st_E = 13, st_F = 14, st_G = 15, st_H = 16,
    st_AA = 17, st_BB = 18, st_CC = 19, st_DD = 20, st_EE = 21, st_FF = 22, st_GG = 23, st_HH = 24, 
    st_1 = 25, st_3 = 26, st_4 = 27, st_6 = 28, st_8 = 29, st_P = 30, st_9 = 31, st_U = 32,
    st_X = 33, st_DB = 34, st_FB = 35, st_DF = 36, st_DH = 37, st_HE = 38, st_CE = 39, st_HC = 40,
    st_CA = 41, st_HA = 42, st_CG = 43, st_FH = 44, st_FC = 45, st_CB = 46, st_DA = 47, st_AG = 48,
    st_ED = 49, st_EH = 50, st_11 = 51, st_33 = 52, st_EG = 53, st_6G = 54, st_EA = 55, st_D9 = 56,
    st_8E = 57, st_PB = 58, st_12 = 59, st_42 = 60, st_46 = 61, st_14 = 62, st_4k = 63, st_48 = 64,
    st_PM = 65, st_13 = 66, st_XY = 67, st_47 = 68, st_4M = 69, st_P8 = 70, st_U2 = 71, st_UV = 72,
    st_1J = 73, st_15 = 74, st_4h = 75, st_9T = 76, st_PJ = 77, st_DFB = 78, st_DHB = 79, st_HCE = 80,
    st_HCA = 81, st_CEA = 82, st_DBH = 83, st_DFH = 84, st_CEG = 85, st_CAG = 86, st_FBH = 87, st_FBC = 88,
    st_FHC = 89, st_HEG = 90, st_ZA = 91, st_EHA = 92, st_11J = 93, st_33K = 94, st_12I = 95, st_14L = 96,
    st_4kN = 97, st_UVW = 98, st_133 = 99, st_1J3 = 100, st_13K = 101, st_113 = 102, st_158 = 103, st_4hO = 104,
    st_PJQ = 105, st_HCEA = 106, st_DFBH = 107, st_CEAG = 108, st_FBHC = 109, st_xGE = 110, st_END = 111, st_x = 112,
    st_xG = 113, st_Z = 114, st_EAD = 115, st_EGD = 116, st_EAG = 117, st_EAGD = 118, st_HCB = 119, st_GD = 120,
    st_GDA = 121, st_EC = 122, st_ECH = 123, st_ECHA = 124 
};

// definování vstupních znaků (vnitřní reprezentace znaků)
enum vstupy {
    vs_a = 0, vs_b = 1, vs_c = 2, vs_d = 3, vs_e = 4, vs_f = 5, vs_g = 6, vs_h = 7 , vs_end = 8 
};

// definování nonterminálů
enum non_term {
    nt_S = 10, nt_A = 11, nt_B = 12, nt_C = 13, nt_D = 14, nt_E = 15, nt_F = 16, nt_G = 17, nt_H = 18,
    nt_1 = 19, nt_2 = 20, nt_3 = 21, nt_4 = 22, nt_5 = 23, nt_6 = 24, nt_7 = 25, nt_8 = 26, 
    nt_9 = 27, nt_h = 28, nt_I = 29, nt_K = 30, nt_L = 31, nt_M = 32, nt_N = 33, nt_O = 34,
    nt_P = 35, nt_Q = 36, nt_R = 37, nt_T = 38, nt_U = 39, nt_V = 40, nt_W = 41, nt_X = 42,
    nt_Y = 43, nt_J = 44, nt_k = 45, nt_Z = 46, nt_x = 47
};

// výčet všech derivačních pravidel
enum pravidla {
    A_a = 1, B_b = 2, C_c = 3, D_d = 4, E_e = 5, F_f = 6, G_g = 7, H_h = 8,
    A_AA = 9, B_BB = 10, C_CC = 11, D_DD = 12, E_EE = 13, F_FF = 14, G_GG = 15, H_HH = 16,
    j_DB = 17, j_FB = 18, j_DFB = 19, j_DHB = 20, d_E = 21, d_HE = 22, d_CE = 23, d_HCE = 24,
    t_CA = 25, t_HCA = 26, t_CEA = 27, t_HCEA = 28, c_DH = 29, c_DBH = 30, c_DFH = 31, c_DFBH = 32,
    p_HA = 33, p_HCA = 34, p_HCEA = 35, s_A = 36, s_CA = 37, s_CEA = 38, o_CG = 39, o_CEG = 40,
    o_CAG = 41, o_CEAG = 42, dd_DFH = 43, dd_DFBH = 44, h_FC = 45, h_FBC = 46, h_FHC = 47, h_FBHC = 48,
    I_xGE = 49, J_CB = 50, K_DA = 51, W_AG = 52, L_ZA = 53, M_CE = 54, N_EHA = 55, ss_6G = 56,
    X_11J = 57, Y_33K = 58, O_EG = 59, F_DF = 60, P_DF = 61, Q_EA = 62, R_D9 = 63, T_8E = 64,
    U_PB = 65, V_HCE = 66, S_12 = 67, S_42 = 68, S_46 = 69, S_12I = 70, S_14L = 71, S_4kN = 72,
    S_48 = 73, S_PM = 74, S_13 = 75, S_XY = 76, S_47 = 77, S_4M = 78, S_P8 = 79, S_U2 = 80,
    S_UVW = 81, S_133 = 82, S_1J3 = 83, S_13K = 84, S_113 = 85, S_158 = 86, S_4hO = 87, S_9T = 88,
    S_PJQ = 89, S_S = 90, k_FH = 91, k_FBH = 92, x_HE = 93, x_HCE = 94, Z_ED = 95, Z_EAD = 96,
    Z_EGD = 97, Z_EAGD = 98, O_EAG = 99, x_HCEA = 100, J_HCB = 101, K_GDA = 102, N_ECHA = 103, c_DHB = 104,
    P_DFB = 105, P_DFBH = 106
};



#endif	/* DATA_H */

