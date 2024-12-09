#include <iostream>

int main() {
    int A, B;
    std::cin >> A >> B;
    
    int area = A * B - (A + B - 1);
    
    std::cout << area << std::endl;
    
    return 0;
}