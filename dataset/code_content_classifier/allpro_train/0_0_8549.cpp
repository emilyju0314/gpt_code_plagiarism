#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
vector<vector<int>> tree;
vector<int> color;

int power(int base, int exp) {
    int res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (1LL * res * base) % MOD;
        }
        base = (1LL * base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int dfs(int node, int parent) {
    int white = (color[node] == 0);
    int total_children = 0;

    for (int child : tree[node]) {
        if (child != parent) {
            total_children++;
            white = (1LL * white * dfs(child, node)) % MOD;
        }
    }

    int black = power(2, total_children);
    return ((1LL * white + black) * power(2, MOD - 2)) % MOD;
}

int main() {
    int N;
    cin >> N;

    tree.resize(N);
    color.resize(N, 0);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int expected_holeyness = dfs(0, -1);
    cout << expected_holeyness << endl;

    return 0;
}