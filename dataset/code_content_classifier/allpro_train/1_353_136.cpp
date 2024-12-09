#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    map<char, long long> ct;
    for (auto it : a) ct[it]++;
    long long p = 0;
    for (long long i = 0; i < a.size(); i++) {
      long long pos = i;
      for (long long j = a.size() - 1; j > i; j--) {
        if (a[j] < a[pos]) pos = j;
      }
      if (pos == i) continue;
      swap(a[i], a[pos]);
      p++;
      break;
    }
    if (a.compare(b) < 0)
      cout << a << "\n";
    else
      cout << "---\n";
  }
  return 0;
}
