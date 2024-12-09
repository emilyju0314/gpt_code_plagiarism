#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    
    std::vector<int> alice(n), bob(m);
    
    for (int i = 0; i < n; i++) {
        std::cin >> alice[i];
    }
    
    for (int i = 0; i < m; i++) {
        std::cin >> bob[i];
    }
    
    std::sort(alice.begin(), alice.end());
    std::sort(bob.begin(), bob.end());
    
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (alice[i] < bob[j]) {
            i++;
        } else if (alice[i] > bob[j]) {
            j++;
        } else {
            i++;
            j++;
        }
    }
    
    if (i == n) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}