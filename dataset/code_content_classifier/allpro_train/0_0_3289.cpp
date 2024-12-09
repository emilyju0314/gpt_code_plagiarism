#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, T;
    std::cin >> N >> T;
    
    std::vector<int> count(T+1, 0);
    for(int i = 0; i < N; i++) {
        int l, r;
        std::cin >> l >> r;
        count[l]++;
        count[r]--;
    }
    
    int max_count = 0;
    int curr_count = 0;
    for(int i = 0; i <= T; i++) {
        curr_count += count[i];
        max_count = std::max(max_count, curr_count);
    }
    
    std::cout << max_count << std::endl;
    
    return 0;
}