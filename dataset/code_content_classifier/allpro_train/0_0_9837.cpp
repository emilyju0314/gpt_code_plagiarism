#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> balls(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> balls[i];
    }

    std::sort(balls.begin(), balls.end());
    
    for (int i = 0; i < n - 2; ++i) {
        if (balls[i+2] - balls[i] <= 2) {
            std::cout << "YES\n";
            return 0;
        }
    }

    std::cout << "NO\n";

    return 0;
}