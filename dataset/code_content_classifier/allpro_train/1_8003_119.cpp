#include <bits/stdc++.h>
using namespace std;
int P[1000001], C[1000001];
int N;
int main(int argc, char **argv) {
  ios::sync_with_stdio(false);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    int k = N / i;
    int r = N % i;
    if (k % 2) {
      C[0]++;
      C[1]--;
      C[r + 1]++;
      C[i]--;
    } else {
      C[1]++;
      C[r + 1]--;
    }
  }
  int Q = 0;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    Q ^= a;
  }
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    cnt += C[i];
    if (cnt % 2) Q ^= i;
  }
  cout << Q << endl;
  return 0;
}
