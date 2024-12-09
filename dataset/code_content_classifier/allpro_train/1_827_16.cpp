#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-2;
const int N = 1e5 + 50;
const double PI = acos(-1.);
const double E = 2.71828182845904523536;
const int MOD = 1e9 + 7;
char s[N];
int main() {
  int n;
  cin >> n >> s;
  int a = 0, b = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'r' && i % 2 == 0) a++;
    if (s[i] == 'b' && i % 2 == 1) b++;
  }
  int ans = min(a, b) + max(a, b) - min(a, b);
  a = 0, b = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'r' && i % 2 == 1) a++;
    if (s[i] == 'b' && i % 2 == 0) b++;
  }
  ans = min(min(a, b) + max(a, b) - min(a, b), ans);
  cout << ans << endl;
  return 0;
}
