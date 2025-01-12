#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

void gotoxy(short x, short y){
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void bajtowa(){
    char ch;
    do {
        system("cls");
        gotoxy(45, 10); printf(" ======== Typ danych ========");
        gotoxy(45, 11); printf(" ");
        gotoxy(45, 12); printf(" 1. INT");
        gotoxy(45, 13); printf(" 2. FLOAT");
        gotoxy(45, 14); printf(" 3. DOUBLE");
        gotoxy(45, 15); printf(" ");
        gotoxy(45, 16); printf(" 4. Powrot");
        gotoxy(45, 17); printf(" ============================");
        gotoxy(45, 18); printf(" Wybierz opcje: ");
        fflush(stdin);
        do {
            ch = getch();
        } while (ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != 27);
        
        switch (ch) {
            case '1':
            break;
            case '2':
            break;
            case '3':
            break;
            case '4':
            return;
            break;
            case 27:
            return;
            break;
        }
    } while (1);
}

void intToBinary() {
    system("cls");
    int num;
    printf("Podaj liczbe: "); scanf("%d", &num);
    int num2 = num;
    system("cls");

    printf("Liczba calkowita %d w systemie dwojkowym wynosi: ", num2);
    for (int i = 31; i >= 0; i--) {
        if (num >> i) printf("%d", (num >> i) & 1); 
    }
    if(num == 0){
        printf("0");
    }
    getch();
}

void floatToBinary() {
    system("cls");
    float num;
    printf("Podaj liczbe: "); scanf("%f", &num);
    float integer2;
    float fractional;
    fractional = modff(num, &integer2);
    int integer = (int)integer2;
    system("cls");

    printf("Liczba float %lf w systemie dwojkowym wynosi: ", num);

    for (int i = 31; i >= 0; i--) {
        if (integer >> i) printf("%d", (integer >> i) & 1); 
    }
    if(integer == 0){
        printf("0");
    }

    printf(".");

    int counter = 0;
    double power = 0.5f;
    while (fractional > 0 && counter < 23) { 
        if (fractional >= power) {
            printf("1");
            fractional -= power;

        } else {
            printf("0");
        }
        power /= 2;
        counter++;
    }

    if (fractional == 0) {
        printf("0");
    }
    getch();
}

void doubleToBinary() {
    system("cls");
    double num;
    printf("Podaj liczbe: "); scanf("%lf", &num);
    double integer2;
    double fractional;
    fractional = modf(num, &integer2);
    int integer = (int)integer2;
    system("cls");

    printf("Liczba double %lf w systemie dwojkowym wynosi: ", num);

    for (int i = 31; i >= 0; i--) {
        if (integer >> i) printf("%d", (integer >> i) & 1); 
    }
    if(integer == 0){
        printf("0");
    }

    printf(".");

    int counter = 0;
    double power = 0.5;
    while (fractional > 0 && counter < 32) { 
        if (fractional >= power) {
            printf("1");
            fractional -= power;

        } else {
            printf("0");
        }
        power /= 2;
        counter++;
    }

    if (fractional == 0) {
        printf("0");
    }
    getch();
}


void binarna(){
    char ch;
    system("cls");
    gotoxy(45, 10); printf(" ======== Typ danych ========");
    gotoxy(45, 11); printf(" ");
    gotoxy(45, 12); printf(" 1. INT");
    gotoxy(45, 13); printf(" 2. FLOAT");
    gotoxy(45, 14); printf(" 3. DOUBLE");
    gotoxy(45, 15); printf(" ");
    gotoxy(45, 16); printf(" 4. Powrot");
    gotoxy(45, 17); printf(" ============================");
    gotoxy(45, 18); printf(" Wybierz opcje: ");
    fflush(stdin);
    do {
        ch = getch();
    } while (ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != 27);
        
    switch (ch) {
        case '1':
        intToBinary();
        break;
        case '2':
        floatToBinary();
        break;
        case '3':
        doubleToBinary();
        break;
        case '4':
        return;
        break;
        case 27:
        return;
        break;
    }
}

void menu() {
    char ch;
    do {
        system("cls");
        gotoxy(45, 10); printf(" ===== Projekt ASK 21219 =====");
        gotoxy(45, 11); printf(" ");
        gotoxy(45, 12); printf(" 1. Drukuj postac bajtowa");
        gotoxy(45, 13); printf(" 2. Drukuj postac binarna");
        gotoxy(45, 14); printf(" 3. Jak odejmowac w U2");
        gotoxy(45, 15); printf(" 4. Konwersja DEC -> FLOAT");
        gotoxy(45, 16); printf(" 5. Konwersja FLOAT -> DEC");
        gotoxy(45, 17); printf(" ");
        gotoxy(45, 18); printf(" 6. Koniec programu");
        gotoxy(45, 19); printf(" =============================");
        gotoxy(45, 20); printf(" Wybierz opcje: ");
        fflush(stdin);
        do {
            ch = getch();
        } while (ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != '5' && ch != '6' && ch != 27);
        
        switch (ch) {
            case '1':
            bajtowa();
            break;
            case '2':
            binarna();
            break;
            case '3':
            break;
            case '4':
            break;
            case '5':
            break;
            case '6':
            exit(0);
            case 27:
            exit(0);
        }
    } while (1);
}

int main() {
    menu();
    return 0;
}

