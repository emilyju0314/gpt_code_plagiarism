#include <bits/stdc++.h>
using namespace std;
int run() {
  int n = 0;
  cin >> n;
  string str;
  cin >> str;
  int i = 0, ans = n;
  while (i < n) {
    if (i <= n - 2) {
      if ('R' == str[i] && 'U' == str[i + 1]) {
        ans--;
        i += 2;
      } else if ('U' == str[i] && 'R' == str[i + 1]) {
        ans--;
        i += 2;
      } else
        i++;
    } else {
      i++;
    }
  }
  cout << ans << endl;
  return 0;
}
int main(int argc, char* argv[]) {
  run();
  return 0;
}
