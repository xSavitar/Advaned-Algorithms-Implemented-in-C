/* Filename: MergeSortImp.c */
/* Author: Alangi Derick */
/* Description: This is the implementation of merge sort using C and 
		case study arrays. */
		
//header files include
#include<stdio.h>
#include<stdlib.h>

//function prototypes
void Merge(int *, int, int, int);
void MergeSort(int *, int, int);

//main function definition
int
main(void){
	int size, *Array, i;
	
	printf("\n-------------------Merge Sort Algorithm--------------------\n\n");
	
	printf("Enter number of array cells: ");
	scanf("%d", &size);
	
	Array = malloc(size * sizeof(int));
	
	printf("Enter %d elements separated by spaces: ", size);
	for(i=0; i<size; i++){
		scanf("%d", &Array[i]);
	}

	//merge sorting takes place here by spliting the array into halves
	//for sorting.
	MergeSort(Array, 0, size - 1);
		
	printf("\n----------Sorted Array From Merge Sort Algorithm--------\n\n");
	printf("Sorted elements in the array is: ");
	for(i=0; i<size; i++){
		printf("%d ", Array[i]);
	}
	printf("\n");
return 0;
}

//implementation of the merge routine
void Merge(int *array, int min, int mid, int max){
	int temp[100];
	int i, j, k, m;
	
	j = min;
	m = mid + 1;
	
	for(i=min; j<=mid && m<=max ; i++){
		if(array[j] <= array[m]){
			temp[i] = array[j];
			j++;
		}
		else {
			temp[i] = array[m];
			m++;
		}
	}
	
	if(j > mid){
		for(k=m; k<=max; k++){
			temp[i] = array[k];
			i++;
		}
	}
	else {
		for(k=j; k<=mid; k++){
			temp[i] = array[k];
		}
	}
	for(k=min; k<=max; k++)
		array[k] = temp[k];	
}

//implementation of the splitting routine.
//this routine is responsible for divide and conquer approach
void MergeSort(int *array, int min, int max){
	int mid;
	if(min < max){
		mid = (min + max)/2;
		MergeSort(array, min, mid);
		MergeSort(array, mid+1, max);
		Merge(array, min, mid, max);
	}
}
