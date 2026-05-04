#include "bits/stdc++.h"
using namespace std;

class Database{
    public:
    virtual void save() = 0;
};

class MongoDatabase : public Database {
    public:
    void save() override {
        cout<<"Saving in Mongo DB"<<endl;
    }
};

class MySQLDatabase : public Database {
    public:
    void save() override {
        cout<<"Saving in MySQL DB"<<endl;
    }
};

class UserService {
    Database* db;
    public:
    UserService (Database* db) {
        this->db = db;
    }

    void save() {
        this->db->save();
    }
};

int main() {
    cout<<"Implementing Dependency Inversion Principle"<<endl;
    MongoDatabase* mongo = new MongoDatabase();
    MySQLDatabase* sql = new MySQLDatabase();
    UserService* mongoUser = new UserService(mongo);
    UserService* sqlUser = new UserService(sql);
    mongoUser->save();
    sqlUser->save();
    return 0;
}