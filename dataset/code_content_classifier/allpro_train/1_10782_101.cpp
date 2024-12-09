#include <bits/stdc++.h>
using namespace std;
long long x, y;
vector<string> a;
string int_to_string(long long x) {
  string res = "";
  while (x) {
    res += x % 10 + '0';
    x /= 10;
  }
  reverse(res.begin(), res.end());
  return res;
}
int main() {
  cin >> x >> y;
  while (x != 0 && y != 0 && x != y) {
    if (x > y) {
      long long k = x / y;
      if (y == 1)
        a.push_back(int_to_string((x - 1) / y) + "A");
      else
        a.push_back(int_to_string(k) + "A");
      x %= y;
    } else {
      long long k = y / x;
      if (x == 1)
        a.push_back(int_to_string((y - 1) / x) + "B");
      else
        a.push_back(int_to_string(k) + "B");
      y %= x;
    }
  }
  if (x == 1 || y == 1)
    for (long long i = 0; i < a.size(); i++) cout << a[i];
  else
    cout << "Impossible";
}
