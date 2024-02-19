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
	struct Node *gecici=NULL;
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
		}
		else if(ilk->sayi > deger){
			gecici=(struct Node*) malloc(sizeof(struct Node));
			gecici->sayi=deger;
			gecici->sonraki=ilk;
			ilk->onceki=gecici;
		}
		else{
		    ptr=ilk;
		    while(ptr->sonraki!=NULL && ptr->sonraki->sayi < deger) ptr=ptr->sonraki;
		    gecici=(struct Node*) malloc(sizeof(struct Node));
		    gecici->sonraki=ptr->sonraki;
		    ptr->sonraki=gecici;
		    gecici->onceki=ptr;
		    if(gecici->sonraki!=NULL) gecici->sonraki->onceki=gecici;
		    gecici->sayi=deger;
	    }
	    
		cevap:
		printf("Devam etmek istiyor musunuz (E/H): ");
		scanf("%s",&devam);
		if(devam=='E'||devam=='e') continue;
		else if(devam=='H'||devam=='h') break;
		else printf("!!!(E/H)!!!\n"); goto cevap;
	}
	printf("\n\n");
	gecici=ilk;
	while(gecici!=NULL){
		printf("%d\n",gecici->sayi);
		gecici=gecici->sonraki;
	}
	getch();
	return 0;
}
