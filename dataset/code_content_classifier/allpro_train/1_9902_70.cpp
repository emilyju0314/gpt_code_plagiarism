#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int k, i, count1 = 0, j, ind1, ind2, sum1, t1, t2, a1, b1, x1;
  long long int dp[1000010];
  string s1;
  cin >> k;
  cin >> s1;
  dp[0] = -1;
  long long int l2 = s1.size();
  for (i = 0; i < l2; i++) {
    if (s1[i] == '1') {
      count1++;
      dp[count1] = i;
    }
  }
  if (count1 < k)
    cout << "0" << endl;
  else if (k == 0) {
    for (i = 1; i <= count1; i++) {
      x1 = dp[i] - dp[i - 1] - 1;
      sum1 = sum1 + (x1 * (x1 + 1)) / 2;
    }
    x1 = l2 - 1 - dp[count1];
    sum1 = sum1 + (x1 * (x1 + 1)) / 2;
    cout << sum1 << endl;
  } else {
    sum1 = 0;
    for (j = k; j <= count1; j++) {
      ind1 = dp[j - k] + 1;
      if (j != count1)
        ind2 = dp[j + 1] - 1;
      else
        ind2 = l2 - 1;
      t1 = ind2 - dp[j];
      t2 = dp[j - k + 1] - ind1;
      a1 = t1;
      b1 = t2;
      sum1 = sum1 + a1 + b1 + 1 + (a1 * b1);
    }
    cout << sum1 << endl;
  }
  return 0;
}
