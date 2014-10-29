/* Filename: IterFib.c */
/* Author: Alangi Derick */
/* Description: This is a program that implements Fibonacci series using
		memoisation with the use of arrays, speeding up the normal
		recursive fibonacci series generator. */
		
//include header file
#include<stdio.h>
#include<stdlib.h>

//macro
#define N 10

//user defined data type
typedef int Fibonacci;

//global array
Fibonacci Fib[100];

//function prototype
void IterFib(Fibonacci);

//main function definition
int
main(int argc, char **argv){
	Fibonacci Num = atoi(argv[1]);
	int i;
	
	//printf("Enter a number to generate the Fibonacci series: ");
	//scanf("%d", &Num);
	
	IterFib(Num);
	
	printf("\n");
return 0;
}

//function definition for generation of fibonacci numbers.
void IterFib(Fibonacci num){
	int i;
	Fib[0] = 0;
	Fib[1] = 1;
	
	for(i=2; i<=num; i++){
		Fib[i] = Fib[i-1] + Fib[i-2];
	}
	
	for(i=0; i<=num; i++){
		printf("%d ", Fib[i]);
	}
}
