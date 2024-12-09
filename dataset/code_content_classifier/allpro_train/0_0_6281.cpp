#include <iostream>
#include <vector>

#define MOD 1000000007

std::vector<long long> fib; // to store Fibonacci numbers

void calculateFibonacciNumbers(int n) {
    fib.resize(n+1);
    fib[1] = fib[2] = 1;
    for(int i = 3; i <= n; i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    calculateFibonacciNumbers(n);

    for(int i = 0; i < m; i++) {
        int type, l, r, x;
        std::cin >> type >> l >> r;

        if(type == 1) {
            std::cin >> x;
            for(int j = l-1; j < r; j++) {
                arr[j] = (arr[j] + x) % MOD;
            }
        } else if(type == 2) {
            long long sum = 0;
            for(int j = l-1; j < r; j++) {
                sum = (sum + fib[j - l + 2] * arr[j]) % MOD;
            }
            std::cout << sum << std::endl;
        }
    }

    return 0;
}