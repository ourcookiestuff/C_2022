/*Jakub Dziurka, 21.10.2022, jakub.dziurka@student.uj.edu.pl

 --> Instrukcja kompilacji:
    gcc sis.c -o sis
np. ./sis 7
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    int liczba, silnia, suma;
    silnia=1;
    suma=0;
    if(argc<2)
        return 0;
    liczba = atoi(argv[1]);
    for(int i=liczba; i>=1; i--)
    {
        silnia*=i;
        suma+=i;
    }
    if(liczba>=13)
    {
        printf("bład!!!!!!!!!\n");
    }
    else
    {
        printf("silnia: %d\n", silnia);
    }
    printf("suma kolejnych liczb: %d\n", suma);
    return 0;
}
