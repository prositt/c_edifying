#include "center.h"

/* Tracks date and time of coding */

int main(){
	/* Needs to initialize time in a function (not compiler) */
	time_t t = time(NULL);
	tm = *localtime(&t);

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

	printf("X -> %i\n\n", get_date());
	return(0);
}

/* Get todays date (not finished) */
int get_date(){
	int x = 1234;
	printf("Year: %d \n", tm.tm_year+1900);
	printf("Mon: %s \n", months[tm.tm_mon]);
	printf("Day: %02d \n", tm.tm_mday);
	printf("Time: %02d:%02d:%02d \n", tm.tm_hour,tm.tm_min, tm.tm_sec);
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
