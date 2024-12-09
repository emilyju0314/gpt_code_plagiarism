#include <bits/stdc++.h>
using namespace std;
const int inf = numeric_limits<int>::max();
const long long linf = numeric_limits<long long>::max();
vector<int> disj;
set<pair<int, int> > seen;
int root(int x) {
  while (disj[x] != x) {
    disj[x] = disj[disj[x]];
    x = disj[x];
  }
  return x;
}
void join(int x, int y) { disj[root(y)] = root(x); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n = ({
    int abcdef;
    cin >> abcdef;
    abcdef;
  });
  long long m = ({
    long long abcdef;
    cin >> abcdef;
    abcdef;
  });
  disj.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    disj[i] = i;
  }
  vector<long long> edges(n + 1, 0);
  vector<long long> sz(n + 1, 1);
  for (long long i = 0; i < m; i++) {
    int a = ({
      int abcdef;
      cin >> abcdef;
      abcdef;
    });
    int b = ({
      int abcdef;
      cin >> abcdef;
      abcdef;
    });
    pair<int, int> p = make_pair(a, b);
    if (seen.count(p) >= 1) {
      continue;
    }
    seen.insert(p);
    int r_a = root(a);
    int r_b = root(b);
    if (r_a != r_b) {
      join(a, b);
      edges[root(a)] = edges[r_a] + edges[r_b] + 1;
      sz[root(a)] = sz[r_a] + sz[r_b];
    } else {
      edges[r_a]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (disj[i] == i) {
      if (edges[i] != (sz[i] * (sz[i] - 1)) / 2) {
        cout << ("NO") << '\n';
        return 0;
      }
    }
  }
  cout << ("YES") << '\n';
  return 0;
}
