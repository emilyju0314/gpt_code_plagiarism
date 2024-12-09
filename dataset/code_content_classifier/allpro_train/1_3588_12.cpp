#include <bits/stdc++.h>
using namespace std;
long long c[300100], l[300100], r[300100], acc[300100];
set<long long> gr[300100];
void dfs(long long v) {
  if (!gr[v].empty()) {
    long long e = *gr[v].begin();
    long long u = r[e] ^ l[e] ^ v;
    gr[v].erase(e);
    gr[u].erase(e);
    if (v < u) c[e] = 1;
    dfs(u);
  }
}
int main() {
  long long n;
  scanf("%I64d", &n);
  long long on = n;
  vector<long long> points;
  for (long long i = 0; i < n; i++) {
    scanf("%I64d %I64d", &l[i], &r[i]);
    points.push_back(l[i]);
    points.push_back(++r[i]);
  }
  sort(points.begin(), points.end());
  unique(points.begin(), points.end());
  for (long long i = 0; i < n; i++) {
    l[i] = lower_bound(points.begin(), points.end(), l[i]) - points.begin();
    r[i] = lower_bound(points.begin(), points.end(), r[i]) - points.begin();
    acc[l[i]]++;
    acc[r[i]]--;
  }
  for (long long i = 1; i < points.size(); i++) acc[i] += acc[i - 1];
  for (long long i = 0; i < points.size(); i++)
    if (acc[i] % 2) {
      l[n] = i;
      r[n] = i + 1;
      n++;
    }
  for (long long i = 0; i < n; i++) {
    gr[l[i]].insert(i);
    gr[r[i]].insert(i);
  }
  for (long long i = 0; i < points.size(); i++) dfs(i);
  for (long long i = 0; i < on; i++) printf("%I64d ", c[i]);
  return 0;
}
