#include <iostream>

int main() {
    int dresses, parties;
    std::cin >> dresses >> parties;

    int result = (parties + dresses - 1) / dresses; // calculate the frequency she has to wear the most reused dress

    std::cout << result << std::endl;

    return 0;
}