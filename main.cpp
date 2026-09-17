#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
#include <string>

#include "cafe.h"
#include "triangle.h"

using namespace std;

// Вариант №87. Выполнил Кузнецов В.А.

struct Operation {
    string type;
    double value;
    double parameter;
    double result;
};

// Clear incorrect input
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Get non-negative number
double getPositiveDouble() {
    double value;

    while (true) {
        cin >> value;

        if (!cin.fail() && value >= 0) {
            return value;
        }

        cout << "Error: enter a non-negative number: ";
        clearInput();
    }
}

// Get percentage from 0 to 100
double getPercentage() {
    double value;

    while (true) {
        cin >> value;

        if (!cin.fail() && value >= 0 && value <= 100) {
            return value;
        }

        cout << "Error: enter a percentage from 0 to 100: ";
        clearInput();
    }
}

// Get positive integer
int getPositiveInt() {
    int value;

    while (true) {
        cin >> value;

        if (!cin.fail() && value > 0) {
            return value;
        }

        cout << "Error: enter a positive integer: ";
        clearInput();
    }
}

// Get menu choice
int getChoice() {
    int value;

    while (true) {
        cin >> value;

        if (!cin.fail() && value >= 0 && value <= 6) {
            return value;
        }

        cout << "Error: choose an option from 0 to 6: ";
        clearInput();
    }
}

// Choose currency
string chooseCurrency() {
    int choice;

    while (true) {
        cout << "\n=== Choose Currency ===\n";
        cout << "1. RUB\n";
        cout << "2. USD\n";
        cout << "3. EUR\n";
        cout << "4. GBP\n";
        cout << "Choose a currency: ";

        cin >> choice;

        if (!cin.fail() && choice >= 1 && choice <= 4) {
            switch (choice) {
            case 1:
                return "RUB";
            case 2:
                return "USD";
            case 3:
                return "EUR";
            case 4:
                return "GBP";
            }
        }

        cout << "Error: choose an option from 1 to 4.\n";
        clearInput();
    }
}

// Display operation history
void showHistory(const vector<Operation>& history, const string& currency) {
    if (history.empty()) {
        cout << "\nHistory is empty.\n";
        return;
    }

    cout << "\n=== Operation History ===\n";

    for (size_t i = 0; i < history.size(); ++i) {
        const Operation& operation = history[i];

        cout << i + 1 << ". ";

        if (operation.type == "Tip") {
            cout << "Bill: " << operation.value << " " << currency
                << ", Tip: " << operation.parameter << "%"
                << " -> Total: " << operation.result << " " << currency;
        }
        else if (operation.type == "Split") {
            cout << "Total: " << operation.value << " " << currency
                << ", People: " << operation.parameter
                << " -> Per person: " << operation.result << " " << currency;
        }
        else if (operation.type == "Discount") {
            cout << "Bill: " << operation.value << " " << currency
                << ", Discount: " << operation.parameter << "%"
                << " -> Total: " << operation.result << " " << currency;
        }

        cout << "\n";
    }
}

int main() {
    int choice;
    double bill, tip, total, discount;
    int people;

    vector<Operation> history;

    string currency = "RUB";

    cout << fixed << setprecision(2);

    do {
        cout << "\n=== Variant 87: Cafe Bill ===\n";
        cout << "Current currency: " << currency << "\n";
        cout << "1. Calculate cafe bill with tip\n";
        cout << "2. Split bill between people\n";
        cout << "3. Apply discount\n";
        cout << "4. Show operation history\n";
        cout << "5. Change currency\n";
        cout << "6. Right triangle calculations\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";

        choice = getChoice();

        switch (choice) {
        case 1:
            cout << "Enter bill amount (" << currency << "): ";
            bill = getPositiveDouble();

            cout << "Enter tip percentage: ";
            tip = getPercentage();

            total = withTip(bill, tip);

            cout << "Total bill = "
                << total << " " << currency << "\n";

            history.push_back({
                "Tip",
                bill,
                tip,
                total
                });

            break;

        case 2:
            cout << "Enter total bill (" << currency << "): ";
            total = getPositiveDouble();

            cout << "Enter number of people: ";
            people = getPositiveInt();

            bill = splitBill(total, people);

            cout << "Bill per person = "
                << bill << " " << currency << "\n";

            history.push_back({
                "Split",
                total,
                static_cast<double>(people),
                bill
                });

            break;

        case 3:
            cout << "Enter bill amount (" << currency << "): ";
            bill = getPositiveDouble();

            cout << "Enter discount percentage: ";
            discount = getPercentage();

            total = withDiscount(bill, discount);

            cout << "Discounted bill = "
                << total << " " << currency << "\n";

            history.push_back({
                "Discount",
                bill,
                discount,
                total
                });

            break;

        case 4:
            showHistory(history, currency);
            break;

        case 5:
            currency = chooseCurrency();
            cout << "Currency changed to " << currency << ".\n";
            break;

        case 6: {
            double a, b;

            cout << "Enter first leg: ";
            cin >> a;

            cout << "Enter second leg: ";
            cin >> b;

            if (cin.fail() || a <= 0 || b <= 0) {
                cout << "Error: legs must be positive numbers.\n";
                clearInput();
                break;
            }

            cout << "Hypotenuse = " << hypotenuse(a, b) << "\n";
            cout << "Area = " << rightTriangleArea(a, b) << "\n";

            break;
        }

        case 0:
            cout << "Program finished.\n";
            break;
        }

    } while (choice != 0);

    return 0;
}