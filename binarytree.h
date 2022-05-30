/**
 * @file binarytree.h
 * @brief The header for binary stree abstract data type
 * @version 0.1
 * @date 2022-04-20
 * 
 */
 
#ifndef binarytree_H
#define binarytree_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************* MAKRO-MAKRO BERPARAMETER **************/

#define Nil NULL
#define Info(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right
#define Next(P) (P)->next


/************* DEKLARASI TYPE SEBAGAI ATRIBUT DATA ADT *************/
typedef char String[50];

typedef char infotype[10];
typedef struct tElmtNode *addressTree;
typedef struct tElmtNode {
	infotype info;
	addressTree left;
	addressTree right;
} ElmtNode;
typedef addressTree BinTree;

/*******************************************************************/
/*                      DEFINISI PRIMITIF ADT                      */
/*******************************************************************/


// Membuat node baru bertipe binary tree node hasil alokasi memori. 
addressTree AlokasiNode (infotype X);

// Mengecek tree kosong atau tidak
boolean IsEmptyTree(BinTree P);

// Mendapatkan anak kiri tree
BinTree GetLeft(BinTree P);

// Mendapatkan anak kanan tree
BinTree GetRight(BinTree P);

// Membuat node baru pada tree
void newNode(BinTree *P, infotype X);

// Membuat sebuah tree
void makeTree(infotype X, BinTree L, BinTree R, BinTree *P);

// Menampilkan setiap node elemen tree
void printInfoTree(BinTree P);

/* Konversi Infix ke Postfix */
void InfixToPostfix (String infix, String postfix);

/* Mengembalikan nilai prioritas dari suatu operator*/
int priority(char x);

/* Mengembalikan nilai true, jika operator a
memiliki prioritas yang lebih tinggi dibanding operator b*/
boolean cekPriority(char a, char b);

#endif
