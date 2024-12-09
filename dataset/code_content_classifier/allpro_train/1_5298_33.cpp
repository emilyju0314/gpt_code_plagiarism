#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using vb = vector<bool>;
using vc = vector<char>;
using vd = vector<double>;
using vi = vector<int>;
using vvi = vector<vi>;
using vlli = vector<lli>;
using vvlli = vector<vlli>;
using pi = pair<int, int>;
using plli = pair<lli, lli>;
char readc() {
  char q;
  scanf("%c", &q);
  return q;
}
int readint() {
  int q;
  scanf("%d", &q);
  return q;
}
lli readlong() {
  lli q;
  scanf("%lld", &q);
  return q;
}
double readdbl() {
  double q;
  scanf("%lf", &q);
  return q;
}
void printint(int q) { printf("%d", q); }
void printlong(lli q) { printf("%lld", q); }
void printdbl(double q, int p = 6) { printf("%.*lf", p, q); }
void readln() { scanf("\n"); }
void println() { printf("\n"); }
void printsp() { printf(" "); }
void print(int q) { printint(q); }
void print(long q) { printlong((lli)q); }
void print(lli q) { printlong(q); }
void print(double q) { printdbl(q); }
void print(char c) { printf("%c", c); }
template <typename T>
void println(T q) {
  print(q);
  println();
}
template <typename T>
T maxim(T f, T s) {
  return (f > s) ? f : s;
}
template <typename T>
T minim(T f, T s) {
  return (f < s) ? f : s;
}
template <typename T>
T abs(T arg) {
  return arg < 0 ? -arg : arg;
}
bool known[101];
bool zero[101];
int a[101];
int queries[101];
map<int, int> sums;
vector<pi> results;
pi query(int x) {
  cout << "+ " << x << endl;
  cout.flush();
  int r1 = readint();
  int r2 = readint();
  if (r1 != results.rbegin()->first) {
    known[x] = true;
    a[x] = sums[r1 - results.rbegin()->first] - queries[x];
    zero[x] = (a[x] == 0);
  }
  queries[x]++;
  results.push_back(make_pair(r1, r2));
  return *results.rbegin();
}
int main() {
  for (int i = 0; i < 100; ++i) sums[(i + 2) * (i + 1) / 2] = i + 2;
  int n = readint();
  int x1 = readint();
  int x2 = readint();
  pi r0 = make_pair(x1, x2);
  results.push_back(r0);
  auto r1 = query(1);
  auto r2 = query(2);
  auto r3 = query(3);
  auto r4 = query(1);
  int X = r1.second - r0.second;
  int Y = r2.second - r1.second;
  int Z = r4.second - r3.second;
  int W = r3.second - r2.second;
  if (!known[1]) {
    known[1] = true;
    a[1] = 0;
  }
  if (known[2] && !known[3]) {
    known[3] = true;
    a[3] = X / a[2];
  }
  if (known[3] && !known[2]) {
    known[2] = true;
    a[2] = X / a[3];
  }
  if (!known[2] && !known[3]) {
    if (Y == 0) {
      a[3] = 0;
      a[2] = Z - X - 1;
    } else {
      if (X == 0) {
        a[2] = 0;
        a[3] = Z - X - 1;
      } else {
        a[2] = 1;
        a[3] = 1;
      }
    }
  }
  known[2] = known[3] = true;
  zero[4] = (W - (a[1] + 1) * (a[2] + 1) == 0);
  for (int i = 0; i < n - 4; ++i) {
    int last3 = results.rbegin()->second;
    auto r = query(i + 4);
    if (zero[i + 4]) {
      known[i + 4] = true;
      a[i + 4] = 0;
    }
    if (!known[i + 4]) {
      known[i + 4] = true;
      a[i + 4] = 1;
    }
    X = r.second - last3;
    zero[i + 5] = (X - (a[i + 2] + 1) * (a[i + 3] + 1) == 0);
  }
  int last3 = results.rbegin()->second;
  int sum = 0;
  for (int i = 1; i <= n - 3; ++i)
    sum += (a[i] + queries[i]) * (a[i + 1] + queries[i + 1]) *
           (a[i + 2] + queries[i + 2]);
  a[n] = (last3 - sum) / (a[n - 1] + 1) / (a[n - 2] + 1);
  cout << "!";
  for (int i = 0; i < n; ++i) cout << " " << a[i + 1];
  println();
  return 0;
}
