#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
    std::string s1, s2, s3;
    std::cin >> s1 >> s2 >> s3;

    int len1 = s1.size();
    int len2 = s2.size();
    int len3 = s3.size();

    std::vector<int> suffix1(len1 + 1, 0);
    std::vector<int> prefix2(len2 + 1, 0);
    std::vector<int> prefix3(len3 + 1, 0);

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= i; j++) {
            if (s1.substr(0, j) == s1.substr(i - j, j)) {
                suffix1[i] = j;
            }
        }
    }

    for (int i = 1; i <= len2; i++) {
        for (int j = 1; j <= i; j++) {
            if (s2.substr(0, j) == s2.substr(i - j, j)) {
                prefix2[i] = j;
            }
        }
    }

    for (int i = 1; i <= len3; i++) {
        for (int j = 1; j <= i; j++) {
            if (s3.substr(0, j) == s3.substr(i - j, j)) {
                prefix3[i] = j;
            }
        }
    }

    int result = len1 + len2 + len3;
    for (int i = 1; i <= std::min(len1, len2); i++) {
        if (s1.substr(len1 - i) == s2.substr(0, i)) {
            result = std::min(result, len1 + len2 - i);
        }
    }

    for (int i = 1; i <= std::min(len2, len3); i++) {
        if (s2.substr(len2 - i) == s3.substr(0, i)) {
            result = std::min(result, len2 + len3 - i);
        }
    }

    for (int i = 1; i <= std::min(len1, len3); i++) {
        if (s1.substr(len1 - i) == s3.substr(0, i)) {
            result = std::min(result, len1 + len3 - i);
        }
    }

    std::cout << result << std::endl;

    return 0;
}