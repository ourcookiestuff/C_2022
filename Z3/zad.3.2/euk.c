/*Jakub Dziurka, 26.11.2022, jakub.dziurka@student.uj.edu.pl

 --> Instrukcja kompilacji:
    gcc euk.c -o euk
    ./euk
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 7

double dot(int n, double *a, double *b)
{
    double suma=0.0;
    for(int i=0; i<n; i++)
    {
        suma+=a[i]*b[i];
    }
    return suma;
}

double norm(int m, double *c)
{
    double pot=0.0, pot_v2;
    for(int i=0; i<m; i++)
    {
        pot+=c[i]*c[i];
    }
    pot_v2=sqrt(pot);
    return pot_v2;
}

int main()
{
    double liczba;
    srand(time(NULL));
//    printf("%f\n",liczba);
    
    double A[N];
    double B[N];
    
    for(int i=0;i<N;i++)
    {
        liczba=rand()%100;
        A[i]=liczba;
    }
    
    for(int i=0;i<N;i++)
    {
        liczba=rand()%100;
        B[i]=liczba;
    }
    
    for(int i=0;i<N;i++)
    {
        printf("%lf\t",A[i]);
    }
    printf("\n");
    for(int i=0;i<N;i++)
    {
        printf("%lf\t",B[i]);
    }
    printf("\n");
    
    printf("Iloczyn skalarny = %lf\n", dot(N,A,B));
    printf("Norma wektora A = %lf\n", norm(N,A));
    printf("Norma wektora B = %lf\n", norm(N,B));
    
    return 0;
}
