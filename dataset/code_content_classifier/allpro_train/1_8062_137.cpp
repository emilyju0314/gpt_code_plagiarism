#include <bits/stdc++.h>
using namespace std;
int A[1010][1010][26];
string s[1010];
int get_sum(int i, int j, int a, int b) {
  int cl = s[i][j] - 'a';
  int x = A[i][j][cl] - A[i][b - 1][cl] - A[a - 1][j][cl] + A[a - 1][b - 1][cl];
  return x;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = "*" + s[i];
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      char c = s[i][j];
      A[i][j][c - 'a']++;
    }
  for (int cl = 0; cl < 26; cl++) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        A[i][j][cl] = A[i][j][cl] + A[i - 1][j][cl] + A[i][j - 1][cl] -
                      A[i - 1][j - 1][cl];
      }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int cl1 = s[i][j] - 'a';
      int low = i, high = n + 1;
      while (low < high) {
        int mid = (low + high) / 2;
        if (get_sum(mid, j, i, j) != mid - i + 1)
          high = mid;
        else
          low = mid + 1;
      }
      int st = i, ed = low;
      int ln = ed - st;
      low--;
      if (st + 3 * (ln)-1 > n) continue;
      if (get_sum(low + ln, j, i + ln, j) != ln ||
          get_sum(low + 2 * ln, j, i + 2 * ln, j) != ln ||
          s[low + 2 * ln][j] == s[low + ln][j] || s[low + ln][j] == s[low][j])
        continue;
      low = j, high = m + 1;
      while (low < high) {
        int mid = (low + high) / 2;
        int x = i, y = j, a = i + ln - 1, b = mid;
        int w = mid - j + 1;
        if (get_sum(a, b, i, j) != ln * w ||
            get_sum(a + ln, b, i + ln, j) != ln * w ||
            get_sum(a + 2 * ln, b, i + 2 * ln, j) != ln * w)
          high = mid;
        else
          low = mid + 1;
      }
      ans += low - j;
    }
  }
  cout << ans << '\n';
}
