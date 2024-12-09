#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;

const int MN = 100100;

int lc = 0;
int l[MN], r[MN], p[MN], sz[MN];

int readtree(const string &s, int &c) {
    assert(s[c] == '(');
    c++;
    if (s[c] == ')') {
        c++;
        return -1;
    }
    int n = lc++;
    l[n] = readtree(s, c);
    r[n] = readtree(s, c);
    assert(s[c] == ')');
    c++;
    sz[n] = 1;
    if (l[n] != -1) {
        p[l[n]] = n;
        sz[n] += sz[l[n]];
    }
    if (r[n] != -1) {
        p[r[n]] = n;
        sz[n] += sz[r[n]];
    }
    return n;
}

int used[MN];
int uc = 0;

bool mark(int x, int y) {
    if (x == -1 || used[x] == uc) {
        if (y == -1) return true;
        return false;
    }
    if (y == -1) return false;
    used[x] = uc;
    return mark(l[x], l[y]) && mark(r[x], r[y]);
}

int dp[MN];
bool useddp[MN];

int solve(int n) {
    if (useddp[n]) return dp[n];
    useddp[n] = true;
    queue<int> q;
    vector<int> v;
    q.push(n);
    while (!q.empty()) {
        int m = q.front(); q.pop();
        v.push_back(m);
        if (l[m] != -1) {
            q.push(l[m]);
        }
        if (r[m] != -1) {
            q.push(r[m]);
        }
    }
    reverse(v.begin(), v.end());
    int ma = sz[n]-1;
    int S = sz[n];
    int m = v[0];
    int u = 0;
    while (n != m) {
        if (sz[n] % sz[m] == 0) {
            uc++;
            bool f = true;
            int fc = 0;
            for (int d: v) {
                if (used[d] != uc) {
                    int e = d;
                    for (int i = 0; i < u; i++) {
                        e = p[e];
                    }
                    if (!mark(e, m)) {
                        f = false;
                        break;
                    }
                    fc++;
                }
            }
            if (fc == sz[n] / sz[m] && f) {
                ma = min(ma, sz[n] / sz[m] - 1 + solve(m));
            }
        }
        u++;
        m = p[m];
    }
    return dp[n] = ma;
}

int main() {
    string s;
    cin >> s;
    int c = 0;
    p[0] = -1;
    readtree(s, c);
    cout << solve(0) << endl;
    return 0;
}