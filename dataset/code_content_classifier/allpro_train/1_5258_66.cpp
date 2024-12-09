#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[10][10];
    memset(a, 0, sizeof(a));

    for (int i = 1; i <= n; ++i) {
        a[to_string(i)[0] - '0'][i % 10]++;
    }

    int ans = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            ans += a[i][j] * a[j][i];
        }
    }
    cout << ans << endl;
    return 0;
}