#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node{
	int sayi;
	struct Node *sonraki;
	struct Node *onceki;
};

int main(void){
	struct Node *ilk=NULL;
	struct Node *ptr=NULL;
	int deger;
	char devam='E';
	
	while(devam=='E'||devam=='e'){
		printf("Bir sayi giriniz: ");
		scanf("%d",&deger);
		
		if(ilk==NULL){
			ilk=(struct Node*) malloc(sizeof(struct Node));
			ilk->sayi=deger;
			ilk->onceki=NULL;
			ilk->sonraki=NULL;
			ptr=ilk;
		}
		else{
			ptr->sonraki=(struct Node*) malloc(sizeof(struct Node));
			ptr->sonraki->onceki=ptr;
			ptr=ptr->sonraki;
			ptr->sayi=deger;
			ptr->sonraki=NULL;
		}
		
		cevap:
		printf("Devam etmek istiyor musunuz (E/H): ");
		scanf("%s",&devam);
		if(devam=='E'||devam=='e') continue;
		else if(devam=='H'||devam=='h') break;
		else printf("!!!(E/H)!!!\n"); goto cevap;
	}
	getch();
	return 0;
}
