#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    while (std::cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        
        std::vector<int> friends(n, 0);
        for (int i = 0; i < m; ++i) {
            int u, v;
            std::cin >> u >> v;
            friends[u - 1]++;
            friends[v - 1]++;
        }
        
        int min_gifts = *std::min_element(friends.begin(), friends.end());
        int max_gifts = 0;
        for (int gifts : friends) {
            max_gifts = std::max(max_gifts, gifts);
        }
        
        std::cout << min_gifts << " " << max_gifts << std::endl;
    }
    
    return 0;
}