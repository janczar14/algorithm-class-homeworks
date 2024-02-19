#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

/* 0 ile 100 arasý 100 adet rastgele tamsayýdan oluþan dizinin ilk elli elemanýný 
küçükten büyüðe, son elli elemanýný da büyükten küçüðe quicksort algoritmasý kullanarak
sýralayýnýz. */

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partitionstb(int arr[], int low, int high){
	int pivot = arr[high];
	int i = (low-1);

	for(int j = low; j <= high-1; j++){
		if(arr[j] <= pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return (i+1);
}

void quickSortstb(int arr[], int low, int high){
	if(low < high){
		int pi = partitionstb(arr, low, high);
		quickSortstb(arr, low, pi - 1);
		quickSortstb(arr, pi + 1, high);
	}
}

int partitionbts(int arr[], int low, int high){
	int pivot = arr[high];
	int i = (low-1);

	for(int j = low; j <= high-1; j++){
		if(arr[j] >= pivot){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	return (i+1);
}

void quickSortbts(int arr[], int low, int high){
	if (low < high){
		int pi = partitionbts(arr, low, high);
		quickSortbts(arr, low, pi - 1);
		quickSortbts(arr, pi + 1, high);
	}
}

int main(){
	int sayilar[100];
	srand(time(NULL));
	for(int a = 0; a < 100; a++){
		sayilar[a] = rand()%100;
	}
	quickSortstb(sayilar, 0, 49);
	quickSortbts(sayilar, 50, 99);
	for(int b = 0; b < 100; b++){
		printf("%d ",sayilar[b]);
		if(b == 49) printf("/ ");
	}
	getch();
	return 0;
}

