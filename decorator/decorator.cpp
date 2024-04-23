using namespace std;
#include <string>
#include <iostream>

class Beverage
{
    public:
    string description = "unknown beverage";
    virtual ~Beverage()=default;
    virtual string getDescription()
    {
        return this->description;
    }
    virtual double cost()=0;
};

class CondimentDecorator : public Beverage
{
    public:
    virtual string getDescription()=0;
};

class DarkRoast : public Beverage
{
    public: 
    double COST =0.99;
    DarkRoast()  {this->description="Dark Roast";}
    double cost() override
    {
        return this->COST;
    }
};

class Decaf : public Beverage
{
    public:
    double COST = 1.05;

    Decaf() { this->description="Decaf";}
    double cost() override
    {
        return this->COST;
    }
};

class Espresso : public Beverage
{
    public:
    double COST = 1.99;

    Espresso() { this->description = "Espresso";}
    
    double cost() override
    {
        return this->COST;
    }
};

class HouseBlend : public Beverage
{
    public:
    double COST = 0.89;
    HouseBlend() { this->description = "House Blend";}
    double cost() override
    {
        return this->COST;
    }
};

class Mocha : public CondimentDecorator
{
    public:
    Beverage* beverage;
    double COST = 0.2;
    Mocha(Beverage* beverage):beverage(beverage){}
    string getDescription()
    {
        return this->beverage->getDescription() + " , Mocha";
    }
    double cost()
    {
        return beverage->cost() + COST;
    }
};

class Soy : public CondimentDecorator
{
    public:
    Beverage* beverage;
    double COST = 0.15;
    Soy(Beverage* beverage):beverage(beverage){}
    string getDescription()
    {
        return beverage->getDescription() + " , Soy";
    }
    double cost()
    {
        return beverage->cost() + COST;
    }
};

class SteamedMilk : public CondimentDecorator
{
    public:
    Beverage* beverage;
    double COST = 0.10;
    SteamedMilk(Beverage* beverage):beverage(beverage){}
    string getDescription()
    {
        return beverage->getDescription() + " , Steamed Milk";
    }
    double cost()
    {
        return beverage->cost() + COST;
    }
};

class Whip : public CondimentDecorator
{
    public:
    Beverage* beverage;
    double COST = 0.20;
    Whip(Beverage* beverage):beverage(beverage){}
    string getDescription()
    {
        return beverage->getDescription() + " , Whip";
    }
    double cost()
    {
        return beverage->cost() + COST;
    }
};




int main() {
    // Order: Espresso
    Beverage* beverage1 = new Espresso();
    std::cout << "Coffee ordered: " << beverage1->getDescription() << std::endl;
    std::cout << "Total cost: " << beverage1->cost() << std::endl;

    // Order: Dark Roast with double Mocha and a Whip
    Beverage* beverage2 = new DarkRoast();
    std::cout << "Coffee ordered: " << beverage2->getDescription() << std::endl;
    std::cout << "Total cost: " << beverage2->cost() << std::endl;
    beverage2 = new Mocha(beverage2);
    std::cout << "Coffee ordered: " << beverage2->getDescription() << std::endl;
    std::cout << "Total cost: " << beverage2->cost() << std::endl;
    
    beverage2 = new Whip(beverage2);
    std::cout << "Coffee ordered: " << beverage2->getDescription() << std::endl;
    std::cout << "Total cost: " << beverage2->cost() << std::endl;
    // std::cout << "Coffee ordered: " << beverage2->getDescription() << std::endl;
    // std::cout << "Total cost: " << beverage2->cost() << std::endl;

    // Order: House Blend with Soy, Steamed Milk and a Whip
    Beverage* beverage3 = new HouseBlend();
    beverage3 = new Soy(beverage3);
    beverage3 = new SteamedMilk(beverage3);
    beverage3 = new Whip(beverage3);
    std::cout << "Coffee ordered: " << beverage3->getDescription() << std::endl;
    std::cout << "Total cost: " << beverage3->cost() << std::endl;

    delete beverage1;
    delete beverage2;
    delete beverage3;
    return 0;
}

