#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n+1), b(n+1), dp(n+1, 1e9);
    vector<int> jump(n+1), rest(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = a[i]; j >= 0; j--) {
            if (i-j-rest[i]+a[i-j] <= n) {
                if (dp[i-j-rest[i]+a[i-j]] > dp[i] + 1) {
                    dp[i-j-rest[i]+a[i-j]] = dp[i] + 1;
                    jump[i-j-rest[i]+a[i-j]] = i;
                    rest[i-j-rest[i]+a[i-j]] = b[i];
                }
            }
        }
    }

    if (dp[0] == 1e9) {
        cout << -1 << endl;
    } else {
        cout << dp[0] << endl;
        vector<int> path;
        int cur = 0;
        while (cur < n) {
            path.push_back(cur);
            int next = jump[cur];
            cur = next;
        }
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
    }

    return 0;
}