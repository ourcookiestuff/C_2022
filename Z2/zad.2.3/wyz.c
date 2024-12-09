/*Jakub Dziurka, 11.01.2023, jakub.dziurka@student.uj.edu.pl

 --> Instrukcja kompilacji:
    gcc wyz.c -o wyz
np. ./wyz 7
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double rozwod(int n, int w, int * WKolumn, double ** A)
{
    int k,m,*Kolumny;
    double s;
    
    if(n==1)
        return A[w][WKolumn[0]];     //macierz 1x1, wyznacznik równy elementowi
    else
    {
        Kolumny = malloc((n-1)*sizeof(double));     //dynamiczny wektor kolumn
        
        s=0;    //zerujemy wartość rozwinięcia
        m=1;    //początkowy mnożnik
        
        for(int i=0;i<n;i++)    //pętla obliczająca rozwinięcie
        {
            k=0;    //tworzymy wektor kolumn dla rekurencji
            for(int j=0;j<n-1;j++)  //ma on o 1 kolumnę mniej niż WK
            {
                if(k==i) k++;   //pomijamy bieżącą kolumnę
                Kolumny[j]=WKolumn[k++];  //pozostałe kolumny przenosimy do Kolumny
            }
            s+=m*A[w][WKolumn[i]]*rozwod(n-1,w+1,Kolumny,A);
            m=-m;   //kolejny mnożnik
        }
        free(Kolumny);
        
        return s;     //ustalamy wartość funkcji
    }
}

int main(int argc, char * argv[])
{
    if(argc<2)
    {
        printf("BŁĄD!\n");
        return 0;
    }
    int n;          //stopień macierzy
    int * WKolumn;       //wektor kolumn
    double ** A;     //macierz
    
    double liczba;
    srand(time(NULL));
    
    n=atoi(argv[1]);
    
    A = malloc(n*sizeof(double*));    //tworzymy macierz wskaźników
    
    printf("Macierz ma takie wartosci: \n");
    for(int i=0; i<n; i++)
    {
        A[i] = malloc(n*sizeof(double));  //tworzymy wiersz
        
        for(int j=0;j<n;j++)
        {
            liczba=rand()%100;
            A[i][j]=liczba;     //czytamy wiersze macierzy
            printf("%f\n", liczba);
        }
    }
    
    WKolumn = malloc(n*sizeof(int));
    
    for(int i=0;i<n;i++)
        WKolumn[i]=i;
    
    printf("Wyznacznik macierzy %dx%d wynosi = %f\n", n, n, rozwod(n,0,WKolumn,A));
    
    free(WKolumn);
    for(int i=0;i<n;i++) free(A[i]);
    free(A);
    
    return 0;
}
