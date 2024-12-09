#include <iostream>
#include <vector>
#include <string>

const int MOD = 1000000007;

bool isNearlyLucky(int n, int k) {
    std::string num = std::to_string(n);
    int count = 0;
    for (int i = 0; i < num.length(); i++) {
        if (num[i] == '4' || num[i] == '7') {
            for(int j=std::max(0,i-k); j<std::min(i+k,(int)num.length()); j++){
                if(num[j]=='4' || num[j]=='7'){
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int t, k;
    std::cin >> t >> k;

    while (t--) {
        int l, r;
        std::cin >> l >> r;

        int count = 0;
        for (int i = l; i <= r; i++) {
            if (isNearlyLucky(i, k)) {
                count++;
            }
        }

        std::cout << count % MOD << std::endl;
    }

    return 0;
}