#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> health(N);
    for(int i = 0; i < N; i++) {
        std::cin >> health[i];
    }
    
    int gcd = health[0];
    for(int i = 1; i < N; i++) {
        gcd = std::__gcd(gcd, health[i]);
    }
    
    std::cout << gcd << std::endl;
    
    return 0;
}