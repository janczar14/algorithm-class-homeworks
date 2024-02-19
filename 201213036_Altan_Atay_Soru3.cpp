#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

struct dizi{
	int sayi[100],en_kucuk,en_buyuk,toplam;
	double ort,std_sapma;
};

struct dizi bilgileri_al(void);
void bilgileri_goster(struct dizi);

int main(void){
	struct dizi sayilar;
	sayilar=bilgileri_al( );
	bilgileri_goster(sayilar);
	getch();
	return 0;
}

struct dizi bilgileri_al(void){
	struct dizi sayilar;
	srand(time(NULL));
	sayilar.en_buyuk=0;
	sayilar.en_kucuk=100;
	sayilar.toplam=0;
	for(int a=0;a<100;a++){
		sayilar.sayi[a]=rand()%100;
		if(sayilar.sayi[a]>sayilar.en_buyuk) sayilar.en_buyuk=sayilar.sayi[a];
		if(sayilar.sayi[a]<sayilar.en_kucuk) sayilar.en_kucuk=sayilar.sayi[a];
		sayilar.toplam+=sayilar.sayi[a];
	}
	sayilar.ort=sayilar.toplam/100.0;
	double pay;
	for(int b=0;b<100;b++){ //standart sapma hesaplama
		pay+=pow((sayilar.sayi[b]-sayilar.ort),2);
	}
	sayilar.std_sapma=pow((pay/99.0),(1.0/2.0));
	return sayilar;
}

void bilgileri_goster(struct dizi sayilar){
	printf("Rastgele 100 adet sayi girildi.\n");
	printf("En buyuk--> %d\n",sayilar.en_buyuk);
	printf("En kucuk--> %d\n",sayilar.en_kucuk);
	printf("Ortalama--> %.2lf\n",sayilar.ort);
	printf("Standart sapma--> %.3lf\n",sayilar.std_sapma);
}
