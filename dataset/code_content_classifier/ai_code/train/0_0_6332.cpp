#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> minMovesOppositeParity(vector<int> a) {
    int n = a.size();
    vector<int> ans(n, -1);
    vector<int> vis(n, 0);

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if ((a[i] + i) < n) {
            if ((a[i] + i) % 2 != a[i] % 2) {
                vis[i] = 1;
                ans[i] = 1;
                q.push(i);
            }
        }
        if ((i - a[i]) >= 0) {
            if ((i - a[i]) % 2 != a[i] % 2) {
                vis[i] = 1;
                ans[i] = 1;
                q.push(i);
            }
        }
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if ((a[curr] + curr) < n && !vis[a[curr] + curr]) {
            if (ans[a[curr] + curr] == -1) {
                ans[a[curr] + curr] = ans[curr] + 1;
                vis[a[curr] + curr] = 1;
                q.push(a[curr] + curr);
            }
        }
        if ((curr - a[curr]) >= 0 && !vis[curr - a[curr]]) {
            if (ans[curr - a[curr]] == -1) {
                ans[curr - a[curr]] = ans[curr] + 1;
                vis[curr - a[curr]] = 1;
                q.push(curr - a[curr]);
            }
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ans = minMovesOppositeParity(a);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}