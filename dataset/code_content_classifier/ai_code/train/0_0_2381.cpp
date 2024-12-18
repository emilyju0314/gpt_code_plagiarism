#include <iostream>
#include <string>

int main() {
    std::string currentMonth;
    int k;
    
    std::cin >> currentMonth;
    std::cin >> k;
    
    std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    int currentMonthIndex;
    for (int i = 0; i < 12; i++) {
        if (months[i] == currentMonth) {
            currentMonthIndex = i;
            break;
        }
    }
    
    int targetMonthIndex = (currentMonthIndex + k) % 12;
    
    std::cout << months[targetMonthIndex] << std::endl;
    
    return 0;
}