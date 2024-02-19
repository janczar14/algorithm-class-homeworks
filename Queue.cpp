#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//Ýlk sorunun Queue yapýsý ile çözümü

struct Node{
	int deger;
	struct Node *sonraki;
};

struct Node *Enqueue(struct Node *ilk,int deger){
	struct Node *yeni=(struct Node *) malloc(sizeof(struct Node));
	yeni->deger=deger;
	yeni->sonraki=NULL;
	
	if(ilk==NULL){
		ilk=yeni;
		return ilk;
	}
	else{
		struct Node *gecici=ilk;
		while(gecici->sonraki!=NULL) gecici=gecici->sonraki;
		gecici->sonraki=yeni;
		return ilk;
	}
}

struct Node *Dequeue(struct Node *ilk,int *deger){
	if(ilk==NULL){
		deger=NULL;
		return ilk;
	}
	else{
		struct Node *gecici;
		gecici=ilk;
		*deger=gecici->deger;
		ilk=ilk->sonraki;
		free(gecici);
		return ilk;
	}
}

int main(void){
	struct Node *top=NULL;
	int deger;
	
	printf("---5 sayi degeri giriniz---");
	
	for(int a=0;a<5;a++){
		printf("\n%d. deger: ",a+1);
		scanf("%d",&deger);
		
		top=Enqueue(top,deger);
	}
	printf("\n");
	for(int a=0;a<5;a++){
		top=Dequeue(top,&deger);
		printf("\n%d. deger: %d\n",a+1,deger);
	}
	
	getch();
	return 0;
}
