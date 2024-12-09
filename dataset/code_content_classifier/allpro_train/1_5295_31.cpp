#include <bits/stdc++.h>
using namespace std;
int alph[27], n, k, len;
string input;
char ch;
unsigned long long int ans = 0, cnt = 0;
int main() {
  cin >> n >> k;
  cin >> input;
  for (int i = 0; i < k; i++) {
    cin >> ch;
    alph[ch - 'a'] = 1;
  }
  for (int i = 0; i < n; i++) {
    if (alph[input[i] - 'a'] != 1) {
      ans += ((cnt * (cnt + 1)) / 2);
      cnt = 0;
    } else {
      cnt++;
    }
  }
  ans += ((cnt * (cnt + 1)) / 2);
  cout << ans;
  return 0;
}
