#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0;
    long long prev = 0;
    for (int i = 0; i < n; i++) {
        prev = (prev * 2 + a[i]) % MOD;
        ans = (ans + prev) % MOD;
    }

    cout << ans << endl;
    
    return 0;
}