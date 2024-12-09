#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, V;
    std::cin >> n >> V;

    std::vector<int> a(n);
    std::vector<int> b(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    double minRatio = 100.0;
    for (int i = 0; i < n; i++) {
        double ratio = (double)b[i] / a[i];
        minRatio = std::min(minRatio, ratio);
    }

    double volume = minRatio * V;
    
    std::cout << volume << std::endl;

    return 0;
}