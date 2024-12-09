#include <bits/stdc++.h>
using namespace std;
long long a[111111];
long long b[111111];
long long s[222222];
long long ps[222222];
set<long long> se;
map<long long, long long> kol;
set<int> res;
int n;
void add(long long x) {
  kol[x]++;
  se.insert(x);
}
void del(long long x) {
  kol[x]--;
  if (kol[x] <= 0) se.erase(x);
}
void check(int ax) {
  ps[0] = 0;
  se.clear();
  kol.clear();
  for (int i = 1; i <= n + n; i++) ps[i] = ps[i - 1] + s[i];
  for (int i = 1; i <= n; i++) {
    add(ps[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (ps[i - 1] <= *se.begin()) res.insert(ax ? n - i + 1 : i);
    del(ps[i]);
    add(ps[i + n]);
  }
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) s[i + 1] = a[i] - b[i];
  for (int i = 0; i < n; i++) s[i + n + 1] = s[i + 1];
  check(0);
  for (int i = 0; i < n; i++) s[i + 1] = a[i] - b[(i - 1 + n) % n];
  for (int i = 1; i <= n >> 1; i++) swap(s[i], s[n - i + 1]);
  for (int i = 0; i < n; i++) s[i + 1 + n] = s[i + 1];
  check(1);
  cout << res.size() << endl;
  while (res.size() > 0) {
    cout << *res.begin() << " ";
    res.erase(*res.begin());
  }
  return 0;
}
