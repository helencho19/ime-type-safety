#include <stdio.h>

class Animal {
    double pos_;
    double hp_;

public:
    Animal() {
        pos_ = 0;
        hp_ = 100;
    }

    ~Animal() {}

    void move(double dist) {
        pos_ += dist;
    }

    double getPosition() {
        return pos_;
    }

    double getHP() {
        return hp_;
    }

    void eat(Animal *prey) {

    }
};

class Shape {
public:
    Shape() {}

    ~Shape() {}
};

int main() {
    // Case 1: An object invokes a method not contained in its class
    // (after an unsafe type cast)
    Animal *fakeAnimal = (Animal *) new Shape;
    fakeAnimal->move(5.0);
    double fakeAnimalPos = fakeAnimal->getPosition();
    printf("Fake animal position: %f\n", fakeAnimalPos);
    delete fakeAnimal;

    // Case 2: Passing in an object of the incorrect type
    // (after an unsafe type cast)
    Animal *realAnimal = new Animal;
    Shape *realShape = new Shape;
    realAnimal->eat((Animal *)realShape);
    printf("Real animal HP: %f\n", realAnimal->getHP());
    delete realShape;
    delete realAnimal;

    // TODO: Type confusion with objects inherited from the same base class
    // (This will probably require making new header files)
}