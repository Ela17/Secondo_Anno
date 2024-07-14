#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct hashFrame {
	int    dim;  // dimensione della tabella
	int* array;  // puntatore alla tabella array[0..dim-1]
};

typedef struct hashFrame* HashTable;

// pre:  0 < m
// post: ritorna una tabella hash di dimensione m a chiavi positive,
//       inizializzata con tutti -1 che rappresenta l'assenza di chiavi
HashTable newHashTable(int m)
{
  HashTable T = malloc(sizeof(struct hashFrame));
  T->dim = m;
  T->array = malloc(m * sizeof(int));
  for(int i = 0; i < m; i++)
	T->array[i] = -1;
  return T;
}

// pre:  0 <= k chiave, 0 < m == dimensione della tabella
// post: ritorna k mod m
int hashFun(int k, int m)
{
  return k % m;
}

// pre:  0 <= k chiave, 0 <= i iterazione, 0 < m == dimensione della tabella
// post: ritorna (hashFun(k, m) + i) mod m
int linearProbing(int k, int i, int m)
{
  return (hashFun(k, m) + i) % m;
}

// post: stampa gli elementi di A[0..n-1]
void printarray(int A[], int n) {
  for (int i = 0; i < n; i++)
	printf("%d  ", A[i]);
  printf("\n");
}


/*******************************************************************************************/

// si implementi la funzione:
// pre: 0 >= k chiave, T tabella hash correttamente allocata
// post: ritorna
//       -1 se la chiave k era presente in T
//       j se k è stato inserito in T alla posizione j
//       -2 se non c'è spazio per inserire k (overflow)
int hashInsert(HashTable T, int k) {
	int m = T->dim;
	bool done = false;
	int i = 0;
	int value;

	while(!done && i < m) {
		value = linearProbing(k, i, m);
		if(T->array[value] == -1) {
			T->array[value] = k;
			done = true;
		}
		else if(k == T->array[value]){
			return -1;
		}
		else i++;
	}

	if(!done) return -2;
	return value;
}


int main() {
  HashTable T = newHashTable(10);
  printf("%d : \t", hashInsert(T, 5)); // 5
	printarray(T->array, 10);
  printf("%d : \t", hashInsert(T, 5)); // -1
	printarray(T->array, 10);
  printf("%d : \t", hashInsert(T, 15)); // 5
	printarray(T->array, 10);
  printf("%d : \t", hashInsert(T, 25)); // 5
	printarray(T->array, 10);
  printf("%d : \t", hashInsert(T, 35)); // 5
	printarray(T->array, 10);
  printf("%d : \t", hashInsert(T, 45)); // 5
	printarray(T->array, 10);
  printf("%d : \t", hashInsert(T, 55)); // 5
	printarray(T->array, 10);
  printf("%d : \t", hashInsert(T, 65)); // 5
	printarray(T->array, 10);
  printf("%d : \t", hashInsert(T, 35)); // -1
	printarray(T->array, 10);
  printf("%d : \t", hashInsert(T, 75)); // 5
	printarray(T->array, 10);
  printf("%d : \t", hashInsert(T, 85)); // 5
	printarray(T->array, 10);
  printf("%d : \t", hashInsert(T, 95)); // 5
	printarray(T->array, 10);
  printf("%d : \t", hashInsert(T, 14)); // -2
	printarray(T->array, 10);
  return 0;
}