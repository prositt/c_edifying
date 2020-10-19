#include "center.h"

/* Tracks date and time of coding */

int main(){

	printf("Hello world!\n\n");
	
	char* string = "Initiated"; 
	printf("String status: %s\n", string);
	printf("String size: %ld\n\n", sizeof(string));	
	
	buf = string;
	printf("Buffer status: %s\n", buf);
	printf("Buffer size: %ld\n\n", sizeof(buf));

	printf("Get user input...\n");
	get_input(&buf, sizeof(buf));
	printf("Buffer in main: %s \n\n", buf);

	return(0);
}

/* Get todays date (not finished) */
int get_date(){
	int x = 1234;
	printf("Todays date is %i\n", x);
	return x;
}

/* Get input from user */
int get_input(char* buf, int buf_size){
	char str[250];
	char* str_ptn;

	printf( "Enter input: " );
	scanf("%s", str );
	printf( "String: %s\n", str);
	
	str_ptn = str;

	if (sizeof(str_ptn) > buf_size){
		printf("Size of string(%ld) is larger than buffer(%ld)\n", sizeof(str_ptn), sizeof(buf));
		return 1;
	}
	*buf = str_ptn;
	printf("Buffer is now: %s\n", buf);
	printf("Buffer size is now: %s\n\n", sizeof(buf));
	return 0;
}
