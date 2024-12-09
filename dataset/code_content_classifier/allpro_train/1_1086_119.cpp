#include <bits/stdc++.h>
using namespace std;
const int N = 200032;
int n, m, p[N];
pair<long long, int> z[N];
long long x[N];
int cal(int i, int l, bool dir) {
  if (dir == 0) {
    int j = upper_bound(x + 1, x + n + 1, x[i] + l) - x - 1;
    int k = lower_bound(x + 1, x + n + 1, x[i] - (l - (x[j] - x[i]))) - x;
    if (k != i)
      return cal(j, l - (x[j] - x[i]), 1);
    else {
      if (j == k) return i;
      int num = l / (x[j] - x[i]);
      if (num % 2) return cal(j, l % (x[j] - x[i]), 1);
      return cal(i, l % (x[j] - x[i]), 0);
    }
  } else {
    int j = lower_bound(x + 1, x + n + 1, x[i] - l) - x;
    int k = upper_bound(x + 1, x + n + 1, x[i] - (l - (x[j] - x[i]))) - x - 1;
    if (k != i)
      return cal(j, l - (x[i] - x[j]), 0);
    else {
      if (j == k) return i;
      int num = l / (x[i] - x[j]);
      if (num % 2) return cal(j, l % (x[i] - x[j]), 0);
      return cal(i, l % (x[i] - x[j]), 1);
    }
  }
}
int main() {
  ios ::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = (1); i <= (n); i++) {
    cin >> z[i].first;
    z[i].second = i;
  }
  z[n + 1].first = -(1LL << 34);
  z[n + 2].first = (1LL << 34);
  n += 2;
  sort(z + 1, z + n + 1);
  for (int i = (1); i <= (n); i++) x[i] = z[i].first;
  for (int i = (1); i <= (n); i++) p[z[i].second] = i;
  while (m--) {
    int i, l;
    cin >> i >> l;
    cout << z[cal(p[i], l, 0)].second << "\n";
  }
  return 0;
}
