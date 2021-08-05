#include <iostream>
using namespace std;

class Machine {
private:
    int id;
public:
    Machine(): id(0) {cout << "Machine no arg constructor called" << endl;}
    Machine(int m_id): id(m_id) {cout << "Machine ID arg constructor called" << endl;}
    void info() {cout << "ID: " << id << endl;}
};

class Vehicle: public Machine {
public:
    Vehicle() {cout << "Vehicle no arg constructor called" << endl;}
    // not allowed to refer to id in Vehicle class
    Vehicle(int v_id): Machine(v_id) {cout << "Vehicle ID arg constructor called" << endl;}
    // constructors are not auto inherited from super class
    // can only inherit constructor from direct super class
};

class Car: public Vehicle {
public:
    Car() {cout << "Car no arg constructor called" << endl;}
};

int main() {
    Vehicle vehicle;
    vehicle.info();
  
    Car car;
    Machine machine(145);

    machine.info();
    Vehicle vehicle2(664);
    vehicle2.info();

    return 0;
}