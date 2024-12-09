#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, x, f;
    std::cin >> N;
    
    std::vector<int> address(N);
    for(int i = 0; i < N; i++) {
        std::cin >> address[i];
    }
    
    std::cin >> x >> f;
    
    std::sort(address.begin(), address.end()); // Sort the addresses in ascending order
    
    int totalFee = 0;
    
    for(int i = 0; i < N-1; i++) {
        int diff = std::max(0, x - address[i]);
        totalFee += diff;
        address[i+1] += diff; // Transfer the remaining satoshi to the next address
    }
    
    std::cout << totalFee * f << std::endl;
    
    return 0;
}