#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define bug(x) cerr << #x << " = " << x << endl
#define bugf(x) cerr << x << " "
#define bugl() cerr << endl
#define couts(x) cout << x << " "
#define coutl(x) cout << x << "\n"
#define endl '\n'


typedef long long ll;

const int N = 3e5 + 5;
int TEST_NUM = 1;


using namespace std;

int used[2*N], cnt[2*N];

void dfs(vector<vector<int>> &g, int x, int col) {
    used[x] = col + 1;
    cnt[col]++;
    for (int i=0; i<g[x].size(); i++) {
        if (!used[g[x][i]]) {
            dfs(g, g[x][i], col);
        }
    }
}

void solve() {
    int n;
    string s;
    cin>> n >> s;
    vector<vector<int>> g(2*n+5);
    for (int i=0; i<n; i++) {
        int v0 = 2 * i, v1 = 2 * i + 1;
        int u0 = 2 * (i+1), u1 = 2 * (i+1) + 1;
        if (s[i] == 'L') {
            g[u0].push_back(v1);
            g[v1].push_back(u0);
        } else {
            g[v0].push_back(u1);
            g[u1].push_back(v0);
        }
    }
    memset(used, 0, sizeof(used));
    memset(cnt, 0, sizeof(cnt));
    for (int i=0; i<=n; i++) {
        if (!used[2*i]) {
            dfs(g,2*i, 2*i);
        }
    }
    for (int i=0; i<=n; i++) cout<< cnt[used[2*i] - 1]<<' ';
    cout<< endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    cin>> TEST_NUM;
    while (TEST_NUM--){
        solve();
    }
    return 0;
}