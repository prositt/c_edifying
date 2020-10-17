#include "center.h"

/* Tracks date and time of coding */

int main(){

	printf("Hello world!\n\n");
	printf("Get user input\n");

	c = get_input();
	printf("C-> %c", c);

	return(0);
}

/* Get todays date (not finished) */
int get_date(){
	int x = 1234;
	printf("Todays date is %i\n", x);
	return x;
}

/* Get input from user */
const char* get_input(){
	char str[100];
	printf( "Enter task2: " );
	scanf("%s", str );
	printf( "String: %s\n", str);
	return str;
}
