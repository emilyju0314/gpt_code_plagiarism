#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "E869120")
            ans++;
    }
    cout << ans << endl;
}
