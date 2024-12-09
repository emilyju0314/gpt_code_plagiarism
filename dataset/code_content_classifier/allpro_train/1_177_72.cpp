#include <bits/stdc++.h>
using namespace std;
template <class C>
void setmin(C &a, C b) {
  if (a > b) a = b;
}
template <class C>
void setmax(C &a, C b) {
  if (a < b) a = b;
}
template <class C>
void printv(vector<C> vec, string end = " ") {
  for (auto const &iter : vec) cout << iter << end;
  if (end != "\n") cout << endl;
}
template <class C>
void printv(set<C> setc, string end = " ") {
  for (auto const &iter : setc) cout << iter << end;
  if (end != "\n") cout << endl;
}
template <class C>
void print(C A[], long long n, string end = " ") {
  for (long long iter = 0; iter < n; ++iter) cout << A[iter] << end;
  if (end != "\n") cout << endl;
}
class Solution {
 public:
  void SolutionFunc() {
    long long a, b, n;
    cin >> a >> b >> n;
    if (n % 3 == 0)
      cout << a << endl;
    else if (n % 3 == 1)
      cout << b << endl;
    else
      cout << (a ^ b) << endl;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  Solution ob;
  long long t = 1;
  cin >> t;
  for (long long t1 = 0; t1 < t; ++t1) {
    ob.SolutionFunc();
  }
  return 0;
}
