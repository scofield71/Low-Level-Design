#include <bits/stdc++.h>
using namespace std;

class ShoppingCart{
    private :
    vector<int> products;
    public : 
    ShoppingCart(vector<int> prds) {
        products = prds;
    }
    vector<int> getProducts() {
        return products;
    }
    void setProducts(vector<int> prds) {
        products = prds;
    }
    int calcTotalPrice() {
        cout<<"Calculating total price of products"<<endl;
        int ans = 0;
        for(auto it:this->products) {
            ans+=it;
        }
        return ans;
    }
};

class CartInvoicePrinter{
    private:
    ShoppingCart* sp;

    public:
    CartInvoicePrinter(ShoppingCart* sp) {
        this->sp = sp;
    }

    void printInvoice() {
        cout<<"Printing invoice of shopping cart..."<<endl;
        for(auto it: sp->getProducts()) {
            cout<<"Item : "<<it<<endl;
        }
    }
};

class Persistance{
    public: 
    ShoppingCart* sp;
    virtual void savingToDB() = 0;
};

class SQLPersistance : public Persistance{
    public:
    SQLPersistance(ShoppingCart* cart) {
        Persistance::sp = cart;
    }

    void savingToDB() {
        cout<<"Saving to SQL DB"<<endl;
    }
};

class MongoPersistance : public Persistance{
    public:
    MongoPersistance(ShoppingCart* cart) {
        Persistance::sp = cart;
    }

    void savingToDB() {
        cout<<"Saving to Mongo DB"<<endl;
    }
};

int main() { 
    //Item serial number equal to price
    vector<int> prds = {1,2,3,4,5};
    ShoppingCart* sp = new ShoppingCart(prds);
    CartInvoicePrinter* printer = new CartInvoicePrinter(sp);
    cout<<"Total price is -> "<<sp->calcTotalPrice()<<endl;
    printer->printInvoice();

    Persistance* sqlStorage = new SQLPersistance(sp);
    Persistance* mongoStoragge = new MongoPersistance(sp);
    sqlStorage->savingToDB();
    mongoStoragge->savingToDB();
    return 0;
}
