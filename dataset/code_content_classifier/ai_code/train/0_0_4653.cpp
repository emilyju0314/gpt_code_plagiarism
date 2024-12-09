#include <iostream>
#include <iomanip>

int main() {
    int N;
    std::cin >> N;
    
    double sum_of_inverses = 0.0;
    for (int i = 0; i < N; i++) {
        int A;
        std::cin >> A;
        sum_of_inverses += 1.0 / A;
    }
    
    double result = 1.0 / sum_of_inverses;
    
    std::cout << std::fixed << std::setprecision(10) << result << std::endl;
    
    return 0;
}