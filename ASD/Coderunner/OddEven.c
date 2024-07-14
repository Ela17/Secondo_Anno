#include <stdio.h>
#include <stdlib.h>
void swap(int A[], int i, int j);
/**
 * si implementi la funzione OddEven():
 * pre: 0 <= n < dim A[]
 * post: permuta gli elementi di A[0..n-1] in modo che i dispari precedano i pari
*/
void OddEven(int A[], int n) {
	if(n >= 1) {
		int i = 0, j = n-1;
		while(A[i] % 2 == 1) i++;
		while(A[j] % 2 == 0) j--;
		while(i < j) {
			if(A[i] % 2 == 0) {
				if(A[j] % 2 == 1) {
					swap(A, i, j);
					j--;
					i++;
				}
				else j--;
			}
			else {
				if(A[j] % 2 == 0) j--;
				i++;
			}
		}
	}
}

// Nota: l'algoritmo si può realizzare in tempo lineare e sul posto, senza array ausiliari, scambiando tra loro gli elementi dell'array mediante swap:
void swap(int A[], int i, int j) {
  int tmp = A[i];
  A[i] = A[j];
  A[j] = tmp;
}

int main() {
  int A[] = {1,4,6,7,9,3,2,8};
  OddEven(A, 8);
  for (int i = 0; i < 8; i++)
	printf("%d ", A[i]);
  printf("\n");
  return 0;
}