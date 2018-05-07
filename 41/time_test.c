#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "util.h"
void get_str_length(char* c) {
	printf("string length is %i\n", strlen(c));
}
int main() {
	time_t current_time;
	char* c_time_string;
	current_time = time(NULL);
    if (current_time == ((time_t)-1))
    {
        (void) fprintf(stderr, "Failure to obtain the current time.\n");
        exit(EXIT_FAILURE);
    }
    time_t sso = 1000000;
    if(sso < current_time){printf("sso is less than current_time\n");}
    printf("time is %i\n", current_time);
    /* Convert to local time format. */
    c_time_string = ctime(&current_time);

    if (c_time_string == NULL)
    {
        (void) fprintf(stderr, "Failure to convert the current time.\n");
        exit(EXIT_FAILURE);
    }

    /* Print to stdout. ctime() has already added a terminating newline character. */
    (void) printf("Current time is %s", c_time_string);
    for (int i = 0; i<99999999; i++){}
    (void) printf("Current time is %s", c_time_string);
	printf("time is %i\n", current_time);
    // exit(EXIT_SUCCESS);

    char foobar[] = "ADD,TO,THE,TITILE";
    char** barfoo = str_split(foobar, ',');
    printf("%s\n gserf", foobar);
    if (barfoo)
    {
    	printf("barfoo is ok\n");
        int i;
        for (i = 0; *(barfoo + i); i++)
        {
            printf("month=[%s]\n", *(barfoo + i));
            free(*(barfoo + i));
        }
        printf("\n");
        free(barfoo);
    }
    // char* d = "abcdejihujouhijoinoihujnf";
    // get_str_length(d);
    // printf("string lesngth is %i\n", strlen(d));
}