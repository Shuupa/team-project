#include <iostream>
#include "triangle.h"

using namespace std;

int main() {
    int choice;

    do {
        cout << "| ----------------------- |" << endl;
        cout << "|      TEAM PROJECT       |" << endl;
        cout << "| ----------------------- |" << endl;
        cout << "1. Right triangle" << endl;
        cout << "2. Cafe bill" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double a, b;

                cout << "Enter first leg: ";
                cin >> a;
                cout << "Enter second leg: ";
                cin >> b;

                cout << "Hypotenuse: " << hypotenuse(a, b) << endl;
                cout << "Area: " << rightTriangleArea(a, b) << endl;
                break;
            }

            case 2:
                cout << "Cafe bill module is not connected yet." << endl;
                break;

            case 0:
                cout << "Exit." << endl;
                break;

            default:
                cout << "Invalid option." << endl;
        }

    } while (choice != 0);

    return 0;
}
