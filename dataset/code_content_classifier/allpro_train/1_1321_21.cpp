#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    long long int odd = 0, ev = 0, in = -1;
    for (long long int i = 0; i < s.size(); i++) {
      if ((s[i] - '0') % 2) {
        odd++;
        if (odd == 2) {
          in = i;
          break;
        }
      }
    }
    if (in != -1) {
      for (long long int i = 0; i < in + 1; i++) {
        cout << s[i];
      }
      cout << "\n";
    } else
      cout << "-1\n";
  }
  return 0;
}
