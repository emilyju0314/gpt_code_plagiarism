#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long po(long long x, long long n) {
  long long ans = 1;
  while (n > 0) {
    if (n & 1) ans = (ans * x) % mod;
    x = (x * x) % mod;
    n /= 2;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) {
    long long n;
    cin >> n;
    vector<long long> v;
    long long f, a, b, f1 = 1, k = 1;
    vector<pair<long long, pair<long long, long long> > > m;
    for (int i = 0; i < n; i++) {
      cin >> f;
      if (!f1) {
        if (f == 1) {
          cin >> a;
          m.push_back(make_pair(k, make_pair(1, a)));
          k++;
        } else {
          cin >> a >> b;
          m.push_back(make_pair(k, make_pair(b, a)));
          k += (b * a);
        }
      } else if (f == 1 && f1) {
        cin >> a;
        v.push_back(a);
        m.push_back(make_pair(k, make_pair(1, a)));
        k++;
      } else if (f == 2 && f1) {
        cin >> a >> b;
        m.push_back(make_pair(k, make_pair(2, a)));
        k += (b * a);
        while (b > 0 && f1) {
          for (int j = 0; j < a; j++) {
            v.push_back(v[j]);
            if (v.size() == 111111) {
              f1 = 0;
              break;
            }
          }
          if (!f1) break;
          b--;
        }
      }
    }
    m.push_back(make_pair(10e16, make_pair(0, 0)));
    long long q;
    cin >> q;
    long long pos, s = 1;
    for (int i = 0; i < q; i++) {
      cin >> pos;
      while (pos >= m[s].first) {
        s++;
      }
      s--;
      if (pos == m[s].first) {
        if (m[s].second.first == 1)
          cout << m[s].second.second << " ";
        else
          cout << v[0] << " ";
      } else {
        pos -= m[s].first;
        b = m[s].second.second;
        pos %= b;
        cout << v[pos] << " ";
      }
    }
    cout << "\n";
  }
  return 0;
}
