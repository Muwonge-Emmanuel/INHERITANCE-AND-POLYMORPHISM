#include <iostream>
#include <string>
using namespace std;

// Parent class with a virtual function
class Animal {
protected:
    string name;
public:
    Animal(string n) : name(n) {}
    virtual void makeSound() const {
        cout << name << " makes a generic animal sound." << endl;
    }
    virtual ~Animal() {}
};

// Derived class 1
class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}
    void makeSound() const override {
        cout << name << " says: Woof! Woof!" << endl;
    }
};

// Derived class 2
class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}
    void makeSound() const override {
        cout << name << " says: Meow!" << endl;
    }
};

// Derived class 3
class Cow : public Animal {
public:
    Cow(string n) : Animal(n) {}
    void makeSound() const override {
        cout << name << " says: Moo!" << endl;
    }
};

// Reference to base class: works with any derived object
void playSound(const Animal& a) {
    a.makeSound();
}

int main() {
    Dog d("dog");
    Cat c("cat");
    Cow w("cow");

    // Base-class pointer
    Animal* ptr;

    cout << "Using base-class pointer " << endl;
    ptr = &d; ptr->makeSound();
    ptr = &c; ptr->makeSound();
    ptr = &w; ptr->makeSound();

    cout << "\n Using base-class reference " << endl;
    playSound(d);
    playSound(c);
    playSound(w);

    cout << "\n Array of base-class pointers" << endl;
    Animal* zoo[] = { &d, &c, &w };
    for (Animal* a : zoo)
        a->makeSound();      // same call, different behaviour

    return 0;
}