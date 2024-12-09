#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int n, m, k;
  cin >> n >> m >> k;
  multiset<int> ms;
  int b[n];
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  for (int i = 1; i < n; ++i) {
    ms.insert(b[i] - b[i - 1]);
  }
  int ans = n;
  int used = n;
  while (used > k) {
    used--;
    int st = *(ms.begin());
    ms.erase(ms.find(st));
    ans += (st - 1);
  }
  cout << ans << endl;
}
