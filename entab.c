#include <stdio.h>
#include <stdlib.h>

#define TABS 8
#define SPACE_CHAR '-'

/* Converts a series of consecutive spaces in a string to a tab character. */
char *entab(char *str) {
    char *output = malloc(1024);
    int i = 0;
    int j = 0;
    int mark_set = -1;
    
    while(str[i] != 0) {
	output[j] = str[i];
	if (str[i] == SPACE_CHAR && mark_set < 0) {
	    mark_set = j;
	}
	else if (str[i] != SPACE_CHAR && mark_set >= 0) {
	    mark_set = -1;
	}
	if (str[i] == SPACE_CHAR && ((i+1) % TABS) == 0) {
	    j = mark_set;
	    mark_set = -1;
	    output[j] = '\t';
	}
	if(str[i] == '\n') {
	    str += i + 1;
	    i = 0;
	    j++;
	    continue;
	}
	i++;
	j++;
    }
    output[j+1] = 0;
    return output;
}

int main(void) {
    printf("%s",entab("01234---012-----\n0123----a"));
    return 0;
}


