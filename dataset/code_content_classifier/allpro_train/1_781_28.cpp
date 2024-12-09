#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char c = getchar();
  long long u = 0, f = 1;
  while (c != '-' && (c < '0' || '9' < c)) c = getchar();
  if (c == '-') {
    f = -1;
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    u = u * 10 + c - '0';
    c = getchar();
  }
  return u * f;
}
inline char readc() {
  for (;;) {
    char c = getchar();
    if ('A' <= c && c <= 'Z' || 'a' <= c && c <= 'z') return c;
  }
}
inline int read_digit() {
  for (;;) {
    char c = getchar();
    if ('0' <= c && c <= '9') return c - '0';
  }
}
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
template <typename T>
inline void updmax(T &a, T b) {
  if (b > a) a = b;
}
template <typename T>
inline void updmin(T &a, T b) {
  if (b < a) a = b;
}
inline void swap(int &a, int &b) {
  int t = a;
  a = b;
  b = t;
}
inline void fileio(string s) {
  if (s == "txt") {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  } else {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}
double pos[100010], cpos[100010], sum[100010];
vector<int> nspe[100010], spe[100010];
int s[100010], t[100010], ck[100010], w[100010];
int cnt[100010];
bool isspe[100010];
double ans = 1.0;
void update(int k, double p) {
  double p0 = pos[k], s0 = sum[k];
  pos[k] = p;
  if (!isspe[k]) {
    sum[k] = 0;
    for (auto u : spe[k]) sum[k] += pos[u];
    for (auto u : nspe[k]) sum[k] += pos[u];
  }
  ans += p0 * sum[k];
  ans -= p * sum[k];
  ans -= p0 * (w[k] - 1);
  ans += p * (w[k] - 1);
  for (auto u : spe[k]) sum[u] += p - p0;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lf", &pos[i]);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &s[i], &t[i]);
    s[i]++;
    t[i]++;
  }
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d%lf", &ck[i], &cpos[i]);
    ck[i]++;
  }
  int v = int(sqrt(n));
  for (int i = 1; i <= n; i++) cnt[ck[i]]++;
  for (int i = 1; i <= n; i++)
    if (cnt[i] >= v) isspe[i] = true;
  for (int i = 1; i < n; i++) {
    if (isspe[s[i]])
      spe[t[i]].push_back(s[i]);
    else
      spe[t[i]].push_back(s[i]);
    if (isspe[t[i]])
      spe[s[i]].push_back(t[i]);
    else
      nspe[s[i]].push_back(t[i]);
    ans -= pos[s[i]] * pos[t[i]];
    w[s[i]]++;
    w[t[i]]++;
    sum[s[i]] += pos[t[i]];
    sum[t[i]] += pos[s[i]];
  }
  for (int i = 1; i <= n; i++) ans += (w[i] - 1.0) * pos[i];
  for (int i = 1; i <= q; i++) {
    update(ck[i], cpos[i]);
    printf("%.8lf\n", ans);
  }
  return 0;
}
