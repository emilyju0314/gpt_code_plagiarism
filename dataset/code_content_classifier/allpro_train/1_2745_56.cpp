#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pii;

const int SAKAIME = 2048;
const int MAX_W = 100000;
const int MAX_N = 300000;

vector<vector<int>> memo(SAKAIME+1, vector<int>(MAX_W+1, 0));
vector<Pii> VW(MAX_N + 1);

int dfs(int v, int l) {
    if (v <= SAKAIME) return memo[v][l];

    int t = 0;
    if (l - VW[v].second >= 0) t = VW[v].first + dfs(v/2, l - VW[v].second);
    return max(dfs(v/2, l), t);
}

int main() {
    int N; cin >> N;
    for (int i = 1; i <= N; i++) cin >> VW[i].first >> VW[i].second;

    for (int i = 1; i <= min(SAKAIME, N); i++) {
        for (int j = 1; j <= MAX_W; j++) {
            if (j - VW[i].second >= 0) memo[i][j] = VW[i].first + memo[i/2][j-VW[i].second];
            memo[i][j] = max(memo[i/2][j], memo[i][j]);
        }
    }
    int Q; cin >> Q;
    while (Q--) {
        int v, l; cin >> v >> l;
        cout << dfs(v, l) << endl;
    }
}