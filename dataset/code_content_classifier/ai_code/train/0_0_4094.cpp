#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int countArrays(int n, int k) {
    long long power = 1 << k;
    long long ans = 1;

    for (int i = 0; i < n; i++) {
        ans = (ans * power) % MOD;
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int result = countArrays(n, k);
        cout << result << endl;
    }

    return 0;
}