#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cout << i + 2 << " ";
  }
  cout << endl;
}
int main() {
  fast();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
