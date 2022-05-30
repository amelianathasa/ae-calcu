/*
 *	File          : pajak.c
 *	Deskripsi     : Body file untuk perhitungan pajak 
 */

#include "pajak.h"

/**
 * Modul untuk menampilkan tampilan kalkulator pajak
*/
void calcuPajak(Pajak data){
    
	// Algoritma
	system("cls");
	printf("                   Kalkulator Pajak\n");
	printf("Masukkan Penghasilan Anda (sebulan): Rp. ");
	scanf("%d", &data.gaji);
    printf("\nMasukkan Status Anda (1. Menikah/ 2. Lajang) : ");
	scanf("%d", &data.status);
    if(data.status == 1){
        printf("Apakah Pasangan anda Berpenghasilan ?(y/n) ");
        scanf("%s",&data.berpenghasilan);
        if(data.berpenghasilan == 'y'){
            printf("Input Penghasilan Pasangan Anda (sebulan): Rp. ");
            scanf("%d",&data.gajiPasangan);
        }
    }
    printf("Masukkan Jumlah Anak Sedarah yang Dimiliki (Maksimal 3 Anak, Jika tidak ada input 0) : ");
	scanf("%d", &data.jml_anak);
}

double totalGajiPertahun(double gaji){
	double totalGaji; 
	totalGaji =  gaji*12; 
	return totalGaji; 
}

/* Digunakan untuk menghitung jumlah PTKP */
double hitungPTKP(Pajak data){
    double totalGaji, totalGajiPasangan, PTKP;

    totalGaji = totalGajiPertahun(data.gaji);
    totalGajiPasangan = totalGajiPertahun(data.gajiPasangan);
	 
    PTKP = 54000000;
    if(data.status == 1 && data.berpenghasilan == 'n'){
        PTKP+=4500000;
    }else if(data.status == 1 && data.berpenghasilan == 'y'){
        if(totalGajiPasangan >= 54000000){
            PTKP+=54000000;
        }else{
            PTKP+=45000000;
        }
    }
    
    if(data.jml_anak == 1){
        PTKP+=4500000;
    }else if(data.jml_anak == 2){
        PTKP+=9000000;
    }else if(data.jml_anak == 3){
        PTKP+=13500000;
    }
    return PTKP;
}

double hitungPKP(Pajak data){
    double PKP, PTKP; 

    PTKP = hitungPTKP(data);
    PKP = totalGajiPertahun(data.gaji) - hitungPTKP(data); 

    return PKP; 
}

/* Digunakan untuk menghitung jumlah PPh */
double hitungPPh(Pajak data){
    double PPH, dataPKP; 
    dataPKP = hitungPKP(data);

    if (dataPKP < 50000000)
    {
        PPH = dataPKP*5/100;
    }else if (dataPKP >= 50000000 && dataPKP <= 250000000)
    {
        PPH = dataPKP*15/100;
    }else if (dataPKP >=250000000 && dataPKP <= 500000000)
    {
        PPH = dataPKP*25/100;
    }else{
        PPH = dataPKP*50/100;
    }     
    return PPH; 
}

