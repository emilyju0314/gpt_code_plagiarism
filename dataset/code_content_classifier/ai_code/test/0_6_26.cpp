#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int count_permutations(int n) {
    long long res = 1;
    for (int i = 1; i <= n; ++i) {
        res = (res * (4 * i - 2)) % MOD;
        res = (res * (long long)i) % MOD;
    }
    return res;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << count_permutations(n) << endl;
    }

    return 0;
}