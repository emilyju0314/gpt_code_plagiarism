#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  while (b) {
    auto tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}
void oneCase() {
  string line;
  cin >> line;
  auto n = line.size();
  vector<int> counter(26);
  int mp = 0;
  for (auto l : line) {
    ++counter[int(l) - 97];
    if (counter[int(l) - 97] > counter[mp]) {
      mp = int(l) - 97;
    }
  }
  vector<char> other;
  for (auto l : line) {
    if (int(l) - 97 != mp) {
      other.push_back(l);
    }
  }
  vector<bool> prime(n + 10, true);
  prime[1] = false;
  for (int i = 2; i < prime.size(); ++i) {
    if (!prime[i]) {
      continue;
    }
    auto cur = 2 * i;
    while (cur < prime.size()) {
      prime[cur] = false;
      cur += i;
    }
  }
  int pos = 0;
  for (int i = 1; i <= n; ++i) {
    if (i == 1 || (prime[i] && i * 2 > n)) {
      if (pos == other.size()) {
        if (counter[mp]) {
          line[i - 1] = char(mp + 97);
          --counter[mp];
        } else {
          cout << "NO\n";
          return;
        }
      } else {
        line[i - 1] = other[pos++];
      }
    } else {
      if (counter[mp]) {
        line[i - 1] = char(mp + 97);
        --counter[mp];
      } else {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n" << line << "\n";
}
int main() {
  int t = 1;
  while (t--) {
    oneCase();
  }
  return 0;
}
