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
int ar[200010];
int m, n;
string s;
int ask(int x) {
  cout << x << endl;
  int n;
  cin >> n;
  return n;
}
int cnt = 0;
int ask1(int x) {
  cout << x << endl;
  int val;
  cin >> val;
  if (s[cnt] == '0') val = -val;
  cnt++;
  cnt %= (int)s.size();
  return val;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    int val = ask(i);
    assert(val >= -1 && val <= 1);
    if (val == 0) exit(0);
    if (val == 1)
      s += '1';
    else
      s += '0';
  }
  int lo = 1;
  int hi = m;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    int val = ask1(mid);
    assert(val >= -1 && val <= 1);
    if (val == 0) {
      exit(0);
    }
    if (val == 1)
      lo = mid + 1;
    else
      hi = mid - 1;
  }
  return 0;
}
