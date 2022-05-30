/*
 *	File          : calculator.c
 *	Deskripsi     : Body file untuk calculator 
 */
 
 #include "calculator.h"

/* MODUL USER INTERFACE */
void menu(){
	printf("             ae - calcu\n");
	printf(" _________________________________ \n");
	printf("|                                 |\n");
	printf("|              Mulai              |\n");
	printf("|             Bantuan             |\n");
	printf("|             Credits             |\n");
	printf("|              Exit               |\n");
	printf("|                                 |\n");
	printf("|_________________________________|\n");
	//printf("+---------------------------------+\n");
	printf("\nMasukkan Pilihan Anda (1-4) ");
}

// Modul untuk menentukan posisi output
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/**
 * Modul untuk menampilkan tampilan menu
*/
void mulai(){
	/* Kamus Data */
	int pilihanCalcu;
	Pajak data;
	
	system("cls");
	printf("             ae - calcu\n");
	printf(" _________________________________\n");
	printf("|               MENU              |\n");
	printf("|_________________________________|\n");
	printf("|                                 |\n");
	printf("|         Kalkulator Dasar        |\n");
	printf("|         Kalkulator Pajak        |\n");
	printf("|             Kembali             |\n");
	printf("|                                 |\n");
	printf("+---------------------------------+\n");
	printf("\nMasukkan Pilihan Anda (1-3) ");
	scanf("%d", &pilihanCalcu);
	switch (pilihanCalcu)
	{
	case 1:
		calcuDasar();
		break;
	case 2:
		calcuPajak(data);
		break;
	case 3:
		menu();
		break;
	default:
		printf("Inputan yang kamu masukkan tidak valid!");
		system("pause");
		mulai();
	}
}

/*******************************************************************/
/*  OPERASI CALCULATOR DASAR                                       */
/*******************************************************************/

/**
 * Modul untuk menampilkan tampilan menu kalkulator
*/
void calcuDasar(){
	// Kamus Data
	String input, postfix;
	
	// Algoritma
	system("cls");
	printf("                   Kalkulator Dasar\n");
	
	printf("\n\n\t\t様様様様様様様様様様様様様様様様様様様様様様様");
	printf("\n\t\t                                             ");
	printf("\n\t\t                                             ");
	printf("\n\t\t                                             ");
	printf("\n\t\t                                             ");
	printf("\n\t\t様様様様様様様様様様様様様様様様様様様様様様様");
	printf("\n\n\t\t    \xda\xc4\xc4\xc4\xbf   \xda\xc4\xc4\xc4\xbf   \xda\xc4\xc4\xc4\xbf   \xda\xc4\xc4\xc4\xbf   \xda\xc4\xc4\xc4\xbf");
	printf("\n\t\t    \xb3 1 \xb3   \xb3 2 \xb3   \xb3 3 \xb3   \xb3 + \xb3   \xb3 - \xb3");
	printf("\n\t\t    \xc0\xc4\xc4\xc4\xd9   \xc0\xc4\xc4\xc4\xd9   \xc0\xc4\xc4\xc4\xd9   \xc0\xc4\xc4\xc4\xd9   \xc0\xc4\xc4\xc4\xd9");
	printf("\n\n\t\t    \xda\xc4\xc4\xc4\xbf   \xda\xc4\xc4\xc4\xbf   \xda\xc4\xc4\xc4\xbf   \xda\xc4\xc4\xc4\xbf   \xda\xc4\xc4\xc4\xbf");
	printf("\n\t\t    \xb3 4 \xb3   \xb3 5 \xb3   \xb3 6 \xb3   \xb3 x \xb3   \xb3 / \xb3");
	printf("\n\t\t    \xc0\xc4\xc4\xc4\xd9   \xc0\xc4\xc4\xc4\xd9   \xc0\xc4\xc4\xc4\xd9   \xc0\xc4\xc4\xc4\xd9   \xc0\xc4\xc4\xc4\xd9");
	printf("\n\n\t\t    \xda\xc4\xc4\xc4\xbf   \xda\xc4\xc4\xc4\xbf   \xda\xc4\xc4\xc4\xbf   \xda\xc4\xc4\xc4\xbf   \xda\xc4\xc4\xc4\xbf");
	printf("\n\t\t    \xb3 7 \xb3   \xb3 8 \xb3   \xb3 9 \xb3   \xb3 ^ \xb3   \xb3 v \xb3");
	printf("\n\t\t    \xc0\xc4\xc4\xc4\xd9   \xc0\xc4\xc4\xc4\xd9   \xc0\xc4\xc4\xc4\xd9   \xc0\xc4\xc4\xc4\xd9   \xc0\xc4\xc4\xc4\xd9");
	printf("\n\n\t\t\t    \xda\xc4\xc4\xc4\xbf\t\t\xda\xc4\xc4\xc4\xbf");
	printf("\n\t\t\t    \xb3 0 \xb3\t\t\xb3 = \xb3");
	printf("\n\t\t\t    \xc0\xc4\xc4\xc4\xd9\t\t\xc0\xc4\xc4\xc4\xd9");
	printf("\n\n\t\t様様様様様様様様様様様様様様様様様様様様様様様");
	
	gotoxy(21, 5);printf("Masukkan operasi matematika: ");
	scanf("%s", &input);
	
	if (cekInput(input) == false) {
		input[0] = '\0'; // Kosongkan string
		system("pause");
		system("cls");
		calcuDasar();
	}
	InfixToPostfix(input, postfix);

}

/* Cek apakah inputan user benar atau tidak */
boolean cekInput(String input){
    int i, length;
    boolean inputTrue = true, nextAngka = true;   // Buat mennetukan inputan selanjutnya harus angka atau bukan
    char tmp;
    length = strlen(input);

    // Cek inputan awal dan akhir tidak boleh operator
    if(cekOperator(input[0]) == true || cekOperator(input[length-1]) == true){
        printf("Inputan tidak sesuai!\n");
        inputTrue = false ;
    }

    // Cek keseluruhan inputan
    for(i=0; i<length; i++){
        if(cekParentheses(input[i]) == true){
            continue;
        }

        if (cekAngka(input[i]) == true)
        {
            nextAngka = false;
            continue;
        }

        // Cek apakah ada operator yang bersebelahan
        if((cekOperator(input[i]) == true) && (nextAngka == false)){
            nextAngka = true;
            continue;
        }else{
        	inputTrue = false;
            printf("Inputan tidak sesuai!\n");
        }
    }
    
    return inputTrue;
}

/* Cek inputan user berupa operator */
boolean cekOperator(char c){
    if(c == '^' || c == 'v' || c == 'x' || c == ':' || c == '+' || c == '-'){
        return true;
    }else{
        return false;
    }
}

/* Cek inputan user berupa angka */
boolean cekAngka(char c){
    if (c >= '0' && c <= '9'){
        return true;
    }else{
        return false;
    }
}

/* Cek inputan user berupa kurung */
boolean cekParentheses(char c){
    if(c == '(' || c == ')'){
        return true;
    }else{
        return false;
    }
}

/**
 * Modul untuk menampilkan tampilan bantuan
*/
void bantuan(){
	char kembali;
	system("cls");
	printf("                     ae - calcu\n");
	printf(" ____________________________________________________\n");
	printf("|                      BANTUAN                       |\n");
	printf("|____________________________________________________|\n");
	printf("|===================== BANTUAN ======================|\n");
	printf("|[1] Gunakan 'Kalkulator Dasar' untuk meghitung      |\n");
	printf("|    ekspresi matematika                             |\n");
	printf("|    Simbol - Simbol yang ada pada kalkulator umum : |\n");
	printf("|    1. 0 - 9 berarti angka dari 0 'nol' sampai 9    |\n");
	printf("|    2. '(' berarti kurung buka                      |\n");
	printf("|    3. ')' berarti kurung tutup                     |\n");
	printf("|    4. '+' berati pertambahan                       |\n");
	printf("|    5. '-' berarti pengurangan                      |\n");
	printf("|    6. 'x' berarti perkalian                        |\n");
	printf("|    7. '/' berarti pembagian                        |\n");
	printf("|    8. '^' berarti pangkat                          |\n");
	printf("|    9. 'v' berarti akar pangkat                     |\n");
	printf("|[2] Gunakan 'Kalkulator Pajak' untuk menghitung     |\n");
	printf("|    pajak penghasilan.                              |\n");
	printf("|    Pengguna diarahkan untuk dapat menginput data : |\n");
	printf("|    1. Gaji Per-tahun                               |\n");
	printf("|    2. Status Perkawinan                            |\n");
	printf("|    3. Jumlah anak sedarah yang dimiliki            |\n");
	printf("+----------------------------------------------------+\n");
	printf("Kembali? (y/n)");
	scanf("%s", &kembali);
	if (kembali == 'y')
	{
		menu();
	}else{
		printf("Inputan tidak valid!");
		system("pause");
		credits();
	}
	
}
/**
 * Modul untuk menampilkan tampilan credits
*/
void credits(){
	char kembali;
	system("cls");
	printf("             ae - calcu\n");
	printf(" _________________________________\n");
	printf("|              CREDITS            |\n");
	printf("|_________________________________|\n");
	printf("|                                 |\n");
	printf("|          Amelia Nathasa         |\n");
	printf("|      Falia Davina Gustaman      |\n");
	printf("|           Nayara Saffa          |\n");
	printf("|                                 |\n");
	printf("| @D4 - Teknik Informatika POLBAN |\n");
	printf("+---------------------------------+\n");
	printf("Kembali? (y/n)");
	scanf("%s", &kembali);
	if (kembali == 'y')
	{
		menu();
	}else{
		printf("Inputan tidak valid!");
		system("pause");
		credits();
	}
}

