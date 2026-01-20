#include <stdio.h>

int main() {
    int min = 1, max = 100;
    int tahmin;
    char cevap;
    int deneme = 0;

    printf("1 ile 100 arasinda bir sayi tut.\n");
    printf("Cevaplar:\n");
    printf("B = Daha BUYUK\n");
    printf("K = Daha KUCUK\n");
    printf("D = DOGRU\n\n");

    while (1) {
        tahmin = (min + max) / 2;
        deneme++;

        printf("Tahminim: %d\n", tahmin);
        printf("Cevabin (B/K/D): ");
        scanf(" %c", &cevap);

        if (cevap == 'D' || cevap == 'd') {
            printf("\n Sayini %d denemede buldum!\n", deneme);
            break;
        }
        else if (cevap == 'B' || cevap == 'b') {
            min = tahmin + 1;
        }
        else if (cevap == 'K' || cevap == 'k') {
            max = tahmin - 1;
        }
        else {
            printf("Gecersiz cevap! Lutfen B, K veya D gir.\n");
            deneme--; // hatali girdi denemeyi saymasin
        }

        if (min > max) {
            printf("\n Hile yaptin! Tutarsiz cevaplar verdin.\n");
            break;
        }
    }

    return 0;
}