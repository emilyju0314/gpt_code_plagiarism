#include <iostream>
#include <algorithm>

int main() {
    int n, s;
    std::cin >> n >> s;

    int kegs[n];
    for(int i = 0; i < n; i++) {
        std::cin >> kegs[i];
    }

    std::sort(kegs, kegs + n);

    long long total = 0;
    for(int i = 0; i < n; i++) {
        total += kegs[i];
    }

    if(total < s) {
        std::cout << -1 << std::endl;
    } else {
        long long min_keg = kegs[0];
        long long extra = total - s;
        if(extra <= 0) {
            std::cout << min_keg << std::endl;
        } else {
            if(extra >= min_keg * n) {
                std::cout << min_keg << std::endl;
            } else {
                long long leftover = s % n;
                if(leftover == 0) {
                    std::cout << min_keg << std::endl;
                } else {
                    std::cout << min_keg - extra/n << std::endl;
                }
            }
        }
    }

    return 0;
}