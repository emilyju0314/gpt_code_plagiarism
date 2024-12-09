#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;
    
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }
    
    for (int i = 0; i < q; ++i) {
        int t, x, y;
        std::cin >> t >> x >> y;
        
        if (t == 1) {
            std::swap(p[x-1], p[y-1]);
        } else {
            int ans = x;
            for (int j = 0; j < y; ++j) {
                ans = p[ans-1];
            }
            std::cout << ans << std::endl;
        }
    }
    
    return 0;
}