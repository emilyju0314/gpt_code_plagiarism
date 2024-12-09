To solve this problem, we can use the following steps in C++:

#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int MAXN = 100005;

int n, m, q;
vector<pair<int, char>> tree[MAXN];
string strings[MAXN];
map<pair<int, int>, int> dp;
map<pair<int, int>, int> count;

void dfs(int u, int p, string str) {
    for (auto edge : tree[u]) {
        int v = edge.first;
        char c = edge.second;

        if (v != p) {
            string newstr = str + c;
            count[{u, v}] = newstr.length();

            for (int i = 0; i < newstr.length(); i++) {
                string sub = newstr.substr(0, i+1);
                dp[{u, v}] += (sub == strings[u]);
            }

            dfs(v, u, newstr);
        }
    }
}

int query(int u, int v, int l, int r) {
    int res = 0;

    for (int i = l-1; i < r; i++) {
        string sub = strings[i].substr(0, count[{u, v}]);

        res += (sub == strings[i]);
    }

    return res;
}

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < n-1; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        tree[u].push_back({v, c});
        tree[v].push_back({u, c});
    }

    for (int i = 0; i < m; i++) {
        cin >> strings[i];
    }

    dfs(1, -1, "");

    for (int i = 0; i < q; i++) {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        cout << query(u, v, l, r) << endl;
    }

    return 0;
} 

This code reads the input, constructs a tree data structure from the input, then performs a depth-first search (DFS) to compute the concatenation of the letters on the shortest path between each pair of nodes. It then handles the queries by comparing the substrings of each given string to the concatenated string. Finally, it outputs the results of each query.