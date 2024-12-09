#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
int n;
bool insort[N + 2], in[N + 2];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<int> v;
  int ans = 0, cur = 1;
  for (int i = 1, j = 1; i <= 2 * n; i++) {
    string s;
    cin >> s;
    if (s == "remove") {
      if (!v.empty()) {
        if (v.back() == j)
          v.pop_back();
        else {
          ans++;
          for (int k : v) insort[k] = 1;
          v.clear();
        }
      }
      j++;
    } else {
      int x;
      cin >> x;
      in[x] = 1;
      v.push_back(x);
    }
  }
  cout << ans << '\n';
  return 0;
}
