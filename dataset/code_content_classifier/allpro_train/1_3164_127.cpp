#include <bits/stdc++.h>
using namespace std;
const int Maxn = 10005;
const long long Inf = 1000000000000000000ll;
int n, m, L, s, t;
int a[Maxn], b[Maxn];
long long w[Maxn];
bool mod[Maxn];
vector<pair<int, int> > neigh[Maxn];
long long dist[Maxn], dist2[Maxn];
void Solve1() {
  fill(dist, dist + n + 1, Inf);
  dist[t] = 0;
  priority_queue<pair<long long, int> > Q;
  Q.push(pair<long long, int>(-dist[t], t));
  while (!Q.empty()) {
    int v = Q.top().second;
    long long d = -Q.top().first;
    Q.pop();
    if (d != dist[v]) continue;
    for (int i = 0; i < neigh[v].size(); i++) {
      pair<int, int> u = neigh[v][i];
      if (d + w[u.second] < dist[u.first]) {
        dist[u.first] = d + w[u.second];
        Q.push(pair<int, int>(-dist[u.first], u.first));
      }
    }
  }
}
void Solve2() {
  fill(dist2, dist2 + n + 1, Inf);
  dist2[s] = 0;
  priority_queue<pair<long long, int> > Q;
  Q.push(pair<long long, int>(-dist2[s], s));
  while (!Q.empty()) {
    int v = Q.top().second;
    long long d = -Q.top().first;
    Q.pop();
    if (d != dist2[v]) continue;
    for (int i = 0; i < neigh[v].size(); i++) {
      pair<int, int> u = neigh[v][i];
      if (d + w[u.second] < dist2[u.first] &&
          d + w[u.second] + dist[u.first] < L)
        if (mod[u.second])
          w[u.second] += L - (d + w[u.second] + dist[u.first]);
        else {
          dist2[u.first] = d + w[u.second];
          Q.push(pair<int, int>(-dist2[u.first], u.first));
        }
    }
  }
}
int main() {
  scanf("%d %d %d %d %d", &n, &m, &L, &s, &t);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %I64d", &a[i], &b[i], &w[i]);
    if (w[i] == 0) {
      w[i] = 1;
      mod[i] = true;
    }
    neigh[a[i]].push_back(pair<int, int>(b[i], i));
    neigh[b[i]].push_back(pair<int, int>(a[i], i));
  }
  Solve1();
  if (dist[s] > L) {
    printf("NO\n");
    return 0;
  }
  Solve2();
  if (dist2[t] >= Inf) {
    printf("YES\n");
    for (int i = 0; i < m; i++) printf("%d %d %I64d\n", a[i], b[i], w[i]);
  } else
    printf("NO\n");
  return 0;
}
