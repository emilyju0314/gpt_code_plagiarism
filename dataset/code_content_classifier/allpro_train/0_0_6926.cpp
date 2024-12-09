#include <iostream>
#include <vector>
#include <unordered_set>

bool isPowerOfTwo(int x) {
    return x && !(x & (x - 1));
}

int minimumRemovals(std::vector<int>& sequence) {
    int removals = 0;
    std::unordered_set<int> seen;

    for (int num : sequence) {
        bool found = false;
        for (int i = 1; i <= (1 << 30); i <<= 1) {
            int complement = i - num;
            if (seen.count(complement)) {
                found = true;
                break;
            }
        }
        if (!found) {
            removals++;
        }
        seen.insert(num);
    }

    return removals;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        std::cin >> sequence[i];
    }

    int result = minimumRemovals(sequence);
    std::cout << result << std::endl;

    return 0;
}