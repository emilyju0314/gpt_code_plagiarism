#include <iostream>
#include <algorithm>

int main() {
    int a1, a2, k1, k2, n;
    std::cin >> a1 >> a2 >> k1 >> k2 >> n;

    int minPlayers = std::max(0, n - (a1*(k1-1) + a2*(k2-1)));
    
    int maxA1 = std::min(a1, n/k1);
    int maxA2 = std::min(a2, (n - maxA1*k1)/k2);
    int maxPlayers = maxA1 + maxA2;

    std::cout << minPlayers << " " << maxPlayers << std::endl;

    return 0;
}