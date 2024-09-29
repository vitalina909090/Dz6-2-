#include <iostream>
#include <Windows.h>
using namespace std;

class Flat {
private:
    double area;
    double price;

public:
    Flat() : area(0), price(0) {}
    Flat(double areaP, double priceP) : area(areaP), price(priceP) {}

    double getArea() const { 
        return area; 
    }
    double getPrice() const {
        return price; 
    }

    bool operator==(const Flat& other) const {
        return area == other.area;
    }

    Flat& operator=(const Flat& other) {
        if (this != &other) {
            area = other.area;
            price = other.price;
        }
        return *this;
    }

    bool operator>(const Flat& other) const {
        return price > other.price;
    }

    void print() const {
        cout << "Площа: " << area << " кв.м, Ціна: " << price << " $" << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Flat apartment1(40, 14000);
    Flat apartment2(30, 12000);

    apartment1.print();
    apartment2.print();

    //1 приклад
    if (apartment1 == apartment2) {
        cout << "Квартири мають однакову площу." << endl;
    }
    else {
        cout << "Квартири мають різну площу." << endl;
    }

    //2 приклад
    if (apartment1 > apartment2) {
        cout << "apartment1 дорожча за apartment2." << endl;
    }
    else {
        cout << "apartment2 дорожча або має таку ж ціну, як apartment1." << endl;
    }

    //3 приклад
    apartment1 = apartment2;
    apartment1.print();

    return 0;
}
