#include <iostream>
#include <vector>
#include <algorithm>

int countAB(const std::string& str) {
    int count = 0;
    for (int i = 0; i < str.size() - 1; i++) {
        if (str[i] == 'A' && str[i + 1] == 'B') {
            count++;
            i++; // Skip the next character to avoid counting overlapping 'AB's
        }
    }
    return count;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<std::string> strings(N);
    for (int i = 0; i < N; i++) {
        std::cin >> strings[i];
    }

    // Sort the strings in lexicographical order
    std::sort(strings.begin(), strings.end());

    // Find the maximum number of occurrences of 'AB' after concatenating the strings
    int maxAB = 0;
    do {
        std::string concatenated;
        for (const std::string& str : strings) {
            concatenated += str;
        }
        maxAB = std::max(maxAB, countAB(concatenated));
    } while (std::next_permutation(strings.begin(), strings.end()));

    // Output the answer
    std::cout << maxAB << std::endl;

    return 0;
}