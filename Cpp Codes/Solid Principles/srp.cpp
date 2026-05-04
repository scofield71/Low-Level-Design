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

class CartDBStorage{
    private:
    ShoppingCart* sp;

    public: 
    CartDBStorage(ShoppingCart* sp) {
        this->sp = sp;
    }

    void savingToDB() {
        cout<<"Saving the shopping cart entities in database"<<endl;
    }
};
int main() { 
    //Item serial number equal to price
    vector<int> prds = {1,2,3,4,5};
    ShoppingCart* sp = new ShoppingCart(prds);
    CartDBStorage* storage = new CartDBStorage(sp);
    CartInvoicePrinter* printer = new CartInvoicePrinter(sp);
    cout<<"Total price is -> "<<sp->calcTotalPrice()<<endl;
    storage->savingToDB();
    printer->printInvoice();
    return 0;
}
