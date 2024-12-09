#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}

int dayOfWeek(int year, int month, int day) {
    if (month < 3) {
        month += 12;
        year--;
    }
    return (day + 2*month + 3*(month+1)/5 + year + year/4 - year/100 + year/400) % 7;
}

int main() {
    int Y1, M1, D1, Y2, M2, D2;
    cin >> Y1 >> M1 >> D1 >> Y2 >> M2 >> D2;

    int count = 0;

    for (int year = Y1; year <= Y2; year++) {
        for (int month = 1; month <= 12; month++) {
            if (month == 2) {
                if (isLeapYear(year)) {
                    if (dayOfWeek(year, month, 13) == 5) {
                        count++;
                    }
                } else {
                    if (dayOfWeek(year, month, 13) == 5) {
                        count++;
                    }
                }
            } else {
                if (dayOfWeek(year, month, 13) == 5) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}