#include <bits/stdc++.h>
using namespace std;
template <class T>
string TS(T ss) {
  ostringstream oss;
  oss << ss;
  return oss.str();
}
template <class T>
T ABS(T n) {
  return (n >= 0 ? n : -n);
}
template <class T>
T BP(T n, long long int k) {
  T res = 1;
  while (k) {
    if (k & 1) {
      res *= n;
    }
    n *= n;
    k >>= 1;
  }
  return res;
}
struct ST {
  long long int v, k, d;
  ST(long long int v, long long int k, long long int d) : v(v), k(k), d(d) {}
  ST(long long int v, long long int k) : v(v), k(k) {}
  ST() {}
  bool operator<(const ST &it) const { return v < it.v; }
};
char buf[(int)1e6 + 10], buf1[(int)1e6 + 10];
long long int n = 0, m = 0, k = 0;
vector<long long int> v;
void task() {
  long long int a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  v.resize(4);
  vector<long long int> v1(10, 0);
  v1[0] = 1;
  v[0] = a + b;
  v[1] = a + c;
  v[2] = b + d;
  v[3] = c + d;
  sort((v).begin(), (v).end());
  for (int i = 1; i < 4; i++) {
    if (v[i] == v[i - 1]) {
      v1[i] = v1[i - 1];
    } else {
      v1[i] = v1[i - 1] + v[i] - v[i - 1];
    }
  }
  if (n - v1[3] >= 0) {
    cout << (n - v1[3] + 1) * n;
  } else {
    cout << 0;
  }
}
int main() {
  task();
  return 0;
}
