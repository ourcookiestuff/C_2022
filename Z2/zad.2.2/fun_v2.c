/*Jakub Dziurka, 21.10.2022, jakub.dziurka@student.uj.edu.pl

 --> Instrukcja kompilacji:
    gcc -c def.c
    gcc -c fun_v2.c
    gcc def.o fun_v2.o -o fun_v2
np. ./fun_v2 6
*/

#include <stdio.h>
#include <stdlib.h>
#include "nag.h"

int main(int argc, char * argv[])
{
    if(argc<2)
    {
        printf("Błąd\n");
        return 0;
    }
    int n;
    n=atoi(argv[1]);
    printf("\n");
    printf("silnia intowa dla %d = %d\n\n", n, silnia_i(n));
    printf("podwójna silnia intowa dla %d = %d\n\n", n, silnia2_i(n));
    printf("silnia doublowa dla %d = %f\n\n", n, silnia_f(n));
    printf("podwójna silnia doublowa dla %d = %f\n\n", n, silnia_f(n));
    for(int i=1;i<=n;i++)
    {
        printf("fibonacci intowy dla %d = %d\n", i, fib_i(i-1));
    }
    printf("\n");
    for(int i=1;i<=n;i++)
    {
        printf("fibonacci doublowy dla %d = %f\n", i, fib_f(i-1));
    }
    printf("\n");
    return 0;
}
