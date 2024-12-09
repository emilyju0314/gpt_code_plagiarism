#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> F;
map<pair<int, int>, int> Id;
int N, K = 1, Ans = 0, Num[2], A[3];
int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[0] >> A[1] >> A[2];
    sort(A, A + 3);
    if (A[0] >= Ans) {
      Ans = A[0];
      K = 1;
      Num[0] = i;
    }
    if (min(F[make_pair(A[1], A[2])] + A[0], A[1]) > Ans) {
      Ans = min(F[make_pair(A[1], A[2])] + A[0], A[1]);
      K = 2;
      Num[0] = i;
      Num[1] = Id[make_pair(A[1], A[2])];
    }
    if (A[0] > F[make_pair(A[1], A[2])]) {
      F[make_pair(A[1], A[2])] = A[0];
      Id[make_pair(A[1], A[2])] = i;
    }
  }
  cout << K << endl;
  for (int i = 0; i < K; i++) cout << Num[i] << ' ';
  return 0;
}
