#include <bits/stdc++.h>
using namespace std;
long long ar[500005], br[500005];
int main() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long cnt = 0;
  for (int i = 0; i < s.size(); i += 2) {
    if (s[i] == s[i + 1] && s[i] == 'a') {
      cnt++;
      s[i] = 'b';
    } else if (s[i] == s[i + 1] && s[i] == 'b') {
      cnt++;
      s[i] = 'a';
    }
  }
  cout << cnt << endl;
  cout << s << endl;
}
