#include <bits/stdc++.h>
using namespace std;
string gen(int n, int k) {
  string str;
  int cnt = 0;
  while (k > 1) {
    cnt += 2;
    str += "()";
    k--;
  }
  str += "(";
  for (int i = cnt + 2; i < n; i += 2) {
    str += "()";
  }
  str += ")";
  return str;
}
pair<int, int> cal(int i, int n, string &str, char ch) {
  int a = i;
  for (i = i; i < n; i++) {
    if (str[i] == ch) {
      for (int x = a, j = i; x < j; x++, j--) {
        swap(str[j], str[x]);
      }
      return {a + 1, i + 1};
    }
  }
  return {a + 1, a + 1};
}
int main() {
  int test;
  cin >> test;
  while (test--) {
    int n;
    int k;
    cin >> n >> k;
    string str;
    cin >> str;
    string gstr = gen(n, k);
    std::vector<pair<int, int> > v;
    for (int i = 0; i < n; i++) {
      if (str[i] != gstr[i]) {
        v.push_back(cal(i, n, str, gstr[i]));
      }
    }
    cout << v.size() << endl;
    for (auto it : v) cout << it.first << " " << it.second << endl;
  }
  return 0;
}
