#include <stdio.h>

int isSorted(int *a, int n){
	for(int i = 0; i < n-1; i++){     
		if(a[i] > a[i+1])
        	return 0;
    }    
    return 1;
}

void bubblePass(int *a, int n){
    for(int i = 0; i < n-1; i++){
      	if(a[i] > a[i+1]){
        	int temp = a[i]; 
            a[i] = a[i+1];
            a[i+1] = temp;
        }
    }
}

void bubbleSort(int *a, int n){
    while((isSorted(a, n)) == 0){
        bubblePass(a, n);
    }
}

int numBubblePasses(int *a, int n){
    int count = 0;
    while((isSorted(a, n)) == 0){
        bubblePass(a, n);
        count++;
    }
    return count;
}

int maxIndex(int *a, int n){
    int max = 0;
    for(int i = 0; i < n; i++){
      	if(a[i] >= a[max])
    	  	max = i;
    }
    return max;
}

void swapWithMax(int *a, int n){
    int max = maxIndex(a, n);
    if(max < n-1){
    	int temp = a[max];
        a[max] = a[n-1];
        a[n-1] = temp;
    }
}

void selectionSort(int *a, int n){
    for(int i = n-1; i > 0; i--){
    	if((isSorted(a, n) == 0))
    	    swapWithMax(a, i+1);
    }
}

int numSwaps(int *a, int n){
    int count = 0;
    for(int i = 0; i < n-1; i++){
    	if((n-i-1) > maxIndex(a, n-i)){
    		swapWithMax(a, n-i);
    		count++;
        }
    }
    return count;
}

