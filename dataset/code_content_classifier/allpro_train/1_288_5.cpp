#include <bits/stdc++.h>
using namespace std;
const long long N = 1 << 21;
const long long big = 1e9 + 1;
const long long block = 800;
const long long mod = 1e6;
long long n, q;
long long a[N];
long long S[2][22];
void merge(long long l = 0, long long r = (1 << n) - 1, long long st = n) {
  if (l == r) return;
  long long m = (l + r) / 2;
  merge(l, m, st - 1);
  merge(m + 1, r, st - 1);
  long long ptr[2] = {l, m + 1};
  for (int i = m + 1; i <= r; i++) {
    while (ptr[0] <= m && a[ptr[0]] <= a[i]) ptr[0]++;
    S[0][st] += (m + 1) - ptr[0];
  }
  for (int i = l; i <= m; i++) {
    while (ptr[1] <= r && a[ptr[1]] <= a[i]) ptr[1]++;
    S[1][st] += r + 1 - ptr[1];
  }
  ptr[0] = l, ptr[1] = m + 1;
  vector<long long> z;
  for (int i = l; i <= r; i++) {
    if (ptr[0] > m)
      z.push_back(a[ptr[1]++]);
    else if (ptr[1] > r)
      z.push_back(a[ptr[0]++]);
    else
      z.push_back(a[ptr[0]] > a[ptr[1]] ? a[ptr[1]++] : a[ptr[0]++]);
  }
  for (int i = l; i <= r; i++) a[i] = z[i - l];
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < (1 << n); i++) cin >> a[i];
  merge();
  cin >> q;
  while (q--) {
    long long h = 0;
    cin >> h;
    for (int i = 0; i <= min(n, h); i++) swap(S[0][i], S[1][i]);
    long long sub = 0;
    for (int i = 0; i < 21; i++) sub += S[0][i];
    cout << sub << '\n';
  }
}
