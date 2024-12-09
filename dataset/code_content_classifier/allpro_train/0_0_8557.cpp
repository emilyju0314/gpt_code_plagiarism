#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> a(N);
    for(int i=0; i<N; i++) {
        std::cin >> a[i];
    }

    int minCost = INT_MAX;
    for(int i=-100; i<=100; i++) {
        int cost = 0;
        for(int j=0; j<N; j++) {
            cost += pow(a[j] - i, 2);
        }
        minCost = std::min(minCost, cost);
    }

    std::cout << minCost << std::endl;

    return 0;
}