#include <iostream>
#include <algorithm>

int main() {
    int A, B;
    std::cin >> A >> B;
    
    int sum = A + B;
    int diff = A - B;
    int prod = A * B;
    
    int largest = std::max({sum, diff, prod});
    
    std::cout << largest << std::endl;

    return 0;
}