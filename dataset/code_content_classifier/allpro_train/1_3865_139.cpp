#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e6 + 7;
const int Maxn = 2 + 7;
int child[maxn][Maxn], newv = 1, lg = 30, cnt[maxn];
void mk(int p) {
  int root = 0;
  cnt[0]++;
  for (int i = lg; i >= 0; i--) {
    int c = ((p >> i) & 1);
    if (child[root][c] == -1) {
      child[root][c] = newv++;
    }
    root = child[root][c];
    cnt[root]++;
  }
}
void rm(int p) {
  int root = 0;
  cnt[root]--;
  for (int i = lg; i >= 0; i--) {
    int c = ((p >> i) & 1);
    if (child[root][c] == -1) {
      return;
    }
    root = child[root][c];
    cnt[root]--;
  }
}
void rs(int p, int l) {
  int root = 0, ans = 0;
  for (int i = lg; i >= 0; i--) {
    int c = ((p >> i) & 1);
    int q = ((l >> i) & 1);
    if (q == 0) {
      if (child[root][c] == -1) {
        break;
      }
      root = child[root][c];
    } else {
      ans += cnt[child[root][c]];
      if (child[root][(!c)] == -1) {
        break;
      }
      root = child[root][(!c)];
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  memset(child, -1, sizeof child);
  int q;
  cin >> q;
  while (q--) {
    int k, p;
    cin >> k >> p;
    if (k == 1) {
      mk(p);
    } else if (k == 2) {
      rm(p);
    } else if (k == 3) {
      int l;
      cin >> l;
      rs(p, l);
    }
  }
}
