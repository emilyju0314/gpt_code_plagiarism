#include <bits/stdc++.h>
using namespace std;
struct ass {
  int t;
  string v;
  char op;
  int var1, var2;
};
const int MAXN = 5e3 + 3;
int n, m;
map<string, int> ID;
ass a[MAXN];
bool val[MAXN];
int calc(int p, int v) {
  memset(val, 0, sizeof(val));
  for (int i = 0; i < (int)n; i++) {
    if (a[i].t == 0) {
      val[i] = a[i].v[p] - '0';
    } else {
      int v1, v2;
      if (a[i].var1 == -1)
        v1 = v;
      else
        v1 = val[a[i].var1];
      if (a[i].var2 == -1)
        v2 = v;
      else
        v2 = val[a[i].var2];
      if (a[i].op == '&') val[i] = v1 & v2;
      if (a[i].op == '^') val[i] = v1 ^ v2;
      if (a[i].op == '|') val[i] = v1 | v2;
    }
  }
  int ret = 0;
  for (int i = 0; i < (int)n; i++) ret += val[i];
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  ID["?"] = -1;
  string var, tmp, opn1, opn2, op;
  for (int i = 0; i < (int)n; i++) {
    cin >> var >> tmp;
    ID[var] = i;
    cin >> opn1;
    if (opn1[0] == '0' || opn1[0] == '1') {
      a[i] = {0, opn1, ' ', 0, 0};
    } else {
      cin >> op >> opn2;
      char cop;
      if (op[0] == 'A') cop = '&';
      if (op[0] == 'O') cop = '|';
      if (op[0] == 'X') cop = '^';
      a[i] = {1, "", cop, ID[opn1], ID[opn2]};
    }
  }
  string ans1, ans2;
  ans1.resize(m);
  ans2.resize(m);
  for (int i = 0; i < (int)m; i++) {
    int v0 = calc(i, 0), v1 = calc(i, 1);
    if (v0 <= v1) {
      ans1[i] = '0';
    } else {
      ans1[i] = '1';
    }
    if (v0 >= v1) {
      ans2[i] = '0';
    } else {
      ans2[i] = '1';
    }
  }
  cout << ans1 << endl << ans2 << endl;
}
