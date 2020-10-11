#include "center.h"

/* Tracks date and time of coding */

int main(){

	printf("Hello world!\n\n");
	printf("Now featuring header...\n");

	x = get_date();
	printf("x = %i\n", x);

	return(0);
}

/* This should be added */
int get_date(){
	int x = 1234;
	printf("Todays date is %i\n", x);
	return x;
}
