#include <iostream>
#include <string>

int main() {
    std::string day1, day2;
    std::cin >> day1 >> day2;

    if ((day1 == "monday" && day2 == "thursday") ||
        (day1 == "tuesday" && day2 == "friday") ||
        (day1 == "wednesday" && day2 == "saturday") ||
        (day1 == "thursday" && day2 == "sunday") ||
        (day1 == "friday" && day2 == "monday") ||
        (day1 == "saturday" && day2 == "tuesday") ||
        (day1 == "sunday" && day2 == "wednesday")) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}