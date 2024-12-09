#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; ++i) {
    cin >> vec[i];
  }
  int sumFingers = 0;
  for (int i = 0; i < n; ++i) {
    sumFingers = sumFingers + vec[i];
  }
  int best, counts = 0;
  for (int i = 1; i <= 5; ++i) {
    best = sumFingers + i - 1;
    if (best % (n + 1) != 0) counts++;
  }
  cout << counts << endl;
}
