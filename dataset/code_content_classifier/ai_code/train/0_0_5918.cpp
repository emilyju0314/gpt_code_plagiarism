#include <iostream>
#include <string>

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

int daysInMonth(int month, int year) {
    if (month == 2) {
        if (isLeapYear(year)) {
            return 29;
        } else {
            return 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11){
        return 30;
    } else {
        return 31;
    }
}

int calculateDays(int year, int month, int day) {
    int days = 0;
    for (int y = 1900; y < year; y++) {
        if (isLeapYear(y)) {
            days += 366;
        } else {
            days += 365;
        }
    }

    for (int m = 1; m < month; m++) {
        days += daysInMonth(m, year);
    }

    days += day - 1;

    return days;
}

int main() {
    std::string date1, date2;
    std::cin >> date1 >> date2;

    int year1, month1, day1;
    int year2, month2, day2;

    sscanf(date1.c_str(), "%d:%d:%d", &year1, &month1, &day1);
    sscanf(date2.c_str(), "%d:%d:%d", &year2, &month2, &day2);

    int days1 = calculateDays(year1, month1, day1);
    int days2 = calculateDays(year2, month2, day2);

    int difference = abs(days1 - days2);

    std::cout << difference << std::endl;

    return 0;
}