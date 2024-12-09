#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> numbers(n);
    std::unordered_map<int, int> occurrences;

    for(int i = 0; i < n; i++) {
        std::cin >> numbers[i];
        occurrences[numbers[i]]++;
    }

    long long total_pairs = 0;

    for(const auto& num_count : occurrences) {
        int count = num_count.second;
        total_pairs += (static_cast<long long>(count) * (count - 1)) / 2;
    }

    std::cout << total_pairs << std::endl;

    return 0;
}