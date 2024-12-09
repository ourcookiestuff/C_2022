/*Jakub Dziurka, 21.10.2022, jakub.dziurka@student.uj.edu.pl

 --> Instrukcja kompilacji:
    gcc podsil.c -o podsil
np. ./podsil 7
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    if(argc<2)
        return 0;
    int n, i;
    double factorial = 1;
    n = atoi(argv[1]);
    if(n>25)
    {
        printf("Błąd, za duża liczba\n");
        return 0;
    }
    if(n>0 && n%2!=0)
    {
        for(i=1; i<=n; i++)
        {
            if(i%2!=0)
            {
                printf("%d ", i);
                factorial=factorial*i;
            }
        }
        printf("\n");
    }
    printf("%d!! = %f\n\n", n, factorial);
    return 0;
}
