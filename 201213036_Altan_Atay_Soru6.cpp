#include<stdio.h>
#include<conio.h>

int sayi(int x){
	int durum=0,a;
	for(a=2;a<x;a++){
		if((x%a)==0) durum=1;
	}
	return durum;
}

int main(){
	int a;
	printf("Bir sayi giriniz--> ");
	scanf("%d",&a);
    if(sayi(a)==0 && a>1) printf("Girilen sayi asaldir.");
    else printf("Girilen sayi asal degildir.");
	getch();
	return 0;
}
