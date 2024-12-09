#include <bits/stdc++.h>
using namespace std;
constexpr long long inf = 0x3FFF;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  for (long long i = 0; i + 2 < s.size(); i++) {
    if ((s[i] ^ s[i + 1] ^ s[i + 2]) == ('A' ^ 'B' ^ 'C')) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
