#include <iostream>
#include <string>

int main() {
    int n;
    std::string movements;

    // Input the number of unit segments and the movements protocol
    std::cin >> n;
    std::cin >> movements;

    int min_length = 1;
    // Count the number of changes in direction
    for(int i = 1; i < n; i++) {
        if(movements[i] != movements[i-1]) {
            min_length++;
        }
    }

    // Output the minimum possible length of the sequence
    std::cout << min_length << std::endl;

    return 0;
}