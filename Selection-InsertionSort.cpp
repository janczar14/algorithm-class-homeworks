#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

/* 0 ile 100 arasý 100 adet rastgele tamsayýdan oluþan dizinin ilk elli elemanýný 
selectionsort ile büyükten küçüðe, son elli elemanýný da insertionsort ile küçükten büyüðe
sýralayýnýz. */

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int arr[], int n){
	int i, j;
	for(i = 0; i < n-1; i++){
		for(j = 0; j < n-i-1; j++){
			if(arr[j] < arr[j+1]) swap(&arr[j], &arr[j+1]);
		}
	}
}

void selectionSort(int arr[], int n){
	int i, j, min_idx;
	for(i = 50; i < n-1; i++){
		min_idx = i;
		for(j = i+1; j < n; j++){
			if(arr[j] < arr[min_idx]) min_idx = j;
		}
		swap(&arr[min_idx], &arr[i]);
	}
}

int main(void){
	int sayilar[100];
	srand(time(NULL));
	for(int a = 0; a <100; a++){
		sayilar[a] = rand()%100;
	}
	bubbleSort(sayilar, 50);
	selectionSort(sayilar, 100);
	for(int b = 0; b < 100; b++){
		printf("%d ", sayilar[b]);
		if(b == 49) printf("/ ");
	}
	getch();
	return 0;
}
