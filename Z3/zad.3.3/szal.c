/*Jakub Dziurka, 27.11.2022, jakub.dziurka@student.uj.edu.pl

 --> Instrukcja kompilacji:
    gcc szal.c -o szal
    ./szal
*/

#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

union V{
    float f;
    uint32_t u;
};

float count(float x) {
    float y = expf(x) - powf(x, 2);
    return fabsf(y);
}

int main()
{
    union V x;
    x.u = 0u;
    union V i;
    float closest_match = count(x.f);
    for(i.u = 1u; i.u < UINT32_MAX; i.u += 1){
        float diff = count(i.f);
        if(diff < closest_match){
            closest_match = diff;
            x=i;
        }
    }

    printf("Najbliższe przypasowanie x to: %f\n", x.f);
    return 0;
}

