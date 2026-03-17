#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_COL 23

char *fold(char *str) {
    char *output = malloc(1024);
    int out_p = 1;
    int str_p = 0;
    int mod = 1;
    int lst_space = -1;
    while (str[str_p]) {
        if (str[str_p] == ' ') {
            lst_space = out_p; 
        }
        if ((mod % MAX_COL) == 0) {
            if (lst_space == -1) {
                output[out_p++] = '\n';
                mod = 1;
                continue;
            } else if (str[str_p] == ' ') {
                output[out_p++] = '\n';
                str_p++;
                lst_space = -1;
                mod = 1;
                continue;
            } else {
                output[lst_space] = '\n';
                mod =  out_p - lst_space;
                lst_space = -1;
            }
        }
        output[out_p] = str[str_p];
        out_p++;
        str_p++;
        mod++;
    } 
    return &output[1];
}

void print(char *str) {
    while(*str) {
        if(*str == '\n') {
            printf("|");
        } else {
            printf("%c",*str);
        }
        str++;
    }
    printf("\n");
}

int main(void) {
    char *res = fold("Ariel Zablozki is the coolest guy I know, I hope he likes to stay cool and be cool!");
    print(res);
    return 0;
}



