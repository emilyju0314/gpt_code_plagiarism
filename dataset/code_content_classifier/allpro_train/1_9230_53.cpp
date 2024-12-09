#include <bits/stdc++.h>
using namespace std;
inline void EnableFileIO(const string& fileName) {
  if (fileName.empty()) return;
  freopen((fileName + ".in").c_str(), "r", stdin);
  freopen((fileName + ".out").c_str(), "w", stdout);
  return;
}
const long long INF = 1e9;
const double EPS = 1e-10;
const int N = 5e5 + 100;
int n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  EnableFileIO("");
  cin >> n;
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    a += INF, b += INF, c += INF, d += INF;
    if ((a & 1) && (b & 1)) {
      cout << 1 << endl;
    } else if ((a & 1)) {
      cout << 2 << endl;
    } else if ((b & 1)) {
      cout << 3 << endl;
    } else {
      cout << 4 << endl;
    }
  }
  return 0;
}
