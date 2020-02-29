#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

struct Person {
    uint8_t padding_1[8];
    bool happy;
    float sad;
    double is_dead;
    uint8_t padding_2[8];
};

struct World {
    int person_count;
    struct Person** persons;
    bool should_explode;
};

void create_person(struct Person* person) {
    person->happy = rand();
    person->sad = 0.5f;
    person->is_dead = 0xdead;
}

void create_planet(unsigned long long population, struct World* world) {
    // Allocate memory
    world->persons = (struct Person**)malloc(population * sizeof(struct Person*));

    // Create every person and fill the person struct
    for (uint64_t i = 0; i < population; i++) {
        world->persons[i] = (struct Person*)malloc(sizeof(struct Person));
        create_person(world->persons[i]);
        world->person_count++;
    }
}

int main(void) {
    struct World* earthy_earth = (struct World*)malloc(sizeof(struct World));
    create_planet(7800000000, earthy_earth);
    printf("Congratulations. You've reached the end! %i\n", earthy_earth->person_count * sizeof(struct Person));
    free(earthy_earth);
    return 0;
}
