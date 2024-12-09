#include <iostream>
using namespace std;
#define MOD 1000000007

// Function to calculate power in O(log n)
int power(long long x, long long y) {
    int res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

int main() {
    long long N, M;
    cin >> N >> M;

    // Calculate the number of different configurations of the resulting set of gems
    // using a mathematical formula
    int result = power(M, (N/M)-2); // Number of magic gems that can be split
    result = (result + (M-1)*(N % M)) % MOD; // Magic gems that are not split, and normal gems
    cout << result << endl;

    return 0;
}