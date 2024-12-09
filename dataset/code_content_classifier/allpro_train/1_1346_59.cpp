#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a * (b / (gcd(a, b))); }
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
inline long long toLL(string s) {
  long long v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}
using namespace std;
vector<vector<int> > G(3005);
int DP[3005][3005];
int N, E;
void bfs(int u) {
  queue<pair<int, int> > Q;
  Q.push(make_pair(u, 0));
  while (!Q.empty()) {
    pair<int, int> v = Q.front();
    Q.pop();
    if (DP[u][v.first] != -1) continue;
    DP[u][v.first] = v.second;
    for (int k = 0; k < ((int)((G[v.first]).size())); k++) {
      Q.push(make_pair(G[v.first][k], v.second + 1));
    }
  }
}
int main() {
  scanf("%d %d", &N, &E);
  memset(DP, -1, sizeof(DP));
  int u, v;
  for (int i = 0; i < E; i++) {
    scanf("%d %d", &u, &v);
    --u;
    --v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for (int i = 0; i < N; i++) {
    bfs(i);
  }
  int s1, s2, t1, t2, d1, d2;
  scanf("%d %d %d", &s1, &t1, &d1);
  scanf("%d %d %d", &s2, &t2, &d2);
  --s1;
  --t1;
  --s2;
  --t2;
  if (DP[s1][t1] == -1 || DP[s2][t2] == -1 || DP[s1][t1] > d1 ||
      DP[s2][t2] > d2) {
    puts("-1");
    return 0;
  }
  int min_cost = (DP[s1][t1] + DP[s2][t2]);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (DP[s1][i] + DP[i][j] + DP[j][t1] <= d1 &&
          DP[s2][i] + DP[i][j] + DP[j][t2] <= d2) {
        min_cost = min(
            min_cost, DP[s1][i] + DP[s2][i] + DP[i][j] + DP[j][t1] + DP[j][t2]);
      }
      swap(s1, t1);
      swap(s2, t2);
      if (DP[s1][i] + DP[i][j] + DP[j][t1] <= d1 &&
          DP[s2][i] + DP[i][j] + DP[j][t2] <= d2) {
        min_cost = min(
            min_cost, DP[s1][i] + DP[s2][i] + DP[i][j] + DP[j][t1] + DP[j][t2]);
      }
      swap(s2, t2);
      swap(s1, t1);
      swap(s1, t1);
      if (DP[s1][i] + DP[i][j] + DP[j][t1] <= d1 &&
          DP[s2][i] + DP[i][j] + DP[j][t2] <= d2) {
        min_cost = min(
            min_cost, DP[s1][i] + DP[s2][i] + DP[i][j] + DP[j][t1] + DP[j][t2]);
      }
      swap(s1, t1);
      swap(s2, t2);
      if (DP[s1][i] + DP[i][j] + DP[j][t1] <= d1 &&
          DP[s2][i] + DP[i][j] + DP[j][t2] <= d2) {
        min_cost = min(
            min_cost, DP[s1][i] + DP[s2][i] + DP[i][j] + DP[j][t1] + DP[j][t2]);
      }
    }
  }
  printf("%d", E - min_cost);
}
