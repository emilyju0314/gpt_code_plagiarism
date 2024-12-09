#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> numbers(n);
    for(int i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }

    std::sort(numbers.begin(), numbers.end());

    long long sum = 0;
    for(int i = 0; i < n/2; i++) {
        sum += numbers[i] + numbers[n-i-1];
    }

    std::cout << sum*sum << std::endl;

    return 0;
}