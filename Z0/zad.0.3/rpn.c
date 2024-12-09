/*Jakub Dziurka, 24.10.2022, jakub.dziurka@student.uj.edu.pl

 --> Instrukcja kompilacji:
    gcc rpn.c -o rpn
np. ./rpn 5 7 + 7 / 0 x -
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    for(int i=1;i<argc;i++)
    {
        if(* argv[i]=='+'||* argv[i]=='-'||* argv[i]=='x'||* argv[i]=='/')
        {
            switch(* argv[i])
            {
                case '+': printf("Plus\n"); break;
                case '-': printf("Subtract\n"); break;
                case 'x': printf("Times\n"); break;
                case '/': printf("Divide\n"); break;
            }
        }
        else
        {
            printf("%s\n", argv[i]);
        }
    }
    return 0;
}
