#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
template <class T>
inline T biton(T n, T pos) {
  return n | ((T)1 << pos);
}
template <class T>
inline T bitoff(T n, T pos) {
  return n & ~((T)1 << pos);
}
template <class T>
inline T ison(T n, T pos) {
  return (bool)(n & ((T)1 << pos));
}
template <class T>
inline T gcd(T a, T b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
template <typename T>
string NumberToString(T Number) {
  ostringstream second;
  second << Number;
  return second.str();
}
inline int nxt() {
  int aaa;
  scanf("%d", &aaa);
  return aaa;
}
inline long long int lxt() {
  long long int aaa;
  scanf("%lld", &aaa);
  return aaa;
}
inline double dxt() {
  double aaa;
  scanf("%lf", &aaa);
  return aaa;
}
template <class T>
inline T bigmod(T p, T e, T m) {
  T ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % m;
    p = (p * p) % m;
  }
  return (T)ret;
}
int ar[100010];
int mark[100010];
void gen(int u) {
  if (u > 10000) return;
  mark[u] = 1;
  if (!mark[u * 10 + 4]) gen(u * 10 + 4);
  if (!mark[u * 10 + 7]) gen(u * 10 + 7);
}
int tree[100010];
void update(int i, int val, int n) {
  while (i <= n) {
    tree[i] += val;
    i += i & (-i);
  }
}
int query(int i) {
  int sum = 0;
  while (i) {
    sum += tree[i];
    i -= i & (-i);
  }
  return sum;
}
int main() {
  gen(4);
  gen(7);
  int n = nxt(), m = nxt();
  for (int i = 1; i < n + 1; i++) {
    ar[i] = nxt();
    if (mark[ar[i]]) update(i, 1, n);
  }
  while (m--) {
    char c[10];
    scanf("%s", c);
    int a = nxt();
    int b = nxt();
    if (c[0] == 'c') {
      printf("%d\n", query(b) - query(a - 1));
    } else {
      int d = nxt();
      for (int i = a; i < b + 1; i++) {
        if (mark[ar[i]]) update(i, -1, n);
        ar[i] += d;
        if (mark[ar[i]]) update(i, 1, n);
      }
    }
  }
  return 0;
}
