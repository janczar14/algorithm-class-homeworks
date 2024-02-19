#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

int merge(int dizi[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2]; 
    for(int i=0;i<n1;i++) L[i]=dizi[l+i];
    for(int j=0;j<n2;j++) R[j]=dizi[m+1+j];
 
    int i=0,j=0,k=l; 
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            dizi[k]=L[i];
            i++;
        }
        else{
            dizi[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        dizi[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        dizi[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int dizi[],int l,int r){
    if(l>=r){
        return;
    }
    int m=(l+r-1)/2;
    mergeSort(dizi,l,m);
    mergeSort(dizi,m+1,r);
    merge(dizi,l,m,r);
}

int main(){
    int A[10],B[10],C[20];
    srand(time(NULL));
    for(int a=0;a<10;a++) A[a]=rand()%100;
    for(int a=0;a<10;a++) B[a]=rand()%100;
    
    int arr_size=sizeof(A)/sizeof(A[0]);
 
    printf("A dizisi elemanlari\n");
    for(int k=0;k<10;++k) printf("%d ",A[k]);
    mergeSort(A,0,arr_size-1);
    printf("\n\nSiralanmis hali\n");
    int temp1[10];
    for(int c=9,d=0;c>=0;c--,d++) temp1[d]=A[c];
    for(int k=0;k<10;++k) printf("%d ",temp1[k]);

    printf("\n\n\nB dizisi elemanlari\n");
    for(int k=0;k<10;++k) printf("%d ",B[k]);
    mergeSort(B,0,arr_size-1);
    printf("\n\nSiralanmis hali\n");
    int temp2[10];
    for(int c=9,d=0;c>=0;c--,d++) temp2[d]=B[c];
    for(int k=0;k<10;++k) printf("%d ",temp2[k]);
    
    int index1=0,index2=0;
    for(int k=19;k>=0;--k){
        if(index1==10)
            C[k]=B[index2++];
        else if(index2==10)
            C[k]=A[index1++];
        else{
            if(A[index1]<B[index2])
                C[k]=A[index1++];
            else
                C[k]=B[index2++];
        }     
    }
    printf("\n\n\nIki dizi C dizisinde birlestirildi.\n\n");
    printf("C dizisi elemanlari\n");
    for(int k=0;k<20;++k) printf("%d ", C[k]);
    getch();
    return 0;
}
