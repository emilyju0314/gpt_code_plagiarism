#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int m, n;
    std::cin >> m;
    
    std::vector<int> discount_quantities(m);
    for(int i = 0; i < m; i++) {
        std::cin >> discount_quantities[i];
    }
    
    std::cin >> n;
    std::vector<int> items(n);
    for(int i = 0; i < n; i++) {
        std::cin >> items[i];
    }
    
    std::sort(items.begin(), items.end());
    
    int total_cost = 0;
    int discount_index = 0;
    for(int i = n-1; i >= 0; i -= discount_quantities[discount_index]) {
        total_cost += items[i];
        discount_index = std::min(discount_index + 1, m-1);
    }
    
    std::cout << total_cost << std::endl;
    
    return 0;
}