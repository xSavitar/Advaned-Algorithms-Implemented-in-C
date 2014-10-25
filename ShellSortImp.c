/* Filename: ShellSortImp.c */
/* Author: Alangi Derick */
/* Description: This is the implementation of sorting algorithms using
   		arrays */
   		
   		
//including header files
#include<stdio.h>
#include<stdlib.h>

//user type definition
typedef int Item;

//function prototype
void ShellSort(Item *, int *, int, int);

//main function definition
int 
main(void){
	Item *Array, Sequence[] = {8, 4, 2, 1};
	int size, i;
	
	printf("\n-------------------Shell Sorting Algorithm------------------\n\n");
	
	printf("Enter size of array: ");
	scanf("%d", &size);
	
	Array = (int *)malloc(size * sizeof(int));
	
	printf("Enter %d elements separated by spaces: ", size);
	for(i=0; i<size; i++){
		scanf("%d", &Array[i]);
	}
	
	printf("\n\nThe Unsorted Array is: ");
	for(i=0; i<size; i++){
		printf("%d ", Array[i]);
	}
	printf("\n");
	
	//this is a call to the shell sort function
	ShellSort(Array, Sequence, 0, size-1);
	
	//prints the sorted array
	printf("\n-----------------Sorted Array using Shell Sort------------------\n\n");
	printf("The Sorted Array is: ");
	for(i=0; i<size; i++){
		printf("%d ", Array[i]);
	}
	printf("\n");
	
	free(Array);
return 0;
}

//function definition for shell sort
void ShellSort(Item *array, int *sequence, int start, int stop){
	int step, i, j, inc;
	
	for(step = 0; sequence[step] >= 1; step++){
		inc = sequence[step];
		
		for(i = start + inc; i <= stop; i++){
			j = i;
			Item val = array[i];
			
			while((j >= start + inc) && val < array[j - inc]){
				array[j] = array[j - inc];
				j -= inc;
			}
			array[j] = val;
		}
	}
}
