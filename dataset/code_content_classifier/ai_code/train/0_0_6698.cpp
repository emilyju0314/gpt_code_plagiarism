#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    
    std::vector<int> alice(n), bob(m);
    for(int i = 0; i < n; i++) {
        std::cin >> alice[i];
    }
    for(int i = 0; i < m; i++) {
        std::cin >> bob[i];
    }
    
    std::sort(alice.begin(), alice.end(), std::greater<int>());
    std::sort(bob.begin(), bob.end(), std::greater<int>());
    
    int i = 0, j = 0, totalAlice = 0, totalBob = 0;
    
    while(i < n && j < m) {
        if(alice[i] > bob[j]) {
            totalAlice += alice[i];
            i++;
        } else {
            totalBob += bob[j];
            j++;
        }
    }
    
    while(i < n) {
        totalAlice += alice[i];
        i++;
    }
    
    if(totalAlice > totalBob) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}