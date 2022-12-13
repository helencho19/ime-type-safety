#include <stdio.h>

#include "animal.hpp"

Animal::Animal()
{
    pos_ = 0;
    hp_ = 100;
}

Animal::~Animal() {}

void Animal::move(double dist)
{
    pos_ += dist;
}

double Animal::getPosition()
{
    return pos_;
}

double Animal::getHP()
{
    return hp_;
}

void Animal::eat(Animal *prey)
{
    // hp_ += prey->getHP();
}