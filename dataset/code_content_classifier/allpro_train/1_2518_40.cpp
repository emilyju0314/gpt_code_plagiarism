#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int NN = 272727;
char s[NN], t[NN];
vector<int> S, T;
vector<pii> ans;
int main() {
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  int fl = 0;
  if (s[1] != t[1]) fl = 1;
  int ls = strlen(s + 1);
  int lt = strlen(t + 1);
  int len = 1;
  for (int i = 2; i <= ls; i++) {
    if (s[i] != s[i - 1]) {
      S.push_back(len);
      len = 1;
    } else
      len++;
  }
  S.push_back(len);
  len = 1;
  for (int i = 2; i <= lt; i++) {
    if (t[i] != t[i - 1]) {
      T.push_back(len);
      len = 1;
    } else
      len++;
  }
  T.push_back(len);
  if (!fl and T.size() + S.size() == 7 and
      abs((int)T.size() - (int)S.size()) == 5) {
    cout << 3 << endl;
    int a, b, c, d, e, f, g;
    if (S.size() == 6) {
      a = S[0];
      b = S[1];
      c = S[2];
      d = S[3];
      e = S[4];
      f = S[5];
      g = T[0];
      cout << a + b + c << ' ' << 0 << endl;
      cout << d << ' ' << a << endl;
      cout << a + e << ' ' << d + b << endl;
      return 0;
    } else {
      a = T[0];
      b = T[1];
      c = T[2];
      d = T[3];
      e = T[4];
      f = T[5];
      g = S[0];
      cout << 0 << ' ' << a + b + c << endl;
      cout << a << ' ' << d << endl;
      cout << b + d << ' ' << a + e << endl;
      return 0;
    }
  }
  reverse(S.begin(), S.end());
  reverse(T.begin(), T.end());
  if (S.size() > T.size() + 1) {
    int give = S.size() - T.size();
    give = (give + 1) >> 1;
    int A = 0, B = 0;
    if ((fl == 0 and give & 1) or (fl and give % 2 == 0)) give++;
    if (give & 1)
      fl = 1;
    else
      fl = 0;
    B = T[T.size() - 1];
    for (int i = S.size() - give; i < S.size(); i++) A += S[i];
    S[S.size() - give - 1] += B;
    T.pop_back();
    if (!T.empty())
      T[T.size() - 1] += S[S.size() - give];
    else
      T.push_back(S[S.size() - give]);
    for (int i = S.size() - give + 1; i < S.size(); i++) T.push_back(S[i]);
    while (give--) S.pop_back();
    ans.push_back({A, B});
  }
  if (S.size() < T.size() - 1) {
    int give = T.size() - S.size();
    give = (give + 1) >> 1;
    int A = 0, B = 0;
    if ((fl == 0 and give & 1) or (fl and give % 2 == 0)) give++;
    if (give & 1)
      fl = 1;
    else
      fl = 0;
    A = S[S.size() - 1];
    for (int i = T.size() - give; i < T.size(); i++) B += T[i];
    T[T.size() - give - 1] += A;
    S.pop_back();
    if (!S.empty())
      S[S.size() - 1] += T[T.size() - give];
    else
      S.push_back(T[T.size() - give]);
    for (int i = T.size() - give + 1; i < T.size(); i++) S.push_back(T[i]);
    while (give--) T.pop_back();
    ans.push_back({A, B});
  }
  int A = 0, B = 0;
  if (fl == 0) {
    if (S.size() > T.size()) {
      A += S[S.size() - 1];
      S.pop_back();
    } else {
      B += T[T.size() - 1];
      T.pop_back();
    }
    ans.push_back({A, B});
    swap(A, B);
  }
  while (S.size() > 1 or T.size() > 1) {
    if (S.size()) A += S[S.size() - 1], S.pop_back();
    if (T.size()) B += T[T.size() - 1], T.pop_back();
    ans.push_back({A, B});
    swap(A, B);
  }
  cout << ans.size() << endl;
  for (pii p : ans) printf("%d %d\n", p.first, p.second);
  return 0;
}
