#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
template <class T>
T gcd(T a, T b) {
  return a ? gcd(b % a, a) : b;
}
template <class T>
T sqr(T a) {
  return a * a;
}
template <class T>
T sgn(T a) {
  return a > 0 ? 1 : (a < 0 ? -1 : 0);
}
const int N = 2e5 + 10;
const int inf = 1e9 + 10;
const int mod = 1e9 + 7;
int n;
int m;
int k;
vector<pair<pair<int, int>, int>> g[N];
int d;
int a[N];
long long b[N];
long long v[N];
vector<long long> del;
map<long long, int> w;
int up[N];
int sl[N];
int down[N];
int sr[N];
int mpp[2 * N];
bool com(pair<pair<int, int>, int> q, pair<pair<int, int>, int> p) {
  if (q.first.second < p.first.second) return true;
  if (q.first.second == p.first.second) return q.first.first < p.first.first;
  return false;
}
long long sum(int x) {
  if (x == 0) return 0;
  return b[x - 1];
}
int main() {
  cin >> n >> k;
  d = (int)sqrt(abs((double)n)) + 1;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (x == 2)
      a[i] = -1;
    else
      a[i] = 1;
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a[i] *= x;
  }
  b[0] = a[0];
  for (int i = 1; i < n; i++) b[i] = a[i] + b[i - 1];
  del.push_back(0);
  del.push_back(k);
  del.push_back(-k);
  for (int i = 0; i < n; i++) {
    del.push_back(b[i]);
    del.push_back(b[i] - k);
    del.push_back(b[i] + k);
  }
  sort((del).begin(), (del).end()),
      (del).resize(unique((del).begin(), (del).end()) - (del).begin());
  for (int i = 0; i < ((int)(del).size()); i++) w[del[i]] = i;
  for (int i = 0; i < n; i++) {
    sl[i] = w[sum(i)];
    up[i] = w[sum(i) + k];
    sr[i] = w[b[i]];
    down[i] = w[b[i] - k];
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;
    r--;
    g[l / d].push_back(make_pair(make_pair(l, r), i));
  }
  for (int i = 0; i < d + 2; i++) sort((g[i]).begin(), (g[i]).end(), com);
  for (int i = 0; i < d + 2; i++) {
    if (((int)(g[i]).size()) == 0) continue;
    for (int i = 0; i < 2 * N; i++) mpp[i] = 0;
    long long ans = 0;
    int l = g[i][0].first.first;
    int r = l - 1;
    mpp[sl[l]]++;
    for (int j = 0; j < ((int)(g[i]).size()); j++) {
      while (r < g[i][j].first.second) {
        r++;
        ans += mpp[down[r]];
        mpp[sr[r]]++;
      }
      while (l < g[i][j].first.first) {
        mpp[sl[l]]--;
        ans -= mpp[up[l]];
        l++;
      }
      while (l > g[i][j].first.first) {
        l--;
        ans += mpp[up[l]];
        mpp[sl[l]]++;
      }
      v[g[i][j].second] = ans;
    }
  }
  for (int i = 0; i < m; i++) printf("%I64d\n", v[i]);
  return 0;
}
