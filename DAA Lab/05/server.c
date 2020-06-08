#include "session5_sort.h"
#include <stdbool.h>

int Result[3];

long int InsertionSort(Record *A, int n){
	for(int i = 0; i < n; i++){
    	Record Temp = A[i];
    	int j = i - 1;
    	while (j >= 0 && A[j].serialnumber > Temp.serialnumber){
    		A[j+1] = A[j];
      		j--;
      		Result[0]++;
    	}
    	A[j+1] = Temp;
  	}
  	return Result[0];
}

long int BubbleSort(Record *A, int n){
	for(int i = 0; i < n-2; i++){
    	bool noSwaps = true;
    	for(int j = 0; j < n-2-i; j++){
      		Result[1]++;
      		if(A[j].serialnumber > A[j+1].serialnumber){
        		Record Temp = A[j];
        		A[j] = A[j+1];
        		A[j+1] = Temp;
        		noSwaps = false;
      		}
    	}
    	if(noSwaps) 
    		return Result[1];
  	}
  	return Result[1];
}

long int SelectionSort(Record *A, int n){
	for(int i = 0; i < n-1; i++){
    	int min = i;
    	for(int j = i+1; j < n; j++){
      		Result[2]++;
      		if(A[j].serialnumber < A[min].serialnumber) 
      			min = j;
    	}
    	Record temp = A[i];
    	A[i] = A[min];
    	A[min] = temp;
  	}
  return Result[2];
}

long int binsearch(Record *A, Record key, int low, int high){
	if(high <= low){
		if(key.serialnumber < A[low].serialnumber)
			return low;
		else
			return low + 1;
	}
	int mid = (high + low) / 2;
	if(key.serialnumber < A[mid].serialnumber)
		return binsearch(A, key, low, mid-1);
	else
		return binsearch(A, key, low+1, mid);
}

long int InsertionBinSort(Record* A, int n){
	long int count = 0;
	for(int i = 1; i < n; ++i){
		Record temp = A[i];
		int j = i - 1;
		int bc = binsearch(A, temp, 0, j-1);
		while(j >= 0 && A[j].serialnumber > temp.serialnumber){
			A[j+1]=A[j];
			j--;
			count++;
		}
		count++;
		A[j+1] = temp;
	}
	return count;
}


