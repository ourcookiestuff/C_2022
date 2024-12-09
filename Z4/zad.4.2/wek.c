/*Jakub Dziurka, 13.12.2022, jakub.dziurka@student.uj.edu.pl

 --> Instrukcja kompilacji:
    gcc wek.c -o wek
np. ./wek Plummer_128.dat.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define eps 0.0
#define G 1.0

typedef struct{
    double m;
    double x[3];
    double v[3];
} cialo;

typedef struct
{
    double x;
    double y;
    double z;
    // double t;
} wektor;

wektor plus(wektor a, wektor b)
{
    wektor c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;
    
    return c;
}

wektor sila_12(cialo m1, cialo m2)
{
    wektor F,r;
    double d;
    
    r.x = (m1.x)[0]-(m2.x)[0];
    r.y = (m1.x)[1]-(m2.x)[1];
    r.z = (m1.x)[2]-(m2.x)[2];
    
    d=sqrt(r.x*r.x+r.y*r.y+r.z*r.z + eps*eps);
    
    F.x = -G*m1.m*m2.m*r.x/d/d/d;
    F.y = -G*m1.m*m2.m*r.y/(d*d*d);
    F.z = -G*m1.m*m2.m*r.z/(d*d*d);
    
    return F;
}

int main(int argc, char * argv[])
{
    FILE * datafile;
    int num;
    double liczby[7];
    cialo * tablica;
    
    if(argc>=2)
    {
        datafile = fopen(argv[1],"r");
        if(datafile==NULL)
        {
            printf("ERROR: nie udało się otworzyć pliku.\n");
            exit(-1);
        }
    }
    else
    {
        printf("ERROR: nie podano nazwy pliku.\n");
        exit(-1);
    }
    
    fscanf(datafile,"%d\n",&num);
    
    tablica = malloc(num*sizeof(cialo));
    
    for(int i=0;i<num;i++)
    {
        fscanf(datafile,"%lf %lf %lf %lf %lf %lf %lf", &liczby[0], &liczby[1], &liczby[2], &liczby[3], &liczby[4], &liczby[5], &liczby[6]);
        tablica[i].m=liczby[0];
        tablica[i].x[0]=liczby[1];
        tablica[i].x[1]=liczby[2];
        tablica[i].x[2]=liczby[3];
        tablica[i].v[0]=liczby[4];
        tablica[i].v[1]=liczby[5];
        tablica[i].v[2]=liczby[6];
    }
    
    fclose(datafile);
    
    wektor F12,F_total,F_ij;
    
    F12 = sila_12(tablica[0],tablica[1]);
    
    for(int j=0; j<num; j++)
    {
        F_total.x=0.0;
        F_total.y=0.0;
        F_total.z=0.0;
        for(int i=0; i<num; i++)
        {
            if(i==j) continue;
            F_ij = sila_12(tablica[j],tablica[i]);
            F_total = plus(F_total,F_ij);
        }
        printf("Fx=%lf\tFy=%lf\tFz=%lf\n",F_total.x, F_total.y, F_total.z);
    }
    
    free(tablica);
    
    return 0;
}
