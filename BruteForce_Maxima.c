/* Filename: BruteForce_Maxima.c */
/* Author: Alangi Derick */
/* Description: This is a program that is meant to implement the brute-force maxima algorithm
		of a given set of points in a graph, it computes and compares all the points 
		with each other on the graph using a brute-force approach and returns the maximal
		points. */
		
		
#include<stdio.h>
#include<stdlib.h>

//macro definition
#define N 20

//declaration of a function
typedef struct Points {
	int x_coord;
	int y_coord;
}Points;

//function prototypes
void Maxima(int);

//declaration of a global variable
Points points[N];

//main function definition
int 
main(void)
{
	int i, j, n;
	
	printf("---------------Brute-Force Maxima Algorithm-------------------\n");
	
	printf("How many points do you want to enter: ");	
	scanf("%d", &n);
	
	//read the number of points you want to plot on the graph
	// if the number of points is less than one, which means no point on the graph
	//it exits the program.
	/* But if the number of points is one: it returns the point or if the number of points
	   is greater than one, then it outputs the maximal points */
	   
	if(n < 1){
		exit(1);
	}
	else {
		for(i=0; i<n; i++){
			scanf("%d%d", &points[i].x_coord, &points[i].y_coord);
		}
	}
	
	//calls the brute-force algorithm to compute the maximal points.
	Maxima(n);
	
	printf("\n-------------End of Brute-Force Maxima Algorithm----------\n");
return 0;
}


//function definition of brute-force maxima algorithm
void Maxima(int n){
	int i, j, maximal;
	for(i=0; i<n; i++){
			maximal = 1;
			for(j=0; j<n; j++){
				//printf("point: (%d, %d)\n", points[i].x_coord, points[i].y_coord);
				//does the comparison of the points.
				if(i!=j && (points[i].x_coord <= points[j].x_coord) 
					&& (points[i].y_coord <= points[j].y_coord)){
					maximal = 0;
					break;
				}
		}
		if(maximal==1){
				printf("Maximal point: p(%d, %d).\n", points[i].x_coord, points[i].y_coord);
			}
	}
}
