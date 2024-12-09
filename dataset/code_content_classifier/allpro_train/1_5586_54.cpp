#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.14159265359;
template <typename T>
T abs(T x) {
  return x > 0 ? x : -x;
}
template <typename T>
T sqr(T x) {
  return x * x;
}
const int maxn = 1000005;
struct nd {
  nd *nxt[26];
  vector<int> was[2];
  nd() { fill(nxt, nxt + 26, nullptr); }
};
nd *root = new nd();
void add(const string &x, int idx, int tp) {
  nd *v = root;
  for (char c : x) {
    c -= 'a';
    if (v->nxt[c] == nullptr) {
      v->nxt[c] = new nd();
    }
    v->was[tp].push_back(idx);
    v = v->nxt[c];
  }
  v->was[tp].push_back(idx);
}
char tmp[maxn];
int used[2][maxn];
int ans[maxn];
int sum;
void dfs(nd *v, int d) {
  for (int i = 0; i < 26; i++) {
    if (v->nxt[i]) {
      dfs(v->nxt[i], d + 1);
    }
  }
  int p = 0;
  for (int x : v->was[0]) {
    if (used[0][x]) {
      continue;
    }
    while (p < v->was[1].size() && used[1][v->was[1][p]]) {
      p++;
    }
    if (p < v->was[1].size()) {
      sum += d;
      ans[x] = v->was[1][p];
      used[0][x] = 1;
      used[1][v->was[1][p]] = 1;
    }
  }
}
int main() {
  srand(time(NULL));
  int n;
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s\n", tmp);
    add(tmp, i + 1, 0);
  }
  for (int i = 0; i < n; i++) {
    scanf("%s\n", tmp);
    add(tmp, i + 1, 1);
  }
  dfs(root, 0);
  printf("%d\n", sum);
  for (int i = 1; i <= n; i++) {
    printf("%d %d\n", i, ans[i]);
  }
  return 0;
}
