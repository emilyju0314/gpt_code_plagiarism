#include <iostream>
#include <vector>

int main() {
    int n, x;
    std::cin >> n >> x;
    
    std::vector<int> encoding(n);
    for(int i = 0; i < n; i++) {
        std::cin >> encoding[i];
    }
    
    int total_length = 0;
    for(int i = 0; i < n; i++) {
        total_length += encoding[i];
    }
    
    int max_length = x - n + 1;
    
    if(total_length + n - 1 == x && total_length <= max_length) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
    
    return 0;
}