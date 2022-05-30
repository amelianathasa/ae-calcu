/*
 *	File          : stack.h
 *	Deskripsi     : Header file dari ADT Stack [Linked List]
 */

#ifndef _stack_H
#define _stack_H

#include "boolean.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define nil NULL
#define info(p) (p)->info
#define prev(p) p->prev
#define top(s) (s).top

/* Definisi Type Bentukan ADT Stack [Linked List] */

typedef struct telmstack *address;

typedef struct telmstack{
	char info;
	address prev;
}tabstack;

typedef struct{
	address top;
}stack;

/* Prototype ADT Stack [Linked List] */
/* {Konstruktor pembentuk Stack} */
void createstack(stack *s);
/* I.S : S terdefinisi, tidak diketahui nilainya
   F.S : S diinisialisasi top(s) = nil,
*/

/* {Operasi terhadap komponen : selektor Get dan Set} */
//Destruktor or Dealokator
address alokasi(char x);
//Mengirim sebuah elemen stack dalam bentuk address

void dealokasi(address p);
/* I.S : P terdefinisi
   F.S : P dikembalikan ke sistem
   Melakukan dealokasi / pengembalian address P ke sistem
*/

/* {Kelompok Interaksi Dengan I/O Device} */
void push(stack *s, char x);
/* I.S : S terdefinisi sembarang, mungkin kosong
   F.S : S bertambah sebuah elemen sebagai elemen pertama
*/

void pop(stack *s, char *x);
/* I.S : S terdefinisi, Stack tidak kosong
   F.S : Menghapus elemen pada top(s)
*/

void cetakstack(stack s);
/* I.S : S terdefinisi, mungkin kosong
   F.S : Menampilkan seluruh elemen dalam stack ke layar dari mulai TOP sampai dengan bottom jika tidak kosong
*/

/* {Kelompok Operasi Cek elemen kosong} */
boolean isstackempty(stack s);
//Mengirimkan true jika stack kosong, false jika tidak

#endif


