#include <bits/stdc++.h>
using namespace std;
const unsigned long long MOD = 257;
int n, m;
string s[5005];
int L[5005], R[5005], U[5005], D[5005];
void init() {
  int b, pos;
  for (int i = 0; i < n; i++) {
    b = -1;
    for (int j = 0; j < m; j++) {
      if (s[i][j] != '.') {
        pos = i * m + j;
        L[pos] = b;
        if (b != -1) R[b] = pos;
        b = pos;
      }
    }
    R[b] = -1;
  }
  for (int i = 0; i < m; i++) {
    b = -1;
    for (int j = 0; j < n; j++) {
      if (s[j][i] != '.') {
        pos = j * m + i;
        U[pos] = b;
        if (b != -1) {
          D[b] = pos;
        }
        b = pos;
      }
    }
    D[b] = -1;
  }
}
int dfs(int now) {
  int x = now / m, y = now % m;
  if (L[now] != -1) R[L[now]] = R[now];
  if (R[now] != -1) L[R[now]] = L[now];
  if (U[now] != -1) D[U[now]] = D[now];
  if (D[now] != -1) U[D[now]] = U[now];
  int go;
  if (s[x][y] == 'U')
    go = U[now];
  else if (s[x][y] == 'D')
    go = D[now];
  else if (s[x][y] == 'L')
    go = L[now];
  else if (s[x][y] == 'R')
    go = R[now];
  if (go == -1) return 1;
  return dfs(go) + 1;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int ans = 0, num = 0, tmp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] != '.') {
        init();
        tmp = dfs(i * m + j);
        if (tmp == ans)
          num++;
        else if (tmp > ans) {
          ans = tmp;
          num = 1;
        }
      }
    }
  }
  cout << ans << " " << num << endl;
}
