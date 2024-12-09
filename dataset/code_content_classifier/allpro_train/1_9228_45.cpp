#include <bits/stdc++.h>
using namespace std;
inline void getarrint(vector<int>& a, int n, istream& in) {
  for (int i = 0; i <= n - 1; i++) in >> a[i];
}
class Solution {
 public:
  void solve(std::istream& in, std::ostream& out) {
    int n;
    in >> n;
    vector<int> mood(n);
    getarrint(mood, n, in);
    for (int i = 1; i * i < n; i++) {
      if (n % i == 0) {
        int div1 = i;
        int div2 = n / i;
        bool ok;
        if (n / div1 >= 3) {
          for (int knight = 0; knight <= div1 - 1; knight++) {
            ok = true;
            for (int j = knight; j <= n - 1; j += div1) {
              ok &= mood[j];
            }
            if (ok) {
              out << "YES" << '\n';
              return;
            }
          }
        }
        if (n / div2 >= 3) {
          for (int knight = 0; knight <= div2 - 1; knight++) {
            ok = true;
            for (int j = knight; j <= n - 1; j += div2) {
              ok &= mood[j];
            }
            if (ok) {
              out << "YES" << '\n';
              return;
            }
          }
        }
      }
    }
    out << "NO" << '\n';
    return;
  }
};
void solve(std::istream& in, std::ostream& out) {
  out << std::setprecision(12);
  Solution solution;
  solution.solve(in, out);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  istream& in = cin;
  ostream& out = cout;
  solve(in, out);
  return 0;
}
