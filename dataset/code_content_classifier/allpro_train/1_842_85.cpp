#include <bits/stdc++.h>
using namespace std;

int main(void) {
  long long N, K, S;
  cin >> N >> K >> S;
  for (int i = 0; i < K; i++) {
    cout << S << " ";
  }
  for (int i = K; i < N; i++) {
    cout << (S + 1) % ((long long)(1e9)) << " ";
  }
  return 0;
}