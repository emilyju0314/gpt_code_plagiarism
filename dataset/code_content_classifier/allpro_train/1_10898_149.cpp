#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll n;
    while (cin >> n && n != -1) {
        ll base = 4;
        string ans;
        while (n) {
            ans += to_string(n % base);
            n /= base;
        }
        reverse(ans.begin(), ans.end());
        if (ans.empty()) cout << 0 << endl;
        else cout << ans << endl;
    }
}
