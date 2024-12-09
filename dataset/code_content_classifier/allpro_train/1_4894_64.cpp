#include <bits/stdc++.h>
using namespace std;
template <class T>
string tos(T x) {
  stringstream stringstream;
  stringstream << x;
  return stringstream.str();
}
void rot(vector<vector<int> > v, vector<vector<int> >& tmp, int r1, int c1,
         int r2, int c2) {
  tmp.resize(c2 - c1 + 1);
  int i, j;
  for (i = 0; i < tmp.size(); i++) tmp[i].resize(r2 - r1 + 1);
  for (i = r1; i <= r2; i++)
    for (j = c1; j <= c2; j++)
      tmp[j - c1][tmp[0].size() - (i - r1) - 1] = v[i][j];
}
bool isPal(string second) {
  int i = 0, j = second.size() - 1;
  while (i < j) {
    if (islower(second[i]) && islower(second[j]) && second[i] != second[j])
      return false;
    i++;
    j--;
  }
  return true;
}
bool* sieve(int n) {
  bool* prime = new bool[n + 1];
  memset(prime, 0, sizeof(prime));
  prime[0] = false;
  prime[1] = false;
  int m = (int)sqrt(n);
  for (int i = 2; i <= m; i++)
    if (prime[i])
      for (int k = i * i; k <= n; k += i) prime[k] = false;
  return prime;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int lcm(int a, int b) { return a * b / gcd(a, b); }
int inf = 10000000;
int n, year[10000];
int valid() {
  int i;
  for (i = 0; i < n; i++)
    if (year[i] > year[i + 1]) return false;
  return year[n] <= 2011;
}
void printAns() {
  int i;
  for (i = 1; i <= n; i++) cout << year[i] << endl;
  exit(0);
}
int dif(int x, int y) {
  string s1(tos(x)), s2(tos(y));
  int i, res = 0;
  for (i = 0; i < 4; i++)
    if (s1[i] - s2[i]) res++;
  return res;
}
int main() {
  cin >> n;
  int i, j;
  year[0] = 1000;
  for (i = 1; i <= n; i++) cin >> year[i];
  if (valid()) printAns();
  for (i = 1; i <= n; i++) {
    for (j = year[i - 1]; j <= 2011; j++)
      if (dif(year[i], j) <= 1) {
        year[i] = j;
        break;
      }
  }
  if (valid()) printAns();
  cout << "No solution\n";
  return 0;
}
