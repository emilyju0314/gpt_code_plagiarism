#include <bits/stdc++.h>
using namespace std;
const int N = 500100;
int i, j, n, m, k, a[N], used[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  string s;
  cin >> s;
  for (i = 0; i < n; i++) cin >> a[i];
  int i = 0;
  k = 0;
  used[0] = 1;
  while (!used[i] || k == 0) {
    used[i] = 1;
    k++;
    int t = a[i];
    if (s[i] == '<') t = -t;
    if (i + t >= n || i + t < 0) return cout << "FINITE", 0;
    i = i + t;
  }
  cout << "INFINITE";
  return 0;
}
