#include "center.h"

/* Tracks date and time of coding */

int main(){

	printf("Hello world!\n\n");
	
	int nbr = 10;
	int* nbr_ptr;

	nbr_ptr = &nbr;
	
	int_info(nbr_ptr);

	printf("Get user input...\n");
	switch(get_input(nbr_ptr)){
		case 0:
			printf("\nSuccess\n");
			break;

		case 1:
			printf("\nFail!\n");
			break;
	}

	int_info(nbr_ptr);

	printf("nbr value is now: %i\n", nbr);

	return(0);
}

/* Get todays date (not finished) */
int get_date(){
	int x = 1234;
	printf("Todays date is %i\n", x);
	return x;
}

/* Get input from user */
int get_input(int* ptr){
	int input;

	int_info(ptr);
	printf( "Enter input: ");
	scanf("%i", &input );
	printf( "Input: %i\n", input);
	
	if (sizeof(input) > sizeof(*ptr)){
		printf("Size of input(%ld) is larger than nbr(%ld)\n\n", sizeof(input), sizeof(*ptr));
		return 1;
	} else {
		printf("Size OK, %ld <= %ld\n\n", sizeof(input), sizeof(*ptr));
	}

	int_info(ptr);

	*ptr = input;
	int_info(ptr);

	return 0;
}

int int_info(int* ptr){
	if(dbg){
		printf("ptr value: %i\n", *ptr);
		printf("ptr adress: %i\n", ptr);
		printf("ptr value size: %ld\n\n", sizeof(*ptr));
		return 0;
	}
}
