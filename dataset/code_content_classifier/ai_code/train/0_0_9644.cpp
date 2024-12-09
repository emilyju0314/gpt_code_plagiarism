#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> numbers(n * n);
    for (int i = 0; i < n * n; i++) {
        std::cin >> numbers[i];
    }
    
    std::sort(numbers.begin(), numbers.end());
    
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += numbers[i];
    }
    
    s /= n;
    
    std::cout << s << std::endl;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << numbers[i * n + j] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}