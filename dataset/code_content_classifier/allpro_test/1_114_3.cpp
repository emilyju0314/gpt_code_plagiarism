#include <bits/stdc++.h>
using namespace std;
int a[200005] = {0};
void solve() {
  int n;
  scanf("%d", &n);
  map<int, bool> cnt;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]] = 1;
  }
  sort(a, a + n);
  int num = n / 2;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (!num) return;
      if (cnt[a[j] % a[i]] != 1) {
        cout << a[j] << ' ' << a[i] << endl;
        num--;
      }
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
