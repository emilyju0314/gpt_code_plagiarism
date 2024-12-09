#include <bits/stdc++.h>
using namespace std;
const int d = 100005;
int freq[d];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    ++freq[value];
  }
  int sum = 0, mx = 1;
  for (int i = 0; i <= 1000; i++) {
    if (freq[i] != 0) ++sum;
    if (freq[i] > mx) mx = freq[i];
  }
  cout << mx << "  " << sum;
}
