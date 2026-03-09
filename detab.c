//(setq c-basic-offset 4)
//(c-set-offset 'case-label '+)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB 8

/* Returns a NEW null terminated string with 'tabs'
 * replaced by the appropriate number of spaces to align
 * tabstops. */
char *detab(char *str) {
    char *outstr = malloc(1024);
    int pos = 0;
    int j = 0;
    int i = 0;
    
    while (str[i] != 0) {
        if (str[i] == '\t') {
            int num_spaces = TAB - pos;
            memset(&outstr[j], ' ', num_spaces);
            j += num_spaces;
            pos = 0;
            i++;
            continue;
        }
        outstr[j] = str[i];
        pos++;
        if (str[i] == '\n' || pos > TAB - 1) pos = 0;
        j++;
        i++;
    }
    outstr[j] = 0;
    return outstr;
 }

int main(void) {
    char str[] = "aaa\tb\tc\naa\tbca\n";
    printf("%s\n",str);
    printf("%s\n",detab(str));
    return 0;
}
