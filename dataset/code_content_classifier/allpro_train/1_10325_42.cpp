#include <bits/stdc++.h>
using namespace std;
int mex(vector<int> A) {
  sort(A.begin(), A.end());
  int x = 0;
  for (int i = 0; i < A.size(); i++) {
    if (A[i] == x) {
      x++;
    } else if (A[i] > x) {
      return x;
    }
  }
  return x;
}
bool check(vector<int> A) {
  for (int i = 0; i < A.size() - 1; i++) {
    if (A[i + 1] < A[i]) {
      return false;
    }
  }
  return true;
}
int main() {
  int T, N;
  cin >> T;
  while (T--) {
    cin >> N;
    vector<int> ans;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    while (true) {
      if (check(A) == true) {
        break;
      }
      int temp = mex(A);
      if (temp == N) {
        int i;
        for (i = 0; i < N; i++) {
          if (A[i] != i) {
            break;
          }
        }
        A[i] = N;
        ans.push_back(i + 1);
      } else {
        A[temp] = temp;
        ans.push_back(temp + 1);
      }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
