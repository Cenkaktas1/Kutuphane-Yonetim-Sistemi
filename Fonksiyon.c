#include "Fonksiyon.h"

int ay_to_int(const char *ay) {
    const char *aylar[] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    for (int i = 0; i < 12; ++i) {
        if (strcmp(ay, aylar[i]) == 0) return i;
    }
    return -1;
}

void GirisKontrol(kontrol test){
    giris = fopen("giris.txt","r");

    printf("\n  ============== GIRIS ==============\n\n");

    while(1){
        printf("   Ad   : ");
        scanf("%s",test.ad);
        printf("   Soyad: ");
        scanf("%s",test.soyad);
        printf("   Sifre: ");
        scanf("%s",test.sifre);

        fscanf(giris, "%s\t%s\t%s", isim, soyisim, sifre);

        if(strcmp(isim, test.ad) != 0){
            printf("   Adinizi yanlis girdiniz, lutfen tekrar deneyiniz!\n\n");
        }
        else if(strcmp(soyisim, test.soyad) != 0){
            printf("   Soyadinizi yanlis girdiniz, lutfen tekrar deneyiniz!\n\n");
        }
        else if(strcmp(sifre, test.sifre) != 0){
            printf("   Sifrenizi yanlis girdiniz, lutfen tekrar deneyiniz!\n\n");
        }
        else{
            printf("   Giris Basarili!\n");
            break;
        }

    }
    //printf("\n  ===================================\n");
    fclose(giris);
}

void KitapEkle(ekle kitap){
    int sayac = 1;
    int girilmis = 0;
    char kitapadi[40];
    char yazaradi[40];
    char zaman[30];

    time(&kitap.sure);

    kitaplar = fopen("kitap.txt","r+");

    while(getchar() != '\n');
    printf("Kitap Adi: ");
    fgets(kitapadi, 40, stdin);

    printf("Yazar Adi: ");
    fgets(yazaradi, 40, stdin);
    yazaradi[strcspn(yazaradi, "\n")] = 0;
    kitapadi[strcspn(kitapadi, "\n")] = 0;

    fseek(kitaplar, 0, SEEK_SET);
    while(fscanf(kitaplar, "%d\t%[^\t]\t%[^\t]\t%[^\n]",&kitap.sira, kitap.ad, kitap.yazar, zaman) != EOF){
        if(strcmp(kitapadi, kitap.ad) == 0){
            girilmis = 1;
        }
        sayac++;
    }
    if(girilmis != 1){
        fseek(kitaplar, 0, SEEK_END);
        fprintf(kitaplar,"%d\t%s\t%s\t%s\n", sayac, kitapadi, yazaradi, ctime(&kitap.sure));
        printf("\nKitap basariyla eklenmistir.\n\n");
        printf("\n  ===================================\n");
    }
    else{
        printf("\nBu kitabi daha once eklediniz!\n");
    }

    fclose(kitaplar);
}

void KitapSil(){
    char zaman[30];
    int numara;
    int i = 0;

    gecici = fopen("gecici.txt","r+");
    if(gecici == NULL)
        gecici = fopen("gecici.txt","w+");

    kitaplar = fopen("kitap.txt","r");

    if(kitaplar == NULL)
        printf("Henuz eklenmis bir kitap bulunmamaktadir.\n");

    else{
        printf("Silmek istediginiz kitabin sira numarasini giriniz: ");
        scanf("%d",&numara);

        fseek(kitaplar, 0, SEEK_SET);
        while(fscanf(kitaplar,"%d\t%[^\t]\t%[^\t]\t%[^\n]", &kitap.sira, kitap.ad, kitap.yazar, zaman) != EOF){
            if(numara != kitap.sira){
                i++;
                fprintf(gecici,"%d\t%s\t%s\t%s\n", i, kitap.ad, kitap.yazar, zaman);
            }
        }
        printf("Silme islemi basariyla gerceklesmistir!\n");
        printf("\n=========================================\n\n");

        fclose(kitaplar);
        fclose(gecici);
        remove("kitap.txt");
        rename("gecici.txt","kitap.txt");
    }
}

void KitapListe(){
    char zaman[30];
    int i = 1;
    kitaplar = fopen("kitap.txt","r+");
    if(kitaplar == NULL)
        printf("Okumus oldugunuz herhangi bir kitap bulunmamaktadir. Bir an once kitap okumaya baslamanizi tavsiye ederiz. :)\n\n");
    else{
        printf("\n\tKitap Adi\t\t\t\t  Yazar Adi\t\t\t\t  Tarih\n");
        printf("====================================================================================================\n");
        fseek(kitaplar, 0, SEEK_SET);
        while(fscanf(kitaplar, "%d\t%[^\t]\t%[^\t]\t%[^\n]",&kitap.sira, kitap.ad, kitap.yazar, zaman) != EOF){
            char gunStr[4], ayStr[4];
            int gun, saat, dakika, saniye, yil;

            sscanf(zaman, "%3s %3s %d %d:%d:%d %d",gunStr, ayStr, &gun, &saat, &dakika, &saniye, &yil);

                struct tm t = {0};
                t.tm_year = yil - 1900;
                t.tm_mon  = ay_to_int(ayStr);
                t.tm_mday = gun;
                t.tm_hour = saat;
                t.tm_min  = dakika;
                t.tm_sec  = saniye;

                kitap.sure = mktime(&t);

                struct tm* x = localtime(&kitap.sure);

                printf("=> %d) %s",kitap.sira,kitap.ad);
                i++;

                    for(int i=0; i<40-strlen(kitap.ad); i++){
                        printf(" ");
                    }


                printf("\t%s",kitap.yazar);

                    for(int i=0; i<40-strlen(kitap.yazar); i++){
                        printf(" ");
                    }


                if(x->tm_mday < 10)
                    printf("0%d:", x->tm_mday);
                else
                    printf("%d:", x->tm_mday);

                if(x->tm_mon+1 < 10)
                    printf("0%d:", x->tm_mon+1);
                else
                    printf("%d:", x->tm_mon+1);

                printf("%d\n", x->tm_year+1900);
        }
    }
    fclose(kitaplar);
}

void FilmEkle(){

    while(getchar() != '\n');
    printf("\nFilm adi: ");
    fgets(film.FilmAdi, 45, stdin);
    film.FilmAdi[strcspn(film.FilmAdi, "\n")] = 0;

    movies = fopen("movies.dat", "rb+");

    if (movies == NULL) {
        perror("Dosya acilamadi");
        movies = fopen("movies.dat", "wb");
    }

    film.sira = 1;
    fseek(movies, 0, SEEK_SET);
    while(fread(&kayit, sizeof(kayitKontrol), 1, movies) == 1){
        film.sira++;
    }

    fseek(movies, 0, SEEK_END);
    if (fwrite(&film, sizeof(ekle2), 1, movies) != 1) {
    printf("Kayit yazilamadi!\n");
}
    fclose(movies);

}

void FilmSil(){

    printf("\n=========================================\n\n");

    int numara;
    int i = 0;

    gecici = fopen("gecici.dat","rb+");
    if(gecici == NULL)
        gecici = fopen("gecici.dat","wb+");

    movies = fopen("movies.dat", "rb+");

    if(movies == NULL)
        printf("Henuz eklenmis bir film bulunmamaktadir.\n");
    else{
        printf("Silmek istediginiz filmin sira numarasini giriniz: ");
        scanf("%d",&numara);

        fseek(movies, 0, SEEK_SET);

        while(fread(&film, sizeof(ekle2), 1, movies) == 1){
            if(film.sira != numara){
                i++;
                film.sira = i;
                fwrite(&film, sizeof(ekle2), 1, gecici);
            }
        }
        printf("Silme islemi basariyla gerceklesmistir!\n");
        printf("\n=========================================\n");

        fclose(movies);
        fclose(gecici);
        remove("movies.dat");
        rename("gecici.dat", "movies.dat");
    }
}

void FilmListe(){
    movies = fopen("movies.dat", "rb");
    if (movies == NULL) {
        perror("Dosya acilamadi");
    }

    if (fread(&film, sizeof(ekle2), 1, movies) != 1) {
        printf("Henuz eklenmis bir film bulunmamaktadir.\n");
        fclose(movies);
    }

    printf("\n  ============ FILMLERIM ============\n");

    fseek(movies, 0, SEEK_SET);
    while(fread(&film, sizeof(ekle2), 1, movies) == 1){
    printf("\n=> %d) %s", film.sira, film.FilmAdi);
    }
    printf("\n");

    fclose(movies);
}

void DiziEkle(){
    int girilmis = 0;

    series = fopen("series.dat", "rb+");

    if (series == NULL) {
        series = fopen("series.dat", "wb");
    }

        while(getchar() != '\n');
        printf("\nDizi adi: ");
        fgets(film.FilmAdi, 45, stdin);
        film.FilmAdi[strcspn(film.FilmAdi, "\n")] = 0;

        film.sira = 1;
        fseek(series, 0, SEEK_SET);

        while(fread(&kayit, sizeof(kayitKontrol), 1, series) == 1){
            film.sira++;
            if(strcmp(film.FilmAdi, kayit.FilmAdi) == 0){
                girilmis = 1;
            }
        }

        if(girilmis == 1){
            printf("\nBu diziyi daha once eklediniz!\n");
        }
        else{
            fseek(series, 0, SEEK_END);
            fwrite(&film, sizeof(ekle2), 1, series);
        }

        fclose(series);
}

void DiziSil(){
    printf("\n=========================================\n\n");

    int numara;
    int i = 0;

    gecici = fopen("gecici.dat","rb+");
    if(gecici == NULL)
        gecici = fopen("gecici.dat","wb+");

    series = fopen("series.dat","rb+");

    if(series == NULL)
        printf("Henuz eklenmis bir dizi bulunmamaktadir.\n");
    else{
        printf("Silmek istediginiz dizinin sira numarasini giriniz: ");
        scanf("%d",&numara);

    fseek(series, 0, SEEK_SET);
    while(fread(&film, sizeof(ekle2), 1, series) == 1){
        if(numara != film.sira){
            i++;
            film.sira = i;
            fwrite(&film, sizeof(ekle2), 1, gecici);
        }
    }

    printf("Silme islemi basariyla gerceklesmistir!\n");
    printf("\n=========================================\n");

    fclose(series);
    fclose(gecici);
    remove("series.dat");
    rename("gecici.dat", "series.dat");
    }
}

void DiziListe(){
    series = fopen("series.dat", "rb");
    if (series == NULL) {
        perror("Dosya acilamadi");
    }

    if (fread(&film, sizeof(ekle2), 1, series) != 1) {
        printf("Henuz eklenmis bir dizi bulunmamaktadir.\n");
        fclose(series);
    }

    printf("\n  ============ DIZILERIM ============\n");

    fseek(series, 0, SEEK_SET);
    while(fread(&film, sizeof(ekle2), 1, series) == 1){
    printf("\n=> %d) %s", film.sira, film.FilmAdi);
    }
    printf("\n");

    fclose(series);
}
