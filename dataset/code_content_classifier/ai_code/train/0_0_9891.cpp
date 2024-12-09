#include <iostream>
#include <algorithm>

#define MOD 1000000007

using namespace std;

long long power(long long a, long long b) {
    long long res = 1;
    while(b > 0) {
        if(b % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    // Calculate the number of ways using combinatorial formula
    long long ways = power(2, k);

    // Apply modular inverse to calculate the final result
    long long result = power(ways, n) % MOD;
    result = power(result, m) % MOD;

    cout << result << endl;

    return 0;
}