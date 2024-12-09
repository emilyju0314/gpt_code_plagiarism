#include <iostream>

int main() {
    int A, B;
    std::cin >> A >> B;
    
    int start_time = (A + B) % 24;
    
    std::cout << start_time << std::endl;
    
    return 0;
}