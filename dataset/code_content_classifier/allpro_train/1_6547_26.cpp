#include <bits/stdc++.h>
using namespace std;
int N, M, Q;
string S[505], T;
int mo = 5;
int mat[500][800];
int rev(int a) {
  int revt[] = {0, 1, 3, 2, 4};
  return revt[a];
}
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> N >> M;
  for (y = 0; y < (N); y++) {
    cin >> S[y];
    for (x = 0; x < (M); x++) mat[x][y] = S[y][x] - 'a';
  }
  cin >> Q;
  for (i = 0; i < (Q); i++) {
    cin >> T;
    for (x = 0; x < (M); x++) mat[x][N + i] = T[x] - 'a';
  }
  signed long long pat = 1;
  int step = 0, ret = 0;
  for (step = 0; step < (N); step++) {
    for (y = ret; y < M; y++)
      if (mat[y][step]) break;
    if (y == M) {
      pat = pat * 5 % 1000000007;
      continue;
    }
    for (x = step; x < N + Q; x++) swap(mat[ret][x], mat[y][x]);
    int re = rev(mat[ret][step]);
    for (x = step; x < N + Q; x++) mat[ret][x] = mat[ret][x] * re % mo;
    for (y = 0; y < (M); y++)
      if (y != ret && mat[y][step]) {
        re = mat[y][step];
        for (x = step; x < N + Q; x++)
          mat[y][x] = ((mat[y][x] - re * mat[ret][x]) % mo + mo) % mo;
      }
    ret++;
  }
  for (i = 0; i < (Q); i++) {
    for (x = ret; x < M; x++)
      if (mat[x][N + i]) break;
    if (x == M)
      cout << pat << endl;
    else
      cout << 0 << endl;
  }
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  solve();
  return 0;
}
