#include<stdio.h>
#include<conio.h>

int faktoriyel(int x){
	int fx=1,a=1;
	while(a<=x) fx*=a++;
	return fx;
}
int kombinasyon(int n,int r){
	int f1,f2,f3,sonuc;
	f1=faktoriyel(n); f2=faktoriyel(r); f3=faktoriyel(n-r);
	sonuc=f1/(f2*f3);
	return sonuc;
}

int main(){
	int n,r,sonuc;
	printf("----C(n,r)----\n");
	printf("n degeri--> ");
	scanf("%d",&n);
	printf("r degeri--> ");
	scanf("%d",&r);
	sonuc=kombinasyon(n,r);
	printf("C(n,r)= %d",sonuc);
	getch();
	return 0;
}
