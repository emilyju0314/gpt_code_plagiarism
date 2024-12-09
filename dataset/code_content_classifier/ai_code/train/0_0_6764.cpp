#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> x(m);
    for(int i = 0; i < m; i++) {
        cin >> x[i];
    }

    vector<int> freq(n + 1, 0);
    for(int i = 1; i <= m; i++) {
        freq[x[i - 1]] = i;
    }

    long long ans = 0;
    for(int i = 1; i < m; i++) {
        int pos_diff = abs(freq[x[i - 1]] - freq[x[i]]);
        ans += min(pos_diff, n - pos_diff);
    }

    cout << ans;

    for(int i = 2; i <= n; i++) {
        int pos_diff = abs((freq[x[0]] - i));
        ans = ans - min(pos_diff, n - pos_diff);
        pos_diff = abs((freq[x[0]] + m - i));
        ans = ans + min(pos_diff, n - pos_diff);

        cout << " " << ans;
    }

    return 0;
}