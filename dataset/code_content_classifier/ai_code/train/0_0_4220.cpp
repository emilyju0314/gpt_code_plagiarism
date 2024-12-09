#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    long long A;
    double B;
    std::cin >> A >> B;
    
    long long result = static_cast<long long>(A * B * 100);
    std::cout << result << std::endl;
    
    return 0;
}