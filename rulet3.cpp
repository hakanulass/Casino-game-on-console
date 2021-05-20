#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
//y���nla ekleme ve ��karma
struct yigin
{
  int bakiye;
  yigin * sonraki;
};
yigin*ilk=NULL;
yigin*gecici=NULL;
yigin*sil=NULL;
yigin*yeni=NULL;



//bakiye i�in ekleme i�lemi y���nla
void push(int bakiye)//push = ekleme
{
  if(ilk==NULL)//bo� bir alan olu�turuluyor
  {
    ilk = (yigin * )malloc(sizeof(yigin));
    ilk -> sonraki = NULL;
  } 
  ilk ->bakiye = bakiye;
  yigin * yeni = (yigin * )malloc(sizeof(yigin));
  yeni -> sonraki = ilk;
  ilk = yeni;
}

//bakiye i�in ��karma i�lemi y���nla
int pop()//pop = ��karma 
{
  if(ilk -> sonraki == NULL)
        return -1;
        int sonuc = ilk -> sonraki -> bakiye;
        yigin *gecici = ilk;
        free(gecici);
        return sonuc;
}

//bakiye i�in listeleme i�lemi y���nla
void printStack()//printStack = listeleme
{
  printf("\n");
  yigin *gecici = ilk;//b�t�n bilgiler ge�ici alana al�n�yor
  while(gecici != NULL )
  {
    printf("%d _ ",gecici->bakiye);//ge�ici alandakiler yazd�r�l�yor
    gecici = gecici -> sonraki;
  }
}
//RULET ba�l��� fonksiyonu
void rulet_basligi(void);
//rulet �evirme fonksiyonu
int rulet_cevir(void);

int oyun(int o){
if(o>1){
    oyun(o-1);
    //de�i�kenler
int bahismodu;
int duzbahis, yatirilan, parite;
int sayi;
int bakiye;
int renkbahis;


//diziler
int kirmizi[18]={1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
int siyah[18]={2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};

//Ho�geldiniz yaz�s� ve ba�l�k
printf("***\n");
printf("***\n");
rulet_basligi();
printf("\n***\n");
printf("***\n");


//Oyun hakk�nda a��klamalar
printf("CASINO'ya hosgeldiniz\n");
printf("\nHer girisinizde hesabiniza 100$ bakiye tanimlanir\n");
printf("Casino'muzda 3 tip oyun oynayabilirsiniz\n\n");
printf("1) Duz Bahis oyunu: Bir sayi secersiniz. Yuksek risk! Yuksek kazanc! (1den 35e kadar)\n\n");
printf("2) Renk oyunu: Bir renk seciniz(K veya S)\n Kirmizi numaralar  1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36\n Siyah numaralar 2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35\n\n");
printf("3) Tek-Cift oyunu: Tek veya Cift seciniz (1 veya 2)");


//oyun modu se�imi ve bakiye tan�m�
printf("\nLutfen oynamak istediginiz bahis turunu seciniz.1, 2 veya 3'e basiniz> ");
scanf("%d", &bahismodu);
bakiye=100;


//Kazand�k�a oyunun d�nmesini sa�layan d�ng�
while(bakiye>0)
{
    if (bahismodu==1)       //D�z bahis modu
       {
        printf("\nHer sey kazanmak icin degil mi? :)\n 1'den 36'ya kadar sayi seciniz> ");
        scanf("%d", &duzbahis);
        x1:
        printf("Ne kadar para yatirmak istersiniz? Odemeler 1'e 35 yapilir> ");
        scanf("%d", &yatirilan);
        if(yatirilan>bakiye){
            printf("Bakiyeniz: $%d, lutfen uygun bir para yatiriniz.\n",bakiye);
            goto x1;
        }
        printf("\nHesabinizdan $%d , %d numaraya yatirildi", yatirilan, duzbahis);
        printf("\nRuleti cevirmek icin ENTER'a basiniz. Ellerini ac ve dua et! :)");
        getchar();
        getchar();
        rulet_cevir();
                if (sayi==duzbahis){
                   bakiye += (yatirilan*35);                 
                   printf("Tebrikler Kazandiniz! Hesabiniza $%d para tanimlandi.\n", yatirilan*35);
                   push(bakiye);
                   printStack();
                   }
                else{
                   bakiye -= yatirilan;
                   pop();
                   printf("Uzgunuz. $%d kaybettiniz.\n", yatirilan);
                   push(bakiye);
                   printStack();
       }
       }
     else if (bahismodu==2)         //K�rm�z� veya siyah renk bahis modu
          {
           printf("\nTamam. Bir renk seciniz. Kirmizi icin 1'e Siyah icin 2'ye basiniz> ");
           scanf("%d", &renkbahis);
           x2:
           printf("\nNe kadar para yatirmak istersiniz? Odemeler 1'e 1 yapilir> ");
           scanf("%d", &yatirilan);
           if(yatirilan>bakiye){
            printf("Bakiyeniz: $%d, lutfen uygun bir para yatiriniz.\n",bakiye);
            goto x2;
        }
           printf("\nHesabinizdan $%d , %d numaraya yatirildi", yatirilan, renkbahis);
           printf("\nRuleti cevirmek icin ENTER'a basiniz. Ellerini ac ve dua et! :)");
           getchar();
           getchar();
           rulet_cevir();
                if (renkbahis==1)
                    {
                    if (sayi==kirmizi[18])
                      {bakiye += yatirilan;   
                       push(bakiye);
                       printf("Tebrikler Kazandiniz! Hesabiniza $%d para tanimlandi,\n", yatirilan);
                       printStack();
                       }
                    else{
                       bakiye -= yatirilan;
                       pop();
                       printf("Uzgunuz. $%d kaybettiniz.\n", yatirilan);
                       printStack();
                    }
                    }
                 if (renkbahis==2)
                    {
                    if (sayi==siyah[18]){
                       bakiye += yatirilan;

                       push(bakiye);
                       printf("Tebrikler Kazandiniz! Hesabiniza $%d para tanimlandi.\n", yatirilan);
                       printStack();}
                    else{
                       bakiye -= yatirilan;
                       pop();
                       push(bakiye);
                       printf("Uzgunuz. $%d kaybettiniz.\n", yatirilan);
                       printStack();
                    }
                    }
          }
     else           //Tek ve �ift bahis modu
         {  printf("Tamam. Tek icin 1'e Cift icin 2'ye basiniz. Seciminizi bilgece yapiniz :)> ");
            scanf("%d", &parite);
            x3:
            printf("\nNe kadar para yatirmak istersiniz? Odemeler 1'e 1 yapilir> ");
            scanf("%d", &yatirilan);
            if(yatirilan>bakiye){
            printf("Bakiyeniz: $%d, lutfen uygun bir para yatiriniz.\n",bakiye);
            goto x1;
        }
                  if (parite==1){
                     printf("\nTek sayilara $%d yatirdiniz", yatirilan);}
                  else{
                      printf("\nCift sayilara $%d yatirdiniz", yatirilan);}
            printf("\nRuleti cevirmek icin ENTER'a basiniz. Ellerini ac ve dua et! :)");
            getchar();
            getchar();
            rulet_cevir();
                   if (parite==1)
                      {
                        if (sayi%2==1)
                          {bakiye += yatirilan;
                        
                           printf("Tebrikler Kazandiniz! Hesabiniza $%d para tanimlandi.\n", bakiye);
                           push(bakiye);
                           printStack();}
                        else{
                           bakiye -= yatirilan;
                           pop();
                           printf("Uzgunuz. $%d kaybettiniz.\n", yatirilan);
                           push(bakiye);
                           printStack();
                        }
                      }
                   else{
                         if (sayi%2==0)
                          {bakiye += yatirilan;
                          
                           printf("Tebrikler Kazandiniz! Hesabiniza $%d para tanimlandi.\n", bakiye);
                           push(bakiye);
                           printStack();}
                        else{}
                           bakiye -= yatirilan;
                           pop();
                           printf("Uzgunuz. $%d kaybettiniz.\n", yatirilan);
                           push(bakiye);
                           printStack();
                           }
         }

}






getchar();
getchar();
return (0);
}
}

int main (void) //main fonksiyonu
{
oyun(10);

}


void rulet_basligi(void)
{
    printf("       \n");
    printf("      *  * *     *     *    *          * * * *    * * * * * * *   \n");
    printf("      *     *    *     *    *          *                *      \n");
    printf("      *   *      *     *    *          *                *\n");
    printf("      *   *      *     *    *          * * * *          * \n");
    printf("      *    *     *     *    *          *                *  \n");
    printf("      *     *     *  *      * * * *    * * * *          *  \n");
    printf("                           ");
}


int rulet_cevir(void)
{
    int sayi;
    srand(time(NULL));
    sayi=1+(rand()%36);
    printf("Top yere dustu * %d *\n", sayi);
    return sayi;
}