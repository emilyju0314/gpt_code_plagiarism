#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
int dix[] = {1, -1, 0, 0, 1, 1, -1, -1};
int diy[] = {0, 0, 1, -1, 1, -1, 1, -1};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  vector<int> v(n);
  int res = 0;
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 1; i < n - 1; i++)
    if (v[i] > v[i - 1] && v[i] > v[i + 1]) res++;
  for (int i = 1; i < n - 1; i++)
    if (v[i] < v[i - 1] && v[i] < v[i + 1]) res++;
  cout << res << '\n';
  return 0;
  ;
}
