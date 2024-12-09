#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 2 * 1e5 + 5;

vector<int> adjList[MAX_N];
string prefix;
string res;
int k;
int duplicateCount = 0;

void dfs(int u) {
    if (u == 0) return;

    if (adjList[u].size() == 0) {
        if (duplicateCount < k) {
            prefix += prefix;
            duplicateCount++;
        }
        res += prefix;
        res += prefix[prefix.size() - 1];
        return;
    }

    dfs(adjList[u][0]);

    if (prefix + prefix[prefix.size() - 1] < prefix) {
        prefix += prefix;
        duplicateCount++;
    }
    res += prefix;
    res += prefix[prefix.size() - 1];

    dfs(adjList[u][1]);
}

int main() {
    int n;
    cin >> n >> k;

    string labels;
    cin >> labels;

    for (int i = 0; i < n; i++) {
        adjList[i].clear();
    }

    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        if (l > 0) {
            adjList[i].push_back(l);
        }
        if (r > 0) {
            adjList[i].push_back(r);
        }
    }

    prefix = labels.substr(0, 1);
    dfs(1);

    cout << res << endl;

    return 0;
}