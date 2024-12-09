#include <bits/stdc++.h>
using namespace std;
int n, m;
char pieza[2] = {'B', 'W'};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  char aux;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> aux;
      if (aux == '.') {
        cout << pieza[(i + j) % 2];
      } else {
        cout << aux;
      }
    }
    cout << "\n";
  }
  return 0;
}
