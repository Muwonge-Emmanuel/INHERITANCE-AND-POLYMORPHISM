#include <iostream>
#include <string>
using namespace std;

// Level 1: Vehicle (base class)
class Vehicle {
public:
    int wheels = 4;
    void start() {
        cout << "Vehicle starts with " << wheels << " wheels." << endl;
    }
};

// Level 2: Car inherits Vehicle
class Car : public Vehicle {
public:
    int doors = 4;
    void openDoors() {
        cout << "Car opens " << doors << " doors." << endl;
    }
};

// Level 3: Toyota inherits Car
class Toyota : public Car {
public:
    string country = "Japan";
    void hybridMode() {
        cout << "Toyota (" << country << ") switches to hybrid mode." << endl;
    }
};

// Level 4: Corolla inherits Toyota
class Corolla : public Toyota {
public:
    string model = "Corolla Cross";
    void showModel() {
        cout << "Model: " << model << endl;
    }
};

int main() {
    Corolla myCar;   // a single Corolla object

    cout << " Inherited from Vehicle  " << endl;
    myCar.start();

    cout << "\n Inherited from Car  " << endl;
    myCar.openDoors();

    cout << "\n Inherited from Toyota " << endl;
    myCar.hybridMode();

    cout << "\n Corolla's own members " << endl;
    myCar.showModel();

    return 0;
}