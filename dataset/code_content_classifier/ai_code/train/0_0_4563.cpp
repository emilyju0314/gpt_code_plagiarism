#include <iostream>
#include <vector>

int main() {
    int K, N;
    std::cin >> K >> N;
    
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    int maxDistance = 0;
    int totalDistance = 0;
    
    for (int i = 0; i < N-1; i++) {
        int distance = A[i+1] - A[i];
        if (distance < 0) {
            distance += K;
        }
        maxDistance = std::max(maxDistance, distance);
        totalDistance += distance;
    }
    
    totalDistance -= maxDistance;
    
    std::cout << totalDistance << std::endl;
    
    return 0;
}