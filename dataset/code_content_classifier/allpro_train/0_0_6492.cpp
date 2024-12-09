#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> prices(N);

    for(int i = 0; i < N; i++) {
        std::cin >> prices[i];
    }

    std::vector<int> sortedPrices = prices;
    std::sort(sortedPrices.begin(), sortedPrices.end());

    int minItems = 1;
    int maxItems = 1;

    for(int i = 0; i < N - 1; i++) {
        if(sortedPrices[i] < sortedPrices[i + 1]) {
            minItems++;
            maxItems++;
        } else {
            maxItems++;
        }
    }

    std::cout << minItems << std::endl;
    std::cout << maxItems << std::endl;

    return 0;
}