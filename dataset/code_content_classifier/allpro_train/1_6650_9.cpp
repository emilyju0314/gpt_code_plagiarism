#include <bits/stdc++.h>

using namespace std;

const int md = 1000000007;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}

inline int mul(int a, int b) {
  return (long long) a * b % md;
}

const int N = 777;

int p[N];

int find_set(int x) {
  if (x != p[x]) {
    p[x] = find_set(p[x]);
  }
  return p[x];
}

void add_edge(int x, int y) {
  int xx = find_set(x);
  int yy = find_set(y);
  p[xx] = yy;
}

char s[N][N];
int sz[N];

int main() {
  int h, w;
  scanf("%d %d", &h, &w);
  for (int i = 0; i < h; i++) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < h / 2 + w / 2; i++) {
    p[i] = i;
  }
  int ans = 1;
  for (int i = 0; i < h - i - 1; i++) {
    for (int j = 0; j < w - j - 1; j++) {
      string z = "";
      z += s[i][j];
      z += s[h - i - 1][j];
      z += s[i][w - j - 1];
      z += s[h - i - 1][w - j - 1];
      sort(z.begin(), z.end());
      int cnt = 0;
      do {
        cnt++;
      } while (next_permutation(z.begin(), z.end()));
      if (cnt == 24) {
        ans = mul(ans, 12);
        add_edge(i, h / 2 + j);
      } else {
        ans = mul(ans, cnt);
      }
    }
  }
  if (h % 2 == 1) {
    string x = "";
    for (int j = 0; j < w; j++) {
      x += s[h / 2][j];
    }
    string y = x;
    reverse(y.begin(), y.end());
    if (x != y) {
      ans = mul(ans, 2);
    }
  }
  if (w % 2 == 1) {
    string x = "";
    for (int i = 0; i < h; i++) {
      x += s[i][w / 2];
    }
    string y = x;
    reverse(y.begin(), y.end());
    if (x != y) {
      ans = mul(ans, 2);
    }
  }
  for (int i = 0; i < h / 2 + w / 2; i++) {
    sz[i] = 0;
  }
  for (int i = 0; i < h / 2 + w / 2; i++) {
    sz[find_set(i)]++;
  }
  for (int i = 0; i < h / 2 + w / 2; i++) {
    if (sz[i] > 0) {
      for (int j = 0; j < sz[i] - 1; j++) {
        ans = mul(ans, 2);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
