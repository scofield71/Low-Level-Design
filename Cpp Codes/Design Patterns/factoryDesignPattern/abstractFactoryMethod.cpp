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

class Pasta {
    public:
    virtual void prepare() = 0;
};

class VegPasta : public Pasta {
    public:
    void prepare() override {
        cout << "Preparing Veg Pasta" << endl;
    }
};

class MushroomPasta : public Pasta {
    public:
    void prepare() override {
        cout << "Preparing Mushroom Pasta" << endl;
    }
};

class NonVegPasta : public Pasta {
    public:
    void prepare() override {
        cout << "Preparing Non-Veg Pasta" << endl;
    }
};

class RedMeatPasta : public Pasta {
    public:
    void prepare() override {
        cout << "Preparing Red Meat Pasta" << endl;
    }
};

class BurgerFactory {
    public : 
    virtual Burger* createBurger(string type) = 0;
    virtual Pasta* createPasta(string type) = 0;
};

class VegFactory : public BurgerFactory {
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
    Pasta* createPasta(string type) override {
        if (type == "Veg") {
            return new VegPasta();
        } else if (type == "Mushroom") {
            return new MushroomPasta();
        } else {
            return nullptr;
        }
    }
};

class NonVegFactory : public BurgerFactory {
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
    Pasta* createPasta(string type) override {
        if (type == "Non-Veg") {
            return new NonVegPasta();
        } else if (type == "Red Meat") {
            return new RedMeatPasta();
        } else {
            return nullptr;
        }
    }
};

int main() {
    BurgerFactory* vegFactory = new VegFactory();
    vegFactory->createBurger("Veg")->prepare();
    vegFactory->createPasta("Mushroom")->prepare();
    
    BurgerFactory* nonVegFactory = new NonVegFactory();
    nonVegFactory->createBurger("Non-Veg")->prepare();
    nonVegFactory->createPasta("Red Meat")->prepare();
    return 0;
}