#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<std::string> numbers(n);
    for (int i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }
    
    int min_diff = INT_MAX;
    
    std::sort(numbers.begin(), numbers.end());
    
    do {
        int max_num = 0, min_num = INT_MAX;
        for (int i = 0; i < n; i++) {
            std::string num = numbers[i];
            std::sort(num.begin(), num.end());
            int current_num = std::stoi(num);
            
            max_num = std::max(max_num, current_num);
            min_num = std::min(min_num, current_num);
        }
        
        min_diff = std::min(min_diff, max_num - min_num);
        
    } while (std::next_permutation(numbers.begin(), numbers.end()));
    
    std::cout << min_diff << std::endl;
    
    return 0;
}