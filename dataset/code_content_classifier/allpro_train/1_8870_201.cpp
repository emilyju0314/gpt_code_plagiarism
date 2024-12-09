#include <bits/stdc++.h>
const int N = 303;
using namespace std;
int a[N][N];
bool can[N][N];
int p[N], ans[N];
bool was[N];
int n;
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = (1); i <= (n); i++) cin >> p[i];
  char ch;
  for (int i = (1); i <= (n); i++) a[i][i] = 1;
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++) {
      cin >> ch;
      if (ch == '1') a[i][j] = a[j][i] = 1;
    }
  for (int k = (1); k <= (n); k++)
    for (int i = (1); i <= (n); i++)
      for (int j = (1); j <= (n); j++)
        if (a[i][k] && a[k][j]) a[i][j] = 1;
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++)
      if (a[i][j]) can[j][p[i]] = 1;
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++)
      if (!was[j] && can[i][j]) {
        ans[i] = j, was[j] = 1;
        break;
      }
  for (int i = (1); i <= (n); i++) cout << ans[i] << ' ';
  return 0;
}
