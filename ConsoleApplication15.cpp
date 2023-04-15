#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

class Class1 {
public:
    virtual Class1* clone() const {
        return new Class1(*this);
    }
    virtual void print() const {
        cout << "Class1" << endl;
    }
};

class Class2 : public Class1 {
public:
    virtual Class2* clone() const {
        return new Class2(*this);
    }
    virtual void print() const {
        cout << "Class2" << endl;
    }
};

int main() {
    vector<Class1*> vec;
    vec.push_back(new Class1());
    vec.push_back(new Class2());

    for (auto& elem : vec) {
        Class1* ptr = elem->clone();
        ptr->print();
        delete ptr;
    }

    for (auto& elem : vec) {
        delete elem;
    }

    return 0;
}












