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

class SpecialBurger : public Burger {
    public:
    void prepare() override {
        cout << "Preparing Special Burger" << endl;
    }
};

class LowFatBurger : public Burger {
    public:
    void prepare() override {
        cout << "Preparing Low-Fat Burger" << endl;
    }
};

class EconomicalBurger : public Burger {
    public:
    void prepare() override {
        cout << "Preparing Economical Burger" << endl;
    }
};

class BurgerFactory {
    public : 
    virtual Burger* createBurger(string type) = 0;
};

class VegBurgerFactory : public BurgerFactory {
    public:
    Burger* createBurger(string type) override {
        if (type == "Veg") {
            return new VegBurger();
        } else if (type == "Vegan") {
            return new VeganBurger();
        } else if (type == "Economical") {
            return new EconomicalBurger();
        } else {
            return nullptr;
        }
    }
};

class NonVegBurgerFactory : public BurgerFactory {
    public:
    Burger* createBurger(string type) override {
        if (type == "Non-Veg") {
            return new NonVegBurger();
        } else if (type == "Special") {
            return new SpecialBurger();
        } else if (type == "Low-Fat") {
            return new LowFatBurger();
        } else {
            return nullptr;
        }
    }
};

int main() {
    BurgerFactory* vegFactory = new VegBurgerFactory();
    Burger* vegBurger = vegFactory->createBurger("Veg");
    vegBurger->prepare();

    Burger* veganBurger = vegFactory->createBurger("Vegan");
    veganBurger->prepare();

    Burger* economicalBurger = vegFactory->createBurger("Economical");
    economicalBurger->prepare();

    BurgerFactory* nonVegFactory = new NonVegBurgerFactory();
    Burger* nonVegBurger = nonVegFactory->createBurger("Non-Veg");
    nonVegBurger->prepare();

    Burger* specialBurger = nonVegFactory->createBurger("Special");
    specialBurger->prepare();

    Burger* lowFatBurger = nonVegFactory->createBurger("Low-Fat");
    lowFatBurger->prepare();

    return 0;
}