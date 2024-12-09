#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int>> adj;
vector<int> subtree_size, factorial, inv_factorial, ans;

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int power(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

void dfs(int node, int parent) {
    subtree_size[node] = 1;
    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node);
            subtree_size[node] += subtree_size[child];
        }
    }
}

void calculate_factorials(int n) {
    factorial.resize(n+1);
    inv_factorial.resize(n+1);

    factorial[0] = 1;
    for (int i = 1; i <= n; i++) {
        factorial[i] = mul(factorial[i - 1], i);
    }

    inv_factorial[n] = power(factorial[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) {
        inv_factorial[i] = mul(inv_factorial[i + 1], i + 1);
    }
}

int calculate_comb(int n, int k) {
    return mul(factorial[n], mul(inv_factorial[k], inv_factorial[n - k]));
}

void dynamic_programming(int node, int parent, int n) {
    ans[node] = 1;
    if (parent != -1) {
        ans[node] = mul(ans[parent], calculate_comb(n-1, subtree_size[node]-1));
    }

    for (int child : adj[node]) {
        if (child != parent) {
            dynamic_programming(child, node, n);
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n);
    ans.resize(n);
    subtree_size.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, -1);
    calculate_factorials(n);

    dynamic_programming(0, -1, n);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}