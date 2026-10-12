# BenimKutuphanem

C ile yazilmis, konsolda calisan kisisel arsiv uygulamasi. Okunan kitaplari, izlenen filmleri ve dizileri kaydetmeye yarar.

## Ozellikler

- Ad, soyad ve sifre ile giris (`giris.txt`)
- **Kitaplarim:** kitap ekleme, silme ve eklenme tarihiyle listeleme (`kitap.txt`)
- **Filmlerim:** film ekleme, silme ve listeleme (`movies.dat`, ikili dosya)
- **Dizilerim:** dizi ekleme, silme ve listeleme (`series.dat`, ikili dosya)
- Ayni kaydin iki kez eklenmesini engelleme

## Derleme

Code::Blocks ile `BenimKutuphanem.cbp` dosyasini acip derleyebilirsiniz. Komut satirindan derlemek icin:

```bash
gcc main.c Fonksiyon.c BenimFonksiyonlarim.c -o BenimKutuphanem
```

## Calistirma

Program veri dosyalarini calistigi klasorde arar. Ornek veriler `bin/Debug/` klasorundedir:

```bash
cd bin/Debug
./BenimKutuphanem
```

`giris.txt` dosyasi tek satirdan olusur ve degerler sekmeyle ayrilir: `Ad<TAB>Soyad<TAB>Sifre`

## Dosya yapisi

| Dosya | Aciklama |
|---|---|
| `main.c` | Ana menu ve alt menuler |
| `Fonksiyon.c/.h` | Giris, kitap, film ve dizi islemleri |
| `BenimFonksiyonlarim.c/.h` | Menu secimi dogrulama (`SecimKontrol`) |
| `resources/icons/` | Uygulama ikonlari |
