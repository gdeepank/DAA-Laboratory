#include<stdio.h>
#include "quickSort.h"

ptrPair divide(int *a, int n){
    ptrPair newPair;
    int pi = getPartitionIndex(a,n);
    newPair.first = &a[0];
    newPair.second = &a[pi]+1;
    newPair.firstLen = pi+1;
    newPair.secondLen = n-pi-1;
    return newPair;
}

int getPartitionIndex(int *a, int n){ 
    int p = a[0]; 
    int i = -1, j = n; 
    while(1){
        do{ 
            i++; 
        }while (a[i] < p); 
        
        do{ 
            j--; 
        }while (a[j] > p);

        if (i >= j) 
            return j; 
        
        int temp = a[i];
        a[i]=a[j];
        a[j]=temp;
    } 
} 

void conquer(int *a, int n){
    if(n>1){
        ptrPair newPair = divide(a,n);
        conquer(newPair.first,newPair.firstLen);
        conquer(newPair.second,newPair.secondLen);
    }
}

void quickSort(int *a, int n){
    conquer(a,n);
}

int isSorted(int *a, int n){
    for(int i = 0; i < n-1; ++i)
        if(a[i] > a[i+1])
            return 0;
    return 1;
}

