#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(short x, short y){
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
} 

void menu() {
}

int main() {
    menu();
    return 0;
}

