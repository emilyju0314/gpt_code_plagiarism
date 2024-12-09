#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 5;
vector<int> adj[MAX];
vector<int> a(MAX);
vector<int> divisors[MAX];
int cnt[MAX] = {0};
bool vis[MAX] = {false};

int gcd(int x, int y) {
    if(y == 0) return x;
    return gcd(y, x % y);
}

void dfs(int v, int p) {
    for(int div : divisors[a[v]]) {
        cnt[div]++;
    }
    vis[v] = true;

    for(int u : adj[v]) {
        if(!vis[u]) {
            dfs(u, v);
        }
    }

    for(int div : divisors[a[v]]) {
        cnt[div]--;
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        for(int j = 1; j * j <= a[i]; j++) {
            if(a[i] % j == 0) {
                divisors[i].push_back(j);
                if(j != a[i]/j) {
                    divisors[i].push_back(a[i]/j);
                }
            }
        }
    }

    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, -1);

    for(int i = 1; i <= 2e5; i++) {
        if(cnt[i] > 0) {
            cout << i << " " << cnt[i] << endl;
        }
    }

    return 0;
}