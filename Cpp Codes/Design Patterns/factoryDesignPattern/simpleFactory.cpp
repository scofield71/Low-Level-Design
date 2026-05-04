#include "bits/stdc++.h"
using namespace std;

class Burger {
    public:
    virtual void prepare() = 0;
};

class VegBurger : public Burger {
    public:
    void prepare() override {
        cout << "Preparing Veg Burger" << endl;
    }
};

class NonVegBurger : public Burger {
    public:
    void prepare() override {
        cout << "Preparing Non-Veg Burger" << endl;
    }
};

class VeganBurger : public Burger {
    public:
    void prepare() override {
        cout << "Preparing Vegan Burger" << endl;
    }
};

class BurgerFactory {
    public : 
    Burger* createBurger(string type) {
        if (type == "Veg") {
            return new VegBurger();
        } else if (type == "Non-Veg") {
            return new NonVegBurger();
        } else if (type == "Vegan") {
            return new VeganBurger();
        } else {
            return nullptr;
        }
    }
};

int main() {
    BurgerFactory factory;
    Burger* vegBurger = factory.createBurger("Veg");
    Burger* nonVegBurger = factory.createBurger("Non-Veg");
    Burger* veganBurger = factory.createBurger("Vegan");

    vegBurger->prepare();
    nonVegBurger->prepare();
    veganBurger->prepare();
    
    return 0;
}