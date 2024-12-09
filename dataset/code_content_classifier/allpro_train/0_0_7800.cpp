#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k, m;
    std::cin >> n >> k >> m;

    std::vector<int> powers(n);
    for(int i = 0; i < n; i++) {
        std::cin >> powers[i];
    }

    std::sort(powers.begin(), powers.end());

    double maxAverage = 0.0;
    for(int i = 0; i <= std::min(n, m); i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += powers[j];
            int remainingOperations = m - (n - i);
            if(remainingOperations <= k * (j - i + 1)) {
                double average = (double)sum + std::min(remainingOperations / (j - i + 1), k);
                average /= (j - i + 1);
                maxAverage = std::max(maxAverage, average);
            }
        }
    }

    std::cout.precision(20);
    std::cout << std::fixed << maxAverage << std::endl;

    return 0;
}