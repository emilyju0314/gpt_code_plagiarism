#include <iostream>

using namespace std;

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}

int daysInMonth(int year, int month) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

int daysBetweenDates(int y1, int m1, int d1, int y2, int m2, int d2) {
    int days = 0;

    while (y1 != y2 || m1 != m2 || d1 != d2) {
        days++;
        d1++;

        if (d1 > daysInMonth(y1, m1)) {
            d1 = 1;
            m1++;
        }

        if (m1 > 12) {
            m1 = 1;
            y1++;
        }
    }

    return days;
}

int main() {
    int y1, m1, d1, y2, m2, d2;

    while (true) {
        cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
        if (y1 < 0 || m1 < 0 || d1 < 0 || y2 < 0 || m2 < 0 || d2 < 0) {
            break;
        }

        cout << daysBetweenDates(y1, m1, d1, y2, m2, d2) << endl;
    }

    return 0;
}