#include <iostream>

using namespace std;

const int MOD = 1000000007;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int m, n;
    cin >> m >> n;
    
    long long result = power(m, n, MOD);
    cout << result << endl;
    
    return 0;
}