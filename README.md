# Akıllı Kasa Programı

Bir mağaza kasiyerinin girdiği ürün tutarı ve müşterinin ödediği paraya göre **para üstünü hesaplayan** ve bunu **en az sayıda banknot ve madeni parayla** gösteren C programı.

**Öğrenci:** Mert Sevinç — **No:** 1260505073 — **Ders:** Algoritma ve Programlama

## Programın Amacı

Kasiyer ürün tutarını ve müşterinin ödediği parayı (TL) girer. Program para üstünü bulur ve küpürleri büyükten küçüğe doğru dağıtarak en az sayıda para verir. Sonda toplam küpür sayısını da yazar.

**Kullanılan küpürler:**

| Banknotlar | Madeni paralar |
|---|---|
| 200, 100, 50, 20, 10, 5, 1 TL | 50, 25, 10, 5, 1 Kr |

## Ödevin Kuralları

- Ürün tutarı ve ödenen para `float` olarak tutulur.
- Küpür hesabı **kuruş cinsinden, tamsayılarla (`int`)** yapılır.
- Programın sonunda verilen **toplam küpür sayısı** yazdırılır.
- Kod yalnızca `float`, `int` (ve `char`) türlerini kullanır. `if`, `for` ve `while` kullanılmamıştır.

## Rapor Sorusu: Ondalıklı Sayı Hatası

Ürün 18,70 TL, ödenen 20 TL için doğru para üstü **130 kuruştur**. Yuvarlama yapmadan hesaplayınca:

```c
int hatalikurus = (int)((odenenfiyat - urunfiyati) * 100);
```

program **129 kuruş** bulur.

**Nedeni:** Bilgisayar sayıları ikilik tabanda saklar ve 18,70 bu tabanda tam yazılamaz. `float` onu yaklaşık olarak **18,7000007629** saklar. Çıkarma sonucu 1,30 yerine **1,2999992371** çıkar, 100 ile çarpınca yaklaşık 129,9999 olur. `(int)` dönüşümü yuvarlamaz, küsuratı **atar**; sonuç 129 olur.

**Çözüm:** Her tutarı ayrı ayrı kuruşa çevirip **yuvarlayarak** `int` yapmak, çıkarmayı tamsayıyla yapmak:

```c
int urun_kurus   = (int)(urunfiyati * 100 + 0.5f);
int odenen_kurus = (int)(odenenfiyat * 100 + 0.5f);
int para_ustu    = odenen_kurus - urun_kurus;
```

`+ 0.5f` eklemek, `(int)` ile kesmeyi "en yakın tamsayıya yuvarlama"ya çevirir. Sonuç: 2000 − 1870 = **130 kuruş**.

## Algoritma

1. Ürün tutarını ve ödenen parayı `float` olarak oku.
2. Her ikisini `* 100 + 0.5` ile kuruşa yuvarla ve `int` yap.
3. `para_ustu = odenen_kurus - urun_kurus`, `kalan = para_ustu`.
4. Küpürleri büyükten küçüğe sırayla işle (20000, 10000, 5000, 2000, 1000, 500, 100, 50, 25, 10, 5, 1 kuruş).
5. Her küpür için `adet = kalan / küpür` (kaç tane sığar) ve `kalan = kalan % küpür` (geriye ne kalır).
6. Tüm adetleri topla.
7. Para üstünü, her küpürün adedini ve toplamı ekrana yazdır.

Küpür sığmıyorsa `/` işlemi 0 verir ve `%` kalanı değiştirmez; bu yüzden `if` kullanmaya gerek kalmaz. Büyükten küçüğe gidildiği için sonuç en az sayıda küpürle verilir (açgözlü algoritma).

## Derleme ve Çalıştırma

```bash
gcc -Wall akillikasaprogrami.c -o akillikasa
./akillikasa        # Windows'ta: akillikasa.exe
```

Ondalık ayracı olarak **nokta** kullanın (`18.70`). Virgül yanlış okunur.

## Örnek Çalıştırma

Ürün **18.70**, ödenen **20**:

```
Hatalı Kuruş : 129
Urun : 18.7000007629
Fark : 1.2999992371
Doğru Kuruş : 130

 Para Üstü : 1 TL 30 Kuruş
200 TL : 0 adet
100 TL : 0 adet
 50 TL : 0 adet
 20 TL : 0 adet
 10 TL : 0 adet
  5 TL : 0 adet
  1 TL : 1 adet
 50 Kr : 0 adet
 25 Kr : 1 adet
 10 Kr : 0 adet
  5 Kr : 1 adet
  1 Kr : 0 adet

Toplam Küpür ve Madeni Para Sayısı: 3
```

## Test Sonuçları

| Ürün (TL) | Ödenen (TL) | Para üstü | Toplam küpür |
|---|---|---|---|
| 18.70 | 20 | 1 TL 30 Kr | 3 |
| 263.85 | 500 | 236 TL 15 Kr | 7 |
| 50 | 50 | 0 TL 0 Kr | 0 |

## Dosyalar

- `akillikasaprogrami.c` — programın kaynak kodu
- `README.md` — bu dosya

## Geliştirme Araçları

- **Visual Studio Code** ve **GCC**: kodu yazmak ve derlemek için
- **GitHub**: projeyi yüklemek için
- **Claude (yapay zekâ asistanı)**: ödevin mantığını anlamak için. Önce örnek bir çözüm gördüm, ardından adım adım anlatmasını isteyip her adımı kendim yazıp çalıştırdım. Hataları (para üstünün 0 ve 13000 çıkması, küpür bölenini yanlış yazmam, toplamda 10 TL'yi unutmam) birlikte inceleyip düzelttim.

## Sınırlamalar

- `float` yaklaşık 7 anlamlı basamak hassasiyetine sahiptir; çok büyük tutarlarda hata yarım kuruşu aşabilir. Gerçek kasa programlarında para baştan kuruş cinsinden `int` olarak tutulur.
- Ödenen para ürün tutarından küçükse program kontrol yapmaz (ödev bunun olmayacağını varsayar).
