#include <iostream>
#include <string>

bool isValidPrice(std::string price) {
    if (price.empty()) {
        return false;
    }
    
    if (price[0] == '.') {
        return false;
    }
    
    int dotCount = 0;
    for (char c : price) {
        if (c == '.') {
            dotCount++;
        }
    }
    
    if (dotCount > 1) {
        return false;
    }
    
    // Additional checks can be implemented if needed
    
    return true;
}

double extractValue(std::string price) {
    // Remove dots from the price string
    price.erase(std::remove(price.begin(), price.end(), '.'), price.end());
    
    // Convert the price string to double
    return std::stod(price);
}

int main() {
    std::string bill;
    std::cin >> bill;
    
    double total = 0.0;
    std::string tempPrice;
    
    for (char c : bill) {
        if (isdigit(c) || c == '.' || (isalpha(c) && !tempPrice.empty())) {
            tempPrice += c;
        } else {
            if (isValidPrice(tempPrice)) {
                total += extractValue(tempPrice);
            }
            tempPrice.clear();
        }
    }
    
    if (isValidPrice(tempPrice)) {
        total += extractValue(tempPrice);
    }
    
    std::cout << total << std::endl;
    
    return 0;
}