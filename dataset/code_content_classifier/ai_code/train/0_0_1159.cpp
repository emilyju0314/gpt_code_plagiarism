#include <iostream>
#include <vector>
#include <string>

#define MOD 1000000007

std::string fibonacciString(long long k) {
    if (k == 1) return "a";
    if (k == 2) return "b";

    std::string fn_2 = "a";
    std::string fn_1 = "b";
    std::string fn;

    for (long long i = 3; i <= k; i++) {
        fn = fn_1 + fn_2;
        fn_2 = fn_1;
        fn_1 = fn;
    }

    return fn;
}

int main() {
    long long k, m;
    std::cin >> k >> m;

    std::string fibonacci = fibonacciString(k);

    for (int i = 0; i < m; i++) {
        std::string si;
        std::cin >> si;

        int count = 0;
        int n = si.length();

        for (int j = 0; j <= k - n; j++) {
            if (fibonacci.substr(j, n) == si) {
                count++;
            }
        }

        std::cout << count % MOD << std::endl;
    }

    return 0;
}