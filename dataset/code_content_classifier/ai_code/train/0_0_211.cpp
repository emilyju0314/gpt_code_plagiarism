#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::string> rows(n);
    for (int i = 0; i < n; i++) {
        std::cin >> rows[i];
    }
    
    int min_ones = m;
    for (int mask = 0; mask < (1 << n); mask++) {
        std::vector<int> count(m, 0);
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                for (int j = 0; j < m; j++) {
                    count[j] += (rows[i][j] == '0');
                }
            } else {
                for (int j = 0; j < m; j++) {
                    count[j] += (rows[i][j] == '1');
                }
            }
        }
        
        int ones = 0;
        for (int j = 0; j < m; j++) {
            ones += std::min(count[j], n - count[j]);
        }
        
        min_ones = std::min(min_ones, ones);
    }
    
    std::cout << min_ones << std::endl;
    
    return 0;
}