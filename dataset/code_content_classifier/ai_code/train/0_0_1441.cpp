#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, L;
    std::cin >> n >> L;

    std::vector<int> kefa_dist(n);
    std::vector<int> sasha_dist(n);

    for(int i = 0; i < n; i++) {
        std::cin >> kefa_dist[i];
    }

    for(int i = 0; i < n; i++) {
        std::cin >> sasha_dist[i];
    }

    // Rotate the kefa's distances to check for all possible starting points
    for(int start = 0; start < n; start++) {
        std::rotate(kefa_dist.begin(), kefa_dist.begin() + 1, kefa_dist.end());

        // Check if the rotated kefa's distances match sasha's distances
        if(kefa_dist == sasha_dist) {
            std::cout << "YES" << std::endl;
            return 0;
        }
    }

    std::cout << "NO" << std::endl;

    return 0;
} 

// To solve this problem, we rotate Kefa's distances in the vector one by one and check if it matches Sasha's distances. If it matches for any rotation, then we output "YES", otherwise we output "NO".