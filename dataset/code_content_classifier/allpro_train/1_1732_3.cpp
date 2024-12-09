#include <bits/stdc++.h>
#include <complex>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define loop(i, x, n) for (int i = (x); i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define EQ(a, b) (abs((a) - (b)) < EPS)
#define int long long
#define INF 1e9
#define MOD 1e9 + 7
using namespace std;

template<typename T> void cmin(T &a, T b) { a = min(a, b); }
template<typename T> void cmax(T &a, T b) { a = max(a, b); }

using P = complex<double>;
const double PI = acos(-1);
const double EPS = 1e-9;
// P p(a,b)=a+bi -> 点p(a,b)
namespace std {
  bool operator<(const P &a, const P &b) { return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b); }
  bool operator==(const P &a, const P &b) { return a.real() == b.real() && a.imag() == b.imag(); }
} // namespace std

struct L : public vector<P> {
  L(const P &a, const P &b) {
    push_back(a);
    push_back(b);
  }
};
//内積
double dot(P a, P b) { return real(conj(a) * b); }
//外戚
double cross(P a, P b) { return imag(conj(a) * b); }

int ccw(P a, P b, P c) {
  b -= a;
  c -= a;
  if (cross(b, c) > 0) return +1; // counter clockwise
  if (cross(b, c) < 0) return -1; // clockwise
  if (dot(b, c) < 0) return +2; // c--a--b on line
  if (norm(b) < norm(c)) return -2; // a--b--c on line
  return 0;
}
signed main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    int flag = ccw(P(a, b), P(c, d), P(x, y));
    if (flag == 1)
      cout << "COUNTER_CLOCKWISE" << endl;
    else if (flag == -1)
      cout << "CLOCKWISE" << endl;
    else if (flag == 2)
      cout << "ONLINE_BACK" << endl;
    else if (flag == -2)
      cout << "ONLINE_FRONT" << endl;
    else
      cout << "ON_SEGMENT" << endl;
  }
  return 0;
}

