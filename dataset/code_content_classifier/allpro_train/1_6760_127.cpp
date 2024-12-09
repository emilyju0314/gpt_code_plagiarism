#include <bits/stdc++.h>
using namespace std;
long long n, m, i, j, k, h, t, maxn, ttt, t1, t2, sig = 0, l, d;
set<int> st1, st2;
struct node {
  long long x, y;
} p[300007];
map<long long, long long> mp1, mp2;
bool vis[300007];
bool cmp(node a, node b) { return a.x > b.x; }
int a[505][505], b[505][505];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  int sum = 0;
  sum = min(n - m, m - 1) + n - 1;
  sum += 2 * n + 1;
  cout << sum << endl;
  return 0;
}
