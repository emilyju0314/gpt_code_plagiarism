#include <iostream>

int main() {
    int num;
    double product = 1.0;

    // Enter the number of values to be inputted
    std::cin >> num;

    // Enter all the values and calculate the product
    for (int i = 0; i < num; i++) {
        double value;
        std::cin >> value;
        product *= value;
    }

    // Print the product with 9 decimal places
    std::cout << std::fixed;
    std::cout.precision(9);
    std::cout << product << std::endl;

    return 0;
}