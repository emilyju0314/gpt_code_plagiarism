#include <bits/stdc++.h>
using namespace std;
const int N = 600031;
int n, k;
string st;
int am;
int total_size;
int done[531][531][11], knap[531][531][11];
vector<int> g[531];
int memo[531][531][11];
int subsize[N];
int have[531][11];
int C;
int dep[N];
int solve(int v, int dep_above, int to_put) {
  if (done[v][dep_above][to_put]) return memo[v][dep_above][to_put];
  done[v][dep_above][to_put] = 1;
  for (int i = 0; i <= g[v].size(); i++) {
    for (int j = 0; j <= to_put; j++) {
      knap[v][i][j] = -1e9;
    }
  }
  knap[v][0][0] = 0;
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    for (int already = 0; already <= to_put; already++) {
      for (int here = 0; here + already <= to_put; here++) {
        for (int in_root = 0; in_root <= 1; in_root++) {
          int saved = knap[v][i][already];
          if (in_root) saved += subsize[to] * (dep[to] - dep_above);
          if (in_root == 1 && here == 0) continue;
          if (in_root == 1)
            saved += solve(to, dep[to], here - 1);
          else
            saved += solve(to, dep_above, here);
          knap[v][i + 1][already + here] =
              max(knap[v][i + 1][already + here], saved);
        }
      }
    }
  }
  for (int i = 0; i <= to_put; i++)
    memo[v][dep_above][to_put] =
        max(memo[v][dep_above][to_put], knap[v][g[v].size()][i]);
  return memo[v][dep_above][to_put];
}
void add(string st, int am) {
  int ptr = 0;
  for (int i = 0; i < st.size(); i++) {
    int here = st[i] - '0';
    if (have[ptr][here] == 0) {
      ++C;
      have[ptr][here] = C;
      g[ptr].push_back(C);
      dep[C] = dep[ptr] + 1;
    }
    ptr = have[ptr][here];
    subsize[ptr] += am;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> st;
    cin >> am;
    add(st, am);
    total_size += st.size() * am;
  }
  int res = solve(0, 0, k);
  cout << total_size - res << endl;
  return 0;
}
