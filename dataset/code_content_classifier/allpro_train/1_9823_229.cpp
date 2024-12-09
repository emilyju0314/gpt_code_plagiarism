#include <bits/stdc++.h>
using namespace std;
long double pi = acos(-1);
long long QPow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}
int a1[100002];
int houzhui[100002];
int a2[100002];
signed main() {
  ifstream in("Text.txt");
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n, m;
  long long k;
  int a, b;
  int t;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> a1[i];
  for (int i = 0; i < m; i++) cin >> a2[i];
  sort(a1, a1 + n);
  sort(a2, a2 + m);
  int p1 = n - 1;
  int p2 = m - 1;
  while (p1 >= 0 && p2 >= 0 && a1[p1] <= a2[p2]) p1--, p2--;
  bool flag = 0;
  if (p1 == -1)
    flag = 0;
  else if (p2 == -1 || a1[p1] > a2[p2])
    flag = 1;
  if (flag)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
