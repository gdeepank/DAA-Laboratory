#include"heapSort.h"

Heap buildMaxHeap(int *const a, int n){
	Heap h;
	h.a = a;
	h.size = n;
	int i = h.size/2 - 1;
	while(i >= 0){
		maxHeapify(h,i);
		i--;
	}
	return h;
}

void maxHeapify(Heap h, int idx){
	int large = idx;
    int l = 2*idx + 1; 
    int r = 2*idx + 2; 
    if (l < h.size && h.a[large] < h.a[l]) 
        large = l; 
    if (r < h.size && h.a[large] < h.a[r]) 
        large = r;  
    if (large != idx){ 
  		int temp = h.a[idx];
  		h.a[idx] = h.a[large];
  		h.a[large] = temp; 
        maxHeapify(h, large); 
    }
} 

void heapSort(int *const a, int n){
	Heap h;
	h.size = n;
	h.a = a;
	buildMaxHeap(h.a, h.size);
	for (int i = h.size-1; i>=0; i--){ 
        int temp = h.a[0];
  		h.a[0] = h.a[i];
  		h.a[i] = temp; 
  		h.size = i;
        maxHeapify(h, 0); 
    } 		
}

