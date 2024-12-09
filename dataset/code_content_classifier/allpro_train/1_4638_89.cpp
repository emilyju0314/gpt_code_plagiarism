#include <bits/stdc++.h>
using namespace std;
signed long long N, A, B, C;
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> N >> A >> B >> C;
  if (N % 4 == 0) cout << 0 << endl;
  if (N % 4 == 1) cout << min(A * 3, min(C, A + B)) << endl;
  if (N % 4 == 3) cout << min(A, min(C * 3, C + B)) << endl;
  if (N % 4 == 2) cout << min(A * 2, min(B, C * 2)) << endl;
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
