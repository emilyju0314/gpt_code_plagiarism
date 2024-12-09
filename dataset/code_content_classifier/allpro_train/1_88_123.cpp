#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  bool arr[n][n];
  memset(arr, 0, sizeof(arr));
  int xo1[n][n];
  int xo2[n][n];
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < (n / 4); j++) {
      char temp = s[j];
      int temp1;
      if (temp < 48 || temp > 57)
        temp1 = temp - 55;
      else
        temp1 = temp - 48;
      if ((temp1 & (1 << 3)) != 0) arr[i][4 * j] = 1;
      if ((temp1 & (1 << 2)) != 0) arr[i][4 * j + 1] = 1;
      if ((temp1 & (1 << 1)) != 0) arr[i][4 * j + 2] = 1;
      if ((temp1 & (1 << 0)) != 0) arr[i][4 * j + 3] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == 0) {
        xo1[i][j] = arr[i][j];
        continue;
      }
      xo1[i][j] = xo1[i][j - 1] + arr[i][j];
    }
  }
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        xo2[i][j] = arr[i][j];
        continue;
      }
      xo2[i][j] = xo2[i - 1][j] + arr[i][j];
    }
  }
  set<int> s1, s2;
  for (int x = 1; x <= sqrt(n); x++) {
    if (n % x != 0) continue;
    int count1 = 0;
    int count2 = 0;
    for (int c = 0; c < n; c++) {
      bool yeah = 1;
      bool yeah1 = 1;
      for (int i = 0; i < n; i += x) {
        int ans = 0;
        if (i != 0)
          ans = xo2[i + x - 1][c] - xo2[i - 1][c];
        else
          ans = xo2[i + x - 1][c];
        if (ans != x && ans != 0) {
          yeah = 0;
          break;
        }
      }
      for (int i = 0; i < n; i += (n / x)) {
        int ans = 0;
        if (i != 0)
          ans = xo2[i + (n / x) - 1][c] - xo2[i - 1][c];
        else
          ans = xo2[i + (n / x) - 1][c];
        if (ans != (n / x) && ans != 0) {
          yeah1 = 0;
          break;
        }
      }
      if (yeah1) count1++;
      if (yeah) count2++;
    }
    if (count1 == n) s1.insert(n / x);
    if (count2 == n) s1.insert(x);
  }
  for (int x = 1; x <= sqrt(n); x++) {
    if (n % x != 0) continue;
    int count1 = 0;
    int count2 = 0;
    for (int r = 0; r < n; r++) {
      bool yeah = 1;
      bool yeah1 = 1;
      for (int i = 0; i < n; i += x) {
        int ans = 0;
        if (i != 0)
          ans = xo1[r][i + x - 1] - xo1[r][i - 1];
        else
          ans = xo1[r][i + x - 1];
        if (ans != x && ans != 0) {
          yeah = 0;
          break;
        }
      }
      for (int i = 0; i < n; i += (n / x)) {
        int ans = 0;
        if (i != 0)
          ans = xo1[r][i + (n / x) - 1] - xo1[r][i - 1];
        else
          ans = xo1[r][i + (n / x) - 1];
        if (ans != (n / x) && ans != 0) {
          yeah1 = 0;
          break;
        }
      }
      if (yeah1) count1++;
      if (yeah) count2++;
    }
    if (count1 == n) s2.insert(n / x);
    if (count2 == n) s2.insert(x);
  }
  int ans = 1;
  for (auto itr = s1.begin(); itr != s1.end(); itr++) {
    int temp = (*itr);
    if (s2.find(temp) != s2.end()) ans = max(ans, temp);
  }
  cout << ans << endl;
  return 0;
}
