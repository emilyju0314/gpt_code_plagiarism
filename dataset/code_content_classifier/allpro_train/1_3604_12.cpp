#include <bits/stdc++.h>
using namespace std;
string s1 = "a";
string s2 = "";
string s3 = "";
long long k = 1;
void f(long long n) {
  if (n == 2) {
    s3 = s3 + "a";
    return;
  }
  if (n == 1) return;
  if (n % 2 == 0) {
    f((n - 2) / 2);
    char p = k + 'a';
    s1 = s1 + p;
    s2 = p + s2;
    s3 = s3 + p + p;
  } else {
    f((n - 1) / 2);
    char p = k + 'a';
    s1 = s1 + p;
    s3 = s3 + p + p;
  }
  k++;
}
int main() {
  long long n;
  cin >> n;
  f(n);
  cout << s1 << s2 << "z" << s3 << " " << s1;
}
