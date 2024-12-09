#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) cin >> arr[i];
  long long leftIndx = 0;
  long long rightIndx = n - 1;
  long long sum1 = 0;
  long long sum3 = 0;
  long long lastFoundEqualSum = 0;
  while (leftIndx <= rightIndx) {
    if (sum1 <= sum3) {
      sum1 += arr[leftIndx];
      leftIndx++;
    } else {
      sum3 += arr[rightIndx];
      rightIndx--;
    }
    if (sum1 == sum3) {
      lastFoundEqualSum = sum1;
    }
  }
  cout << lastFoundEqualSum << "\n";
  return 0;
}
