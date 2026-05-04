#include "bits/stdc++.h"
using namespace std;


class N2DShape {
    public:
    virtual int area() = 0;
};

class N3DShape {
    public:
    virtual int area() = 0;
    virtual int volume() = 0;
};

class Square: public N2DShape {
    int side;
    public:
    Square(int s) {
        this->side = s;
    }
    int area() override {
        return side*side;
    }
};

class Rectangle: public N2DShape {
    int length;
    int breadth;
    public:
    Rectangle(int l, int b) {
        this->length = l;
        this->breadth = b;
    }

    int area() override {
        return this->length*this->breadth;
    }
};

class Cube: public N3DShape {
    int side;
    public:
    
    Cube(int s) {
        this->side = s;
    }
    int area() override {
        return 6*side*side;
    }

    int volume() override {
        return side*side*side;
    }
};

int main() {
    cout<<"Implementing Interface Segregation Principle"<<endl;
    N2DShape* square = new Square(4);
    N2DShape* rectangle = new Rectangle(2,3);
    N3DShape* cube = new Cube(6);
    cout<<"Area of square : "<<square->area()<<endl;
    cout<<"Area of rectangle : "<<rectangle->area()<<endl;
    cout<<"Area of cube : "<<cube->area()<<endl;
    cout<<"Volume of cube : "<<cube->volume()<<endl;
    return 0;
}