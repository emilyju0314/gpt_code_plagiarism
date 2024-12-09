#include <bits/stdc++.h>
using namespace std;
string s1 = "qwertyuiop";
string s2 = "asdfghjkl;";
string s3 = "zxcvbnm,./";
map<char, char> init(char c) {
  map<char, char> ret;
  if (c == 'R') {
    for (int i = 0; i < 9; ++i) {
      ret[s1[i + 1]] = s1[i];
      ret[s2[i + 1]] = s2[i];
      ret[s3[i + 1]] = s3[i];
    }
  } else {
    for (int i = 0; i < 9; ++i) {
      ret[s1[i]] = s1[i + 1];
      ret[s2[i]] = s2[i + 1];
      ret[s3[i]] = s3[i + 1];
    }
  }
  return ret;
}
int a[100005] = {0};
int p[100005] = {0};
int main() {
  int n, m;
  cin >> n >> m;
  if (m % n != 0) {
    cout << -1;
  } else {
    int num = m / n;
    int count = 0;
    while (num % 2 == 0) {
      num /= 2;
      count++;
    }
    while (num % 3 == 0) {
      num /= 3;
      count++;
    }
    if (num == 1)
      cout << count;
    else
      cout << -1;
  }
  return 0;
}
