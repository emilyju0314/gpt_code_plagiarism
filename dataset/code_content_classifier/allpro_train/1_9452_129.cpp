#include <bits/stdc++.h>
using namespace std;
int l;
int st, dr;
char s[100005];
int a[100005], b[100005], sum[100005];
int aux[100005];
int comp(int v1[], int v2[]);
void copi();
void f(int st, int dr);
void rev(int v[]);
void correct();
void add();
int main() {
  cin >> l;
  cin >> (s + 1);
  st = l / 2;
  dr = st + 1;
  if (s[dr] == '0') {
    correct();
    f(st - 1, st);
    rev(a);
    rev(b);
    add();
    copi();
    f(dr - 1, dr);
    rev(a);
    rev(b);
    add();
    if (comp(aux, sum) < 0) copi();
  } else {
    if (l % 2 == 0) {
      f(st, dr);
      rev(a);
      rev(b);
      add();
      copi();
    } else {
      f(st, dr);
      rev(a);
      rev(b);
      add();
      copi();
      ++st;
      ++dr;
      if (s[dr] != '0') {
        f(st, dr);
        rev(a);
        rev(b);
        add();
        if (comp(aux, sum) < 0) copi();
      }
    }
  }
  for (int i = sum[0]; i; --i) cout << int(sum[i]);
  return 0;
}
void copi() {
  sum[0] = aux[0];
  for (int i = 1; i <= aux[0]; ++i) sum[i] = aux[i];
}
int comp(int v1[], int v2[]) {
  if (v1[0] < v2[0]) return -1;
  if (v1[0] > v2[0]) return 1;
  for (int i = v1[0]; i; --i)
    if (v1[i] > v2[i])
      return 1;
    else if (v1[i] < v2[i])
      return -1;
  return 0;
}
void f(int st, int dr) {
  for (int i = 0; i <= l; ++i) a[i] = b[i] = 0;
  a[0] = st;
  for (int i = 1; i <= st; ++i) a[i] = s[i] - '0';
  b[0] = 0;
  for (int i = dr; i <= l; ++i) b[++b[0]] = s[i] - '0';
}
void rev(int v[]) {
  int lg = v[0];
  for (int i = 1; i <= lg / 2; ++i) swap(v[i], v[lg - i + 1]);
}
void add() {
  aux[0] = max(a[0], b[0]);
  int temp = 0;
  for (int i = 1; i <= aux[0]; ++i) {
    temp += (a[i] + b[i]);
    aux[i] = temp % 10;
    temp /= 10;
  }
  while (temp) {
    aux[++aux[0]] = temp % 10;
    temp /= 10;
  }
}
void correct() {
  while (s[dr] == '0') ++dr;
  while (s[st] == '0') --st;
}
