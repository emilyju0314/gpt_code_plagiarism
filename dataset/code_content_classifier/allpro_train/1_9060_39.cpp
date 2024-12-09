#include <bits/stdc++.h>
using namespace std;
int m;
int a[200005], c[200005];
pair<int, int> b[200005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i].first;
    b[i].second = i;
  }
  sort(a, a + m);
  sort(b, b + m);
  for (int i = m - 1; i >= 0; i--) {
    c[b[m - 1 - i].second] = a[i];
  }
  for (int i = 0; i < m; i++) {
    cout << c[i] << " ";
  }
}
