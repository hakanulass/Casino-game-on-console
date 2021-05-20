#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
int a=0,secim;

struct StackNode{
int data;
struct StackNode* next;
};

struct StackNode* newNode(int data){
struct StackNode* stackNode =
(struct StackNode*) malloc(sizeof(struct StackNode));
stackNode->data = data;
stackNode->next = NULL;
return stackNode;
}

int isEmpty(struct StackNode *root){
return !root;
}

void push(struct StackNode** root, int data){
struct StackNode* stackNode = newNode(data);
stackNode->next = *root;
*root = stackNode;
}

int pop(struct StackNode** root){
if (isEmpty(*root))
return INT_MIN;
struct StackNode* temp = *root;
*root = (*root)->next;
int popped = temp->data;
free(temp);
return popped;
}

int peek(struct StackNode* root){
if (isEmpty(root))
return INT_MIN;
return root->data;
}

struct karakter{
int skor;
char isim[20];
};


void anaMenu(){
printf("**OyununAdi**\n[1]Basla\n[2]Ayarlar\n[3]Cikis");
x:
printf("\nLutfen Secim Yapiniz...");
scanf("%d",&secim);

switch(secim){
case 1: oyun(); break;
case 2: ayarlar(); break;
case 3: printf("Oyudan Cikis Yapiliyor..."); return 0; break;
default: printf("Yanlis Secim Yaptiniz..."); goto x; break;
}
}

void ayarlar(){
xx:
system("cls");
printf("**AYARLAR**\nAna Menuye Donmek Icin 1'e Basiniz...");
scanf("%d",&secim);
if(secim==1){
system("cls");
anaMenu();
}
else{
goto xx;
}
}

void basadon(){
aa:
printf("\nBastan baslamak icin 1'e basiniz...");
int abc;
scanf("%d",&abc);
if(abc=1){
system("cls");
return main();
}
else{
printf("Yanlis secim yaptiniz...");
system("cls");
goto aa;
}

}

void oyun(){
struct StackNode* root = NULL;
push(&root,0);
push(&root,10);
push(&root,20);
push(&root,30);
push(&root,40);
push(&root,50);
push(&root,60);
push(&root,70);
push(&root,80);
push(&root,90);
push(&root,100);
int secim2[a],a=0;
struct karakter *p,ktr;
p=&ktr;


system("cls");
printf("Karakterinizin ismini yaziniz...  ");
scanf(" %s",&ktr.isim);

baslangic:
system("cls");
printf("%s, alt kattan sesler geliyor",ktr.isim);

printf("\n[1]Sesin gitmesini bekle.\n[2]Polis cagir.\n[3]Goz at.");
printf("\nLutfen secim yapiniz...");
geri:
scanf("%d",&secim2[a]);

switch(secim2[a]){
case 1:printf("Ses sana dogru yaklasiyor..."); a++; goto p1s1; break;
case 2:system("CLS"); printf("Hatlar kesilmis... Asagi gitmek zorundasyn..."); a++; goto p1s2; break;
case 3:system("CLS"); printf("Bir zombi ustune atladi . Ondan kacmaya calisirken yere dustun...");
pop(&root); printf("\nYere dustugunuz icin 10 hasar aldiniz. Suanki caniniz: %d\n",peek(root)); a++; goto p1s3; break;
default: printf("Yanlis secim yaptiniz... Tekrar yaziniz..."); goto geri; break;
}

p1s1:

system("CLS");
geri2:
printf("Ses sana dogru yaklasiyor...Birseyler yapmalisin...\n[1]Aldiris etme.\n[2]Kendini korumak icin bisey al.");
scanf("%d",&secim2[a]);
switch(secim2[a]){
case 1:system("cls"); printf("Birkac zombi geldi ve seni paramparca etti..."); a++; ktr.skor=a;
pop(&root); pop(&root); pop(&root); pop(&root); pop(&root); pop(&root); pop(&root); pop(&root); pop(&root); pop(&root);
printf("\nSuanki caniniz: %d",peek(root)); printf("\nOyun bitti skorunuz: %d",p->skor); basadon(); break;
case 2:printf("Hatlar kesilmis... Asagi gitmek zorundasyn..."); a++; goto p2s1; break;
default: printf("Yanlis secim yaptiniz... Tekrar yaziniz..."); goto geri2; break;
}

p2s1:
system("CLS");
printf("Asagidasin... Camdan baktiginda gordugun manzara seni sok etti.\nBirkac zombi yan komsunun pesinden kosturuyor.\n[1]Git ve onu koru\n[2]Bosver, zaten cok ses yapiyor.");

p1s2:

geri3:
printf("Asagidasin ve 2 tane zombi evin icinde dolaniyor...\n[1]Kac!\n[2]Bir bicak al ve onlara saldyr.");
scanf("%d",&secim2[a]);
switch(secim2[a]){
case 1:printf("Arka kapidan sessizce kactin..."); a++; goto p2s2; break;
case 2:pop(&root); printf("Zombilerin isini bitirdin fakat bicakla elini kestigin icin 10 hasar aldin.\nSuanki caniniz: %d\nBirileri sesini duymadan once evden ayril...",peek(root)); a++; goto p2s3; break;
default: system("CLS"); printf("Yanlis secim yaptiniz... Tekrar yaziniz...");  goto geri3; break;}

p2s2:
system("CLS");
printf("Suan arka bahcedesin... Kilerde dede yadigari bir tabanca ve sustali bicak buldun...\n[1]Daha guvende hissediyorum, birkac zombi oldurmeliyim\n[2]Sessizce cevrede yardima ihtiyaci olan insanlara goz atmaliyim");

p1s3:
Sleep(300);
printf("Yerden hizlica kalktin ve evden kacmak uzeresin...");
goto p2s3;

p2s3:
printf("\nNereye gideceksin?\n[1]Sakin bir cafeye gidecegim.\n[2]Dostumun evine gidecegim, orasi daha guvenli olabilir.\n[3]Emniyet mudurlugune gitmeliyim.");

return 0;
}


int main(){
anaMenu();
}

