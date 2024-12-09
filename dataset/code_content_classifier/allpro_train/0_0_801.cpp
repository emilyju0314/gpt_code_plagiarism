#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> ab(n);
    for (int i = 0; i < n; i++) {
        cin >> ab[i].first >> ab[i].second;
    }

    long long ans = 1;
    long long up = 1, down = 1;
    for (int i = 0; i < n; i++) {
        int a = ab[i].first, b = ab[i].second;

        long long up_next = (up * (a + b) + down * a) % MOD;
        long long down_next = (up * b + down * a) % MOD;
        up = up_next;
        down = down_next;

        ans = (ans * (up + down)) % MOD;
    }

    cout << ans << endl;

    return 0;
}