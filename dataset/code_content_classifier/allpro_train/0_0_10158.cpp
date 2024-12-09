#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> adj;
vector<int> color;
vector<int> cnt_a;
int x;

void dfs(int v, int p) {
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
        cnt_a[v] += cnt_a[u];
    }
    if ((cnt_a[v] == 0 || cnt_a[v] == x) && v != 1) {
        color[v] = 'b';
    } else {
        color[v] = 'a';
        cnt_a[v]++;
    }
}

int main() {
    int n;
    cin >> n >> x;

    adj.resize(n+1);
    color.resize(n+1);
    cnt_a.resize(n+1, 0);

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    dfs(1, 0);

    int distinct_strings = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt_a[i] > 0 && cnt_a[i] < x) {
            distinct_strings++;
        }
    }

    cout << distinct_strings << endl;
    for (int i = 1; i <= n; i++) {
        cout << color[i];
    }
    cout << endl;

    return 0;
}