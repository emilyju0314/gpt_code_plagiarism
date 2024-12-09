#include <iostream>
#include <map>

int main() {
    std::map<int, int> thisMonthData;
    std::map<int, int> lastMonthData;

    // Read this month's data
    int customerNum, tradingDate;
    char comma;
    while (std::cin >> customerNum >> comma >> tradingDate) {
        thisMonthData[customerNum]++;
    }

    // Skip the blank line
    std::string blank;
    std::getline(std::cin, blank);

    // Read last month's data
    while (std::cin >> customerNum >> comma >> tradingDate) {
        lastMonthData[customerNum]++;
    }

    // Output companies with transactions for two consecutive months
    for (auto& pair : lastMonthData) {
        int customer = pair.first;
        if (thisMonthData.find(customer) != thisMonthData.end()) {
            std::cout << customer << " " << thisMonthData[customer] + lastMonthData[customer] << std::endl;
        }
    }

    return 0;
}