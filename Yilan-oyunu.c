#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOYUT 10
#define MAX 100

int main() {
    int x[MAX], y[MAX];
    int uzunluk = 3;
    int yemX, yemY;
    int puan = 0;
    char yon = 'D';

    srand(time(NULL));

    // Baslangic yilan
    for (int i = 0; i < uzunluk; i++) {
        x[i] = 5 - i;
        y[i] = 5;
    }

    yemX = rand() % BOYUT;
    yemY = rand() % BOYUT;

    while (1) {
        system("clear"); // Android'de calismayabilir

        // Oyun alani
        for (int i = 0; i < BOYUT; i++) {
            for (int j = 0; j < BOYUT; j++) {
                int yazildi = 0;

                // Yilan ciz
                for (int k = 0; k < uzunluk; k++) {
                    if (x[k] == j && y[k] == i) {
                        printf("O ");
                        yazildi = 1;
                        break;
                    }
                }

                // Yem
                if (!yazildi && j == yemX && i == yemY) {
                    printf("X ");
                    yazildi = 1;
                }

                if (!yazildi)
                    printf(". ");
            }
            printf("\n");
        }

        printf("Puan: %d\n", puan);
        printf("Yon (W A S D): ");
        scanf(" %c", &yon);

        // Kuyruk takip etsin
        for (int i = uzunluk - 1; i > 0; i--) {
            x[i] = x[i - 1];
            y[i] = y[i - 1];
        }

        // Kafa hareketi
        if (yon == 'W' || yon == 'w') y[0]--;
        else if (yon == 'S' || yon == 's') y[0]++;
        else if (yon == 'A' || yon == 'a') x[0]--;
        else if (yon == 'D' || yon == 'd') x[0]++;

        // Duvar carpmasi
        if (x[0] < 0 || x[0] >= BOYUT || y[0] < 0 || y[0] >= BOYUT) {
            printf(" Duvara carptin! Oyun Bitti!\n");
            break;
        }

        // Kendine carpma
        for (int i = 1; i < uzunluk; i++) {
            if (x[0] == x[i] && y[0] == y[i]) {
                printf(" Kendine carptin! Oyun Bitti!\n");
                return 0;
            }
        }

        // Yem yeme
        if (x[0] == yemX && y[0] == yemY) {
            puan++;
            uzunluk++;
            yemX = rand() % BOYUT;
            yemY = rand() % BOYUT;
        }
    }

    return 0;
}