#include <bits/stdc++.h>
using namespace std;
long long is_permutation(vector<long long> A, vector<long long> B) {
  sort((A).begin(), (A).end());
  sort((B).begin(), (B).end());
  int is_equal = (A.size() == B.size() ? true : false);
  for (int i = 0; i < A.size(); i++) {
    if (A[i] != B[i]) {
      is_equal = false;
    }
  }
  return is_equal;
}
void read(vector<long long> &A, int n) {
  for (int i = 0; i < n; i++) cin >> A[i];
}
void get_difference(vector<long long> &A, vector<long long> &D) {
  for (int i = 0; i + 1 < A.size(); i++) {
    D.push_back(A[i + 1] - A[i]);
  }
}
int main() {
  int no_of_elements;
  cin >> no_of_elements;
  vector<long long> A(no_of_elements);
  read(A, no_of_elements);
  vector<long long> B(no_of_elements);
  read(B, no_of_elements);
  vector<long long> beginning_difference;
  get_difference(A, beginning_difference);
  vector<long long> ending_difference;
  get_difference(B, ending_difference);
  cout << (A[0] == B[0] && A[no_of_elements - 1] == B[no_of_elements - 1] &&
                   is_permutation(beginning_difference, ending_difference)
               ? "Yes\n"
               : "No\n");
  return 0;
}
