#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(short x, short y){
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
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

