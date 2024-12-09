#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long size, iter = 1;
  cin >> iter;
  while (iter--) {
    string s;
    cin >> s;
    size = s.size();
    if (size > 10)
      cout << s[0] << size - 2 << s[size - 1] << endl;
    else
      cout << s << endl;
  }
  return 0;
}
