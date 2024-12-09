#include <bits/stdc++.h>
using namespace std;

int N; long long X;
int A[2000];
int D[2][2000];
long long res;

int main() {
  cin >> N >> X;
  for(int i = 0; i < N; ++i) cin >> A[i];
  for(int i = 0; i < N; ++i)res += D[0][i] = A[i];
  for(int k = 1; k < N; ++k) {
    int prev = (k - 1) % 2, cur = k % 2;
    long long tmp = k * X;
    for(int i = 0; i < N; ++i) tmp += D[cur][i] = min(D[prev][i], D[prev][(i + N - 1) % N]);
    res = min(res, tmp);
  }
  cout << res << endl;
  return 0;
}
