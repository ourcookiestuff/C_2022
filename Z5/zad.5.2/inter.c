/*Jakub Dziurka, 21.01.2023, jakub.dziurka@student.uj.edu.pl

 --> Instrukcja kompilacji:
    gcc -c liczby_wymierne.c
    ar rsc librational.a liczby_wymierne.o
    gcc inter.c -lrational -L. -o inter
    ./inter kod.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "liczby_wymierne.h"
#define MAXSIZE 100

typedef enum  {
    ADD=201,
    SUB=234,
    MUL=238,
    DVD=222,
    INV=237,
    NEG=218,
    SQR=246
} instr;

instr hash(char * kod){
    return (int) kod[0] + ((int) kod[1]) + ((int) kod[2]);
}

static int sp = 0;
int *x;
liczba_wymierna values[MAXSIZE];

void clear_stack() {
    sp = 0;
}

liczba_wymierna push(liczba_wymierna number)
{
    if(sp<*x)
    {
        values[sp++] = number;
    }
    return number;
}

liczba_wymierna pop()
{
    if(sp>0)
    {
        return values[--sp];
    }
    else
    {
        printf("Brak wystarczającej ilości danych do operacji\n");
        clear_stack();
        exit(-1);
    }
}

int main(int argc, char * argv[])
{
    FILE * datafile;
    char kod[128][80];
    liczba_wymierna r,p,a,op2;
    int licznik=0;
 

    if(argc>=2){
        datafile = fopen(argv[1],"r");
        if(datafile==NULL)
        {
            printf("ERROR: nie udalo sie otworzyÄ pliku.\n");
            exit(-1);
        }
    }
    else
    {
        printf("ERROR: nie podano nazwy pliku.\n");
        exit(-1);
    }
 
    int i=0;
    x=&i;

    while(fscanf(datafile,"%s",kod[i])&&!feof(datafile))
    {
        i++;
    }
 
    int num=i;
    if(i==0)
    {
        printf("Pusty plik!!!\n");
        return 0;
    }
    printf("rozmiar = %d\n",i);

    fclose(datafile);
  
    for(int i=0;i<num;i++)
    {
        printf("%s\t%d\n",kod[i],hash(kod[i]));
    }
    
    printf("\n");
    
    for(int i=0;i<num;i++)
    {
        switch( hash(kod[i]) )
        {
            case ADD: push(a=add(pop(),pop()));
                break;
            case SUB:
                op2=pop();
                push(a=sub(pop(),op2));
                break;
            case MUL: push(a=mul(pop(),pop()));
                break;
            case DVD:
                op2=pop();
                push(a=dvd(pop(),op2));
                break;
            case INV:
                push(a=inv(pop()));
                if(a.mianownik==0)
                {
                    printf("Dzielenie przez zero. BŁĄD!!!!!!\n");
                    return 0;
                }
                break;
            case NEG:
                push(a=neg(pop()));
                break;
            case SQR:
                push(a=sqr(pop()));
                break;
            default:
                licznik++;
                sscanf(kod[i],"%d/%d",&(a.licznik),&(a.mianownik));
                if(a.mianownik==0)
                {
                    printf("Dzielenie przez zero. BŁĄD!!!!!!\n");
                    return 0;
                }
                if(licznik==num)
                {
                    printf("Brak metody operacji. BŁĄD!!!!\n");
                    return 0;
                }
                push(a);
        }
    }

    printf("Wynik = %d/%d\n",a.licznik,a.mianownik);

    return 0;
}
