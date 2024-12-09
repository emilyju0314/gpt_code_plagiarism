#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<int> go;
int n, a[N];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int now = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1 && i != n - 1)
      now++;
    else {
      if (i == n - 1 && a[i] == 1) now++;
      if (now != 0) go.push_back(now);
      now = 0;
    }
  }
  int ans = (go.size() == 0 ? 0 : go.size() - 1);
  for (int i = 0; i < go.size(); i++) {
    ans += go[i];
  }
  cout << ans;
}
