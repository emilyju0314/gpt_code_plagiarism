#include <iostream>
#include <vector>
#include <algorithm>

std::string generateBAStrings(const std::string& s, int k) {
    std::string result;
    for(char c : s) {
        if(c == 'a') {
            result.push_back(c);
        } else {
            for(int i = 0; i <= k; i++) {
                result.push_back('b');
            }
        }
    }
    return result;
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n, k;
        long long x;
        std::cin >> n >> k >> x;

        std::string s;
        std::cin >> s;

        std::vector<long long> prefixCount(n+1, 1);
        for(int i = 1; i <= n; i++) {
            prefixCount[i] = prefixCount[i-1] + (s[i-1] == '*' ? (k+1) : 1);
        }

        std::string result;
        for(int i = n; i >= 1; i--) {
            if(x <= prefixCount[i-1]) {
                result = generateBAStrings(s.substr(0, i-1), k);
                result.push_back('a');
                break;
            } else {
                x -= prefixCount[i-1];
            }
        }

        std::cout << result << std::endl;
    }

    return 0;
}