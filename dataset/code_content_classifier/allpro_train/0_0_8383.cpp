#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string s;
    int K;
    std::cin >> s >> K;

    std::vector<std::string> substrings;

    for (int i = 0; i < s.length(); ++i) {
        for (int j = 1; j <= s.length() - i; ++j) {
            substrings.push_back(s.substr(i, j));
        }
    }

    std::sort(substrings.begin(), substrings.end());

    std::cout << substrings[K - 1] << std::endl;

    return 0;
}