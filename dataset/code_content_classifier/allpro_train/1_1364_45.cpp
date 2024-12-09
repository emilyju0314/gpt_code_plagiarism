#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 310000;
char st[N];
int pos[N];
long long ans;
int cnt;
int main() {
  ios ::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    string tmp;
    cin >> pos[i] >> tmp;
    st[i] = tmp[0];
  }
  for (int r = 1, l = 0; r <= n; ++r)
    if (st[r] == 'P') {
      if (l) {
        int v1 = 0, v2 = 0;
        for (int p = l, q = l; p <= r; ++p)
          if (st[p] != 'R') v1 = max(v1, pos[p] - pos[q]), q = p;
        for (int p = l, q = l; p <= r; ++p)
          if (st[p] != 'B') v2 = max(v2, pos[p] - pos[q]), q = p;
        ans += min((pos[r] - pos[l]) * 2ll, (pos[r] - pos[l]) * 3ll - v1 - v2);
      }
      l = r;
      cnt++;
    }
  for (int i = 1; i <= n; ++i)
    if (st[i] == 'P') {
      for (int j = 1; j <= i; ++j)
        if (st[j] == 'R') {
          ans += pos[i] - pos[j];
          break;
        }
      for (int j = 1; j <= i; ++j)
        if (st[j] == 'B') {
          ans += pos[i] - pos[j];
          break;
        }
      break;
    }
  for (int i = n; i >= 1; --i)
    if (st[i] == 'P') {
      for (int j = n; j >= i; --j)
        if (st[j] == 'R') {
          ans += pos[j] - pos[i];
          break;
        }
      for (int j = n; j >= i; --j)
        if (st[j] == 'B') {
          ans += pos[j] - pos[i];
          break;
        }
      break;
    }
  if (cnt == 0) {
    int l = 0, r = 0;
    for (int i = 1; i <= n; ++i)
      if (st[i] == 'R') r = i;
    for (int i = n; i >= 1; --i)
      if (st[i] == 'R') l = i;
    ans += pos[r] - pos[l];
    l = r = 0;
    for (int i = 1; i <= n; ++i)
      if (st[i] == 'B') r = i;
    for (int i = n; i >= 1; --i)
      if (st[i] == 'B') l = i;
    ans += pos[r] - pos[l];
  }
  cout << ans << endl;
}
