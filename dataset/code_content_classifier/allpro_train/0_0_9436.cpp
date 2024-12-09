#include <iostream>
#include <string>
#include <vector>

bool isPalindrome(const std::string& s) {
    int i = 0, j = s.length() - 1;
    while(i < j) {
        if(s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    std::string S, T;
    std::cin >> S >> T;

    int ans = 0;
    int n = S.length(), m = T.length();

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            std::string subS = S.substr(i, j - i + 1);
            if(isPalindrome(subS)) {
                for(int k = 0; k < m; k++) {
                    for(int l = k; l < m; l++) {
                        std::string subT = T.substr(k, l - k + 1);
                        if(isPalindrome(subT) && subS == subT) {
                            ans++;
                        }
                    }
                }
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}