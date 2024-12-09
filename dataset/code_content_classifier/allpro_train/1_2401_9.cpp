#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  ;
  string s;
  getline(cin, s);
  long long int ans = 0, cur = 0;
  int sg = +1;
  for (int i = (0); i < (int((s).size())); i += (1)) {
    if (s[i] == '+' || s[i] == '-') {
      ans += sg * cur;
      cur = 0;
    }
    if (s[i] == '+') sg = +1;
    if (s[i] == '-') sg = -1;
    cur = (cur * 10) + (s[i] - '0');
    if (i == int((s).size()) - 1) {
      ans += sg * cur;
    }
  }
  cout << ans << '\n';
  return 0;
}
