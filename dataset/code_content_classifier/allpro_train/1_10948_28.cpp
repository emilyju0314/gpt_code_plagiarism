#include <bits/stdc++.h>
using namespace std;
int main() {
  int sum = 0;
  int max = 0;
  int n, s, temp;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    if (temp > max) max = temp;
    sum += temp;
  }
  sum -= max;
  if (sum <= s)
    cout << "YES";
  else
    cout << "NO";
}
