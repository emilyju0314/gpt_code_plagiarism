#include <bits/stdc++.h>
using namespace std;
long long N, arr[200010], num[61], maks, imaks;
long long f(long long bil) {
  long long res = 0;
  while (bil % 2 == 0) {
    bil /= 2;
    res++;
  }
  return res;
}
int main() {
  cin >> N;
  for (long long i = 0; i < N; i++) {
    cin >> arr[i];
    num[f(arr[i])]++;
  }
  for (long long i = 0; i <= 60; i++) {
    if (num[i] > maks) {
      maks = num[i];
      imaks = i;
    }
  }
  cout << N - maks << endl;
  if (N > maks) {
    for (long long i = 0; i < N; i++) {
      if (f(arr[i]) != imaks) cout << arr[i] << " ";
    }
    cout << endl;
  }
}
