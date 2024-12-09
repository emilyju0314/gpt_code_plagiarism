#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int mod = 1e9 + 7;
string A, B, C;
int dp[51][2][10][10];

bool f(string s, int i, int x) {
  return s[i] == '?' || (s[i] - '0') == x;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  while (cin >> A >> B >> C, A != "0") {
    fill_n((int*)dp, 51 * 2 * 10 * 10, 0);
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    reverse(C.begin(), C.end());
    int n = A.size();
    dp[0][0][0][0] = 1;
    for (int d = 0; d < n; d++) {
      for (int c = 0; c < 2; c++) {
        for (int a = 0; a < 10; a++) {
          for (int b = 0; b < 10; b++) {
            if (!dp[d][c][a][b]) continue;
            for (int i = 0; i < 10; i++) {
              for (int j = 0; j < 10; j++) {
                if (!(f(A, d, i) && f(B, d, j))) continue;
                int carry = c + a + b > 9;
                if (C[d] != '?' && (i + j + carry) % 10 != (C[d] - '0')) continue;
                (dp[d + 1][carry][i][j] += dp[d][c][a][b]) %= mod;
              }
            }
          }
        }
      }
    }
    int ans = 0;
    for (int c = 0; c < 2; c++) {
      for (int a = 1; a < 10; a++) {
        for (int b = 1; b < 10; b++) {
          if (c + a + b > 9) continue;
          (ans += dp[n][c][a][b]) %= mod;
        }
      }
    }
    cout << ans << endl;
  }

  return 0;
}
