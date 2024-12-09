#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long int myRand(long long int B) { return (unsigned long long)rng() % B; }
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  long long int res = 0;
  const int N = 450;
  vector<int> a(n);
  vector<vector<int>> v(N);
  for (int i = 0; i < n; i++) {
    a[i] = i;
    v[i / N].push_back(i);
  }
  auto debug = [](vector<int> v) -> void {
    for (int i : v) {
      printf("%d ", i);
    }
    printf("\n");
  };
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    if (x == y) {
      printf("%lld\n", res);
      continue;
    }
    if (x > y) swap(x, y);
    for (int j = y + 1; j < n; j++) {
      if (j / N != y / N) break;
      if (a[y] > a[j]) res--;
    }
    for (int j = y / N + 1; j <= (n - 1) / N; j++) {
      res -= lower_bound(v[j].begin(), v[j].end(), a[y]) - v[j].begin();
    }
    for (int j = y - 1; j >= 0; j--) {
      if (j / N != y / N) break;
      if (a[j] > a[y]) res--;
    }
    for (int j = y / N - 1; j >= 0; j--) {
      res -= v[j].end() - lower_bound(v[j].begin(), v[j].end(), a[y]);
    }
    for (int j = x + 1; j < n; j++) {
      if (j / N != x / N) break;
      if (a[x] > a[j]) res--;
    }
    for (int j = x / N + 1; j <= (n - 1) / N; j++) {
      res -= lower_bound(v[j].begin(), v[j].end(), a[x]) - v[j].begin();
    }
    for (int j = x - 1; j >= 0; j--) {
      if (j / N != x / N) break;
      if (a[j] > a[x]) res--;
    }
    for (int j = x / N - 1; j >= 0; j--) {
      res -= v[j].end() - lower_bound(v[j].begin(), v[j].end(), a[x]);
    }
    if (a[x] > a[y]) res++;
    int cp1 = a[x], cp2 = a[y];
    if (cp2 > cp1) res--;
    swap(a[x], a[y]);
    auto it = lower_bound(v[x / N].begin(), v[x / N].end(), cp1);
    v[x / N].erase(it);
    it = lower_bound(v[y / N].begin(), v[y / N].end(), cp2);
    v[y / N].erase(it);
    it = lower_bound(v[x / N].begin(), v[x / N].end(), cp2);
    v[x / N].insert(it, cp2);
    it = lower_bound(v[y / N].begin(), v[y / N].end(), cp1);
    v[y / N].insert(it, cp1);
    for (int j = y + 1; j < n; j++) {
      if (j / N != y / N) break;
      if (a[y] > a[j]) res++;
    }
    for (int j = y / N + 1; j <= (n - 1) / N; j++) {
      res += lower_bound(v[j].begin(), v[j].end(), a[y]) - v[j].begin();
    }
    for (int j = y - 1; j >= 0; j--) {
      if (j / N != y / N) break;
      if (a[j] > a[y]) res++;
    }
    for (int j = y / N - 1; j >= 0; j--) {
      res += v[j].end() - lower_bound(v[j].begin(), v[j].end(), a[y]);
    }
    for (int j = x + 1; j < n; j++) {
      if (j / N != x / N) break;
      if (a[x] > a[j]) res++;
    }
    for (int j = x / N + 1; j <= (n - 1) / N; j++) {
      res += lower_bound(v[j].begin(), v[j].end(), a[x]) - v[j].begin();
    }
    for (int j = x - 1; j >= 0; j--) {
      if (j / N != x / N) break;
      if (a[j] > a[x]) res++;
    }
    for (int j = x / N - 1; j >= 0; j--) {
      res += v[j].end() - lower_bound(v[j].begin(), v[j].end(), a[x]);
    }
    printf("%lld\n", res);
  }
}
