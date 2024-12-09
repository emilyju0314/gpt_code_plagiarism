#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> sequence[i];
    }
    
    std::sort(sequence.begin(), sequence.end());
    
    int max_remainder = 0;
    for (int i = 0; i < n-1; ++i) {
        int remainder = sequence[i+1] % sequence[i];
        max_remainder = std::max(max_remainder, remainder);
    }
    
    std::cout << max_remainder << std::endl;
    
    return 0;
}