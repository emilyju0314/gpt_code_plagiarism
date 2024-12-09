#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 998244353;

using namespace std;

int N;
vector<vector<int>> adj;
vector<int> parent, dp1, dp2;

void dfs1(int u, int p) {
    parent[u] = p;
    for(int v : adj[u]) {
        if(v != p) {
            dfs1(v, u);
            dp1[u] = max(dp1[u], dp1[v] + 1);
        }
    }
}

void dfs2(int u, int p) {
    vector<int> childDiameter;
    for(int v : adj[u]) {
        if(v != p) {
            childDiameter.push_back(dp1[v]);
        }
    }

    sort(childDiameter.rbegin(), childDiameter.rend());

    int numChildren = childDiameter.size();
    if(numChildren >= 2) {
        dp2[u] = max(dp2[u], childDiameter[0] + 1 + childDiameter[1]);
    }

    for(int v : adj[u]) {
        if(v != p) {
            int childDiameterWithoutV = (numChildren >= 2 && dp1[v] == childDiameter[0]) ? childDiameter[1] : childDiameter[0];
            dp2[u] = max(dp2[u], dp2[v] + 1);
            dp2[u] = max(dp2[u], childDiameterWithoutV + 2);
            dfs2(v, u);
        }
    }
}

int main() {
    cin >> N;
    adj.resize(N);
    parent.resize(N);
    dp1.resize(N);
    dp2.resize(N);

    for(int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(0, -1);
    dfs2(0, -1);

    int answer = 0;
    for(int i = 0; i < N; i++) {
        answer = max(answer, max(dp1[i], dp2[i]));
    }

    cout << answer << endl;
    return 0;
}