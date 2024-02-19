#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// Ýlk sorunun Stack yapýsý ile çözümü

struct Node{
	int deger;
	struct Node *sonraki;
};

struct Node *push(struct Node *top,int deger){
	struct Node *yeni=(struct Node *) malloc(sizeof(struct Node));
	yeni->deger=deger;
	yeni->sonraki=NULL;
	
	if(top==NULL){
		top=yeni;
		return top;
	}
	else{
		yeni->sonraki=top;
		return yeni;
	}
}

struct Node *pop(struct Node *top,int *deger){
	if(top==NULL){
		deger=NULL;
		return top;
	}
	else{
		struct Node *gecici;
		gecici=top;
		*deger=gecici->deger;
		
		top=top->sonraki;
		free(gecici);
		
		return top;
	}
}

int main(void){
	struct Node *top=NULL;
	int deger;
	
	printf("---5 sayi degeri giriniz---");
	
	for(int a=0;a<5;a++){
		printf("\n%d. deger: ",a+1);
		scanf("%d",&deger);
		
		top=push(top,deger);
	}
	printf("\n");
	for(int a=5;a>0;a--){
		top=pop(top,&deger);
		printf("\n%d. deger: %d\n",a,deger);
	}
	
	getch();
	return 0;
}
