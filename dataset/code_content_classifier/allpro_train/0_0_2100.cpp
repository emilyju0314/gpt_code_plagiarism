#include <iostream>
#include <vector>
#include <string>

const int MOD = 1e9 + 7;

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;

    long long cnt = 0;
    long long acount = 0, bcount = 0, ccount = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'a' || s[i] == '?') {
            acount++;
        }
        if (s[i] == 'b' || s[i] == '?') {
            bcount = (bcount + acount) % MOD;
        }
        if (s[i] == 'c' || s[i] == '?') {
            ccount = (ccount + bcount) % MOD;
        }
    }

    std::cout << ccount << std::endl;

    return 0;
}