#include "center.h"

/* Tracks date and time of coding */

int main(){
	/* Needs to initialize time in a function (not compiler) */
	time_t t = time(NULL);
	tm = *localtime(&t);


	printf("Hello world!\n\n");

	printf("X -> %i\n", get_date());
	return(0);
}

/* This should be added */
int get_date(){
	int x = 1234;
	printf("Year: %d \n", tm.tm_year+1900);
	printf("Mon: %s \n", months[tm.tm_mon]);
	printf("Day: %02d \n", tm.tm_mday);
	printf("Time: %02d:%02d:%02d \n", tm.tm_hour,tm.tm_min, tm.tm_sec);
	return x;
}
