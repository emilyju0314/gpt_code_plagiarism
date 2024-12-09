#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
const int INF = 0x3f3f3f3f;
const int iinf = 1 << 30;
const long long linf = 2e18;
const int mod = 1000000007;
const double eps = 1e-7;
void douout(double x) { printf("%lf\n", x + 0.0000000001); }
template <class T>
void print(T a) {
  cout << a << endl;
  exit(0);
}
template <class T>
void chmin(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
void chmax(T &a, T b) {
  if (a < b) a = b;
}
void add(int &a, int b) { a = a + b < mod ? a + b : a + b - mod; }
void sub(int &a, int b) { a = (a - b + mod) % mod; }
void mul(int &a, int b) { a = (long long)a * b % mod; }
int addv(int a, int b) { return (a += b) >= mod ? a -= mod : a; }
int subv(int a, int b) { return (a -= b) < 0 ? a += mod : a; }
int mulv(int a, int b) { return (long long)a * b % mod; }
int read() {
  int f = 1, x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int pw(int a, int b) {
  int s = 1;
  for (; b; b >>= 1, a = (long long)a * a % mod)
    if (b & 1) s = (long long)s * a % mod;
  return s;
}
struct node {
  int x, y, id;
} a[N];
int n;
vector<node> v1, v2;
bool cmp1(node a, node b) { return a.y > b.y; }
bool cmp2(node a, node b) { return a.y < b.y; }
signed main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) scanf("%d%d", &a[i].x, &a[i].y), a[i].id = i;
  for (int i = (1); i <= (n); i++)
    if (a[i].x < a[i].y) {
      v1.push_back(a[i]);
    } else {
      v2.push_back(a[i]);
    }
  if (((int)v1.size()) > ((int)v2.size())) {
    printf("%d\n", ((int)v1.size()));
    sort(v1.begin(), v1.end(), cmp1);
    for (auto it = v1.begin(); it != v1.end(); it++) printf("%d ", it->id);
  } else {
    printf("%d\n", ((int)v2.size()));
    sort(v2.begin(), v2.end(), cmp2);
    for (auto it = v2.begin(); it != v2.end(); it++) printf("%d ", it->id);
  }
  return 0;
}
