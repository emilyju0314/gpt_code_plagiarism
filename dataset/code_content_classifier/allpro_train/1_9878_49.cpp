#include <bits/stdc++.h>
using namespace std;
long long wy[1000010][2];
bool tab[1000010];
struct moj {
  long long gdzie;
  char co;
  long long a, b;
  long long ojciec;
  bool policz() {
    if (co == 'I')
      return tab[gdzie];
    else if (co == 'A')
      return tab[a] & tab[b];
    else if (co == 'O')
      return tab[a] | tab[b];
    else if (co == 'X')
      return tab[a] ^ tab[b];
    else
      return !tab[a];
  }
} v[1000010];
void dfs(long long gdzie = 1, long long skad = 1) {
  if (gdzie == -1) return;
  v[gdzie].ojciec = skad;
  if (v[gdzie].co == 'I') return;
  dfs(v[gdzie].a, gdzie);
  dfs(v[gdzie].b, gdzie);
  tab[gdzie] = v[gdzie].policz();
}
void algo(long long gdzie = 1) {
  if (gdzie == -1) return;
  if (gdzie != 1) {
    wy[gdzie][tab[gdzie]] = tab[1];
    tab[gdzie] ^= 1;
    bool a = v[v[gdzie].ojciec].policz();
    wy[gdzie][tab[gdzie]] = wy[v[gdzie].ojciec][a];
    tab[gdzie] ^= 1;
  } else {
    wy[gdzie][0] = 0;
    wy[gdzie][1] = 1;
  }
  if (v[gdzie].co == 'I') return;
  algo(v[gdzie].a);
  algo(v[gdzie].b);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  string s;
  for (long long a, b, i = 1; i <= n; i++) {
    cin >> s >> a;
    if (s[0] == 'A' || s[0] == 'O' || s[0] == 'X')
      cin >> b;
    else
      b = -1;
    if (s[0] == 'I') {
      tab[i] = a;
      a = i;
    }
    v[i] = {i, s[0], a, b, 0};
  }
  dfs();
  algo();
  for (long long i = 1; i <= n; i++) {
    if (v[i].co == 'I') {
      cout << wy[i][tab[i] ^ 1];
    }
  }
  return 0;
}
