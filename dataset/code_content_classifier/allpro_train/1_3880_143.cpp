#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<pair<long,long>> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i].first >> A[i].second;
  }
  sort(A.begin(), A.end());
  cout << A[N -1].first + A[N - 1].second;
}