class Animal
{
protected:
    double pos_;
    double hp_;

public:
    Animal();
    
    ~Animal();

    void move(double dist);
    
    double getPosition();
    
    double getHP();

    void eat(Animal *prey);
};