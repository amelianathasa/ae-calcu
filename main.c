/*
 *	File          : main.c
 *	Deskripsi     : Main driver  
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "calculator.h"

/* Untuk menampilkan main menu */
int main(int argc, char *argv[]) {
	int pilihan;
	do{
	system("cls");
	menu();
	scanf("%d",&pilihan);
	switch(pilihan) {	
		case 1 :
		    mulai();
			break;
		case 2 : 
			bantuan();
			break;
		case 3 :
			credits();
			break;
		case 4 :
			system("cls");
			gotoxy(35,14); puts("Terima kasih!");
			return 0;
		default :
			puts("\nPilihan yang dimasukkan salah!");
			system("pause");
		}
	}while(pilihan != 4);
}

