/*Jacob Cassady
CS 130-01
Professor: Dr. Roman Yampolskiy
Lab 4: Calculator w/ functions
Date Created: 09/08/15*/

#include <stdio.h>

//Declare Functions
int addTwoNumbers(int, int);
int subtractTwoNumbers(int, int);
int multiplyTwoNumbers(int, int);
float divideTwoNumbers(float, float);
int modulus(int, int);
int testIfPrime(int);
int factorial(int);
int power(int, int);
int fibonacci(int);

//Main Function
int main(void) {
	//Variable Declaration
	int operation, responseOne, responseTwo, stop;
	float numerator, denominator;
	
	//Initialization
	operation=0; //Used to store which operation the user would like to perform.
	responseOne = 0; //Used to store user response throughout the main function.
	responseTwo = 0; //Used to store user response throughout the main function.
	numerator = 0; //Used to store the numerator for the divideTwoNumbers function.
	denominator = 0; //Used to store the denominator for the divideTwoNumbers function.
	stop = 0; //Used to stop the program (accomplished by an input of 7)
	
	while(stop==0){
		//Calculator menu
		printf("\n\n\tCalculator Menu:\n");
		printf("\t(1)Addition\n");
		printf("\t(2)Subtraction\n");
		printf("\t(3)Multiplication\n");
		printf("\t(4)Division\n");
		printf("\t(5)Modulus(integers only)\n");
		printf("\t(6)Test if prime(integers only)\n");
		printf("\t(7)Factorial(integers only)\n");
		printf("\t(8)Power\n");
		printf("\t(9)Fibonacci term\n");
		printf("\t(0)Exit\n");
		printf("\n\tPlease choose an operation:");
		scanf("%i",&operation);
	
		//Switch, used to produce different output depending the operation chosen
		switch(operation){
			case 1: //Addition
				printf("\tEnter the first number:");
				scanf("%i",&responseOne);
				printf("\tEnter the second number:");
				scanf("%i",&responseTwo);
				addTwoNumbers(responseOne, responseTwo);
				system("pause");
				system("cls");
				break;
			case 2: //Subtraction
				printf("\tEnter the first number:");
				scanf("%i",&responseOne);
				printf("\tEnter the second number:");
				scanf("%i",&responseTwo);
				subtractTwoNumbers(responseOne, responseTwo);
				system("pause");
				system("cls");
				break;
			case 3: // Multiplication
				printf("\tEnter the first number:");
				scanf("%i",&responseOne);
				printf("\tEnter the second number:");
				scanf("%i",&responseTwo);
				multiplyTwoNumbers(responseOne, responseTwo);
				system("pause");
				system("cls");
				break;
			case 4: // Division
				printf("\tEnter the numerator:");
				scanf("%f",&numerator);
				printf("\tEnter the denominator:");
				scanf("%f",&denominator);
				divideTwoNumbers(numerator, denominator);
				system("pause");
				system("cls");
				break;
			case 5: // Modulus
				printf("\tEnter the first number (integers only):");
				scanf("%i", &responseOne);
				printf("\tEnter the second number (integers only):");
				scanf("%i", &responseTwo);
				modulus(responseOne, responseTwo);
				system("pause");
				system("cls");
				break;
			case 6: // Prime Check.  The dings integer is used to give the factor printout some variety and to report if the number is not a prime.
				printf("\tEnter an interger:");
				scanf("%i",&responseOne);
				testIfPrime(responseOne);
				system("pause");
				system("cls");
				break;
			case 7: //Factorial
				printf("\tEnter an integer:");
				scanf("%i", &responseOne);
				factorial(responseOne);
				system("pause");
				system("cls");
				break;
			case 8: //Power
				printf("\tEnter the base:");
				scanf("%i", &responseOne);
				printf("\tEnter the exponent:");
				scanf("%i", &responseTwo);
				power(responseOne, responseTwo);
				system("pause");
				system("cls");
				break;
			case 9: //Fibonacci
				printf("\tEnter the desired Fibonacci Term: ");
				scanf("%i",&responseOne);
				fibonacci(responseOne);
				system("pause");
				system("cls");
				break;
			case 0: // Exit Program
				printf("\n\n\tGood Bye!");
				stop = 1;
				break;
			default: // Default (For improper inputs)
				printf("\n\tYou did not input a number 1-10\n");
				system("pause");
				system("cls");
		}//End switch
	}
}

/****************************************Function Definition******************************************************/
int addTwoNumbers(int firstNumber, int secondNumber){
	printf("\t%i + %i = %i\n",firstNumber,secondNumber, firstNumber+secondNumber);
	return 0;
} // End addTwoNumbers();

/****************************************Function Definition******************************************************/
int subtractTwoNumbers (int firstNumber, int secondNumber){
	printf("\t%i - %i = %i\n", firstNumber, secondNumber, firstNumber-secondNumber);
	return 0;
}

/****************************************Function Definition******************************************************/
int multiplyTwoNumbers(int firstNumber, int secondNumber){
	printf("\t%i x %i = %i\n", firstNumber, secondNumber, firstNumber*secondNumber);
	return 0;
}//End multiplyTwoNumbers();

/****************************************Function Definition******************************************************/
float divideTwoNumbers(float firstNumber, float secondNumber){
	if (secondNumber == 0){
		printf("\t\nThe answer is undefined because you divided by 0.\n");
	} else {
		printf("\t%.0f / %.0f = %.2f\n", firstNumber, secondNumber, firstNumber/secondNumber);
	}
	return 0;
} //End divideTwoNumbers

/****************************************Function Definition******************************************************/
int modulus (int firstNumber, int secondNumber){
	while(secondNumber == 0){
		printf("\tOops! Undefined.  Your first number was %i.  Enter another second number that is not 0. \n\t Remember: Integers only!:", firstNumber);
		scanf("%i", &secondNumber);
	}
	printf("\t%i %% %i = %i\n", firstNumber, secondNumber, firstNumber%secondNumber);
	return 0;
} //End modulus();

/****************************************Function Definition******************************************************/
int testIfPrime(int response){
	//Declare
	int dings, i;
	
	//Initialize
	dings = 0;
	
	if (response == 0) {
		printf("\n\t0 is not a prime number\n");
	} else {
		for(i = 2; i <= (response / 2); i++){
			if (response%i==0) {
				if(dings == 0){
					printf("\tNot prime.  %i / %i = %i\n", response, i, response/i);
					dings++;
				} else {
					printf("\t\t    %i / %i = %i\n", response, i, response/i);
					dings++;
					continue;
				}
			}
			if(dings == 0){
				printf("\t%i is a prime number\n", response);
			}
		}
	}
	dings = 0;				
	return 0;
} // End testIfPrime()

/****************************************Function Definition******************************************************/
int factorial(int response){
	int answer, i;
	answer =1;
	
	for(i = response; i>0; i--){
		answer *= i;
	}
	printf("\tThe factorial of %i = %i\n", response, answer);
	return 0;
} //End factorial();

/****************************************Function Definition******************************************************/
int power(int base, int exponent){
	//Declare
	int i, answer;
	
	//Initalize
	answer = 1;
	
	if (exponent == 0){
		printf("\t%i ^ %i = 1\n", base, exponent);
	} else {
		for (i = 0; i < exponent; i++){
			answer *= base;
		}
		printf("\t%i ^ %i = %i\n", base, exponent, answer);
	}
	return 0;
} //End power()

/****************************************Function Definition******************************************************/
int fibonacci(int term){
	//Declare
	int result, i;
	int cache[2] = {0 ,1};
	
	//Initalize
	result = 0;
	
	//Print results.
	printf("\tFibonacci terms 0-%i:", term);
	for(i=0;i<=term;i++){
		if (i<=1){
			result = i;
		} else {
			result = cache[0] + cache[1];
			cache[0] = cache[1];
			cache[1] = result;
		}
		printf("\n\tTerm %i = %i:",i, result);
	}
	printf("\n");
	return 0;
} //End fibonacci()
