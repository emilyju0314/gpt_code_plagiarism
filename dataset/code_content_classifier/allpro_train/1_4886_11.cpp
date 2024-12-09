#include <bits/stdc++.h>
using namespace std;
long long x, n, d;
vector<int> a, b;
long long getNextX() {
  x = (x * 37 + 10007) % 1000000007;
  return x;
}
void initAB() {
  int i;
  for (i = 0; i < n; i = i + 1) a[i] = i + 1;
  for (i = 0; i < n; i = i + 1) swap(a[i], a[getNextX() % (i + 1)]);
  for (i = 0; i < n; i = i + 1) b[i] = (i < d);
  for (i = 0; i < n; i = i + 1) swap(b[i], b[getNextX() % (i + 1)]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> d >> x;
  a.resize(n);
  b.resize(n);
  initAB();
  vector<int> c(n, 0);
  c[0] = a[0] * b[0];
  vector<int> sum(n, 0);
  sum[0] = b[0];
  for (int i = 1; i < n; ++i) sum[i] = sum[i - 1] + b[i];
  vector<int> ones;
  for (int i = 0; i < n; ++i)
    if (b[i]) ones.push_back(i);
  vector<int> v(n + 1, 0);
  for (int i = 0; i < n; ++i) v[a[i]] = i;
  for (int i = 1; i < n; ++i) {
    if (sum[i] == 0) {
      c[i] = 0;
      continue;
    }
    int ss = 50;
    bool isFind = 0;
    for (int j = n; j >= n - ss + 1; --j) {
      int ind = v[j];
      if (ind <= i && b[i - ind]) {
        c[i] = j;
        isFind = 1;
        break;
      }
    }
    if (isFind) continue;
    for (int j = 0; j < ones.size(); ++j)
      if (ones[j] <= i) c[i] = max(c[i], a[i - ones[j]]);
  }
  for (int i = 0; i < n; ++i) cout << c[i] << " ";
}
