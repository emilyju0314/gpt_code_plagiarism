#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> friends(n);
    for(int i = 0; i < n; i++) {
        std::cin >> friends[i];
    }
    
    std::sort(friends.begin(), friends.end());
    
    long long total_sum = 0;
    for(int i = 0; i < m; i++) {
        total_sum = (total_sum + friends[0] + friends[1]) % MOD;
    }
    
    std::cout << total_sum << std::endl;
    
    return 0;
}