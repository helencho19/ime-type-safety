#include <stdio.h>

#include "animal.hpp"
#include "shape.hpp"

// THIS IS FOR THE REPORT

int main()
{
    // Case 1a: an object invokes a method not contained in its class
    // (after an unsafe type cast)
    Animal *fakeAnimal = (Animal *)new Shape;
    fakeAnimal->move(5.0); // Bad!

    // Case 1b: passing in an object of the incorrect type
    // (after an unsafe type cast)
    Animal *realAnimal = new Animal;
    Shape *realShape = new Shape;
    realAnimal->eat((Animal *)realShape); // Bad!

    // Case 2a: objects inherited from the same base class
    // This is basically the same as Case 1b.
    Circle *realCircle = new Circle;
    Square *realSquare = new Square;
    bool sameArea = realCircle->hasSameArea((Circle *)realSquare); // Bad!

    // Case 2b: one object is an ancestor of the other
    // This is an unsafe downcast.
    Shape *anotherRealShape = new Shape;
    bool sameAreaAgain = realCircle->hasSameArea((Circle *)anotherRealShape); // Bad!

    
}