#include "bits/stdc++.h"
#include <mutex>
using namespace std;

std::mutex mtx;

class DatabaseConnection {
    private:
    static DatabaseConnection* instance;
    DatabaseConnection() {
        // Private constructor to prevent instantiation
        cout<<"Database Connection Created" << endl;
    }

    public:
    static DatabaseConnection* getInstance() {
        if (DatabaseConnection::instance == nullptr) {
            mtx.lock();
            if (DatabaseConnection::instance == nullptr) {
                DatabaseConnection::instance = new DatabaseConnection();
            }
            mtx.unlock();
        } else {
            cout<<"Database Connection Already Exists" << endl;
        }
        return DatabaseConnection::instance;
    }
};

DatabaseConnection* DatabaseConnection::instance = nullptr;

int main() {
    std::thread t1([]() {
        DatabaseConnection* db = DatabaseConnection::getInstance();
    });
    std::thread t2([]() {
        DatabaseConnection* db = DatabaseConnection::getInstance();
    });
    t1.join();
    t2.join();

    return 0;
}