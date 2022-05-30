/*
 *	File          : pajak.h
 *	Deskripsi     : Header file untuk perhitungan pajak 
 */

#include <stdio.h>

typedef struct {
    double gaji;
    double gajiPasangan;
    int status;
    int jml_anak;
    char berpenghasilan;
} Pajak;

/* Digunakan untuk menampilkan tampilan kalkulator pajak */
void calcuPajak(Pajak data);

/* Digunakan untuk menghitung jumlah PTKP */
double hitungPTKP(Pajak data);

/* Digunakan untuk menghitung jumlah Gaji pertahun */
double totalGajiPertahun(double gaji);

/* Digunakan untuk menghitung jumlah PKP */
double hitungPKP(Pajak data);

/* Digunakan untuk menghitung jumlah PPh */
double hitungPPh(Pajak data);
