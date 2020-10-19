#include <stdio.h>
#include <string.h>
#include <time.h>

//Structs
 time_t t;
 struct tm tm;

//Functions
int get_date();
int get_input(int* ptr);

int int_info(int* ptr);
int dbg;

//Constants
 int x;
 char *months[12] = {"januari",
                    "februari",
                    "mars",
                    "april",
                    "maj",
                    "juni",
                    "augusti",
                    "september",
                    "oktober",
                    "november",
                    "december"};

