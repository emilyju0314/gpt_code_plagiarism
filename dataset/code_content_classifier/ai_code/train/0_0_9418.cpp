#include <iostream>
using namespace std;

const int MOD = 1000000007;

long long power(long long base, long long exp) {
    long long result = 1;
    while(exp > 0) {
        if(exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    long long total_ways = power(2, n) - 1;
    long long combinations_ab = (total_ways - power(2, n-a) - power(2, n-b)) % MOD;
    if(combinations_ab < 0) {
        combinations_ab += MOD;
    }

    cout << combinations_ab << endl;

    return 0;
}