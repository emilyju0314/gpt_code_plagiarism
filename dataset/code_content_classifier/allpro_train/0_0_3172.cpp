#include <iostream>
#include <vector>

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> durations(n);
    for (int i = 0; i < n; i++) {
        std::cin >> durations[i];
    }

    bool found = false;
    for (int startMonth = 1; startMonth <= 12; startMonth++) {
        bool validSequence = true;
        int currMonth = startMonth;
        int year = 2000;
        for (int i = 0; i < n; i++) {
            int daysInMonth = 0;
            switch(currMonth) {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    daysInMonth = 31;
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    daysInMonth = 30;
                    break;
                case 2:
                    daysInMonth = isLeapYear(year) ? 29 : 28;
                    break;
            }
            if (durations[i] != daysInMonth) {
                validSequence = false;
                break;
            }
            currMonth++;
            if (currMonth > 12) {
                currMonth = 1;
                year++;
            }
        }
        if (validSequence) {
            found = true;
            break;
        }
    }

    if (found) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}