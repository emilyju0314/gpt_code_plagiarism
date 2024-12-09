#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, count = 0, ob;
  cin >> a >> b;
  ob = b;
  vector<long long int> stored;
  while (a != b && a < b) {
    count++;
    if (b % 2 == 0) {
      stored.push_back(b / 2);
      b = b / 2;
    } else if (b % 10 == 1) {
      b = (b - 1) / 10;
      stored.push_back(b);
    } else {
      break;
    }
  }
  if (a == b) {
    cout << "YES\n";
    if (count != 0) {
      cout << count + 1 << '\n';
      for (auto itr = stored.end() - 1; itr != stored.begin() - 1; itr--) {
        cout << *itr << " ";
      }
      cout << ob << '\n';
    } else {
      cout << count + 1 << '\n';
      cout << b << '\n';
    }
  } else {
    cout << "NO\n";
  }
  return 0;
}
