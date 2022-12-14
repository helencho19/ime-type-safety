#include <stdio.h>

// Inspired by https://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm 
class Shape
{

protected: 
    size_t width_;
    size_t height_;

public:
    Shape();

    ~Shape();

    void setDims(size_t w, size_t h);

    void printDims(); 
};

class Square : public Shape
{
public:
    void setDims(size_t w, size_t h); 

    size_t getArea(); 
};

class Circle : public Shape
{
protected:
    double radius_;

public:
    void setRadius(double radius);

    double getArea();

    bool hasSameArea(Circle *c);
};