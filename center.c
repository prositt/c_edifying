#include "center.h"

/* Tracks date and time of coding */

int main(){
	/* Needs to initialize time in a function (not compiler) */
	time_t t = time(NULL);
	tm = *localtime(&t);


	
	printf("Hello world!\n\n");
	
	log_mood();
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
	int pos;

	int_info(ptr);
	printf( "Enter input: ");
	scanf("%i %i", &pos, &input );
	printf( "Pos %i, input: %i\n", pos, input);
	
	if (pos > sizeof(ptr)){
		printf("Outside range, %ld > %ld\n\n", pos, sizeof(*ptr));
		return 1;
	} else {
		printf("Size OK, %ld <= %ld\n\n", pos, sizeof(*ptr));
	}

	ptr[pos] = input;
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

int print_arr(int arr[]){
	for (int i = sizeof(arr)+1; i >= 0; i--){
		printf("%i, ", arr[i]);
	}
	printf("\n");
}

int log_mood(){
	FILE* file;
	file = fopen("./doc/log.txt", "a");
	fprintf(file, "Date: %d.%s.%d\t", tm.tm_year+1900, months[tm.tm_mon-1], tm.tm_mday);
	fprintf(file, "Mood: %s\n", str_input());
	fclose(file);
}

char* str_input(){
	static char str[255];
	printf("Enter mood: (single word)\n");
	scanf("%s", &str);
	printf("%s\n", str);
	return str;
}