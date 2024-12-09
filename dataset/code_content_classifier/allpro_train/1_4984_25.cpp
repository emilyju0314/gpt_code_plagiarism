#include <bits/stdc++.h>
using namespace std;
const long long int mx = INT_MAX;
const long long int mn = INT_MIN;
const long long int mv = 1000005;
const long long int pi = 3.141592653589793238462643;
string a, b[55], c, h;
long long int d, e, f, g;
set<string> l;
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cin >> a;
  b[e++] = a;
  for (int i = 0; i <= (int)(a.size()); ++i) {
    a += a[0];
    a.erase(0, 1);
    l.insert(a);
  }
  cout << (int)(l.size());
}
