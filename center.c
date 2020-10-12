#include "center.h"

/* Tracks date and time of coding */

int main(){

	printf("Hello world!\n\n");
	printf("Now featuring header...\n");

	printf("Wanting user input...\n");

	char star[100];
	printf( "Enter task: " );
	scanf("%s", star );
	printf( "String: %s\n", star);

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
	printf( "Enter task: " );
	scanf("%s", str );
	printf( "String: %s\n", str);
	return str;
}
