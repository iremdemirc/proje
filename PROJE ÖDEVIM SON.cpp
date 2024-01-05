#include <stdio.h>


struct Hesap {
    int hesapNo;
    char isim[50];
    double bakiye;
};


void hesapOlustur(struct Hesap hesaplar[], int *hesapSayisi);
void hesapListele(struct Hesap hesaplar[], int hesapSayisi);
void paraYatir(struct Hesap hesaplar[], int hesapSayisi, int hesapNo, double miktar);
void paraCek(struct Hesap hesaplar[], int hesapSayisi, int hesapNo, double miktar);

int main() {
    struct Hesap hesaplar[100]; 
    int hesapSayisi = 0;
    int secim;

    do {
        printf("\n1. Hesap Olustur\n");
        printf("2. Hesap Listele\n");
        printf("3. Para Yatir\n");
        printf("4. Para Cek\n");
        printf("0. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                hesapOlustur(hesaplar, &hesapSayisi);
                break;
            case 2:
                hesapListele(hesaplar, hesapSayisi);
                break;
            case 3:
                {
                    int hesapNo;
                    double miktar;
                    printf("Hesap No: ");
                    scanf("%d", &hesapNo);
                    printf("Yatirilacak Miktar: ");
                    scanf("%lf", &miktar);
                    paraYatir(hesaplar, hesapSayisi, hesapNo, miktar);
                }
                break;
            case 4:
                {
                    int hesapNo;
                    double miktar;
                    printf("Hesap No: ");
                    scanf("%d", &hesapNo);
                    printf("Cekilecek Miktar: ");
                    scanf("%lf", &miktar);
                    paraCek(hesaplar, hesapSayisi, hesapNo, miktar);
                }
                break;
            case 0:
                printf("Programdan cikiliyor...\n");
                break;
            default:
                printf("Gecersiz secim. Tekrar deneyin.\n");
        }
    } while (secim != 0);

    return 0;
}

void hesapOlustur(struct Hesap hesaplar[], int *hesapSayisi) {
    if (*hesapSayisi < 100) {
        printf("Isim: ");
        scanf("%s", hesaplar[*hesapSayisi].isim);
        hesaplar[*hesapSayisi].hesapNo = *hesapSayisi + 1;
        hesaplar[*hesapSayisi].bakiye = 0.0;
        (*hesapSayisi)++;
        printf("Hesap olusturuldu.\n");
    } else {
        printf("Maximum hesap sayisina ulasildi.\n");
    }
}

void hesapListele(struct Hesap hesaplar[], int hesapSayisi) {
    printf("\nHesap Listesi:\n");
    printf("-------------------------------------------------\n");
    printf("| Hesap No | Isim          | Bakiye           |\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < hesapSayisi; i++) {
        printf("| %-8d | %-13s | %-16.2f |\n", hesaplar[i].hesapNo, hesaplar[i].isim, hesaplar[i].bakiye);
    }

    printf("-------------------------------------------------\n");
}

void paraYatir(struct Hesap hesaplar[], int hesapSayisi, int hesapNo, double miktar) {
    for (int i = 0; i < hesapSayisi; i++) {
        if (hesaplar[i].hesapNo == hesapNo) {
            hesaplar[i].bakiye += miktar;
            printf("%.2f TL yatirildi. Yeni bakiye: %.2f TL\n", miktar, hesaplar[i].bakiye);
            return;
        }
    }

    printf("Hesap bulunamadi.\n");
}

void paraCek(struct Hesap hesaplar[], int hesapSayisi, int hesapNo, double miktar) {
    for (int i = 0; i < hesapSayisi; i++) {
        if (hesaplar[i].hesapNo == hesapNo) {
            if (hesaplar[i].bakiye >= miktar) {
                hesaplar[i].bakiye -= miktar;
                printf("%.2f TL cekildi. Yeni bakiye: %.2f TL\n", miktar, hesaplar[i].bakiye);
            } else {
                printf("Yetersiz bakiye. Islem iptal edildi.\n");
            }
            return;
        }
    }

    printf("Hesap bulunamadi.\n");
}
