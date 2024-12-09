#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:60000000")
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
double const pi = 3.1415926535897932384626433832795;
int const inf = (int)1e9;
long long const inf64 = (long long)4e18;
const string name = "c";
const int NMAX = 7010;
long long ans;
int n, m1, m2, cnt;
int idx[NMAX], num1[NMAX], num2[NMAX];
pair<int, char> PREV[NMAX];
int nxt[NMAX][30];
pair<int, int> save[NMAX];
int main() {
  cin >> n;
  memset(num1, 0, sizeof(num1));
  idx[0] = 0;
  num1[0] = 1;
  memset(num2, 0, sizeof(num2));
  num2[0] = 1;
  memset(nxt, 255, sizeof(nxt));
  m1 = 1, m2 = 1, cnt = 1;
  PREV[0] = make_pair(-1, -1);
  for (int i = 0; i < (int)n; i++) {
    int op, x;
    char c, buf[4];
    scanf("%d%d%s", &op, &x, buf);
    c = buf[0];
    x--;
    if (op == 2) {
      PREV[m2] = make_pair(x, c);
      int now2 = m2++, now1 = 0;
      while (now1 >= 0 && now2 >= 0) {
        num2[now1]++;
        if (nxt[now1][PREV[now2].second - 'a'] == -1) break;
        now1 = nxt[now1][PREV[now2].second - 'a'];
        now2 = PREV[now2].first;
      }
      save[m2 - 1] = make_pair(now1, now2);
    } else {
      int now1 = idx[x];
      if (nxt[now1][c - 'a'] == -1) {
        nxt[now1][c - 'a'] = cnt++;
        for (int j = 0; j < (int)m2; j++)
          if (save[j].first == now1 && PREV[save[j].second].second == c) {
            num2[cnt - 1]++;
            save[j] = make_pair(cnt - 1, PREV[save[j].second].first);
          }
      }
      num1[nxt[now1][c - 'a']]++;
      idx[m1++] = nxt[now1][c - 'a'];
    }
    ans = 0;
    for (int i = 0; i < (int)cnt; i++) ans += num1[i] * num2[i];
    printf("%d\n", ans);
  }
  return 0;
}
