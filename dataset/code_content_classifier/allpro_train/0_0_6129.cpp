#include <iostream>
#include <map>
#include <vector>

int main() {
    std::map<int, int> freq;
    int n;
    std::vector<int> nums;

    // Read the sequence of integers
    while (std::cin >> n) {
        nums.push_back(n);
        freq[n]++;
    }

    // Find the mode value(s)
    int maxFreq = 0;
    for (const auto& pair : freq) {
        maxFreq = std::max(maxFreq, pair.second);
    }

    for (const auto& pair : freq) {
        if (pair.second == maxFreq) {
            std::cout << pair.first << std::endl;
        }
    }

    return 0;
}