#include <iostream>
#include <string>

bool isValidDate(int day, int month, int year) {
    if (year >= 2013 && year <= 2015) {
        if (month >= 1 && month <= 12) {
            if (day > 0) {
                if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day <= 31) {
                    return true;
                } else if ((month == 4 || month == 6 || month == 9 || month == 11) && day <= 30) {
                    return true;
                } else if (month == 2) {
                    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                        if (day <= 29) {
                            return true;
                        }
                    } else {
                        if (day <= 28) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    std::string prophesy;
    std::cin >> prophesy;

    // Loop through all possible dates in the range
    for (int year = 2013; year <= 2015; year++) {
        for (int month = 1; month <= 12; month++) {
            for (int day = 1; day <= 31; day++) {
                if (isValidDate(day, month, year)) {
                    std::string date = "";
                    if (day < 10) {
                        date += "0";
                    }
                    date += std::to_string(day) + "-";
                    if (month < 10) {
                        date += "0";
                    }
                    date += std::to_string(month) + "-" + std::to_string(year);

                    // Count the occurrences of the date in the prophesy
                    int count = 0;
                    size_t pos = prophesy.find(date);
                    while (pos != std::string::npos) {
                        count++;
                        pos = prophesy.find(date, pos + 1);
                    }

                    if (count > 1) {
                        std::cout << date << std::endl;
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}