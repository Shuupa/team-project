#include <iostream>

using namespace std;

int main() {
    int choice;

    do {
        cout << "| ----------------------- |" << endl;
        cout << "|      TEAM PROJECT       |" << endl;
        cout << "| ----------------------- |" << endl;
        cout << "1. Прямоугольный треугольник" << endl;
        cout << "2. Счёт в кафе" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите пункт: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Модуль прямоугольного треугольника пока не подключён." << endl;
                break;

            case 2:
                cout << "Модуль счёта в кафе пока не подключён." << endl;
                break;

            case 0:
                cout << "Выход." << endl;
                break;

            default:
                cout << "Неверный пункт меню." << endl;
        }

    } while (choice != 0);

    return 0;
}
