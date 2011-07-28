

#include <string.h>
#include "ys_proto/types/stringarray.h"

// return the char length (size) of an YS_string_array (aircraft list) "s" which cointains "elements" elements (number of aircraft)
int sizeofsarray(char* array, int elements)
{
    int len = 0;
    int zeros = 0;
    while (zeros<elements)
    {
        len+=strlen(array+len)+1;
        zeros ++;
    }
    return len;
}


void printsarray(char* array, int elements)
{
    int len = 0;
    int zeros = 0;
    while (zeros<elements)
    {
        printf("%s\n", array+len);
        len+=strlen(array+len)+1;
        zeros ++;
    }
}
