#include <iostream>
#include <string>
#include <vector>

#define MOD 1000000007

int main() {
    std::string s1, s2, s3;
    std::cin >> s1 >> s2 >> s3;

    int len1 = s1.length();
    int len2 = s2.length();
    int len3 = s3.length();

    int minLength = std::min({len1, len2, len3});
    
    std::vector<int> count(minLength, 0);
    
    for (int l = 1; l <= minLength; l++) {
        for (int i = 0; i + l <= len1 && i + l <= len2 && i + l <= len3; i++) {
            if (s1.substr(i, l) == s2.substr(i, l) && s1.substr(i, l) == s3.substr(i, l)) {
                count[l - 1]++;
            }
        }
    }

    for (int i = 0; i < minLength; i++) {
        std::cout << count[i] % MOD << " ";
    }
    
    return 0;
}