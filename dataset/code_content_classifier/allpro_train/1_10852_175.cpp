#include <bits/stdc++.h>
using namespace std;
const double pi = 2 * acos(0.0);
const string alphabetU = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string alphabetL = "abcdefghijklmnopqrstuvwxyz";
const double EPS = 1e-9;
const int INF = 1 << 28;
const long long INFL = 1LL << 62;
const double INFD = 1e+20;
int in() {
  int r = 0, c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') return -in();
  for (; c > 32; r = (r << 1) + (r << 3) + c - '0', c = getchar())
    ;
  return r;
}
int inl() {
  long long r = 0, c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') return -in();
  for (; c > 32; r = (r << 1) + (r << 3) + c - '0', c = getchar())
    ;
  return r;
}
string ins() {
  string s;
  while (!feof(stdin)) {
    char c = fgetc(stdin);
    if (c == 13) continue;
    if (c == 10) return s;
    s += c;
  }
  return s;
}
void getline(char* entry) {
  char c;
  string s;
  while ((c = getchar()) != '\n') s += c;
  strcpy(entry, s.c_str());
}
int toi(string x) {
  int z;
  istringstream iss(x);
  iss >> z;
  return z;
}
string str[] = {"YES", "NO"};
int modulo(int m, int n) { return m >= 0 ? m % n : (n - abs(m % n)) % n; }
int main() {
  long long n, d, m, l, i;
  n = in();
  d = in();
  m = in();
  l = in();
  for (i = 0; i < n - 1; i++) {
    if ((i * m + l) / d * d + d < (i + 1) * m) break;
  }
  cout << (i * m + l) / d * d + d << endl;
}
