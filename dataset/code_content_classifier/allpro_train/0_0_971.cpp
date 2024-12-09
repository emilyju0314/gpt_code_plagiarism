#include <iostream>
#include <vector>

#define MOD 998244353

int countBits(int n) {
    int count = 0;
    while(n > 0) {
        count++;
        n &= n - 1;
    }
    return count;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> dolls(n);
    for(int i = 0; i < n; i++) {
        std::cin >> dolls[i];
    }

    std::vector<int> count(m+1, 0);
    for(int i = 0; i < n; i++) {
        count[countBits(dolls[i])]++;
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < (1 << m); j++) {
            if((j & (1 << i)) == 0) {
                count[j] = (count[j] + count[j ^ (1 << i)]) % MOD;
            }
        }
    }

    for(int i = 0; i <= m; i++) {
        std::cout << count[i] << " ";
    }

    return 0;
}