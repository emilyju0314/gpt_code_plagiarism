#include <bits/stdc++.h>
using namespace std;
map<string, int> type;
char buf[1000];
void getAmp(string s, int &amp, int &star, string &name) {
  amp = 0;
  while (s.size() && s[0] == '&') {
    s = s.substr(1);
    ++amp;
  }
  star = 0;
  while (s.size() && s[((int)((s).size())) - 1] == '*') {
    s = s.substr(0, ((int)((s).size())) - 1);
    ++star;
  }
  name = s;
}
int getType(string name, int amp, int star) {
  if (type.find(name) == type.end()) return -1;
  int k = type[name];
  if (k == -1) return -1;
  k += star - amp;
  if (k < 0) return -1;
  return k;
}
int main() {
  type["void"] = 0;
  int N;
  scanf("%d", &N);
  gets(buf);
  for (int i = 0; i < N; ++i) {
    gets(buf);
    istringstream ss(buf);
    string cmd, A, B;
    ss >> cmd;
    int amp, star;
    string name;
    if (cmd == "typeof") {
      ss >> A;
      getAmp(A, amp, star, name);
      int k = getType(name, amp, star);
      if (k == -1)
        printf("errtype\n");
      else {
        string res = "void";
        for (int j = 0; j < k; ++j) res += "*";
        printf("%s\n", res.c_str());
      }
    } else {
      ss >> A >> B;
      getAmp(A, amp, star, name);
      int k = getType(name, amp, star);
      type[B] = k;
    }
  }
  return 0;
};
