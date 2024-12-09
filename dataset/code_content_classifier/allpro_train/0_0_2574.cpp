#include <iostream>

int main() {
    int N;
    std::cin >> N;
    
    int change = 1000 - (N % 1000);
    if(change == 1000) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << change << std::endl;
    }
    
    return 0;
}