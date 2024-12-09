#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        std::cin >> prices[i];
    }
    
    int m;
    std::cin >> m;
    
    std::vector<std::pair<int, int>> queries(m);
    for (int i = 0; i < m; i++) {
        std::cin >> queries[i].first >> queries[i].second;
    }
    
    for (int i = 0; i < m; i++) {
        int min_diff = prices[queries[i].second - 1] - prices[queries[i].first - 1];
        for (int j = queries[i].first - 1; j < queries[i].second; j++) {
            for (int k = j + 1; k < queries[i].second; k++) {
                min_diff = std::min(min_diff, std::abs(prices[j] - prices[k]));
            }
        }
        std::cout << min_diff << std::endl;
    }
    
    return 0;
}