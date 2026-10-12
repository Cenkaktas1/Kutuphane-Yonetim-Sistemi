#include "Fonksiyon.h"
#include "BenimFonksiyonlarim.h"

char isim[20];
char soyisim[20];
char sifre[15];

FILE* kitaplar;
FILE* giris;
FILE* gecici;
FILE* movies;
FILE* series;

kontrol test;
ekle kitap;
ekle2 film;
kayitKontrol kayit;

int main()
{
    char input[20];
    int secim = 1;
    system("color 6");

    GirisKontrol(test);

    while(secim != 0){
        printf("\n  ============ ANA MENU =============\n\n");
        printf("=> 1) FILMLERIM\n");
        printf("=> 2) DIZILERIM\n");
        printf("=> 3) KITAPLARIM\n");
        printf("=> 0) Cikis\n\n");

        printf("Yapmak istediginiz islemi tuslayiniz: ");
        scanf("%s",input);
        secim = SecimKontrol(input, 0, 3);

        switch(secim){
            case 1:
                while(secim != 4){
                    printf("\n  =========== FILM ARSIVI ===========\n\n");
                    printf("Kullanici: %s %s\n\n",isim,soyisim);
                    printf("=> 1) Yeni Film Ekle\n");
                    printf("=> 2) Film Sil\n");
                    printf("=> 3) Izledigim Filmleri Goruntule\n");
                    printf("=> 4) Ana Menu\n\n");

                    printf("Yapmak istediginiz islemi tuslayiniz: ");
                    scanf("%s",input);
                    secim = SecimKontrol(input, 1, 4);
                        switch(secim){
                            case 1:
                                FilmEkle();
                                break;
                            case 2:
                                FilmListe();
                                FilmSil();
                                break;
                            case 3:
                                FilmListe();
                                break;
                            }
                        }
                    break;
                case 2:
                    while(secim != 4){
                        printf("\n  =========== DIZI ARSIVI ===========\n\n");
                        printf("Kullanici: %s %s\n\n",isim,soyisim);
                        printf("=> 1) Yeni Dizi Ekle\n");
                        printf("=> 2) Dizi Sil\n");
                        printf("=> 3) Izledigim Dizileri Goruntule\n");
                        printf("=> 4) Ana Menu\n\n");

                        printf("Yapmak istediginiz islemi tuslayiniz: ");
                        scanf("%s",input);
                        secim = SecimKontrol(input, 1, 4);

                        switch(secim){
                            case 1:
                                DiziEkle();
                                break;
                            case 2:
                                DiziListe();
                                DiziSil();
                                break;
                            case 3:
                                DiziListe();
                                break;
                        }
                    }
                    break;
                case 3:
                    while(secim != 4){
                        printf("\n  =========== KUTUPHANEM ============\n");
                        printf("\nKullanici: %s %s\n\n",isim,soyisim);
                        printf("=> 1) Yeni Kitap Ekle\n");
                        printf("=> 2) Kitap Sil\n");
                        printf("=> 3) Okudugum Kitaplari Goruntule\n");
                        printf("=> 4) Ana Menu\n\n");

                        printf("Yapmak istediginiz islemi tuslayiniz: ");
                        scanf("%s",input);
                        secim = SecimKontrol(input, 1, 4);

                        switch(secim){
                        case 1:
                                printf("\n=========================================\n\n");
                                KitapEkle(kitap);
                                break;
                            case 2:
                                KitapListe();
                                KitapSil();
                                break;
                            case 3:
                                KitapListe();
                                printf("\n");
                                break;
                        }
                    }

                    break;
            }
    }
    return 0;
}
