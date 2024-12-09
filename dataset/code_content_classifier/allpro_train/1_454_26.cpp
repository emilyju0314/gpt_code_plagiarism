#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
void OFAST() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
}
short n, k;
pair<short, short> a[55];
int main() {
  OFAST();
  cin >> n >> k;
  for (int i = (1), _b = (n); i <= _b; ++i)
    cin >> a[i].first >> a[i].second, a[i].second *= -1;
  sort(a + 1, a + 1 + n, greater<pair<short, short> >());
  for (short i = 1, j; i <= n; ++i) {
    j = i;
    while (j + 1 <= n && a[j + 1] == a[i]) ++j;
    if (i <= k && k <= j) {
      cout << j - i + 1;
      return 0;
    }
    i = j;
  }
}
