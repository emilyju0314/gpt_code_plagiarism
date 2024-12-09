#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
bool sortinrev(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  return (a.first > b.first);
}
long long int A[1000000];
long long int B[1000000];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int n, pos, l, r, val1 = 0, help = 0;
  cin >> n >> pos >> l >> r;
  if (pos < l)
    help += (l - pos), pos = l;
  else if (pos > r)
    help += (pos - r), pos = r;
  if ((r - pos) < (pos - l)) {
    if (r != n) {
      val1 += (r - pos);
      val1++;
      if (l != 1) val1 += (r - l), val1++;
    } else {
      if (l != 1) val1 += (pos - l), val1++;
    }
    cout << val1 + help << endl;
  } else {
    if (l != 1) {
      val1 += (pos - l);
      val1++;
      if (r != n) val1 += (r - l), val1++;
    } else {
      if (r != n) val1 += (r - pos), val1++;
    }
    cout << val1 + help << endl;
  }
  return 0;
}
