#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
string labels;
int k;
string result;

string dfs(int u, bool parentDuplicated) {
    string res = "";
    vector<string> children;

    for (int v : adj[u]) {
        children.push_back(dfs(v, parentDuplicated || labels[u - 1] == labels[v - 1]));
    }

    if (labels[u - 1] == labels[0] && parentDuplicated) {
        k--;
        res = labels[u - 1] + labels[u - 1];
    } else {
        res += labels[u - 1];
    }

    for (string child : children) {
        res += child;
    }

    sort(res.begin() + 1, res.end());

    while (res.size() > 1 && k > 0 && res[0] < res[1]) {
        res[1] = res[0];
        k--;
    }

    return res;
}

int main() {
    int n;
    cin >> n >> k;

    cin >> labels;

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }

    for (int i = 2; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        if (l > 0) adj[i].push_back(l);
        if (r > 0) adj[i].push_back(r);
    }

    result = dfs(1, false);

    cout << result << endl;

    return 0;
}