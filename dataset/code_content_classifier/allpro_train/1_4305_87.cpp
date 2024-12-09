#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
static const double PI2 = 8.0 * atan(1.0);
template <class T>
T MIN(const T& a, const T& b) {
  return a < b ? a : b;
}
template <class T>
T MAX(const T& a, const T& b) {
  return a > b ? a : b;
}
template <class T>
void MIN_UPDATE(T& a, const T& b) {
  if (a > b) a = b;
}
template <class T>
void MAX_UPDATE(T& a, const T& b) {
  if (a < b) a = b;
}
int main() {
  int N;
  cin >> N;
  vector<string> ss;
  for (int n = 0; n < (int)N; ++n) {
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size(); ++i) {
      s[i] = tolower(s[i]);
    }
    ss.push_back(s);
  }
  string w;
  cin >> w;
  bool upper[128];
  memset(upper, 0, sizeof(upper));
  for (int i = 0; i < (int)w.size(); ++i) {
    upper[i] = isupper(w[i]) != 0;
    w[i] = tolower(w[i]);
  }
  int replaced[128];
  memset(replaced, 0, sizeof(replaced));
  for (int i = 0; i < (int)ss.size(); ++i) {
    const string& s = ss[i];
    size_t offset = 0;
    while ((offset = w.find(s, offset)) != string::npos) {
      fill_n(replaced + offset, s.size(), true);
      ++offset;
    }
  }
  char lucky;
  cin >> lucky;
  char next = 'a';
  if (lucky == 'a') {
    next = 'b';
  }
  for (int i = 0; i < (int)w.size(); ++i) {
    if (!replaced[i]) {
      continue;
    }
    char& ch = w[i];
    if (ch == lucky) {
      ch = next;
    } else {
      ch = lucky;
    }
  }
  for (int i = 0; i < (int)w.size(); ++i) {
    if (upper[i]) {
      w[i] = toupper(w[i]);
    }
  }
  cout << w << endl;
}
