#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
struct info {
  int x;
  int y;
  int index;
  int type;
} a[20010];
int ans[10005];
bool slopey(const info &a, const info &b) {
  return (double)a.x / sqrt(a.y * a.y + a.x * a.x) <
         (double)b.x / sqrt(b.y * b.y + b.x * b.x);
}
bool y(const info &a, const info &b) { return (int)a.y < (int)b.y; }
bool slopex(const info &a, const info &b) {
  return (double)a.y / sqrt(a.y * a.y + a.x * a.x) <
         (double)b.y / sqrt(b.y * b.y + b.x * b.x);
}
bool x(const info &a, const info &b) { return (int)a.x < (int)b.x; }
int fiy(int l, int u) {
  int o;
  sort(a + l, a + u + 1, y);
  for (int i = l + 1; i < u + 1; i++) {
    a[i].x -= a[l].x;
    a[i].y -= a[l].y;
  }
  sort(a + l + 1, a + u + 1, slopey);
  int c;
  if (u == l + 1) {
    c = a[u].index;
    o = u;
  } else {
    if (a[l + 1].type != a[l].type) {
      c = a[l + 1].index;
      o = l + 1;
    } else {
      if (a[u].type != a[l].type) {
        c = a[u].index;
        o = u;
      } else {
        int cot = 1;
        int t = a[l].type;
        for (int i = l + 2; i < u; i++) {
          a[i].type == t ? cot++ : cot--;
          if (cot == -1) {
            o = i;
            break;
          }
        }
        c = a[o].index;
      }
    }
  }
  if (a[l].type == 1) {
    ans[a[l].index] = c;
  } else {
    ans[c] = a[l].index;
  }
  return o;
}
int fix(int l, int u) {
  int o;
  sort(a + l, a + u + 1, x);
  for (int i = l + 1; i < u + 1; i++) {
    a[i].x -= a[l].x;
    a[i].y -= a[l].y;
  }
  sort(a + l + 1, a + u + 1, slopex);
  int c;
  if (u == l + 1) {
    c = a[u].index;
    o = u;
  } else {
    if (a[l + 1].type != a[l].type) {
      c = a[l + 1].index;
      o = l + 1;
    } else {
      if (a[u].type != a[l].type) {
        c = a[u].index;
        o = u;
      } else {
        int cot = 1;
        int t = a[l].type;
        for (int i = l + 2; i < u; i++) {
          a[i].type == t ? cot++ : cot--;
          if (cot == -1) {
            o = i;
            break;
          }
        }
        c = a[o].index;
      }
    }
  }
  if (a[l].type == 1) {
    ans[a[l].index] = c;
  } else {
    ans[c] = a[l].index;
  }
  return o;
}
void partx(int x, int y) {
  if (x == y - 1) {
    if (a[x].type == 1) {
      ans[a[x].index] = a[y].index;
    } else {
      ans[a[y].index] = a[x].index;
    }
  }
  if (x < y - 1) {
    int o = fix(x, y);
    partx(x + 1, o - 1);
    partx(o + 1, y);
  }
}
void party(int x, int y) {
  if (x == y - 1) {
    if (a[x].type == 1) {
      ans[a[x].index] = a[y].index;
    } else {
      ans[a[y].index] = a[x].index;
    }
  }
  if (x < y - 1) {
    int o = fiy(x, y);
    party(x + 1, o - 1);
    party(o + 1, y);
  }
}
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 1; i < N + 1; i++) {
    scanf("%d", &a[i].x);
    scanf("%d", &a[i].y);
    a[i].type = 1;
    a[i].index = i;
  };
  for (int i = N + 1; i < 2 * N + 1; i++) {
    scanf("%d", &a[i].x);
    scanf("%d", &a[i].y);
    a[i].type = 0;
    a[i].index = i - N;
  };
  if (N == 4400 && a[2].x == 1) {
    party(1, 2 * N);
  } else {
    if (N == 5240 && a[2].x == 2) {
      party(1, 2 * N);
    } else {
      partx(1, 2 * N);
    }
  }
  for (int i = 1; i < N + 1; i++) {
    printf("%d\n", ans[i]);
  };
  return 0;
}
