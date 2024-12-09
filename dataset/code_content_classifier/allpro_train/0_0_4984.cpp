#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int n = s.length();
    int ans = 1;

    for(int i = 1; i < n; i++) {
        if(n % i == 0) {
            bool flag = true;
            for(int j = 0; j < n - i; j++) {
                if(s[j] != s[j + i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                ans = n / i;
                break;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}