#include "center.h"

/* Tracks date and time of coding */

int main(){

	printf("Hello world!\n\n");
	
	int nbr = 10;
	int* nbr_ptr;

	nbr_ptr = &nbr;

	
	printf("nbr value: %i\n", nbr);
	printf("nbr adress: %ld\n", &nbr);
	printf("nbr size: %ld\n\n", sizeof(nbr));	
	
	printf("nbr_ptr value: %i\n", *nbr_ptr);
	printf("nbr_ptr adress: %ld\n", nbr_ptr);
	printf("nbr_ptr size: %ld\n\n", sizeof(nbr_ptr));

	printf("Get user input...\n");
	switch(get_input(nbr_ptr, sizeof(nbr_ptr))){
		case 0:
			printf("\nSuccess\n");
			break;

		case 1:
			printf("\nFail!\n");
			break;
	}

	switch(get_input(nbr, sizeof(nbr))){
		case 0:
			printf("\nSuccess\n");
			break;

		case 1:
			printf("\nFail!\n");
			break;
	}
	printf("nbr_ptr value is now: %i\n", *nbr_ptr);
	printf("nbr_ptr adress: %i\n", nbr_ptr);
	printf("nbr_ptr size is now: %ld\n\n", sizeof(nbr_ptr));

	printf("nbr value is now: %i\n", nbr);
	printf("nbr adress: %i\n",  &nbr);
	printf("nbr size is now: %ld\n\n", sizeof(&nbr));

	return(0);
}

/* Get todays date (not finished) */
int get_date(){
	int x = 1234;
	printf("Todays date is %i\n", x);
	return x;
}

/* Get input from user */
int get_input(int* ptr, size_t size){
	int input;

	printf("ptr value is now: %i\n", *ptr);
	printf("ptr adress: %i\n", ptr);
	printf("ptr size is now: %ld\n\n", sizeof(ptr));

	printf( "Enter input: ");
	scanf("%i", &input );
	printf( "Input: %i\n", input);
	

	if (sizeof(input) > size){
		printf("Size of input(%ld) is larger than nbr(%ld)\n\n", sizeof(input), sizeof(ptr));
		return 1;
	} else {
		printf("Size OK, %ld <= %ld\n\n", sizeof(input), sizeof(size));
	}

	printf("ptr value is now: %i\n", *ptr);
	printf("ptr adress: %i\n", ptr);
	printf("ptr size is now: %ld\n\n", sizeof(ptr));

	printf("...pointer assigned...\n\n");
	*ptr = input;
	printf("ptr value is now: %i\n", *ptr);
	printf("ptr adress: %i\n", ptr);
	printf("ptr size is now: %ld\n\n", sizeof(ptr));
	return 0;
}
