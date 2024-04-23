#include <iostream>
#include <string>
using namespace std;
class Pizza {
public:
    std::string name;
    void prepare() {
        std::cout << "Preparing " << this->name << "..." << std::endl;
    }

    void bake() {
        std::cout << "Baking " << this->name << "..." << std::endl;
    }

    void cut() {
        std::cout << "Cutting " << this->name << " into slices..." << std::endl;
    }

    void box() {
        std::cout << "Boxing your " << this->name << "..." << std::endl;
    }

    std::string getName() {
        return this->name;
    }

    virtual void setName() = 0;
};

class NYStylePepperoniPizza : public Pizza {
public:
    NYStylePepperoniPizza() {
        this->setName();
    }

    void setName() {
        this->name = "New York Style Pepperoni Pizza";
    }
};
class NYStyleCheesePizza : public Pizza {
public:
    NYStyleCheesePizza() {
        this->setName();
    }

    void setName() {
        this->name = "New York Style Cheese Pizza";
    }
};

class NYStyleGreekPizza : public Pizza {
public:
    NYStyleGreekPizza() {
        this->setName();
    }

    void setName() {
        this->name = "New York Style Greek Pizza";
    }
};

class PizzaStore
{
    public:
    enum class Pizzatype
    {
        CHEESE,GREEK,PEPPERONI
    };

    Pizza* orderPizza(Pizzatype pizzatype)
    {
        Pizza* pizza = createPizza(pizzatype);
        pizza->prepare();
        pizza->bake();
        pizza->cut();
        pizza->box();
        return pizza;
    }

    virtual Pizza* createPizza(Pizzatype pizzatype)=0;
};

class NYStylePizzaStore : public PizzaStore
{
    public:
    Pizza* createPizza(Pizzatype pizzatype) override
    {
        switch(pizzatype)
        {
            case(Pizzatype::CHEESE):
            {
                return new NYStyleCheesePizza();
            }
            case(Pizzatype::GREEK):
            {
                return new NYStyleGreekPizza();
            }
            case(Pizzatype::PEPPERONI):
            {
                return new NYStylePepperoniPizza();
            }
            default:
            {
                cout<<"No valid Pizza";
            }
        }
    }
};

int main() {
    std::cout << "\n ====================== \n" << std::endl;

    // Create a New York Style Greek Pizza
    PizzaStore* nyPizzaStore = new NYStylePizzaStore();
    Pizza* nyGreekPizza = nyPizzaStore->orderPizza(PizzaStore::Pizzatype::GREEK);
    std::cout << "Ordered Pizza: " << nyGreekPizza->getName() << std::endl;

    std::cout << "\n ====================== \n" << std::endl;
    Pizza* nyPepperoniPizza = nyPizzaStore->orderPizza(PizzaStore::Pizzatype::PEPPERONI);
    std::cout << "Ordered Pizza: " << nyPepperoniPizza->getName() << std::endl;

    std::cout << "\n ====================== \n" << std::endl;

    return 0;
}

