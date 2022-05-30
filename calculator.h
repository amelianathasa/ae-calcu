/*
 *	File          : calculator.h
 *	Deskripsi     : header file untuk calculator 
 */
 
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string.h>
#include <windows.h>
#include "binarytree.h"
#include "stack.h"
#include "pajak.h"
#include "boolean.h"

/* MODUL USER INTERFACE */
void menu();

// Modul untuk menentukan posisi output
void gotoxy(int x, int y);

/**
 * Modul untuk menampilkan tampilan menu
*/
void mulai();
/**
 * Modul untuk menampilkan tampilan menu kalkulator
*/
void calcuDasar();
/**
 * Modul untuk menampilkan tampilan kalkulator dasar
*/
//void calcuPajak();
/**
 * Modul untuk menampilkan tampilan kalkulator pajak
*/
void bantuan();
/**
 * Modul untuk menampilkan tampilan bantuan
*/
void credits();
/* Cek apakah inputan user benar atau tidak */
boolean cekInput(String input);

/* Cek inputan user berupa operator */
boolean cekOperator(char c);

/* Cek inputan user berupa angka */
boolean cekAngka(char c);

/* Cek inputan user berupa kurung */
boolean cekParentheses(char c);

#endif

