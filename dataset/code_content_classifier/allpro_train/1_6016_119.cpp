#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long int ans = 0;
  int score = 0;
  int temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    temp -= score;
    score += temp;
    ans += abs(temp);
  }
  cout << ans;
  return 0;
}
