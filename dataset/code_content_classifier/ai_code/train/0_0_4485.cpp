#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    
    std::sort(a.begin(), a.end(), std::greater<int>());
    
    int min_cost = 0;
    for (int i = K; i < N; i++) {
        min_cost += a[i];
    }
    
    std::cout << min_cost << std::endl;
    
    return 0;
}