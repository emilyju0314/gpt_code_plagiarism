#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;

int n, k;
vector<int> adj[MAX_N];
int white[MAX_N];

void dfs(int u, int p) {
    white[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            white[u] += white[v];
        }
    }
}

int calculateScore(int u, int p, int red) {
    int blue = white[u] - red;
    int score = white[u] * (red - blue);
    for (int v : adj[u]) {
        if (v != p) {
            score += calculateScore(v, u, red);
        }
    }
    return score;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    int result = calculateScore(1, 0, min(k, white[1]));

    cout << result << endl;

    return 0;
}