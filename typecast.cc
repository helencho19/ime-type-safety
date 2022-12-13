#include <stdio.h>

#include "animal.hpp"
#include "shape.hpp"

class ShapeAnimal : public Animal, public Shape {
    char name_[10];
};

int main() {
    // We just want to see what a static_cast looks like in assembly,
    // so we'll start with a safe static_cast
    // Result: it seems like nothing of interest really happens...
    // Square *square = new Square;
    // square->setDims(5, 5);

    // Shape *shape = static_cast<Shape *>(square);
    // shape->setDims(3, 5);

    // delete shape;

    // Now, let's think about dynamic_cast!
    // Should succeed--an upcast
    // Result: it does! but it doesn't jump to any additional interesting functions
    // Square *square = new Square;
    // Shape *s;
    // s = dynamic_cast<Shape *>(square);
    // s->setDims(3, 5);
    // delete s;

    // Should fail--casting between two unrelated types
    // Actually, this won't even compile... 
    // Square *square = new Square;
    // Animal *a;
    // a = dynamic_cast<Animal *>(square);

    // Should fail--an unsafe downcast
    // Actually, this does not compile either
    // Shape *shape = new Shape;
    // Square *s;
    // s = dynamic_cast<Square *>(shape);

    // reinterpret_cast
    // Upcast (safe)
    // Square *square = new Square;
    // Shape *shape;
    // shape = reinterpret_cast<Shape *>(square);
    // shape->printDims();
    // delete shape;

    // Downcast (unsafe)
    // Result: but this still works... undefined behavior?
    Shape *shape = new Shape;
    shape->setDims(3, 4);
    Square *fakeSquare = reinterpret_cast<Square *>(shape);
    size_t area = fakeSquare->getArea();
    printf("Area: %zu\n", area);

    // Multiple inheritance case: Figure 6 code from HexType paper
    ShapeAnimal *saPtr = new ShapeAnimal;
    printf("ShapeAnimal ptr saPtr: %p\n", saPtr);

    Shape *sPtr = saPtr;
    printf("Shape ptr sPtr: %p\n", sPtr);

    ShapeAnimal *saPtrStatic = static_cast<ShapeAnimal *>(sPtr);
    printf("ShapeAnimal ptr saPtrStatic, after static_cast from sPtr: %p\n", saPtrStatic);

    // reinterpret_cast preserves the new pointer value?
    ShapeAnimal *saPtrReinterp = reinterpret_cast<ShapeAnimal *>(sPtr);
    printf("ShapeAnimal ptr saPtrReinterp, after reinterpret_cast from sPtr: %p\n", saPtrReinterp);

    // C-style casting to a Shape
    Shape *sPtrCStyle = (Shape *)saPtr;
    printf("Shape ptr sPtrCStyle, after C-style casting from saPtr: %p\n", sPtrCStyle);

    // C-style casting
    // Square *square = new Square;
    // Shape *shape = (Shape *)square;
    // shape->printDims();
}