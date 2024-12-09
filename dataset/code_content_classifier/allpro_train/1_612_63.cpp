#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int Read() {
  char c;
  c = getchar();
  int tsqua = 0;
  while (c != ' ' && c != '\n') {
    tsqua = (((tsqua << 1) << 1) << 1) + (tsqua << 1) + (int)(c - '0');
    c = getchar();
  }
  return tsqua;
}
int q;
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    int s[222] = {0};
    for (int i = 0; i < n; i++) cin >> s[i];
    bool ok1 = 1, ok2 = 1;
    for (int i = 1; i < n; i++)
      ok1 &= (s[i] == s[i - 1] + 1 || (s[i] == 1 && s[i - 1] == n));
    ok1 &= (s[0] == s[n - 1] + 1 || (s[0] == 1 && s[n - 1] == n));
    if (ok1) {
      cout << "YES" << endl;
      continue;
    }
    for (int i = 0; i < n - 1; i++)
      ok2 &= (s[i] == s[i + 1] + 1 || (s[i] == 1 && s[i + 1] == n));
    ok2 &= (s[n - 1] == s[0] + 1 || (s[n - 1] == 1 && s[0] == n));
    if (ok2) {
      cout << "YES" << endl;
      continue;
    }
    cout << "NO" << endl;
  }
  return 0;
}
