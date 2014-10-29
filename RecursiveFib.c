/* Filename: FibonacciAlgorithm.c */
/* Author: Alangi Derick */
/* Description: This is a program to implement fibonacci
		recursive problems using functions */
		
//include header file
#include<stdio.h>
#include<stdlib.h>

//user defined data type
typedef int Fibonacci;

//function prototype
int Fib(Fibonacci);

//main function definition
int
main(int argc, char **argv){
	Fibonacci Num = atoi(argv[1]);
	int i;
	
	//printf("Enter a number to generate the Fibonacci series: ");
	//scanf("%d", &Num);
	
	for(i=0; i<=Num; i++){
		printf("%d ", Fib(i));
	}
	printf("\n");
return 0;
}

//function definition for generation of fibonacci numbers.
int Fib(Fibonacci num){
	if(num < 2)
		return num;
	else
		return Fib(num - 1) + Fib(num - 2);
}
