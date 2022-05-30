/*
 *	File          : stack.c
 *	Deskripsi     : Body file dari ADT Stack [Linked List]
 */

#include "stack.h"
#include <stdio.h>
#include <conio.h>

//Kamus Global

/* Prototype ADT Stack [Linked List] */

/* {Konstruktor pembentuk Stack} */
void createstack(stack *s){
/* I.S : S terdefinisi, tidak diketahui nilainya
   F.S : S diinisialisasi top(s) = nil,
*/
	
	//Kamus
	
	//Algoritma
	top(*s) = nil;
}

/* {Opeasi terhadap komponen : selektor Get dan Set} */
//Destruktor or Dealokator
address alokasi(char x){
//Mengirim sebuah elemen stack dalam bentuk address

	//Kamus
	tabstack *p;
	
	//Algoritma
	p = (tabstack*)malloc(sizeof(tabstack));
	if(p != nil){
		info(p) = x;
		p->prev = nil;
		return p;
	} else {
		return nil;
	}
}

void dealokasi(address p){
/* I.S : P terdefinisi
   F.S : P dikembalikan ke sistem
   Melakukan dealokasi /pengembalian address P ke sistem
*/

	//Kamus
	
	//Algoritma
	free(p);
}

/* {Kelompok Interaksi Dengan I/O Device} */
void push(stack *s, char x){
/* I.S : S terdefinisi sembarang, mungkin kosong
   F.S : S bertambah sebuah elemen sebagai elemen pertama
*/
	
	//Kamus
	//tabstack *p;
	address p,q;
	
	//Algoritma
	p = alokasi(x);
	if (isstackempty(*s)) { // Stack Kosong
		top(*s) = p;
	} else { // Stack tidak kosong
		prev(p) = top(*s);
		top(*s) = p;
	}
}

void pop(stack *s, char *x){
/* I.S : S terdefinisi, Stack tidak kosong
   F.S : Menghapus elemen pada top(s)
*/

	//Kamus
	address pTOP,tmp2;
	int out;
	
	//Algoritma
	pTOP = top(*s);
	*x = info(pTOP);
	if(prev(pTOP) == nil){ // hanya ada 1 elemen
		top(*s) = nil;
	} else { // lebih dari satu elemen
		top(*s) = prev(pTOP);
		prev(pTOP) = nil;
	}
}

void cetakstack(stack s){
/* I.S : S terdefinisi, mungkin kosong
   F.S : Menampilkan seluruh elemen dalam stack ke layar dari mulai TOP sampai dengan buttom jika tidak kosong
*/

	//Kamus
	tabstack *p, *q;
	
	//Algoritma
	printf("isi stack dari mulai TOP s.d. BUTTOM : \n");
	if(!isstackempty(s)){
		p = top(s);
		printf("[ %d ]", info(p));
		p = prev(p);
		while (p != nil){
			printf(" - [ %d ]", info(p));
			p = prev(p);
		}
	} else {
		printf("[ Empty ]");
	}
}

/* {Kelompok Operasi Cek elemen kosong} */
boolean isstackempty(stack s){
//Mengirimkan true jika stack kosong, false jika tidak
	
	//Kamus
	
	//ALgoritma
	if(top(s) == nil){
		return true;
	} else {
		return false;
	}	
}


