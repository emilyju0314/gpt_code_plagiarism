#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1001;
const int MAXB = 101;
const long long INF = 1000000000ll;
const long long LLINF = 1000000000000000000ll;
const int MOD = 1000000007;
string s[MAXN];
string a[MAXN];
char chars[62] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a',
                  'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                  'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
                  'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                  'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
                  'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(10);
  cout << fixed;
  int t;
  cin >> t;
  for (int tt = 0; tt < (int)(t); tt++) {
    int n, m, k;
    cin >> n >> m >> k;
    int c = 0;
    for (int i = 0; i < (int)(n); i++) {
      cin >> s[i];
      a[i].resize(m);
      for (int j = 0; j < (int)(m); j++) {
        if (s[i][j] == 'R') {
          c++;
        }
      }
    }
    int id = 0;
    int sum = 0;
    for (int i = 0; i < (int)(n); i++) {
      if (i % 2 == 0) {
        for (int j = 0; j < (int)(m); j++) {
          if (s[i][j] == 'R') {
            sum++;
          }
          a[i][j] = chars[id];
          if (id + 1 < k &&
              (sum == c / k + 1 || (id >= c % k && sum == c / k))) {
            id++;
            sum = 0;
          }
        }
      } else {
        for (int j = m - 1; j >= 0; j--) {
          if (s[i][j] == 'R') {
            sum++;
          }
          a[i][j] = chars[id];
          if (id + 1 < k &&
              (sum == c / k + 1 || (id >= c % k && sum == c / k))) {
            id++;
            sum = 0;
          }
        }
      }
    }
    for (int i = 0; i < (int)(n); i++) {
      for (int j = 0; j < (int)(m); j++) {
        cout << a[i][j];
      }
      cout << "\n";
    }
  }
  return 0;
}
