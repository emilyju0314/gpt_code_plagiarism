#include <bits/stdc++.h>
using namespace std;
void printVec(vector<int> v2, string s = "") {
  cout << s;
  for (int i = 0; i < (int)v2.size(); ++i) cout << v2[i] << " ";
  cout << "\n";
}
bool isOdd(int a) { return (a % 2 == 1); }
void initMem(int n, int mem[]) {
  for (int i = 0; i < n; i++) mem[i] = -1;
}
bool lucky(long long n) {
  n = abs(n);
  while (n) {
    if (n % 10 == 8) {
      return true;
    }
    n /= 10;
  }
  return false;
}
int main() {
  int k;
  int d;
  cin >> k >> d;
  string s = "";
  s += ('0' + d);
  for (int i = 1; i < k; i++) s += '0';
  if (d == 0) {
    if (k == 1)
      cout << 0;
    else
      cout << "No solution";
    return 0;
  }
  cout << s;
  return 0;
}
