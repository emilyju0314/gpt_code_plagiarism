#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
long long num[N], sum[N], a[N], nag[N];
set<int> s[N];
int main() {
  int n, i, j, k;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> num[i];
    a[i] = num[i];
    if (a[i] < 0) nag[i] = a[i];
  }
  sum[1] = num[1];
  for (i = 2; i <= n; i++) {
    sum[i] = sum[i - 1] + num[i];
    nag[i] += nag[i - 1];
  }
  long long res = LONG_LONG_MIN;
  sort(num + 1, num + n + 1);
  int idx = 1, x = -1, y = -1;
  map<long long, int> M;
  for (i = 1; i <= n; i++)
    if (!M[num[i]]) M[num[i]] = idx++;
  for (i = 1; i <= n; i++) s[M[a[i]]].insert(i);
  for (i = 1; i < idx; i++) {
    if (((int)(s[i]).size()) < 2) continue;
    int fir = *s[i].begin();
    int last = *s[i].rbegin();
    if (res < sum[last] - sum[fir - 1] + (-1LL * (nag[last - 1] - nag[fir]))) {
      res = sum[last] - sum[fir - 1] + (-1LL * (nag[last - 1] - nag[fir]));
      x = fir, y = last;
    }
  }
  vector<int> V;
  for (i = 1; i < x; i++) V.push_back(i);
  for (i = y + 1; i <= n; i++) V.push_back(i);
  for (i = x + 1; i < y; i++)
    if (a[i] < 0) V.push_back(i);
  cout << res << " " << ((int)(V).size()) << endl;
  for (__typeof((V).begin()) it = (V).begin(); it != (V).end(); it++)
    cout << *it << " ";
  cout << endl;
  return 0;
}
