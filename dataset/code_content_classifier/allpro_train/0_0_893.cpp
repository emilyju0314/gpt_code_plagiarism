#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> radii(n);
    for(int i = 0; i < n; i++) {
        std::cin >> radii[i];
    }

    double result = 0;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            result += M_PI * radii[i] * radii[i];
        }
    }

    std::cout << result << std::endl;

    return 0;
}