#include<stdio.h>
#include<conio.h>

int sayi(int x){
	int bsmktoplam=0;
	while(x>0){
		bsmktoplam+=x%10;
		x=x/10;
	}
	return bsmktoplam;
}

int main(){
	int x,sonuc;
	printf("Basamak degerleri toplanacak sayiyi giriniz: ");
	scanf("%d",&x);
	sonuc=sayi(x);
	printf("Basamak degerlerinin toplami--> %d",sonuc);
	getch();
	return 0;
}
