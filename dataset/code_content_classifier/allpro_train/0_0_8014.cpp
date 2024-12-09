#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, a;
    std::cin >> n >> a;
    
    std::vector<int> checkpoints(n);
    for (int i = 0; i < n; i++) {
        std::cin >> checkpoints[i];
    }
    
    std::sort(checkpoints.begin(), checkpoints.end());
    
    int min_distance = std::min(abs(checkpoints[0] - a), abs(checkpoints[n-2] - a));
    int total_distance = checkpoints[n-1] - checkpoints[0];
    
    if ((checkpoints[0] < a && a < checkpoints[n-2]) || (checkpoints[0] > a && a > checkpoints[n-2])) {
        min_distance *= 2;
    }
    
    std::cout << total_distance - min_distance << std::endl;
    
    return 0;
}