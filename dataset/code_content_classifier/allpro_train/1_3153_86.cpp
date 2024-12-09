#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long fact(int n) {
  if (n == 0) return 1;
  return n * fact(n - 1);
}
string con(int x) {
  stringstream stringstream;
  stringstream << x;
  string y;
  stringstream >> y;
  return y;
}
bool cmp(pair<int, int> i, pair<int, int> j) {
  if (i.first < j.first) return 0;
  return 1;
}
void moamen() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
};
int arr[10000];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      if (i + j >= n / 2 && j - i <= n / 2 && i - j <= n / 2 &&
          i + j <= n / 2 * 3)
        cout << "D";
      else
        cout << "*";
    cout << endl;
  }
  return 0;
}
