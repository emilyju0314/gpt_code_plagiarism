#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 998244353

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long result = 0;
    for(int i = 0; i <= n - k; i++) {
        long long mul = 1;
        for(int j = n - 1; j >= n - k; j--) {
            mul = (mul * a[j] % MOD);
        }
        result = (result + mul) % MOD;
    }

    cout << result << endl;

    return 0;
}