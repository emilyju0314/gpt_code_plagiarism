#include <iostream>
#include <vector>
#include <algorithm>

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    int max_size = 0;
    std::vector<int> max_subset;
    
    for (int i = 0; i < (1 << n); i++) {
        std::vector<int> subset;
        
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subset.push_back(a[j]);
            }
        }
        
        bool is_simple = true;
        for (int j = 0; j < subset.size(); j++) {
            for (int k = j + 1; k < subset.size(); k++) {
                if (!is_prime(subset[j] + subset[k])) {
                    is_simple = false;
                    break;
                }
            }
            if (!is_simple) {
                break;
            }
        }
        
        if (is_simple && subset.size() > max_size) {
            max_size = subset.size();
            max_subset = subset;
        }
    }
    
    std::cout << max_size << "\n";
    for (int i = 0; i < max_size; i++) {
        std::cout << max_subset[i] << " ";
    }
    
    return 0;
}