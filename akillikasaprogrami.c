#include <stdio.h>

int main()
{
   printf("\n\n\n***********AKILLI KASA***********\n\n\n");
   
   
    //ilk aşama//
    float urunfiyati, odenenfiyat;

    printf("Ürün fiyatini giriniz : ");
    scanf("%f", &urunfiyati);

    printf("\nÖdediğiniz fiyatı giriniz :  ");
    scanf("%f", &odenenfiyat);

    printf("\nÜrünün fiyatı %.2f\n", urunfiyati);
    printf("Ödediğiniz fiyat %.2f\n\n",odenenfiyat);

    int hatalikurus = (int) ((odenenfiyat - urunfiyati) * 100);
    printf("Hatalı Kuruş : %d\n\n" ,hatalikurus);

    //bilgisayar ondalıklı işlemlerde hata yapabilir.//
    //Bu yuzden bulduğumuz değere//
    // 0.5 ekleyerek dogru sonuca yuvarlanmasını saglayacagız//
   
    printf("Urun : %.10f\n" ,urunfiyati);
    printf("Fark : %.10f\n\n" , odenenfiyat - urunfiyati);

    int urun_kurus = (int) (urunfiyati * 100 + 0.5f);
    int odenen_kurus = (int) (odenenfiyat * 100 + 0.5f);
    int para_ustu = (int) (odenen_kurus - urun_kurus);
    printf("Doğru Kuruş : %d\n" ,para_ustu);
   
    //küpür hesabı için banknotları kuruş cinsinden yazıp
    // yeni kalanı belırlıyorum.

    int kalan = para_ustu;

    int try200 = kalan / 20000;   kalan = kalan % 20000;
    int try100 = kalan / 10000;   kalan = kalan % 10000;
    int try50  = kalan / 5000;    kalan = kalan % 5000;
    int try20  = kalan / 2000;    kalan = kalan % 2000;
    int try10  = kalan / 1000;    kalan = kalan % 1000;
    int try5   = kalan / 500;     kalan = kalan % 500;
    int try1   = kalan / 100;     kalan = kalan % 100;
    int kr50  = kalan / 50;      kalan = kalan % 50;
    int kr25  = kalan / 25;      kalan = kalan % 25;
    int kr10  = kalan / 10;      kalan = kalan % 10;
    int kr5   = kalan / 5;       kalan = kalan % 5;
    int kr1   = kalan / 1;       kalan = kalan % 1;

    int toplamkupur = try200 + try100 + try50 + try20 + try5 
      + try1 + kr50 + kr25 + kr10 + kr5 + kr1;

    printf("\n Para Üstü : %d TL %d Kuruş \n\n" , para_ustu / 100 , para_ustu % 100);

    printf("200 TL : %d adet\n", try200);
    printf("100 TL : %d adet\n", try100);
    printf(" 50 TL : %d adet\n", try50);
    printf(" 20 TL : %d adet\n", try20);
    printf(" 10 TL : %d adet\n", try10);
    printf("  5 TL : %d adet\n", try5);
    printf("  1 TL : %d adet\n", try1);
    printf(" 50 Kr : %d adet\n", kr50);
    printf(" 25 Kr : %d adet\n", kr25);
    printf(" 10 Kr : %d adet\n", kr10);
    printf("  5 Kr : %d adet\n", kr5);
    printf("  1 Kr : %d adet\n", kr1);
    
    printf("\nToplam Küpür ve Madeni Para Sayısı: %d\n", toplamkupur);

    printf("\n\n\n************************************\n\n\n");
    
    
    
    return 0;



}