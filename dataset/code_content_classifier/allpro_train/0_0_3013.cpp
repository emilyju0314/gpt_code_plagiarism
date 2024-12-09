#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> daysOfWeek = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};

bool isLeapYear(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

int main() {
    int m, d;

    while (true) {
        cin >> m >> d;
        if (m == 0 && d == 0) break;

        int days = 0;
        
        // Determine number of days passed from Jan 1 to input date
        for (int month = 1; month < m; month++) {
            if (month == 2) {
                days += isLeapYear(2004) ? 29 : 28;
            } else if (month == 4 || month == 6 || month == 9 || month == 11) {
                days += 30;
            } else {
                days += 31;
            }
        }
        days += d - 1;

        // Calculate day of the week
        int dayIndex = (days + 3) % 7; // Jan 1, 2004 is Thursday
        cout << daysOfWeek[dayIndex] << endl;
    }

    return 0;
}