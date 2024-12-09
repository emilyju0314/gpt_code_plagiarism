#include <iostream>

using namespace std;

bool isLeapYear(int year) {
    if (year % 400 == 0) {
        return true;
    }
    if (year % 4 == 0 && year % 100 != 0) {
        return true;
    }
    return false;
}

int main() {
    int y;
    cin >> y;

    int currentYear = y;
    while (true) {
        bool leapYear = isLeapYear(currentYear);
        int daysInYear = leapYear ? 366 : 365;

        if (daysInYear % 7 == 1) {
            break;
        }

        currentYear++;
    }

    cout << currentYear << endl;

    return 0;
}