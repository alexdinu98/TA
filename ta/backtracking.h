#pragma once
#include "global.h"

void backtracking();
void generare_permutari();
void generare_combinari();
void generare_aranjamente();
void problema_reginelor();
void problema_turelor();
void problema_calutilor();
void problema_Parantezelor();
void pb_comis_voiaj();
void generare_submultimi();
void generare_cub();
void generare_steaguri();
int am_succesor(int st[],int n,int k);
void afisv(int st[],int n);
int validperm(int x[10],int k);
int validcomb(int x[10],int k);
int validaranj(int x[10],int k);
bool valid_regine(int x[10],int k);
bool valid_ture(int x[10],int k);
int valid_cai(int x[10],int k);
void costmin(int sat,int n,int** a,int* v);
void back_parant(int* x,int n,int& ns,int k);
void gen_s(int k,int n,int* x);