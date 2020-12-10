//Specifications for Car Class

#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <string>
using namespace std;


class Car
{
    //Private attributes
    private:
        int yearModel;
        string make;
        int speed;

    public:
        //Constructor 1
        Car(int y, string m ){
            yearModel = y;
            make = m;
            speed = 0;
        }
        //Constructor 2
        Car(int y, string m, int s) {
            yearModel = y;
            make = m;
            speed = s;
        }
        //Setters
        void setYearModel(int y) {
            yearModel = y;
        }
        void setMake(string m) {
            make = m;
        }
        void setSpeed(int s) {
            speed = s;
        }
        //Getters
        int getYearModel() const {
            return yearModel;
        }
        string getMake() const {
            return make;
        }
        int getSpeed() const {
            return speed;
        }
        //Functions
        int accelerate() {
            return speed + 5;
        }
        int brake() {
            return speed - 5;
        }
        //Function displays class object's attributes
        void displayCar() {
            cout << "Year model: " << yearModel << endl;
            cout << "Car make: " << make << endl;
            cout << "Inital Speed: " << speed << " mph" << endl;
        }
};


#endif 


