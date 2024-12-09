#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long ull;
int n, k;
int longest[2 * 100010];
string s;
int q;
const string t = "RGB";
void solve() {
  cin >> n >> k >> s;
  int mini = 1e8;
  for (int shift = 0; shift < 3; ++shift) {
    int diff[n];
    int curr = 0;
    for (int i = 0; i < n; ++i) {
      s[i] == t[(i + shift) % 3] ? diff[i] = 0 : diff[i] = 1;
      curr += diff[i];
      if (i >= k) curr -= diff[i - k];
      if (i >= k - 1) mini = min(curr, mini);
    }
  }
  cout << mini << '\n';
}
int main() {
  cin >> q;
  cout << '\n';
  for (int i = 0; i < q; ++i) {
    solve();
  }
  return 0;
}
