#include <bits/stdc++.h>
using namespace std;
void sol() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  if (n * a != m * b) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  char S[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) S[i][j] = '0';
  int nr = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < a; j++) {
      S[i][nr] = '1';
      nr = (nr + 1) % m;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << S[i][j];
    cout << "\n";
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) sol();
  return 0;
}
