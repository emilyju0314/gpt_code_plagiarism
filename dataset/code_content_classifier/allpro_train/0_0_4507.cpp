#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
vector<int> s(MAXN);
vector<int> a(MAXN);

bool dfs(int u, int depth, int sum) {
    if (s[u] != -1) {
        if ((depth % 2 == 0 && sum < s[u]) || (depth % 2 != 0 && sum > s[u])) {
            return false;
        }
    }
    a[u] = sum;
    for (int v : adj[u]) {
        if (!dfs(v, depth + 1, s[u] - sum)) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    if (!dfs(1, 1, s[1])) {
        cout << -1 << endl;
    } else {
        cout << accumulate(a.begin(), a.end(), 0) << endl;
    }

    return 0;
}