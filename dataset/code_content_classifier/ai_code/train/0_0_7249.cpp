#include <iostream>
#include <string>

int main() {
    std::string S;
    std::cin >> S;

    int daysToSunday;
    if (S == "SUN") {
        daysToSunday = 7;
    } else if (S == "MON") {
        daysToSunday = 6;
    } else if (S == "TUE") {
        daysToSunday = 5;
    } else if (S == "WED") {
        daysToSunday = 4;
    } else if (S == "THU") {
        daysToSunday = 3;
    } else if (S == "FRI") {
        daysToSunday = 2;
    } else if (S == "SAT") {
        daysToSunday = 1;
    }
    
    std::cout << daysToSunday << std::endl;

    return 0;
}