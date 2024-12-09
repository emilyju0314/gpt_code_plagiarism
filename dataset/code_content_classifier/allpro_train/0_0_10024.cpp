#include <iostream>

int main() {
    int M1, D1, M2, D2;
    std::cin >> M1 >> D1 >> M2 >> D2;
    
    // Check if the day D1 is the last day of month M1
    if ((M1 == 4 || M1 == 6 || M1 == 9 || M1 == 11) && D1 == 30) {
        std::cout << 1 << std::endl;
    } else if ((M1 == 1 || M1 == 3 || M1 == 5 || M1 == 7 || M1 == 8 || M1 == 10) && D1 == 31) {
        std::cout << 1 << std::endl;
    } else if (M1 == 2 && D1 == 28) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
    
    return 0;
}