/**
 * @file binarytree.c
 * @brief The specification for binary stree abstract data type
 * @version 0.1
 * @date 2022-04-20
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#include "binarytree.h"
#include "stack.h"

/*******************************************************************/
/*  DEFINISI PRIMITIF ADT                                          */
/*******************************************************************/

// Membuat node baru bertipe binary tree node hasil alokasi memori. 
addressTree AlokasiNode (infotype X){
	addressTree P;

	P = (addressTree)malloc(sizeof(ElmtNode));
	if(P != Nil){
		strcpy(Info(P), X);
		Left(P) = Nil;
		Right(P) = Nil;
	}
	return P;
}

// Mengecek tree kosong atau tidak
boolean IsEmptyTree(BinTree P){
	return (P == Nil);
}

// Mendapatkan anak kiri tree
BinTree GetLeft(BinTree P){
	return Left(P);
}

// Mendapatkan anak kanan tree
BinTree GetRight(BinTree P){
	return Right(P);
}

// Membuat node baru pada tree
void newNode(BinTree *P, infotype X){
	*P = AlokasiNode(X);
	if(*P != Nil){
		strcpy(Info(*P), X);
		Left(*P) = Right(*P) = Nil;
	}
}

// Membuat sebuah tree
void makeTree(infotype X, BinTree L, BinTree R, BinTree *P){
	*P = AlokasiNode(X);
	if(*P != Nil){
		strcpy(Info(*P), X);
		Left(*P) = L;
		Right(*P) = R;
	}
}

// Menampilkan setiap node tree
void printInfoTree(BinTree P){
	BinTree L, R, Px;
	
	if(P != Nil) {
		printInfoTree(Left(P)); 
		printf("Info Node\t: %s\n",Info(P));
		if(GetLeft(P)!=Nil) {
			L = GetLeft(P);
			printf("Left Son\t: %s\n",Info(L));
		}
		else {
			printf("Left Son\t: null\n");
		}
		if(GetRight(P)!=Nil) {
			R = GetRight(P);
			printf("Right Son\t: %s\n",Info(R));
		}
		else{
			printf("Right Son\t: null\n");
		}	
		printf("\n");  
		printInfoTree(Right(P));
	}
}

/*******************************************************************/
/*  OPERASI TREE UNTUK CALCULATOR                                  */
/*******************************************************************/

/* Konversi Infix ke Postfix */
void InfixToPostfix (String infix, String postfix){
	/* Kamus Data */
	int i, length, idx=0;
	char tmp;
	stack s;
	
	/* Algoritma */
	createstack(&s);
	length = strlen(infix);
	for(i=0; i<length; i++){
		
		// Jika input berupa angka
		if(cekAngka(infix[i])){
			postfix[idx] = infix[i];
			idx++;
			
		// Jika input berupa '(', push ke dalam stack
		}else if(infix[i] == '('){
			push(&s, infix[i]);
			
		// Jika input berupa ')', 
		// pop stack hingga karakter '(' ditemukan
		}else if(infix[i] == ')'){
			while(!isstackempty(s) && info(top(s))!= '('){
				pop(&s, &tmp);
				postfix[idx] = tmp;
				idx++;
			}
			pop(&s, &tmp);
		}else{
			
		// Jika input berupa operator
			postfix[idx] = ' ';
			idx++;
			if(isstackempty(s)){
				push(&s, infix[i]);
			}else if(!cekPriority(info(top(s)), infix[i])){
				push(&s, infix[i]);
			}else{
				while(!isstackempty(s) && cekPriority(info(top(s)), infix[i])){
					pop(&s, &tmp);
					postfix[idx] = tmp;
					idx++;
				}
				push(&s, infix[i]);
			}
		}
	}
	
	// Pop semua operator dari dalam stack
	while(!isstackempty(s)){
		pop(&s, &tmp);
		postfix[idx] = tmp;
		idx++;
	}
	postfix[idx] = '\0';
}

/* Mengembalikan nilai prioritas dari suatu operator*/
int priority(char x){
	switch(x){
		case ')':
			return 0;
		case '(':
			return 0;
		case '-':
			return 1;
		case '+':
			return 1;
		case ':':
			return 2;
		case 'x':
			return 2;
		case 'v':
			return 3;
		case '^':
			return 3;
	}
}

/* Mengembalikan nilai true, jika operator a
memiliki prioritas yang lebih tinggi dibanding operator b*/
boolean cekPriority(char a, char b){
	return (priority(a) >= priority(b));
}

