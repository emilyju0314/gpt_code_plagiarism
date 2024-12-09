#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chmax(T& a, const T& b) {
  if (a < b) a = b;
}
template <typename T>
void chmin(T& a, const T& b) {
  if (b < a) a = b;
}
int N;
int main() {
  cin >> N;
  string S;
  cin >> S;
  bool left = false, right = false, bottom = false, top = false;
  for (int i = (0); i < (N); i++) {
    if (S[i] == '1' || S[i] == '4' || S[i] == '7') {
      left = true;
    }
    if (S[i] == '3' || S[i] == '6' || S[i] == '9') {
      right = true;
    }
    if (S[i] == '7' || S[i] == '9' || S[i] == '0') {
      bottom = true;
    }
    if (S[i] == '1' || S[i] == '2' || S[i] == '3') {
      top = true;
    }
  }
  if (left && right && bottom && top) {
    cout << "YES" << endl;
  } else if (top && count((S).begin(), (S).end(), '0')) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
