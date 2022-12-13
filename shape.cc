#include "shape.hpp"

Shape::Shape() {
    width_ = 0;
    height_ = 0;
}

Shape::~Shape() {}

void Shape::setDims(size_t w, size_t h) {
    width_ = w;
    height_ = h;
}

void Shape::printDims() {
    printf("Width: %zu, height: %zu\n", width_, height_);
}

void Square::setDims(size_t w, size_t h) {
    if (w == h) {
        width_ = w;
        height_ = h;
    }
}

size_t Square::getArea() {
    return width_ * height_;
}