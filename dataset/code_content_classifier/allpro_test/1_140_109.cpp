#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long int n;
    cin >> n;
    long long int answer;
    answer = floor(sqrt(n)) + floor(cbrt(n)) - floor(cbrt(sqrt(n)));
    cout << answer << endl;
  }
  return 0;
}
