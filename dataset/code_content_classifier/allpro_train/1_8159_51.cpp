#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-5;
long long dp[2][5001];
int main(void) {
  int N;
  int n, m;
  int i;
  cin >> N;
  vector<int> array(N);
  vector<int> array_s(N);
  for (n = 0; n < N; n++) {
    cin >> array[n];
    array_s[n] = array[n];
  }
  sort(array_s.begin(), array_s.end());
  int num = 0;
  for (n = 0; n < N; n++) {
    if (array_s[num] != array_s[n]) {
      num++;
      array_s[num] = array_s[n];
    }
  }
  int a0 = array[0];
  for (i = 0; i <= num; i++) {
    int asi = array_s[i];
    if (a0 <= asi) {
      dp[0][i] = 0;
    } else {
      dp[0][i] = a0 - asi;
    }
  }
  int maxa = a0;
  for (n = 1; n < N; n++) {
    int curr = n & 1;
    int prev = 1 - curr;
    int an = array[n];
    long long prev_best = dp[prev][0];
    for (i = 0; i <= num; i++) {
      prev_best = min(prev_best, dp[prev][i]);
      int asi = array_s[i];
      dp[curr][i] = prev_best + abs(asi - an);
    }
    if (maxa < an) maxa = an;
  }
  int curr = (N - 1) & 1;
  long long result = dp[curr][0];
  for (i = 1; i <= num; i++) {
    long long tmp = dp[curr][i];
    if (result > tmp) result = tmp;
  }
  cout << result;
  return 0;
}
