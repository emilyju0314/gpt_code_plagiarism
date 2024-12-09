#include <iostream>

using namespace std;

bool is(const string s) {
  for (int i = 0; i < s.size() / 2; ++i) {
    if (s[i] != s[s.size() - i - 1]) return false;
  }
  return true;
}

int main() {
  string s;
  cin >> s;
  puts(is(s) && is(s.substr(0, s.size() / 2)) && is(s.substr((s.size() + 1) / 2)) ? "Yes" : "No");
}
