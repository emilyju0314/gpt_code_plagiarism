#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int inches = n / 3; // Converting centimeters to inches
    int feet = inches / 12; // Converting inches to feet
    inches %= 12; // Getting the remaining inches

    // Rounding up if necessary
    if (inches >= 7) {
        feet++;
        inches = 0;
    }

    std::cout << feet << " " << inches << std::endl;
    
    return 0;
}