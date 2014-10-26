/* Filename: QuickSortImp.c */
/* Author: Alangi Derick */
/* Description: QuickSort Algorithm is based on the divide and conquer approach
		and is the choice of sorting in most libraries. */

//TODO: Needs to be modified for proper sorting. So far, it reads the elements
//	sorting is not done correctly.

//include header files
#include<stdio.h>
#include<stdlib.h>

//user data type
typedef int Item;

//function prototypes
void QuickSort(Item *, int, int);
int Partition(Item *, int, int);
void Swap(Item *, int, int);

//main function definition
int
main(void){
	//srand(time(NULL));
	Item *Array;
	int i, size;
	
	printf("\n---------------Quick Sorting Algorithm-------------\n\n");
	printf("Enter size of the array: ");
	scanf("%d", &size);
	
	Array = (int *)malloc(size * sizeof(int));
	
	printf("Enter %d elements separated by spaces: ", size);
	for(i=0; i<size; i++){
		scanf("%d", &Array[i]);
	}
	
	printf("\n\nThe Unsorted array is: ");
	for(i=0; i<size; i++){
		printf("%d ", Array[i]);
	}
	
	//a call to the QuickSort() function
	QuickSort(Array, 0, size - 1);
	
	//prints the elements after sorting.
	printf("\n\nAfter Sorting, the array now is: ");
	for(i = 0; i<size; i++){
		printf("%d ", Array[i]);
	}
	printf("\n");
return 0;
}

//implementation of the prototypes
//Partition prototype definition
int Partition(Item *array, int p, int r){
	int x, i, j;
	
	x = array[r];
	i = p-1;
	
	for(j = p; j < r; j++){
		if(array[j] <= x){
			i = i + 1;
			Swap(array, i, j);
		}
		Swap(array, i+1, r);
	}
	return i+1;
}

//swapping the values in the array cells
void Swap(int *A, int i, int j){
	int temp;
	//swapping occurs
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

//implementation of the quick sort algorithm
void QuickSort(Item *array, int p, int r){
	int i, q;
	
	if(p < r){
		//i = rand() % r;
		//Swap(array, i, p);
		q = Partition(array, p, r);
		QuickSort(array, p, q-1);
		QuickSort(array, q+1, r);
	}
}
