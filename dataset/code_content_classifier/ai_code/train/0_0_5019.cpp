#include <iostream>
#include <string>
#include <vector>

#define MOD 998244353

long long solveUMG(std::string& s) {
    long long umg = 0;
    int n = s.size();

    std::vector<int> cntU(n, 0), cntG(n, 0);
    int u = 0, g = 0;

    for (int i = 0; i < n; i++) {
        if(s[i] == 'U') u++;
        cntU[i] = u;
    }

    for (int i = n-1; i >= 0; i--) {
        if(s[i] == 'G') g++;
        cntG[i] = g;
    }

    for (int i = 0; i < n; i++) {
        if(s[i] == 'M') {
            umg = (umg + (long long)cntU[i] * cntG[i]) % MOD;
        }
    }

    return umg;
}

int main() {
    std::string s;
    std::cin >> s;

    long long result = solveUMG(s);
    std::cout << result << std::endl;

    return 0;
}