#include <bits/stdc++.h>
using namespace std;
bool check(string x) {
  int len = x.size();
  for (int i = 0; i < len - 1; i++) {
    if (abs(x[i] - x[i + 1]) == 1) return false;
  }
  return true;
}
int main() {
  string str;
  int n;
  cin >> n;
  while (n--) {
    cin >> str;
    string odd, even;
    for (char x : str) {
      if (x % 2)
        even.push_back(x);
      else
        odd.push_back(x);
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    string p1 = odd + even;
    string p2 = even + odd;
    if (check(p1)) {
      cout << p1 << endl;
    } else if (check(p2)) {
      cout << p2 << endl;
    } else {
      cout << "No answer\n";
    }
  }
  return 0;
}
