#include <bits/stdc++.h>
using namespace std;
template <typename T>
T MAX(T a, T b) {
  return (a > b) ? a : b;
}
template <typename T>
T MIN(T a, T b) {
  return (a < b) ? a : b;
}
template <typename T>
void UMAX(T &a, T b) {
  a = (a > b ? a : b);
}
template <typename T>
void UMIN(T &a, T b) {
  a = (a < b ? a : b);
}
int readint() {
  char c = getchar();
  int ret = 0;
  while (!(c >= '0' && c <= '9')) c = getchar();
  while (c >= '0' && c <= '9') {
    ret = ret * 10 + c - '0';
    c = getchar();
  }
  return ret;
}
void putint(int v) {
  if (!v) {
    putchar('0');
    return;
  }
  if (v >= 10) putint(v / 10);
  putchar('0' + (v % 10));
}
int gettp(char c) {
  if (c == ' ' || c == '\t' || c == '\n') return 0;
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return 7;
  if (c >= '0' && c <= '9') return 8;
  return c == '+'
             ? 1
             : (c == '-'
                    ? 2
                    : (c == '*' ? 3 : (c == '/' ? 4 : (c == '(' ? 5 : 6))));
}
void mygetline(string &str) {
  char c = getchar();
  while (c == '\n') c = getchar();
  str.clear();
  while (c != '\n') {
    str.push_back(c);
    c = getchar();
  }
}
int cnt = 7;
bool sus[100005], adt[100005], whl[100005];
void readmacro(string &name, string &expr) {
  string str;
  mygetline(str);
  name.clear();
  expr.clear();
  int i, countdown = 7;
  for (i = 0; i < (int)str.size(); ++i) {
    if (gettp(str[i])) --countdown;
    if (countdown < 0) break;
  }
  for (; i < (int)str.size(); ++i) {
    if (gettp(str[i]))
      name.push_back(str[i]);
    else
      break;
  }
  for (; i < (int)str.size(); ++i) {
    if (gettp(str[i])) expr.push_back(str[i]);
  }
}
map<string, int> macros;
int getid(string s) {
  if (gettp(s[0]) == 8) return 0;
  if (gettp(s[0]) != 7) return gettp(s[0]);
  return macros[s];
}
vector<int> refine(string s) {
  vector<int> ret(0);
  int i, j, k;
  for (i = 0; i < (int)s.size();) {
    for (j = i; j < (int)s.size(); ++j) {
      if (gettp(s[i]) >= 1 && gettp(s[i]) <= 6 && j > i) break;
      if (gettp(s[j]) != gettp(s[i])) break;
    }
    if (gettp(s[i])) ret.push_back(getid(s.substr(i, j - i)));
    i = j;
  }
  return ret;
}
int bra(int e) {
  sus[cnt] = sus[e];
  adt[cnt] = 0;
  whl[cnt] = 1;
  return cnt++;
}
int con(int e, int f, int o) {
  if (o == 1) {
    sus[cnt] = (sus[e] || sus[f]);
    adt[cnt] = 1;
    whl[cnt] = 0;
  } else if (o == 2) {
    sus[cnt] = (sus[e] || sus[f] || adt[f]);
    adt[cnt] = 1;
    whl[cnt] = 0;
  } else if (o == 3) {
    sus[cnt] = (sus[e] || sus[f] || adt[e] || adt[f]);
    adt[cnt] = 0;
    whl[cnt] = 0;
  } else {
    sus[cnt] = (sus[e] || sus[f] || (!whl[f]) || adt[f] || adt[e]);
    adt[cnt] = 0;
    whl[cnt] = 0;
  }
  return cnt++;
}
int calc(vector<int> vec) {
  if ((int)vec.size() == 1) {
    assert(vec[0] >= 7 || vec[0] == 0);
    return vec[0];
  }
  int i, j, k, dep = 0, mnd = 1;
  for (i = 0; i < (int)vec.size(); ++i) {
    if (vec[i] == 5)
      ++dep;
    else if (vec[i] == 6)
      --dep;
    if (i && i < (int)vec.size() - 1) UMIN(mnd, dep);
  }
  if (mnd) {
    vec.pop_back();
    reverse(vec.begin(), vec.end());
    vec.pop_back();
    reverse(vec.begin(), vec.end());
    return bra(calc(vec));
  }
  vector<int> cursuf(0), nvec(0);
  for (i = 0; i < (int)vec.size(); ++i) {
    if (vec[i] == 5) ++dep;
    if (dep)
      cursuf.push_back(vec[i]);
    else
      nvec.push_back(vec[i]);
    if (vec[i] == 6) {
      --dep;
      if (!dep) {
        nvec.push_back(calc(cursuf));
        cursuf.clear();
      }
    }
  }
  assert(cursuf.empty() && dep == 0);
  for (i = (int)nvec.size() - 1; i >= 0; --i) {
    if (nvec[i] == 1 || nvec[i] == 2) {
      vector<int> L(0), R(0);
      for (j = 0; j < i; ++j) L.push_back(nvec[j]);
      for (j = i + 1; j < (int)nvec.size(); ++j) R.push_back(nvec[j]);
      return con(calc(L), calc(R), nvec[i]);
    }
  }
  for (i = (int)nvec.size() - 1; i >= 0; --i) {
    if (nvec[i] == 3 || nvec[i] == 4) {
      vector<int> L(0), R(0);
      for (j = 0; j < i; ++j) L.push_back(nvec[j]);
      for (j = i + 1; j < (int)nvec.size(); ++j) R.push_back(nvec[j]);
      return con(calc(L), calc(R), nvec[i]);
    }
  }
  assert(0);
}
int n;
int main() {
  whl[0] = 1;
  int i, j, k;
  scanf("%d", &n);
  string name, expr;
  for (i = 0; i < n; ++i) {
    readmacro(name, expr);
    vector<int> R = refine(expr);
    macros[name] = calc(refine(expr));
  }
  mygetline(expr);
  int d = calc(refine(expr));
  if (sus[d])
    printf("Suspicious\n");
  else
    printf("OK\n");
  return 0;
}
