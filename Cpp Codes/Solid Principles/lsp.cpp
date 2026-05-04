#include <bits/stdc++.h>
using namespace std;

class NonWithdrawableAccount {
    public:
    virtual void deposit(int val) = 0;
};

class WithdrawableAccount: public NonWithdrawableAccount {
    public:
    virtual void withdraw(int val) = 0;
};

class FixedAccount : public NonWithdrawableAccount{
    int balance;
    string name;
    public:
    FixedAccount(string name, int b) {
        this->balance = b;
        this->name = name;
    }

    void deposit(int val) {
        this->balance = this->balance + val;
        cout<<this->name<<" balance : "<<this->balance<<endl;
    }
};

class SavingAccount: public WithdrawableAccount{
    int balance;
    string name;
    public:
    SavingAccount(string name,int b) {
        this->balance = b;
        this->name = name;
    }

    void deposit(int val) {
        this->balance = this->balance + val;
        cout<<this->name<<" balance : "<<this->balance<<endl;
    }

    void withdraw(int val) {
        if(this->balance<val) {
            cout<<this->name<<" Insufficient balance found"<<endl;
            return;
        }
        this->balance = this->balance - val;
        cout<<this->name<<" Balance left : "<<this->balance<<endl;
    }
};

int main() {
    cout<<"Implementing Liskov Substitution Principle application now"<<endl;
    WithdrawableAccount* goluAccount = new SavingAccount("Golu", 1000);
    NonWithdrawableAccount* chotiAccount = new FixedAccount("Choti",500);
    goluAccount->deposit(3000);
    chotiAccount->deposit(200);
    goluAccount->withdraw(2000);
    goluAccount->withdraw(5000);
    return 0;
}