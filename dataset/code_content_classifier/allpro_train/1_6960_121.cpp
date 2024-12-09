#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  long long int ans = 0;
  int n = a.size();
  int i = 0;
  while (i < n) {
    int temp = 0;
    int j;
    if (a[i] == '@') {
      long long int left = 0;
      long long int right = 0;
      int flag = 0;
      int last_char;
      for (j = i - 1; j >= 0; j--) {
        if (isalpha(a[j])) {
          left++;
          temp = 0;
        } else if (a[j] == '_' || (a[j] >= '0' && a[j] <= '9')) {
        } else if (a[j] == '@' || a[j] == '.')
          break;
      }
      flag = 0;
      for (j = i + 1; j < n; j++) {
        if (a[j] == '.') break;
        if (!(isalnum(a[j]))) {
          flag = 1;
          break;
        }
      }
      if (j == i + 1) {
        i = j;
        continue;
      }
      if (!flag) {
        j++;
        while (a[j] >= 'a' && a[j] <= 'z') {
          right++;
          j++;
        }
        ans += (left * right);
      }
      i = j;
    } else
      i++;
  }
  cout << ans << endl;
  return 0;
}
