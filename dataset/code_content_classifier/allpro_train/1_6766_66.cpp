#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string str;
  while (cin >> n) {
    getchar();
    while (n--) {
      cin >> str;
      getchar();
      int l = str.size();
      vector<int> ans;
      for (int i = 0; i < l - 4; i++) {
        if (str[i] == 't' and str[i + 1] == 'w' and str[i + 2] == 'o' and
            str[i + 3] == 'n' and str[i + 4] == 'e') {
          ans.push_back(i + 2);
          str[i + 2] = '.';
          i += 4;
        }
      }
      for (int i = 0; i < l - 2; i++) {
        if (str[i] == 'o' and str[i + 1] == 'n' and str[i + 2] == 'e') {
          ans.push_back(i + 1);
          str[i + 1] = '.';
        } else if (str[i] == 't' and str[i + 1] == 'w' and str[i + 2] == 'o') {
          ans.push_back(i + 1);
          str[i + 1] = '.';
        }
      }
      cout << ans.size() << endl;
      for (int i = 0; i < ans.size(); i++) {
        if (i != 0) cout << " ";
        cout << ans[i] + 1;
      }
      cout << endl;
      ans.clear();
      str.clear();
    }
  }
  return 0;
}
