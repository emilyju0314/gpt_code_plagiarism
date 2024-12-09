#include <bits/stdc++.h>
using namespace std;
long long int n, m, q;
long long int w[22];
long long int arr[1 << 12][1 << 12];
long long int freq[1 << 12];
long long int ans[1 << 12][105];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> q;
  for (long long int i = 0; i < n; i++) {
    cin >> w[i];
  }
  for (long long int j = 0; j < m; j++) {
    string str;
    cin >> str;
    int val = 0;
    for (int i = 0, x = 1; i < n; x += x, i++)
      if (str[i] == '1') val += x;
    freq[val]++;
  }
  for (long long int i = 0; i < (1 << n); i++) {
    for (long long int j = 0; j < (1 << n); j++) {
      for (long long int k = 0; k < n; k++) {
        arr[i][j] += (w[k] * ((i >> k & 1) == (j >> k & 1)));
      }
      if (arr[i][j] <= 100) {
        ans[i][arr[i][j]] += freq[j];
      }
    }
    for (long long int x = 1; x < 101; x++) {
      ans[i][x] += ans[i][x - 1];
    }
  }
  while (q--) {
    string str;
    cin >> str;
    int k;
    cin >> k;
    long long int val = 0;
    for (int i = 0, x = 1; i < n; x += x, i++)
      if (str[i] == '1') val += x;
    cout << ans[val][k] << '\n';
  }
  return 0;
}
