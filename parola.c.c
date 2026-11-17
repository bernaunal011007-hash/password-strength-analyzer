#include <stdio.h>
#include <string.h>
#include <ctype.h>
int yaygin_mi(const char *p) {
    const char *liste[] = {"123456", "password", "qwerty", "12345678", "111111", "abc123", "sifre", "parola"};
    int n = sizeof(liste) / sizeof(liste[0]);
    for (int i = 0; i < n; i++) {
        if (strcmp(p, liste[i]) == 0) return 1;
    }
    return 0;
}

int tekrar_var_mi(const char *p) {
    for (int i = 0; p[i] && p[i+1] && p[i+2]; i++) {
        if (p[i] == p[i+1] && p[i] == p[i+2]) return 1;
    }
    return 0;
}

int main(void) {
    char parola[100];
    printf("Parola gir: ");
    scanf("%99s", parola);

    int puan = 0;
    int buyuk = 0, kucuk = 0, rakam = 0, ozel = 0;
    int uzunluk = strlen(parola);

    for (int i = 0; i < uzunluk; i++) {
        if (isupper((unsigned char)parola[i])) buyuk = 1;
        else if (islower((unsigned char)parola[i])) kucuk = 1;
        else if (isdigit((unsigned char)parola[i])) rakam = 1;
        else ozel = 1;
    }

    if (uzunluk >= 8) puan++;
    if (uzunluk >= 12) puan++;
    puan += buyuk + kucuk + rakam + ozel;
    if (tekrar_var_mi(parola)) puan--;
    if (yaygin_mi(parola)) puan = 0;

    printf("\nPuan: %d/6\n", puan);
    if (puan <= 2) printf("Sonuc: ZAYIF\n");
    else if (puan <= 4) printf("Sonuc: ORTA\n");
    else printf("Sonuc: GUCLU\n");

    if (!buyuk) printf("- Buyuk harf ekle\n");
    if (!kucuk) printf("- Kucuk harf ekle\n");
    if (!rakam) printf("- Rakam ekle\n");
    if (!ozel) printf("- Ozel karakter ekle\n");
    if (uzunluk < 12) printf("- Daha uzun yap (en az 12)\n");

    return 0;
}