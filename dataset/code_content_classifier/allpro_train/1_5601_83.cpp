#include <bits/stdc++.h>
using namespace std;
istream& in = cin;
int n;
void input() { in >> n; }
int ans[100010];
int get_mask(int n) {
  int mask = 0;
  while (n) {
    mask = mask * 2 + 1;
    n /= 2;
  }
  return mask + 1;
}
unsigned int hb(unsigned int p) {
  for (int i = 30; i >= 0; --i) {
    if ((unsigned int)1 << i & p) return (unsigned int)1 << i;
  }
}
bool cale_First() {
  if (n % 2 == 1) {
    return 0;
  }
  int mask = get_mask(n);
  unsigned int pos = n;
  unsigned int MMAX = n;
  while (pos >= 1) {
    unsigned int v = (~pos) % mask;
    while (v > MMAX) v -= hb(v);
    unsigned int T = v;
    while (pos >= 1 && v <= MMAX) {
      ans[pos--] = v++;
    }
    MMAX = T - 1;
  }
  return 1;
}
vector<int> v[1000];
bool vis[1000];
int aim;
bool dfs(int pos) {
  if (pos == 0) return 1;
  if (ans[pos] != -1) {
    if (dfs(pos - 1)) return 1;
  } else {
    for (int son : v[pos]) {
      if (vis[son]) continue;
      vis[son] = 1;
      ans[pos] = son;
      if (dfs(pos - 1)) return 1;
      vis[son] = 0;
      ans[pos] = -1;
    }
  }
  return 0;
}
void test(int n) {
  for (int i = 1; i <= n; ++i) v[i].clear();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      if (i != j && ((i & j) != 0)) {
        v[i].push_back(j);
      }
    }
  for (int i = 1; i <= n; ++i) sort(v[i].begin(), v[i].end(), greater<int>());
  memset(ans, -1, sizeof(ans));
  memset(vis, 0, sizeof(vis));
  aim = n;
  if (dfs(n)) {
    cout << "YES  " << aim << endl;
    for (int i = 1; i <= n; ++i) printf("%2d ", ans[i]);
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
}
unsigned int S[200010];
int main() {
  int TEST_CASE = 1;
  while (TEST_CASE-- > 0) {
    input();
    if (cale_First()) {
      cout << "YES" << endl;
      for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
      cout << endl;
    } else {
      cout << "NO" << endl;
    }
    if (n < 6 || n - hb(n) == 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      if (n % 2 == 0) {
        S[1] = 3;
        S[2] = 6;
        S[3] = 2;
        S[4] = 5;
        S[5] = 1;
        S[6] = 4;
        bool mark = 0;
        for (int i = 8; i < 110000; i += 2) {
          if (i - hb(i) != 0) {
            if (mark == 0) {
              S[i] = i - 1;
              S[i - 1] = i;
            } else {
              S[i - 2] = i;
              S[i - 3] = i - 1;
            }
            mark = 0;
          } else {
            S[i + 1] = i - 1;
            S[i + 2] = i;
            mark = 1;
          }
        }
      } else {
        S[1] = 5;
        S[2] = 3;
        S[3] = 2;
        S[4] = 7;
        S[5] = 1;
        S[6] = 4;
        S[7] = 6;
        for (int i = 8; i <= n; ++i) {
          if (i % 2 == 0) {
            S[i] = i + 1;
          } else {
            S[i] = i - 1;
          }
        }
      }
      for (int i = 1; i <= n; ++i) cout << S[i] << " ";
      cout << endl;
    }
  }
  return 0;
}
