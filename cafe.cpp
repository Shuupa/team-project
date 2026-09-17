#include "cafe.h"

double withTip(double bill, double t) {
    return bill * (1.0 + t / 100.0);
}

double splitBill(double total, int k) {
    return total / k;
}

double withDiscount(double bill, double discount) {
    return bill * (1.0 - discount / 100.0);
}
