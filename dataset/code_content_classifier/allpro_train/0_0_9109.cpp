#include <iostream>
#include <vector>
#include <algorithm>

bool sortingCriteria(std::string s1, std::string s2) {
    return s1 < s2;
}

std::string findMedian(std::vector<std::string>& strings) {
    int k = strings.size();
    return strings[(k-1)/2];
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m;
        std::cin >> n >> m;

        std::vector<std::string> binaryStrings;
        for (int i = 0; i < (1 << m); i++) {
            std::string s;
            for (int j = 0; j < m; j++) {
                int bit;
                std::cin >> bit;
                s += std::to_string(bit);
            }
            binaryStrings.push_back(s);
        }

        for (int i = 0; i < n; i++) {
            std::string remove;
            std::cin >> remove;
            binaryStrings.erase(std::remove(binaryStrings.begin(), binaryStrings.end(), remove), binaryStrings.end());
        }

        std::sort(binaryStrings.begin(), binaryStrings.end(), sortingCriteria);

        std::cout << findMedian(binaryStrings) << std::endl;
    }

    return 0;
}