#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string S;
    int m;
    std::cin >> S >> m;

    std::vector<std::pair<std::string, std::string>> queries;
    for (int i = 0; i < m; i++) {
        std::string xi, yi;
        std::cin >> xi >> yi;
        queries.push_back({xi, yi});
    }

    std::vector<int> results;
    for (const auto& query : queries) {
        std::string xi = query.first;
        std::string yi = query.second;
        int maxLength = 0;
        for (size_t i = 0; i < S.length(); i++) {
            if (S[i] == xi[0]) {
                size_t j = i + 1;
                size_t k = 1;
                while (j < S.length() && k < xi.length() && S[j] == xi[k]) {
                    j++;
                    k++;
                }
                if (k == xi.length()) {
                    size_t l = j;
                    size_t m = 0;
                    while (l < S.length() && m < yi.length() && S[l] == yi[m]) {
                        l++;
                        m++;
                    }
                    if (m == yi.length()) {
                        maxLength = std::max(maxLength, static_cast<int>(l - i));
                    }
                }
            }
        }
        results.push_back(maxLength);
    }

    for (int len : results) {
        std::cout << len << std::endl;
    }

    return 0;
}