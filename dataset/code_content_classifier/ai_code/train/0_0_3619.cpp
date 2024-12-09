#include <iostream>

int main() {
    int M;
    std::cin >> M;
    
    int hoursUntilNewYear = 24 - M + 24;
    
    std::cout << hoursUntilNewYear << std::endl;
    
    return 0;
}