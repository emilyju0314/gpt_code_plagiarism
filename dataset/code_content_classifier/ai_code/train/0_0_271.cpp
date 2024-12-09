#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    long long int n;
    cin >> n;

    long long int ans = 1;
    for (long long int i = 1; i <= n; ++i) {
        ans = (ans * i) % MOD;
    }

    for (long long int i = 1; i < n - 1; ++i) {
        ans = (ans * 2) % MOD;
    }

    cout << ans << endl;
    return 0;
}