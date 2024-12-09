#include <bits/stdc++.h>
using namespace std;
map<string, int> m, n;
string buff;
int ansfo, ansfi;
int main() {
  while (cin >> buff) {
    int a = 0;
    while (1) {
      int i = buff.find_last_of('\\');
      if (i == 2) break;
      buff = buff.substr(0, i);
      int f = n[buff];
      m[buff] += a;
      n[buff]++;
      if (!f) a++;
      ansfo = max(ansfo, m[buff]);
      ansfi = max(ansfi, n[buff]);
    }
  }
  cout << ansfo << " " << ansfi;
  return 0;
}
