#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    int p, n;
    std::cin >> p >> n;

    std::vector<int> numbers(n);
    std::unordered_set<int> buckets;

    for (int i = 0; i < n; i++) {
        std::cin >> numbers[i];
        int bucket = numbers[i] % p;

        if (buckets.find(bucket) != buckets.end()) {
            std::cout << i + 1 << std::endl;
            return 0;
        } else {
            buckets.insert(bucket);
        }
    }

    std::cout << -1 << std::endl;

    return 0;
}