#include <iostream>

int main() {
    int m, d;
    std::cin >> m >> d;

    // Number of days in each month
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Calculate the total number of days in the given month
    int totalDays = daysInMonth[m];

    // Calculate the day of the week on which the month ends
    int lastDay = (totalDays + d - 1) % 7;

    // Calculate the number of columns needed based on the day of the week of the first date and the last date
    int columns = (lastDay + totalDays + 6) / 7;

    std::cout << columns << std::endl;

    return 0;
}