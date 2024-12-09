#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  int N;
  cin >> N;
  vector<long long int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  int mask = 1;
  while (mask < N) {
    mask *= 2;
  }
  long long int tally = 0;
  for (int i = 0; i < N - 1; i++) {
    int move_index = i + mask;
    while (move_index >= N) {
      mask /= 2;
      move_index = i + mask;
    }
    a[move_index] += a[i];
    tally += a[i];
    cout << tally << '\n';
  }
  return 0;
}
