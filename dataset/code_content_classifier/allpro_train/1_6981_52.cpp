#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int arr[26];
  memset(arr, 0, sizeof(arr));
  int excla = 0;
  int ans = 0;
  int res = 0;
  for (int i = 0; i < n; i++) {
    char c;
    string s;
    cin >> c >> s;
    if (i == n - 1) break;
    if (ans == 1) {
      if (c == '!' || c == '?') res++;
      continue;
    }
    if (c == '.') {
      for (int j = 0; j < s.length(); j++) {
        if (arr[s[j] - 'a'] == excla && ans != 0) {
          ans--;
        }
        arr[s[j] - 'a'] = -1;
      }
    } else if (c == '!') {
      ans = 0;
      for (int j = 0; j < s.length(); j++) {
        if (arr[s[j] - 'a'] == excla) {
          arr[s[j] - 'a']++;
          ans++;
        }
      }
      excla++;
    } else {
      if (arr[s[0] - 'a'] == excla && ans != 0) {
        ans--;
      }
      arr[s[0] - 'a'] = -1;
    }
    int temp = 0;
    for (int j = 0; j < 26; j++) {
      if (arr[j] == -1) temp++;
    }
    if (temp == 25) ans = 1;
  }
  cout << res;
  return 0;
}
