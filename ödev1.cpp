// *(yildiz) sembolunu kullanarak 3 farkli sekil basan bir program
#include <iostream> //Standart kutuphane
#include <stdlib.h> //Konsol temizleme komutunun bulundugu kutuphane
using namespace std; //cout, cin, endl gibi komutlarin bulundugu sinif

void duzUcgen(int deger); //duz ucgen basan fonksiyonun prototipi 
void tersUcgen(int deger); //ters ucgen basan fonksiyonun prototipi
void elmas(int deger); //elmas basan fonksiyonun prototipi

int main()
{
    int istek,hak=3,deger; //tanimlamalar
    cout << "1:Duz Ucgen\n2:Ters Ucgen\n3:Elmas\n0:Cikis" << endl; //Secenek panosu
    cin >> istek; //kullanicinin istegini alir
    system("cls"); //Konsolu temizler
    switch (istek) //secime gore yapilacaklarin yer aldigi komut ifadeleri
    {
        case 1: //duz ucgen
            while (hak != 0) //bireyin sinirli sayida boyut girme hakki vardir
            {
                cout << "Duz Ucgen icin 3-15 araligindaki tek sayilardan boyut giriniz:" << endl;
                cin >> deger; //boyut degeri alinir
                if (3 <= deger && deger <= 15 && deger%2==1) //eger girilen deger sartlara uygunsa if ifadesinin icine girer
                {
                    system("cls"); //Konsolu temizler
                    duzUcgen(deger); //ucgeni basacak fonksiyon cagirilir
                    return 0; //daha sonra program sonlandirilir
                }
                else //girilen deger bir sarta bile uygun degilse else ifadesinin icine girer
                {
                    hak--; //istek hakki bir azalir
                    cout << "Yanlis girdiniz!" << endl; //hata belirtilir
                }
            }
            break; //switch-case den cikar
        case 2: //ters ucgen
            while (hak != 0) //bireyin sinirli sayida boyut girme hakki vardir
            {
                cout << "Ters Ucgen icin 3-15 araligindaki tek sayilardan boyut giriniz:" << endl;
                cin >> deger;//boyut degeri alinir
                if (3 <= deger && deger <= 15 && deger%2==1)//eger girilen deger sartlara uygunsa if ifadesinin icine girer
                {
                    system("cls");//Konsolu temizler
                    tersUcgen(deger);//ucgeni basacak fonksiyon cagirilir
                    return 0;//daha sonra program sonlandirilir
                }
                else//girilen deger bir sarta bile uygun degilse else ifadesinin icine girer
                {
                    hak--;//istek hakki bir azalir
                    cout << "Yanlis girdiniz!" << endl;//hata belirtilir
                }
            }
            break;//switch-case den cikar
        case 3:
            while (hak != 0) //bireyin sinirli sayida boyut girme hakki vardir
            {
                cout << "Elmas icin 5-15 araligindaki tek sayilardan boyut giriniz:" << endl;
                cin >> deger;//boyut degeri alinir
                if (5 <= deger && deger <= 15 && deger % 2 == 1)//eger girilen deger sartlara uygunsa if ifadesinin icine girer
                {
                    system("cls");//Konsolu temizler
                    elmas(deger);//ucgeni basacak fonksiyon cagirilir
                    return 0;//daha sonra program sonlandirilir
                }
                else//girilen deger bir sarta bile uygun degilse else ifadesinin icine girer
                {
                    hak--;//istek hakki bir azalir
                    cout << "Yanlis girdiniz!" << endl;//hata belirtilir
                }
            }
            break;//switch-case den cikar
        case 0://cıkıs yapma kismi
            return 0;//cıkıs yapar
        default:
            cout << "Gecersiz istek!" << endl; //seceneklerde olmayan bir istek secilirse bunu ekrana basar
            break; //switch-case den cikar
    }
    return 0; //eger program buraya kadar geldiyse bireyin hakki bitmistir ya da olmayan istekte bulunmustur kod kapatilir
}
void duzUcgen(int deger) 
{
    int yildiz = 1, bosluk = deger/ 2 ;
    for (int k = 0;k < (deger+1)/2;k++)//satir icin dongu
    {
        for (int i = 0;i < bosluk;i++) //bosluk basar
            cout << " ";
        for (int j = 0;j < yildiz;j++) //yildiz basar
            cout << "*";
        cout << endl; //new line
        bosluk--;
        yildiz+=2;
    }
}
void tersUcgen(int deger)
{
    int bosluk, satir = 0, sinirsayi=0, yildiz,sinirsayi2=deger;//tanimlamalar yapildi
    while (satir < (deger + 1) / 2) //satir sayisi için döngü
    {
        bosluk = 0; //her satir için yeniden sifirlanir
        while (bosluk < sinirsayi)//bosluk dongusu
        {
            cout << " "; 
            bosluk++;
        }
        yildiz = 0; //her satir için yeniden sifirlanir
        while (yildiz < sinirsayi2)//yildiz dongusu
        {
            cout << "*";
            yildiz++;
        }
        cout << endl; //new line
        sinirsayi++;
        sinirsayi2 -= 2;
        satir++;
    }
}
void elmas(int deger)
{
    duzUcgen(deger);
    tersUcgen(deger); //bu iki fonksiyonun birlesimi elmas olur
}