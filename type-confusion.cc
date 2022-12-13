#include <stdio.h>

#include "animal.hpp"
#include "shape.hpp"

int main()
{
    // Case 1: an object invokes a method not contained in its class
    // (after an unsafe type cast)
    Animal *fakeAnimal = (Animal *)new Shape;
    fakeAnimal->move(5.0);
    double fakeAnimalPos = fakeAnimal->getPosition();
    fakeAnimalPos++;
    // printf("Fake animal position: %f\n", fakeAnimalPos);
    delete fakeAnimal;

    // Case 2: passing in an object of the incorrect type
    // (after an unsafe type cast)
    Animal *realAnimal = new Animal;
    Shape *realShape = new Shape;
    realAnimal->eat((Animal *)realShape);
}