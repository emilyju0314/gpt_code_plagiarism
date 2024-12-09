#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int j = N - 1; j >= 0; j--) {
    for (int k = j + 1; k < N; k++) {
      if (A[k - 1] > A[k]) {
        int temp = A[k];
        A[k] = A[k - 1];
        A[k - 1] = temp;
        cout << k << " " << k + 1 << endl;
      }
    }
  }
}
