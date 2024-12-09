#include <bits/stdc++.h>
using namespace std;
void addmod(int &a, long long b) {
  a = (a + b);
  if (a >= 1000000007) a -= 1000000007;
}
void mulmod(int &a, long long b) { a = (a * b) % 1000000007; }
int gi() {
  int a;
  scanf("%d", &a);
  return a;
}
long long gll() {
  long long a;
  scanf("%lld", &a);
  return a;
}
int ta[50007][32];
int tl[50007], n;
void pop(int cap, set<int> &v) {
  bool ok = true;
  for (int i = n - 1; i >= 0 && ok; i--) {
    ok = false;
    for (int j = 0; j < tl[i] && !ok; j++)
      if (ta[i][j] <= cap && v.find(ta[i][j]) == v.end()) {
        v.insert(ta[i][j]);
        ok = true;
      }
  }
}
int main() {
  int t;
  n = gi();
  set<int> v;
  vector<int> a(n);
  for (auto i = 0; i < n; i++) {
    a[i] = gi();
  }
  sort(a.begin(), a.end());
  for (int i = n - 1; i >= 0; i--) {
    t = a[i];
    int &xl = tl[i];
    while (t > 1) {
      ta[i][xl++] = t;
      if (t & 1)
        t = (t - 1) / 2;
      else
        t = t / 2;
    }
    ta[i][xl++] = t;
  }
  int lo = 0, hi = 1000000007, md;
  while (lo + 1 < hi) {
    md = (lo + hi) / 2;
    v.clear();
    pop(md, v);
    if (v.size() == n)
      hi = md;
    else
      lo = md;
  }
  v.clear();
  pop(hi, v);
  for (auto i : v) {
    printf("%d ", i);
  }
  cout << endl;
  return 0;
}
