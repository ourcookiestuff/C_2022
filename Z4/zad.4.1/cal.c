/*Jakub Dziurka, 13.12.2022, jakub.dziurka@student.uj.edu.pl
 
Program na przykładzie tangensa

 --> Instrukcja kompilacji:
    gcc cal.c -o cal
    ./cal
*/

#include <stdio.h>
#include <math.h>


void table(double (*f)(double), double x_start, double x_end, double dx)
{
    for(int i=0;i<=(x_end-x_start)/dx;i++)
        printf("%lf\t%f\n",x_start+i*dx,f(x_start+i*dx));
    
}

double suma(double (*f)(double), double x_start, double x_end, double dx)
{
    double suma=0.0;
    for(int i=0;i<=(x_end-x_start)/dx;i++)
        suma=suma+f(x_start+i*dx);
    return suma*dx;
}

double id(double x)
{
    return x;
}

double sqr(double x)
{
    return x*x;
}

int main()
{
    table(tan,0,1,0.1);
        
    printf("Suma ważona = %lf\n",suma(tan,0,1,0.1));
    
    return 0;
}
