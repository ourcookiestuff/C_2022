/*Jakub Dziurka, 22.01.2023, jakub.dziurka@student.uj.edu.pl
 Przyjąłem, że jak w poprzednim zadaniu, stała grawitacji równa się 1, chociaż nie wiem czy w tym przypadku akurat o to chodziło.

 --> Instrukcja kompilacji:
    gcc sym.c -o sym
np. ./sym Plummer_4.dat.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 1 // stała grawitacyjna

typedef struct {
    double x, y, z;
} vector_t;

typedef struct {
    vector_t position, velocity, acceleration;
    double mass;
} body_state_t;

void simulate_n_body(body_state_t* state, int n, double dt) {
    for (int i = 0; i < n; i++) {
        // Aktualizacja pozycji ciała i
        state[i].position.x += state[i].velocity.x * dt;
        state[i].position.y += state[i].velocity.y * dt;
        state[i].position.z += state[i].velocity.z * dt;

        // Inicjalizacja przyspieszenia na 0
        state[i].acceleration.x = 0;
        state[i].acceleration.y = 0;
        state[i].acceleration.z = 0;

        for (int j = 0; j < n; j++) {
            if (i != j) {
                // Obliczenie odległości między ciałami i i j
                double distance_x = state[j].position.x - state[i].position.x;
                double distance_y = state[j].position.y - state[i].position.y;
                double distance_z = state[j].position.z - state[i].position.z;
                double distance = sqrt(distance_x * distance_x + distance_y * distance_y + distance_z * distance_z);

                // Obliczenie siły oddziaływania między ciałami i i j
                double force = (G * state[i].mass * state[j].mass) / (distance * distance);

                // Dodanie siły do przyspieszenia ciała i
                state[i].acceleration.x += force * distance_x / distance;
                state[i].acceleration.y += force * distance_y / distance;
                state[i].acceleration.z += force * distance_z / distance;
            }
        }

        // Aktualizacja prędkości ciała i
        state[i].velocity.x += state[i].acceleration.x * dt;
        state[i].velocity.y += state[i].acceleration.y * dt;
        state[i].velocity.z += state[i].acceleration.z * dt;
    }
}


int main(int argc, char* argv[]) {
    FILE * datafile;
    int num;
    double liczby[7];
    body_state_t * tablica;
    
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
    
    tablica = malloc(num*sizeof(body_state_t));
    
    for(int i=0;i<num;i++)
    {
        fscanf(datafile,"%lf %lf %lf %lf %lf %lf %lf", &liczby[0], &liczby[1], &liczby[2], &liczby[3], &liczby[4], &liczby[5], &liczby[6]);
        tablica[i].mass=liczby[0];
        tablica[i].position.x=liczby[1];
        tablica[i].position.y=liczby[2];
        tablica[i].position.z=liczby[3];
        tablica[i].velocity.x=liczby[4];
        tablica[i].velocity.y=liczby[5];
        tablica[i].velocity.z=liczby[6];
    }
    
    fclose(datafile);
    int n = num; // liczba ciał w symulacji
    double dt = 0.01; // krok czasowy
    double simulation_time = 10; // czas trwania symulacji

    // Symulacja N-ciałowa
    for (double t = 0; t < simulation_time; t += dt) {
        simulate_n_body(tablica, n, dt);

        // Wypisanie pozycji ciała 0
        printf("Pozycja ciała 0: (%.2lf, %.2lf, %.2lf)\n", tablica[0].position.x, tablica[0].position.y, tablica[0].position.z);
    }

    return 0;
}
