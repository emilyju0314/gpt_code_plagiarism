#include <bits/stdc++.h>
using namespace std;
string s[300005], sol, b[300005], ans[300005];
int n, m, mini;
bool p;
bitset<300005> taj;
const int inf = 1e9;
void check(string t, bool f) {
  int br = 0;
  bitset<300005> sad;
  for (int i = 0; i < n; ++i) {
    int br1 = 0, br2 = 0;
    for (int j = 0; j < m; ++j) {
      br1 += (s[i][j] != t[((i & 1) * 2) + (j & 1)]);
      br2 += (s[i][j] != t[((i & 1) * 2) + ((j & 1) ^ 1)]);
    }
    if (br2 < br1) {
      sad[i] = 1;
    }
    br += min(br1, br2);
  }
  if (br < mini) {
    mini = br;
    sol = t;
    p = f;
    taj = sad;
  }
}
void solvepart(bool f) {
  string a = "ACGT";
  do {
    check(a, f);
  } while (next_permutation(a.begin(), a.end()));
}
void rotatematrix(string (&a)[300005]) {
  for (int i = 0; i < m; ++i) {
    b[i].clear();
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      b[i] += a[j][i];
    }
  }
  swap(n, m);
  for (int i = 0; i < n; ++i) {
    a[i] = b[i];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  mini = inf;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  solvepart(0);
  rotatematrix(s);
  solvepart(1);
  if (!p) {
    swap(n, m);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ans[i] += sol[((i & 1) * 2) + ((j & 1) ^ taj[i])];
    }
  }
  if (p) {
    rotatematrix(ans);
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << endl;
  }
  return 0;
}
