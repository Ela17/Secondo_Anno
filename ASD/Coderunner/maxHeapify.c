#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct heapFrame {
	int dim, hd;
	int* keys;
};

typedef struct heapFrame* Heap;

void maxHeapify(int H[], int i, int hd);

Heap newHeap(int n) {
	Heap h = malloc(sizeof(struct heapFrame));
	h->dim = n;
	h->hd = 0;
	h->keys = malloc(n*sizeof(int));
	return h;
}

// pre: 0 <= i <= hd
// post: 2*i + 1 se <= hd, i altrimenti
int left(int i, int hd){
	int leftIndex = 2 * i + 1;
	return (leftIndex <= hd) ? leftIndex : i;
}
// pre: 0 <= i <= hd
// post: 2*1 + 2 se <= hd, i altrimenti
int right(int i, int hd) {
	int rightIndex = 2 * i + 2;
	return (rightIndex <= hd) ? rightIndex : i;
}
// pre: 0 <= i
// post: (i - 1) div 2 se i > 0, i altrimenti
int parent(int i) {
	return (i > 0) ? (i - 1) / 2 : i;
}


void showHeap(Heap h) {
	for(int i = 0; i < h->hd; i++) {
		printf("%d ", h->keys[i]);
	}
	printf("\n");
}

void swap(int A[], int i, int j) {
	int tmp = A[i];
	A[i] = A[j];
	A[j] = tmp;
}


// pre:  hd < dim A[]
// post: A[0..hd] e' uno heap massimo
void buildMaxHeap(int A[], int dim)
{
	int m = dim/2 + 1;
	for(int i = m; i >= 0; i--) {
		maxHeapify(A, i, dim);
	}
}

// pre:  0 < dim <= dim A[]
// post: A[0..dim-1] ordinato in modo non decrescente
void heapSort(int A[], int dim)
{
	buildMaxHeap(A, dim-1);

	for(int i = dim-1; i > 0; i--) {
		swap(A, i, 0);
		maxHeapify(A, 0, i-1);
	}
}


/****************************************************************************/

//Si implementi la funzione:
// pre: 0 <= i <= hd < dim H[], H[left(i, hd)..hd] e H[right(i, hd)..hd] sono heap massimi
// post: H[i..hd] è uno heap massimo
void maxHeapify(int H[], int i, int hd) {
	int l = left(i, hd);
	int r = right(i, hd);

	int m = i;

	if(l < hd && H[l] > H[m]) m = l;
	if(r < hd && H[r] > H[m]) m = r;

	if(m != i) {
		swap(H, i, m);
		maxHeapify(H, m, hd);
	}
}
//in modo che le funzioni preimplementate buildMaxHeap() e heapSort() eseguano correttamente.


int main() {
	int arr[] = {4, 10, 3, 5, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	Heap h = newHeap(n);

	for (int i = 0; i < n; i++) {
		h->keys[i] = arr[i];
	}
	h->hd = n;

	printf("Original array:\n");
	showHeap(h);

	heapSort(h->keys, h->hd);

	printf("Sorted array:\n");
	showHeap(h);

	free(h->keys);
	free(h);
	return 0;
}