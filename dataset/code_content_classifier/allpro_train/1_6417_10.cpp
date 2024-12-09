#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string mat[1010];
  int vet[1010];
  for (int i = 0; i < n; i++) {
    cin >> mat[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> vet[i];
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int resp = 0;
    for (int k = 'A'; k <= 'E'; k++) {
      int answ = 0;
      for (int j = 0; j < n; j++) {
        if (mat[j][i] == k) answ += vet[i];
      }
      resp = max(resp, answ);
    }
    ans += resp;
  }
  cout << ans << endl;
}
