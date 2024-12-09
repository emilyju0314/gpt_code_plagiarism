#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:667772160")
using namespace std;
struct __isoff {
  __isoff() {
    if (0) freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    srand('C' + 'T' + 'A' + 'C' + 'Y' + 'M' + 'B' + 'A');
  }
  ~__isoff() {}
} __osafwf;
const unsigned long long p1 = 31;
const unsigned long long p2 = 29;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int infi = 1e9 + 7;
const long long inf = 1e18 + 7;
const long long dd = 7e5 + 7;
const long long mod = 1e9 + 7;
const long long mod2 = 1e6 + 3;
pair<int, int> TT;
long long vec(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
  a.first -= b.first;
  a.second -= b.second;
  c.first -= b.first;
  c.second -= b.second;
  return a.first * c.second - a.second * c.first;
}
long long dis(pair<int, int> a, pair<int, int> b) {
  a.first -= b.first;
  a.second -= b.second;
  return a.first * a.first + a.second * a.second;
}
bool cmp(pair<int, int> a, pair<int, int> b) {
  int t = vec(a, TT, b);
  if (t == 0) {
    return dis(a, TT) < dis(b, TT);
  }
  return t < 0;
}
int main() {
  int n;
  while (cin >> n) {
    if (n == 0) return 0;
    vector<vector<int> > T(n + 2, vector<int>(n + 2));
    for (long long i = 0; i < (long long)n; i++) {
      for (long long j = 0; j < (long long)n; j++) {
        char c;
        scanf(" %c", &c);
        T[i + 1][j + 1] = c - '0';
      }
    }
    reverse(T.begin(), T.end());
    vector<pair<int, int> > G;
    for (long long i = (long long)1; i < (long long)n + 1; i++) {
      for (long long j = (long long)1; j < (long long)n + 1; j++) {
        if (T[i][j] == 1) {
          if (T[i - 1][j] > 0 && T[i][j - 1] > 0 && T[i + 1][j] == 0 &&
              T[i][j + 1] == 0) {
            G.push_back(make_pair(i, j));
          }
          if (T[i + 1][j] > 0 && T[i][j + 1] > 0 && T[i - 1][j] == 0 &&
              T[i][j - 1] == 0) {
            G.push_back(make_pair(i + 1, j + 1));
          }
          if (T[i + 1][j] > 0 && T[i][j - 1] > 0 && T[i - 1][j] == 0 &&
              T[i][j + 1] == 0) {
            G.push_back(make_pair(i + 1, j));
          }
          if (T[i - 1][j] > 0 && T[i][j + 1] > 0 && T[i + 1][j] == 0 &&
              T[i][j - 1] == 0) {
            G.push_back(make_pair(i, j + 1));
          }
        }
      }
    }
    for (long long i = 0; i < (long long)G.size(); i++) {
      G[i].first -= 1;
      G[i].second -= 1;
      swap(G[i].first, G[i].second);
    }
    sort(G.begin(), G.end());
    G.resize(unique(G.begin(), G.end()) - G.begin());
    {
      int m = G.size();
      for (long long i = 0; i < (long long)m; i++) {
        if (G[i] < G[0]) {
          swap(G[i], G[0]);
        }
      }
      TT = G[0];
      sort(G.begin() + 1, G.end(), cmp);
      vector<pair<int, int> > E;
      for (long long i = 0; i < (long long)m; i++) {
        while (E.size() > 1 &&
               vec(E[E.size() - 2], E[E.size() - 1], G[i]) <= 0) {
          E.pop_back();
        }
        E.push_back(G[i]);
      }
      cout << E.size() << '\n';
      for (long long i = 0; i < (long long)E.size(); i++) {
        cout << E[i].first << ' ' << E[i].second << '\n';
      }
    }
  }
}
