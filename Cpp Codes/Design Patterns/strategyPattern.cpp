#include "bits/stdc++.h"
using namespace std;

class FlyStrategy {
    public:
    virtual void fly() = 0;
};

class WalkStrategy {
    public:
    virtual void walk() = 0;
};

class TalkStrategy {
    public:
    virtual void talk() = 0;
};

class Robot {
    FlyStrategy* flyStrategy;
    WalkStrategy* walkStrategy;
    TalkStrategy* talkStrategy;
    public:

    Robot(FlyStrategy* fly, WalkStrategy* walk, TalkStrategy* talk) {
        this->flyStrategy = fly;
        this->walkStrategy = walk;
        this->talkStrategy = talk;
    }

    void projection() {
        cout<<"I am a robot of 5 feet height"<<endl;
    }

    void getFly() {
        this->flyStrategy->fly();
    }

    void getWalk() {
        this->walkStrategy->walk();
    }

    void getTalk() {
        this->talkStrategy->talk();
    }

};

class NormalWalk: public WalkStrategy {
    public:
    void walk() override {
        cout<<"I can walk normally"<<endl;
    }
};

class SpecialWalk: public WalkStrategy {
    public:
    void walk() override {
        cout<<"I can walk specially"<<endl;
    }
};

class NormalFly: public FlyStrategy {
    public:
    void fly() override {
        cout<<"I can fly normally"<<endl;
    }
};

class SpecialFly: public FlyStrategy {
    public:
    void fly() override {
        cout<<"I can fly specially"<<endl;
    }
};

class NormalTalk: public TalkStrategy {
    public:
    void talk() override {
        cout<<"I can talk normally"<<endl;
    }
};

class SpecialTalk: public TalkStrategy {
    public:
    void talk() override {
        cout<<"I can talk specially"<<endl;
    }
};

int main() {
    cout<<"Implementing Strategy Pattern"<<endl;
    Robot* robot = new Robot(new NormalFly(), new NormalWalk(), new NormalTalk());
    robot->projection();
    robot->getFly();
    robot->getWalk();
    robot->getTalk();

    Robot* specialRobot = new Robot(new SpecialFly(), new SpecialWalk(), new SpecialTalk());
    specialRobot->projection();
    specialRobot->getFly();
    specialRobot->getWalk();
    specialRobot->getTalk();
    return 0;
}