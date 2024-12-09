#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string a, b, c;
    std::cin >> a >> b >> c;

    int max_len = std::max({a.size(), b.size(), c.size()});

    int min_len = INT_MAX;
    for (int i = 1; i <= max_len; i++) {
        std::string s1 = std::string(i, '?') + a + std::string(max_len - i, '?');
        std::string s2 = std::string(i, '?') + b + std::string(max_len - i, '?');
        std::string s3 = std::string(i, '?') + c + std::string(max_len - i, '?');

        if (std::all_of(s1.begin(), s1.end(), [](char c) { return c == '?' || c == 'a'; }) &&
            std::all_of(s2.begin(), s2.end(), [](char c) { return c == '?' || c == 'b'; }) &&
            std::all_of(s3.begin(), s3.end(), [](char c) { return c == '?' || c == 'c'; })) {
            min_len = std::min(min_len, (int)s1.size());
        }
    }

    std::cout << min_len << std::endl;

    return 0;
}