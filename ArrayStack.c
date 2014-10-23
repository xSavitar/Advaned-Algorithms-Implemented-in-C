/******************************/
/** Filename: ArrayStack.c ***/
/** Author: Alangi Derick ****/
/** Description: This is a Program that simulates the behavior of Stack
		Data structures and time complexity of pusing n items
		and popping n/2 items */
		
//inclusion of header files.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//definition of macros
#define N 20
typedef int Item;

//function prototypes.
void Push_Item_To_Stack(int);
int Pop_Item_From_Stack(void);
void Initialise_Stack(int);
int Stack_Empty(void);
int Stack_Full(void);
void Print_Stack_Content(int);

//declaration of global variables
int *Stack; //stack will contain integer
int Top; //top of the stack

//main function definition
int 
main(void){
	Item item, i;

	//generation of random numbers using my seed value as the 
	// system time for perfect runtime simulation
	srand(time(NULL));
	
	printf("This is a program that simulates the behavior of Stack Data Structure.\n");

	printf("\nInitialising the Stack...\n");
	Initialise_Stack(N);
	sleep(1);
	
	printf("Pushing Elements to the Stack.\n");
	for(i=0; i<N; i++){
		if(!Stack_Full()){
			Push_Item_To_Stack(rand() % 100);	
		}
	}
	printf("Initial Content of the Stack(%d items) is: ", N);
	Print_Stack_Content(N);
	
	for(i=0; i<(N/2); i++){
		if(!Stack_Empty()){
			Pop_Item_From_Stack();
		}
	}
	printf("\nAfter Popping %d items, Stack now Contains: ", N/2);
	
	//printf the remaining items in the stack
	Print_Stack_Content(N/2);	
return 0;
}

//function definition
//initialisation of the stack(Allocation of space using malloc)
void Initialise_Stack(int size){
	Stack = malloc(size * sizeof(int));
	Top = 0;
}

//pushing items to the stack 
void Push_Item_To_Stack(Item item){
	Stack[Top++] = item;
}

//popping of items from the stack
int Pop_Item_From_Stack(void){
	return Stack[--Top];
}

//Function to see if the stack is full
int Stack_Full(void){
	return 0;
}

//Check to see if the stack is empty
int Stack_Empty(void){
	return 0;
}

//Displaying the content of the stack
void Print_Stack_Content(int n){
	int i;
	for(i = n - 1; i>=0; i--){
		printf("%d ", Stack[i]);
	}
	printf("\n");
}
