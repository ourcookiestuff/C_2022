/*Jakub Dziurka, 21.01.2023, jakub.dziurka@student.uj.edu.pl

 --> Instrukcja kompilacji:
    gcc echo.c -o echo
np. ./echo "Witajcie" 3
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    int n;
    if(argc<3)
        return 0;
    n = atoi(argv[2]);
    for(int i=0; i<n; i++)
    {
        printf("%s\n", argv[1]);
    }
    
    return 0;
}
