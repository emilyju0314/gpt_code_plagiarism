#include <iostream>
#include <iomanip>

int main() {
    int N;
    std::cin >> N;
    
    if (N % 2 == 0) {
        std::cout << std::fixed << std::setprecision(10) << 0.5 << std::endl;
    } else {
        double odd_count = (N + 1) / 2.0;
        double total_count = N;
        double probability = odd_count / total_count;
        std::cout << std::fixed << std::setprecision(10) << probability << std::endl;
    }
    
    return 0;
}