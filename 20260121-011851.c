#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tahmin, sayi;
    int deneme;
    char devam;

    srand(time(NULL));  // Random sayi

    do {
        sayi = rand() % 100 + 1; // 1-100
        deneme = 0;

        printf("\n1 ile 100 arasinda bir sayi tuttum!\n");

        while (1) {
            printf("Tahminini gir: ");

            if (scanf("%d", &tahmin) != 1) {
                printf("Lutfen gecerli bir sayi gir!\n");
                return 1;
            }

            deneme++;

            if (tahmin > sayi) {
                printf("Daha KUCUK!\n");
            }
            else if (tahmin < sayi) {
                printf("Daha BUYUK!\n");
            }
            else {
                printf("TEBRIKLER!  %d denemede bildin.\n", deneme);
                break;
            }
        }

        printf("Tekrar oynamak ister misin? (E/H): ");
        scanf(" %c", &devam); 

    } while (devam == 'E' || devam == 'e');

    printf("Oyun bitti. Gorusuruz \n");

    return 0;
}