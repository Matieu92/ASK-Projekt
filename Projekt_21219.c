#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

void gotoxy(short x, short y){
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void intToHex() {
    system("cls");
    int num, k;
    do {
        printf("Podaj liczbe: ");
        k = scanf("%d", &num);
        while ((getchar()) != '\n');    
    } while (k == 0);

    int num2 = num;
    system("cls");

    char hex[9];
    int i = 0;

    while (num != 0) {
        int remainder = num % 16;
        
        if (remainder < 10) {
            hex[i] = remainder + '0';
        } 
        else {
            hex[i] = remainder - 10 + 'A';
        }
        num = num / 16;
        i++;
    }
    printf("Liczba calkowita %d w postaci bajtowej wynosi: ", num2);
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
    if(num2 == 0){
        printf("0");
    }
    getch();
}

void floatToHex() {
    system("cls");
    float num;
    int k;
    do {
        printf("Podaj liczbe: ");
        k = scanf("%f", &num);
        while ((getchar()) != '\n');    
    } while (k == 0);

    float num2 = num;
    system("cls");
    unsigned char *ptr = (unsigned char *)&num;
    printf("Liczba float %f w postaci bajtowej wynosi: ", num2);
    for (int i = sizeof(float) - 1; i >= 0; i--) {
        printf("%02X ", ptr[i]);
    }
    getch();
}

void doubleToHex() {
    system("cls");
    double num;
    int k;
    do {
        printf("Podaj liczbe: ");
        k = scanf("%lf", &num);
        while ((getchar()) != '\n');    
    } while (k == 0);
    
    double num2 = num;
    system("cls");
    unsigned char *ptr = (unsigned char *)&num;
    printf("Liczba double %lf w postaci bajtowej wynosi: ", num2);
    for (int i = sizeof(double) - 1; i >= 0; i--) {
        printf("%02X ", ptr[i]);
    }
    getch();
}

void bajtowa(){
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
        intToHex();
        break;
        case '2':
        floatToHex();
        break;
        case '3':
        doubleToHex();
        break;
        case '4':
        return;
        break;
        case 27:
        return;
        break;
    }
}

void intToBinary() {
    system("cls");
    int num, k;
    do {
        printf("Podaj liczbe: ");
        k = scanf("%d", &num);
        while ((getchar()) != '\n');    
    } while (k == 0);

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
    int k;
    do {
        printf("Podaj liczbe: ");
        k = scanf("%f", &num);
        while ((getchar()) != '\n');    
    } while (k == 0);

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
    int k;
    do {
        printf("Podaj liczbe: ");
        k = scanf("%lf", &num);
        while ((getchar()) != '\n');    
    } while (k == 0);

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

void instrukcjaOdejmowaniaU2() {
    system("cls");
    printf("ZASADA:\n");
    printf("Odejmowanie w U2 to inaczej DODANIE liczby przeciwnej (w reprezentacji U2).\n\n");

    printf("KROKI:\n");
    printf("1. ZAMIANA LICZBY ODEJMOWANEJ NA U2:\n");
    printf("   a) Jesli liczba jest DODATNIA:\n");
    printf("      - Zapisz jej reprezentacje binarna i uzupelnij zerami z lewej strony do wymaganej liczby bitow.\n");
    printf("   b) Jesli liczba jest UJEMNA:\n");
    printf("      - Zapisz binarnie jej wartosc bezwzgledna. ZAMIEN bity z 0 na 1, a 1 na 0. Dodaj 1 do wyniku.\n\n");

    printf("2. DODAWANIE BITOW i IGNOROWANIE PRZENIESIENIA:\n");
    printf("   Nalezy dodac odjemna i odjemnik binarnie (0 + 0 = 0, 0 + 1 = 1, 1 + 1 = 0 z jedynka do przodu).\n");
    printf("   Jesli wystapi przeniesienie poza bit znaku, to nalezy to zignorowac.\n");

    printf("\nPRZYKLAD 1: 5 - 3\n");
    printf("   1. Liczba 5: 0101(2), liczba 3: 0011(2)\n");
    printf("   2. Liczba -3 w U2:\n");
    printf("      - Liczba 3: 0011(2)\n");
    printf("      - Zamiana bitow: 1100(2)\n");
    printf("      - Dodanie 1 do wyniku: 1101(2)\n");
    printf("   3. Dodawanie:\n");
    printf("      0101 (5)\n");
    printf("    + 1101 (-3 w U2)\n");
    printf("    ------\n");
    printf("    Zaczynajac od prawej strony:\n");    
    printf("    1 + 1 = 0 i jeden dalej, nastepnie 0 + 0 + jeden = 1. Trzecia kolumna: 1 + 1 = 0 i jeden dalej,\n");    
    printf("    nastepnie 0 + 1 + jeden = 0 i jeden dalej. Przepisujemy jedynke ktora przenieslismy\n");   
    printf("    i zauwazamy ze z 4 bitow zrobilo nam sie 5. Wystapilo przepelnienie.\n\n");   
    printf("   4. Wynik: 10010 (Ignorujemy przeniesienie) -> 0010(2) = 2(10)");
    getch();
}

void instrukcjaKonwersjiDecNaFloat() {
    system("cls");
    printf("KONWERSJA LICZBY DZIESIETNEJ NA FORMAT FLOAT WEDLUG IEEE 754 \n");
    printf("----------------------------------------------------------- \n");

    printf("\n1. PODZIAL LICZBY NA CZESC CALKOWITA I ULAMKOWA:\n");
    printf("   Na poczatku nalezy oddzielic czesc calkowita od tej ulamkowej.");
    printf("\n   Np. dla 14.125: 14 i 0.125 \n\n");

    printf("2. KONWERSJA CZESCI CALKOWITEJ NA BINARNA:\n");
    printf("   Dziel czesc calkowita przez 2 i zapisuj reszty.\n");
    printf("   Odczyt reszty od dolu do gory.\n");
    printf("   Przyklad dla 14:\n");
    printf("   14 / 2 = 7, reszty 0\n");
    printf("   7 / 2 = 3, reszty 1\n");
    printf("   3 / 2 = 1, reszty 1\n");
    printf("   1 / 2 = 0, reszty 1\n");
    printf("   14(10) = 1110(2)\n\n");

    printf("3. KONWERSJA CZESCI ULAMKOWEJ NA BINARNA:\n");
    printf("   Nalezy mnozyc czesc ulamkowa przez 2.\n");
    printf("   Jezeli wynik wychodzi >= 1, zapisz 1 i odejmij 1 od wyniku.\n");
    printf("   Jezeli wynik < 1, zapisz 0 i pomnoz wynik przez 2 dopoki >= 1.\n");
    printf("   Powtarzaj mnozenie i odejmowanie, dopoki nie otrzymasz liczby 0\n");  
    printf("   Wynik zapisujemy od gory do dolu.\n");   
    printf("   Przyklad dla 0.125:\n");
    printf("   0.125 * 2 = 0.250 (0)\n");
    printf("   0.250 * 2 = 0.5 (0)\n");
    printf("   0.5 * 2 = 1.0 (1), 1.0 - 1 = 0.0\n");
    printf("   0.125(10) = 0.001(2)\n\n");
    printf("Nacisnij dowolny klawisz, aby przejsc dalej.");
    getch();

    system("cls");
    printf("KONWERSJA LICZBY DZIESIETNEJ NA FORMAT FLOAT WEDLUG IEEE 754 \n");
    printf("----------------------------------------------------------- \n");

    printf("\n4. POLACZENIE CZESCI CALKOWITEJ I ULAMKOWEJ:\n");
    printf("   Teraz laczymy wyniki obu konwersji: 1110.001(2)\n\n");

    printf("5. NORMALIZACJA:\n");
    printf("   Przesuwamy przecinek, aby stal po tylko jednej cyfrze.\n");
    printf("   Liczba przesuniec to nasz wykladnik.\n");
    printf("   Zapisujemy w formie: liczba * 2 do potegi wykladnik.\n");   
    printf("   1110.001(2) = 1.110001(2) * 2^3\n\n");

    printf("6. OBLICZENIE CECHY (WYKLADNIK Z PRZESUNIECIEM):\n"); 
    printf("   Dodaj liczbe 127 (przesuniecie - bias) do wykladnika.\n");
    printf("   Po dodaniu otrzymujemy exponent, nalezy przeliczyc na bin jak wyzej.\n");
    printf("   3 + 127 = 130 = 10000010(2)\n\n");

    printf("7. ZAPIS W FORMACIE IEEE 754 (POJEDYNCZA PRECYZJA - FLOAT):\n");
    printf("   Liczba w tym formacie wyglada tak: \n");    
    printf("   Bit znaku (1 bit): 0 (dla dodatnich), 1 (dla ujemnych)\n");
    printf("   Cecha (8 bitow): Wykladnik z przesunieciem\n");
    printf("   Mantysa (23 bity): Czesc ulamkowa po normalizacji z punktu 5\n");
    printf("   Dla 14.125:\n");
    printf("   Znak zgodnie z zasada: 0\n");
    printf("   Exponent z punktu 6: 10000010\n");
    printf("   Mantysa: 110001 (przepisane z 6) i reszte uzupelniamy zerami do 23 bitow\n");
    printf("   Ostateczny zapis: 0 10000010 11000100000000000000000\n\n");
    getch();
}

void instrukcjaKonwersjiFloatNaDec() {
    system("cls");
    printf("KONWERSJA FORMATU FLOAT NA LICZBE DZIESIETNA WEDLUG IEE 754\n");
    printf("-----------------------------------------------------------\n");

    printf("Przyklad dla: 0(ZNAK) 10000010(CECHA) 10001100000000000000000(MANTYSA):\n\n");
    printf("1. ODCZYT BITU ZNAKU:\n");
    printf("   Pierwszy bit (0 - dodatnia, 1 - ujemna).\n\n");

    printf("2. OBLICZENIE CECHY (WYKLADNIKA Z PRZESUNIECIEM):\n");
    printf("   Nalezy przeliczyc wykladnik binarny na dziesietny.\n");
    printf("   Mnoz przez potegi dwojki, tam gdzie cyfra 1. Zacznij od prawej: 2^0 do 2^7.\n");
    printf("   Dodawaj kolejno uzyskane wartosci.\n");
    printf("   Exponent: 10000010(2) = 1 * 2^1 + 1 * 2^7 = 130(10)\n");
    printf("   Odejmij bias (127 dla float).\n");
    printf("   Wykladnik bez przesuniecia: 130 - 127 = 3\n\n");

    printf("3. ODCZYT MANTYSY:\n");
    printf("   Dodaj wiodaca jedynke do mantysy. Nie przejmujemy sie koncowymi zerami.\n");
    printf("   Zgodnie z przykladem: 0.100011 + 1 = 1.100011(2)\n\n");

    printf("4. OBLICZENIE WARTOSCI DZIESIETNEJ:\n");
    printf("   Pomnoz mantyse przez 2 do potegi wykladnik (przesun przecinek o wartosc wykladnika).\n");
    printf("   1.100011(2) * 2^3 = 1100.011(2)\n\n");

    printf("5. KONWERSJA BINARNEJ LICZBY Z PRZECINKIEM NA DZIESIETNA:\n");
    printf("   Czesc calkowita mnoz przez potegi dwojki, tam gdzie cyfra to 1. Zacznij z prawej od 2^0 do 2^7.\n");
    printf("   Czesc ulamkowa mnoz przez potegi dwojki, zaczynajac z lewej strony od 2^-1.\n");   
    printf("   Czesc calkowita: 1100(2) = 1 * 2^2 + 1 * 2^3 = 12(10)\n");
    printf("   Czesc ulamkowa: 0.011(2) = 0 * 2^-1 + 1 * 2^-2 + 1 * 2^-3 = 0 + 0.25 + 0.125 = 0.375(10)\n");
    printf("   Wynik: 1100.011(2) = 12.375(10)\n");
    getch();
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
            instrukcjaOdejmowaniaU2();
            break;
            case '4':
            instrukcjaKonwersjiDecNaFloat();
            break;
            case '5':
            instrukcjaKonwersjiFloatNaDec();
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

