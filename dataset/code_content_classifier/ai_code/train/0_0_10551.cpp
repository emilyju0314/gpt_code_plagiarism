#include <iostream>
#include <sstream>
#include <iomanip>

int main() {
    int totalSalesAmount = 0;
    int totalSalesQuantity = 0;
    int count = 0;

    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        int unitPrice, quantity;
        char comma;
        ss >> unitPrice >> comma >> quantity;

        totalSalesAmount += unitPrice * quantity;
        totalSalesQuantity += quantity;
        count++;
    }

    int averageSalesQuantity = totalSalesQuantity / count;
    
    std::cout << totalSalesAmount << std::endl;
    std::cout << std::fixed << std::setprecision(1) << (double)averageSalesQuantity << std::endl;

    return 0;
}