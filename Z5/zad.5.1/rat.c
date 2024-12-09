/*Jakub Dziurka, 21.12.2022, jakub.dziurka@student.uj.edu.pl

 --> Instrukcja kompilacji:
    gcc -c liczby_wymierne.c
    ar rcs librational.a liczby_wymierne.o
    gcc -shared -o librational.so liczby_wymierne.o
    gcc rat.c -lrational -L. -o rat
    ./rat
*/

#include <stdio.h>
#include "liczby_wymierne.h"

int main(int argc, char * argv[])
{
    liczba_wymierna r,p,q;
    
    r.licznik   = 1;
    r.mianownik = 137;
    
    p.licznik   = 2;
    p.mianownik = 9;
    
    q = mul(r,p);
    printf("1) wynik = %d/%d\n",q.licznik, q.mianownik);
    q = sqr(q);
    printf("2) wynik = %d/%d\n",q.licznik, q.mianownik);
    
    return 0;
}

