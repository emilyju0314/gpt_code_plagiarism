#include <bits/stdc++.h>
using namespace std;
class val {
 public:
  long long t;
  long long idx;
};
class Comp {
 public:
  bool operator()(val v1, val v2) { return v1.t < v2.t; }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    long long n;
    cin >> n;
    cout << (n + 1) / 2 << endl;
  }
}
