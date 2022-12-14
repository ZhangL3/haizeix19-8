/*************************************************************************
   > File Name: 13.pointer.cpp
   > Author: hug
   > Mail:   hug@haizeix.com
   > Created Time: 四  9/26 18:14:19 2019
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define offset(T, a) (long long)(&(((T *)(NULL))->a))
#define pchar char *
typedef char * ppchar;

struct Data {
    int a;
    double b;
    char c;
};

void output_args(int argc, char *argv[], char *env[]) {
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    for (int i = 0; env[i]; i++) {
        printf("env[%d] = %s\n", i, env[i]);
        if (strncmp(env[i], "USER=", 5) == 0) {
            if (strcmp(env[i] + 5, "huguang")) {
                printf("you are not CpatainHu, don't run me, Gun!");
                exit(0);
            }
        }
    }
    return ;
}

int main(int argc, char *argv[], char *env[]) {
    int num1 = 0x616263;
    int num2 = 0x61626364;
    printf("%s", (char *)(&num2 + 1));
    printf("%lld\n", offset(struct Data, a));
    printf("%lld\n", offset(struct Data, b));
    printf("%lld\n", offset(struct Data, c));
    pchar p1, p2;
    ppchar p3, p4;
    printf("sizeof(p1) = %lu sizeof(p2) = %lu\n", sizeof(p1), sizeof(p2));
    printf("sizeof(p3) = %lu sizeof(p4) = %lu\n", sizeof(p3), sizeof(p4));
    output_args(argc, argv, env);
    return 0;
}