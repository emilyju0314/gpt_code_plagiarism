#include <bits/stdc++.h>
using namespace std;
int n, k, ans, inp, res;
vector<int> s;
void check(int x) {
  int temp = 0;
  for (int i = 0; i < n; i++) {
    if ((s[i] - s[x]) != k * (i - x)) {
      temp++;
    }
  }
  if (temp < ans) {
    ans = temp;
    res = x;
  }
}
bool valid(int x) {
  if (s[x] - x * k <= 0) return false;
  return true;
}
void solve() {
  int temp = 0;
  for (int i = 0; i < n; i++) {
    if ((s[i] - s[res]) != k * (i - res)) {
      if (s[i] < s[res] + k * (i - res))
        cout << "+ " << i + 1 << " " << s[res] + k * (i - res) - s[i] << "\n";
      else
        cout << "- " << i + 1 << " " << s[i] - (s[res] + k * (i - res)) << "\n";
    }
  }
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> inp;
    s.push_back(inp);
  }
  ans = n - 1;
  res = 0;
  for (int i = 1; i < n; i++) {
    if (valid(i)) check(i);
  }
  cout << ans << "\n";
  ;
  solve();
}
