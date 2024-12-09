/*Jakub Dziurka, 21.10.2022, jakub.dziurka@student.uj.edu.pl

 --> Instrukcja kompilacji:
    gcc fun.c -o fun
np. ./fun 12
*/

#include <stdio.h>
#include <stdlib.h>

int fib_i(int liczba1)
{
    if(liczba1==0||liczba1==1)
    {
        return 1.0;
    }
    else
    {
        return fib_i(liczba1-1)+fib_i(liczba1-2);
    }
}

double fib_f(int liczba1)
{
    if(liczba1==0||liczba1==1)
    {
        return 1.0;
    }
    else
    {
        return fib_f(liczba1-1)+fib_f(liczba1-2);
    }
}

int silnia_i(int liczba1)
{
    if(liczba1<=1)
        return 1;
    return liczba1*silnia_i(liczba1-1);
}

double silnia_f(int liczba1)
{
    if(liczba1<=1)
        return 1;
    return liczba1*silnia_f(liczba1-1);
}

int silnia2_i(int liczba1)
{
    if(liczba1<=1)
        return 1;
    return liczba1*silnia2_i(liczba1-2);
}

double silnia2_f(int liczba1)
{
    if(liczba1<=1)
        return 1;
    return liczba1*silnia2_f(liczba1-2);
}


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
