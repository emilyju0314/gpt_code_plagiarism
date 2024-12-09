#include <bits/stdc++.h>
using namespace std;
long long t;
void fun(int n, int src, int des, int hel, vector<vector<int>>& s) {
  if (n == 0) return;
  fun(n - 1, src, hel, des, s);
  vector<int> a = {src, des};
  s.push_back(a);
  fun(n - 1, hel, des, src, s);
}
long long s(long long num) {
  long long sum = 0;
  while (num) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool fun(long long x1, long long y1, long long x2, long long y2, long long x3,
         long long y3) {
  long long A = (int)pow((x2 - x1), 2) + (int)pow((y2 - y1), 2);
  long long B = (int)pow((x3 - x2), 2) + (int)pow((y3 - y2), 2);
  long long C = (int)pow((x3 - x1), 2) + (int)pow((y3 - y1), 2);
  if ((A > 0 and B > 0 and C > 0) and
      (A == (B + C) or B == (A + C) or C == (A + B)))
    return true;
  return false;
}
void solve() {
  long long x1, x2, x3, y1, y2, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  long long a[6] = {x1, y1, x2, y2, x3, y3};
  long long b[6] = {x1, y1, x2, y2, x3, y3};
  if (fun(x1, y1, x2, y2, x3, y3)) {
    cout << "RIGHT" << endl;
    return;
  }
  for (int i = 0; i < 6; i++) {
    a[i]++;
    if (fun(a[0], a[1], a[2], a[3], a[4], a[5])) {
      cout << "ALMOST" << endl;
      return;
    } else {
      a[i]--;
    }
  }
  for (int i = 0; i < 6; i++) {
    b[i]--;
    if (fun(b[0], b[1], b[2], b[3], b[4], b[5])) {
      cout << "ALMOST" << endl;
      return;
    } else {
      b[i]++;
    }
  }
  cout << "NEITHER" << endl;
  return;
}
int main() { solve(); }
