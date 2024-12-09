#include <iostream>
using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    // the number of ways to go from D to itself in n steps is (3^n - 1) % MOD
    long long result = 1;
    for (int i = 0; i < n; i++) {
        result = (result * 3) % MOD;
    }

    result = (result - 1 + MOD) % MOD; // subtract 1 to exclude staying at D in the final step

    cout << result << endl;

    return 0;
}