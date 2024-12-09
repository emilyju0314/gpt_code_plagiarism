#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> segments(n*k);
    for (int i = 1; i <= n*k; i++) {
        segments[i-1] = i;
    }
    
    std::vector<int> children(k);
    for (int i = 0; i < k; i++) {
        std::cin >> children[i];
    }
    
    sort(children.begin(), children.end());
    
    int j = 0;
    for (int i = 0; i < k; i++) {
        std::swap(segments[j], segments[children[i] - 1]);
        j += n;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n*k; j += n) {
            std::cout << segments[j] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}