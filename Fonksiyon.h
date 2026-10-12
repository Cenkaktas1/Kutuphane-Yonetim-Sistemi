#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma once

typedef struct{
    char ad[20];
    char soyad[20];
    char sifre[15];
} kontrol;

typedef struct{
    int sira;
    char ad[40];
    char yazar[40];
    time_t sure;
} ekle;

typedef struct{
    int sira;
    char FilmAdi[45];
} ekle2;

typedef struct{
    int sira;
    char FilmAdi[45];
} kayitKontrol;

extern FILE* kitaplar;
extern FILE* giris;
extern FILE* gecici;
extern FILE* movies;
extern FILE* series;

extern kontrol test;
extern ekle kitap;
extern ekle2 film;
extern kayitKontrol kayit;

extern char isim[20];
extern char soyisim[20];
extern char sifre[15];

int ay_to_int(const char *ay);
void GirisKontrol(kontrol test);
void KitapEkle(ekle kitap);
void KitapSil();
void KitapListe();
void FilmEkle();
void FilmSil();
void FilmListe();
void DiziEkle();
void DiziSil();
void DiziListe();
