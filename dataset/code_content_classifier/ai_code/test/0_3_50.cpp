#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 998244353

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 1;
    for(int i = 0; i < n; i++) {
        ans = (ans * max(0, a[i] - i)) % MOD;
    }

    cout << ans << endl;

    return 0;
}