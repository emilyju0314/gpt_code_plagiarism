#include <iostream>
#include <string>

#define MOD 1000000007

int main() {
    std::string s;
    std::cin >> s;

    long long ab_count = 0;
    long long result = 0;
    
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'a') {
            ab_count++;
        } else {
            result = (result + ab_count) % MOD;
            ab_count = (2 * ab_count) % MOD;
        }
    }

    std::cout << result << std::endl;

    return 0;
}