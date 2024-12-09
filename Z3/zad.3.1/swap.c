/*Jakub Dziurka, 23.11.2022, jakub.dziurka@student.uj.edu.pl

 --> Instrukcja kompilacji:
    gcc swap.c -o swap
    ./swap 
*/

#include <stdio.h>

void swap (double *x, double *y)
{
    double a,b;
    
    a=*x;
    b=*y;
    
    *x=b;
    *y=a;
}

int main()
{
    double x=3.14, y=2.71;
    
    printf("x=%lf\ty=%f\n",x,y);
    swap(&x,&y);
    printf("x=%f\ty=%f\n",x,y);
    
    return 0;
}
