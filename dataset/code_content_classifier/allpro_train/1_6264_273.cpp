#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e4;
const int mod = (int)1e9 + 7;
const int p1 = 1231723;
const int p2 = 92345;
pair<int, int> HashStr[N];
pair<int, int> deg[N];
pair<int, int> HashT[10][N];
string str;
string task[10];
int l[10], r[10];
int dp[N][10];
char zStr[N];
int z[N];
int good[N];
int lenEdge[N];
set<pair<int, int> > allStr;
int code(char c) { return c - 'a' + 1; }
int add(int a, int b) {
  if (a + b < mod)
    return a + b;
  else if (a + b >= mod)
    return a + b - mod;
  return a + b + mod;
}
int mult(int a, int b) {
  long long c = (long long)a * (long long)b;
  return (int)(c % (long long)mod);
}
pair<int, int> neg(pair<int, int> a) {
  return make_pair(mod - a.first, mod - a.second);
}
pair<int, int> add(pair<int, int> a, pair<int, int> b) {
  return make_pair(add(a.first, b.first), add(a.second, b.second));
}
pair<int, int> mult(pair<int, int> a, pair<int, int> b) {
  return make_pair(mult(a.first, b.first), mult(a.second, b.second));
}
void calcDeg() {
  deg[0] = make_pair(1, 1);
  for (int i = 1; i < N; i++) deg[i] = mult(deg[i - 1], make_pair(p1, p2));
}
void calcHashStr() {
  HashStr[0] = make_pair(code(str[0]), code(str[0]));
  for (int i = 1; i < (int)str.length(); i++)
    HashStr[i] = add(HashStr[i - 1],
                     mult(deg[i], make_pair(code(str[i]), code(str[i]))));
}
void calcHash(string cS, int ind) {
  HashT[ind][0] = make_pair(code(cS[0]), code(cS[0]));
  for (int i = 1; i < (int)cS.length(); i++)
    HashT[ind][i] = add(HashT[ind][i - 1],
                        mult(deg[i], make_pair(code(cS[i]), code(cS[i]))));
}
pair<int, int> getHashStr(int a, int b) {
  pair<int, int> res =
      add(HashStr[b], (a == 0 ? make_pair(0, 0) : neg(HashStr[a - 1])));
  res = mult(res, deg[N - a - 1]);
  return res;
}
pair<int, int> getHashT(int ind) {
  pair<int, int> res = HashT[ind][(int)task[ind].length() - 1];
  res = mult(res, deg[N - 1]);
  return res;
}
void calcZ(int len) {
  z[0] = 0;
  int l = 0, r = 0;
  for (int i = 1; i < len; i++) {
    z[i] = 0;
    if (i <= r) z[i] = min(z[i - l], r - i + 1);
    while (z[i] + i < len && zStr[i + z[i]] == zStr[z[i]]) z[i]++;
    if (i + z[i] - 1 > r) {
      r = i + z[i] - 1;
      l = i;
    }
  }
}
int main() {
  calcDeg();
  cin >> str;
  calcHashStr();
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> task[i];
    cin >> l[i] >> r[i];
  }
  for (int i = 0; i < (int)str.length(); i++) {
    for (int s = 0; s < (int)str.length(); s++) good[s] = 0;
    for (int s = 0; s < (int)str.length() - i; s++) zStr[s] = str[i + s];
    zStr[(int)str.length() - i] = '#';
    for (int k = 0; k < n; k++) {
      for (int q = 0; q < (int)task[k].length(); q++)
        zStr[(int)str.length() - i + 1 + q] = task[k][q];
      calcZ((int)str.length() - i + (int)task[k].length() + 1);
      int ind = 0;
      for (int s = (int)str.length() - i + 1;
           s < (int)str.length() - i + (int)task[k].length() + 1; s++)
        lenEdge[ind++] = z[s];
      sort(lenEdge, lenEdge + ind);
      int ptr = 0;
      for (int len = 1; len <= (int)str.length() - i; len++) {
        while (ptr < ind && lenEdge[ptr] < len) ptr++;
        if (ind - ptr >= l[k] && ind - ptr <= r[k]) good[len]++;
      }
    }
    for (int len = 1; len <= (int)str.length() - i; len++) {
      if (good[len] == n) {
        pair<int, int> curHash = getHashStr(i, i + len - 1);
        if (allStr.find(curHash) == allStr.end()) {
          allStr.insert(curHash);
        }
      }
    }
  }
  cout << allStr.size();
  return 0;
}
