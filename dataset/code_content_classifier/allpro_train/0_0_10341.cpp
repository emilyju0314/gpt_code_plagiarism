#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> knights(n+1, 0);
    
    for (int i = 0; i < m; i++) {
        int l, r, x;
        std::cin >> l >> r >> x;
        
        for (int j = l; j <= r; j++) {
            if (j != x) {
                if (knights[j] == 0) {
                    knights[j] = x;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        std::cout << knights[i] << " ";
    }

    return 0;
}