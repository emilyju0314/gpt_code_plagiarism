#include <bits/stdc++.h>
using namespace std;
long long int cnt[50], cnt2[50];
long long int mat[111][111], tempo[111][111];
int main() {
  int n, k;
  string a, b;
  cin >> n >> k;
  cin >> a >> b;
  for (auto x : a) cnt[x - 'a']++;
  for (auto x : b) cnt2[x - 'a']++;
  for (int i = 0; i < 26; i++) {
    if (cnt2[i] * k > cnt[i] * n) {
      puts("0");
      return 0;
    }
  }
  long long int cnt = 0, found = 0, aux = 0, ans = 0, j = 0, cycle, i;
  while (!found && cnt < n) {
    cnt++;
    for (i = 0; i < a.size(); i++) {
      if (a[i] == b[j]) {
        if (tempo[i][j]) {
          found = j + 1;
          cycle = cnt - tempo[i][j];
          aux = ans - mat[i][j];
          cnt = tempo[i][j];
          ans = mat[i][j];
          break;
        }
        tempo[i][j] = cnt;
        mat[i][j] = ans;
        j++;
        if (j == b.size()) ans++, j = 0;
      }
    }
  }
  ans += (n - cnt) / cycle * aux;
  n = (n - cnt) % cycle;
  j = found - 1;
  for (; i < a.size(); i++) {
    if (b[j] == a[i]) j++;
    if (j == b.size()) ans++, j = 0;
  }
  while (n--) {
    for (int i = 0; i < a.size(); i++) {
      if (b[j] == a[i]) j++;
      if (j == b.size()) ans++, j = 0;
    }
  }
  cout << ans / k << "\n";
}
