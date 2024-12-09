#include <bits/stdc++.h>
using namespace std;
int N;
int M[17];
int R[17];
bool good[720725];
int gcd(int m, int n) { return (m % n == 0) ? n : gcd(n, m % n); }
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> M[i];
  for (int i = 0; i < N; i++) cin >> R[i];
  int lcm = M[0];
  for (int i = 1; i < N; i++) lcm = M[i] * lcm / gcd(lcm, M[i]);
  for (int i = 0; i < N; i++)
    for (int j = R[i]; j <= lcm; j += M[i]) good[j] = true;
  int cnt = 0;
  for (int i = 1; i <= lcm; i++) cnt += good[i];
  printf("%.10f\n", (double)cnt / lcm);
  return 0;
}
