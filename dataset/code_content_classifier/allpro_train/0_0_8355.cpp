#include <iostream>

int main() {
    int n;
    std::cin >> n;
    
    int sum = 0;
    int i = 1;
    while (sum < n) {
        sum += i;
        i++;
    }
    
    if (sum == n) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}