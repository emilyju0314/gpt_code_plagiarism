#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10, inf = 0x3f3f3f3f;
int n;
namespace IO {
int read() {
  int ret = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) ret = ret * 10 + (c ^ 48), c = getchar();
  return ret;
}
void write(int x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 ^ 48);
}
void writeln(int x) {
  write(x);
  putchar('\n');
}
}  // namespace IO
using namespace IO;
namespace Data_Structure {
struct Tway {
  int u, v;
} e[N];
struct data {
  int val, id;
  data(int _v = 0, int _i = 0) : val(_v), id(_i) {}
  bool operator<(const data& rhs) const {
    return val < rhs.val || (val == rhs.val && id < rhs.id);
  }
  bool operator==(const data& rhs) const {
    return val == rhs.val && id == rhs.id;
  }
};
struct Heap {
  priority_queue<data> q, del;
  void insert(const data& A) { q.push(A); }
  void erase(const data& A) { del.push(A); }
  data top() {
    while (q.size() && del.size() && q.top() == del.top()) q.pop(), del.pop();
    return q.size() ? q.top() : data(-1, 0);
  }
} Q;
int top, st[N];
struct LCT {
  int fa[N], siz[N], isiz[N], rev[N], mx[N], val[N], ch[N][2];
  int get(int x) { return ch[fa[x]][1] == x; }
  bool isroot(int x) { return ch[fa[x]][0] != x && ch[fa[x]][1] != x; }
  void pushup(int x) {
    siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + isiz[x] + 1;
    int tmx = max(val[x], max(val[mx[ch[x][0]]], val[mx[ch[x][1]]]));
    if (val[x] == tmx)
      mx[x] = x;
    else if (val[mx[ch[x][0]]] == tmx)
      mx[x] = mx[ch[x][0]];
    else
      mx[x] = mx[ch[x][1]];
  }
  void pushdown(int x) {
    if (!rev[x]) return;
    swap(ch[x][0], ch[x][1]);
    rev[ch[x][0]] ^= 1;
    rev[ch[x][1]] ^= 1;
    rev[x] = 0;
  }
  void rotate(int x) {
    int y = fa[x], z = fa[y], k = get(x);
    if (!isroot(y)) ch[z][get(y)] = x;
    fa[ch[x][!k]] = y;
    fa[y] = x;
    fa[x] = z;
    ch[y][k] = ch[x][!k];
    ch[x][!k] = y;
    pushup(y);
    pushup(x);
  }
  void splay(int x) {
    st[top = 1] = x;
    for (int t = x; !isroot(t); t = fa[t]) st[++top] = fa[t];
    while (top) pushdown(st[top--]);
    while (!isroot(x)) {
      int y = fa[x];
      if (!isroot(y)) rotate(get(y) == get(x) ? y : x);
      rotate(x);
    }
  }
  void access(int x) {
    for (int t = 0; x; t = x, x = fa[x])
      splay(x), isiz[x] += siz[ch[x][1]] - siz[t], ch[x][1] = t, pushup(x);
  }
  void makeroot(int x) {
    access(x);
    splay(x);
    rev[x] ^= 1;
  }
  void getedge(int x, int y) {
    makeroot(x);
    access(y);
    splay(y);
  }
  void link(int i) {
    int x = e[i].u, y = e[i].v;
    makeroot(x);
    makeroot(y);
    fa[x] = n + i;
    isiz[n + i] += siz[x];
    pushup(n + i);
    fa[n + i] = y;
    isiz[y] += siz[n + i];
    pushup(y);
  }
  void cut(int i) {
    int x = e[i].u, y = e[i].v;
    getedge(x, y);
    fa[x] = ch[x][1] = ch[y][0] = 0;
    fa[n + i] = ch[n + i][0] = ch[n + i][1] = isiz[n + i] = 0;
    pushup(n + i);
    pushup(x);
    pushup(y);
  }
  int findf(int x) {
    access(x);
    splay(x);
    while (ch[x][0]) x = ch[x][0];
    return x;
  }
  int odd(int x) { return (siz[x] + 1) >> 1 & 1; }
} T;
}  // namespace Data_Structure
using namespace Data_Structure;
namespace DreamLolita {
int m, cnt;
void solution() {
  n = read();
  m = read();
  cnt = n;
  for (int i = 1; i <= n; ++i) T.val[i] = -inf, T.pushup(i);
  for (int i = 1; i <= m; ++i) {
    int x = read(), y = read(), z = read();
    e[i].u = x;
    e[i].v = y;
    T.val[n + i] = z;
    T.mx[n + i] = n + i;
    if (T.findf(x) == T.findf(y)) {
      T.getedge(x, y);
      int id = T.mx[y] - n, w = T.val[T.mx[y]];
      if (z < w) {
        T.cut(id), T.link(i), Q.erase(data(w, id));
      } else {
        if (cnt)
          puts("-1");
        else
          writeln(Q.top().val);
        continue;
      }
    } else {
      T.makeroot(x);
      cnt -= T.odd(x);
      T.makeroot(y);
      cnt -= T.odd(y);
      T.link(i);
      cnt += T.odd(y);
    }
    Q.insert(data(T.val[i + n], i));
    if (cnt) {
      puts("-1");
      continue;
    }
    for (;;) {
      int id = Q.top().id, u = e[id].u, v = e[id].v;
      T.getedge(u, v);
      if (T.odd(u)) break;
      T.cut(id);
      Q.erase(Q.top());
    }
    writeln(Q.top().val);
  }
}
}  // namespace DreamLolita
int main() {
  DreamLolita::solution();
  return 0;
}
