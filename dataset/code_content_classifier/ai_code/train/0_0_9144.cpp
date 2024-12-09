#include <iostream>
#include <string>

const int MOD = 1000000007;

int main() {
    std::string s;
    std::cin >> s;

    int count = 0;
    long long result = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') {
            count++;
        } else {
            result = (result + count) % MOD;
            count = (count * 2) % MOD;
        }
    }

    std::cout << result << std::endl;

    return 0;
}