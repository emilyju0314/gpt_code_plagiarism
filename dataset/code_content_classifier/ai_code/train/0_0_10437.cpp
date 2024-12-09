#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> numbers(n);
    for(int i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }
    
    long long sum = 0;
    std::sort(numbers.begin(), numbers.end());
    
    int oddCount = 0;
    for(int i = 0; i < n; i++) {
        if(numbers[i] % 2 != 0) {
            oddCount++;
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(oddCount % 2 == 0 || numbers[i] % 2 == 0) {
            sum += numbers[i];
        }
    }
    
    std::cout << sum << std::endl;
    
    return 0;
}