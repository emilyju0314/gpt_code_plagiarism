#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int n, m;
    std::cin >> n;
    
    std::vector<int> a(n);
    long long sum_a = 0;
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        sum_a += a[i];
    }
    
    std::cin >> m;
    std::vector<int> b(m);
    long long sum_b = 0;
    for(int i = 0; i < m; i++) {
        std::cin >> b[i];
        sum_b += b[i];
    }
    
    long long diff = sum_a - sum_b;
    long long best_diff = abs(diff);
    
    std::pair<int, int> swap1, swap2;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            long long new_diff = abs(diff - 2 * (a[i] - b[j]));
            if(new_diff < best_diff) {
                swap1 = std::make_pair(i+1, j+1);
                best_diff = new_diff;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            long long new_diff = abs(diff - 2 * (a[i] - b[j]));
            if(i != swap1.first-1 && j != swap1.second-1 && new_diff < best_diff) {
                swap2 = std::make_pair(i+1, j+1);
                best_diff = new_diff;
            }
        }
    }
    
    std::cout << best_diff << std::endl;
    
    if(best_diff == 0) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << 2 << std::endl;
        std::cout << swap1.first << " " << swap1.second << std::endl;
        std::cout << swap2.first << " " << swap2.second << std::endl;
    }
    
    return 0;
}