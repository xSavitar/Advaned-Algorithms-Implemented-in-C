/* Filename: Plane-Sweep.c */
/* Author: Alangi Derick (d3r1ck) */
/* Description: This is the implementation of the plane-sweep algorithm which is an optimised
		version of the brute-force maxima algorithm for returning the maximal points on
		a graph. */
		
//including of header files
#include<stdio.h>
#include<stdlib.h>

//declaration of (x,y) point structure for reading the points
typedef struct Points {
	int x_coord;
	int y_coord;
}Points;


//definition of macro for the size
#define N 20

//function prototype for Plane-Sweep, Sorting
void Plane_Sweep_Maxima(int n);
void Sort_Points(int);
void Stack_Push(int, int);
int Stack_Pop(void);
void Display_Stack();

//declaration of a global array for the points
Points points[N];
int top;

//memory allocation for the stack
Points Stack[N];

//main function definition
int
main(void){
	int i, number;
	printf("--------------------Plane-Sweep Algorithm----------------------\n");
	printf("Enter the number points(x,y): ");
	scanf("%d", &number);
	
	if(number<1){
		exit(1);
	}
	
	else {
		for(i=0; i<number; i++){
			scanf("%d%d", &points[i].x_coord, &points[i].y_coord);
		}
	}
	
	////sort the points in 2D_Points[] in order of x.
	Sort_Points(number);
	
	//function call to plane-sweep maxima algorithm
	Plane_Sweep_Maxima(number);
	
	//prints the maximal points on the graph
	printf("\n---------------------End of Plane-Sweep-Maxima Algorithm-------------\n");

return 0;
}

//definition of sorting function
//this function sort the points in increasing order of x
void Sort_Points(int n){
	int temp, i, j;
	for(i=0; i<n; i++){
		for(j=i; j<n; j++){
			if(points[i].x_coord >= points[j].x_coord){
				temp = points[i].x_coord;
				points[i].x_coord = points[j].x_coord;
				points[j].x_coord = temp;
			}
		}
	}
}

//definition of stack push
void Stack_Push(int x, int y){
	Stack[top++].x_coord = x;
	Stack[top++].y_coord = y;
}

//definition of the stack pop
int Stack_Pop(void){
	return Stack[--top].x_coord;
}

//definition of the display stack function
void Display_Stack(void){
	int i;
	for(i=N-1; i>=0; i++){
		printf("Maximal Values are: (%d, %d)\n", Stack[i].x_coord, Stack[i].y_coord);
	}
}

//definition of the notEmpty function
//int Empty(void){
//	return 1;
//}

//definition of the plane-sweep algorithm
void Plane_Sweep_Maxima(int n){
	int i;
	for(i=0; i<n; i++){
		while(Stack[top].y_coord <= points[i].y_coord){
			//pop item
			Stack_Pop();
			Stack_Push(points[i].x_coord, points[i].y_coord);
		}
	}
	//output the contents of the stack
	Display_Stack();
}

