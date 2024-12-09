#include <bits/stdc++.h>
using namespace std;
int a, b, c;
bool likes[7][7];
const char *const names[] = {"Anka",   "Chapay", "Cleo",        "Troll",
                             "Dracul", "Snowy",  "Hexadecimal", 0};
int getidx(const std::string &name) {
  for (const char *const *i = names; *i; i++) {
    if (name == *i) return i - names;
  }
}
int groupid[7];
long long ansdiff = LLONG_MAX;
int anssym = 0;
void test() {
  long long diff = 0;
  int sym = 0;
  int gc[3] = {0};
  for (int i = 0; i < 7; i++) {
    gc[groupid[i]]++;
    for (int j = 0; j < 7; j++) {
      if (groupid[i] == groupid[j] && likes[i][j]) {
        sym++;
      }
    }
  }
  long long sc[3] = {a, b, c};
  long long ansmax = 0, ansmin = LLONG_MAX;
  for (int i = 0; i < 3; i++) {
    if (gc[i] == 0) return;
    sc[i] /= gc[i];
    if (sc[i] > ansmax) ansmax = sc[i];
    if (sc[i] < ansmin) ansmin = sc[i];
  }
  diff = ansmax - ansmin;
  if (diff < ansdiff || (diff == ansdiff && sym > anssym)) {
    ansdiff = diff;
    anssym = sym;
  }
}
void perebor(int i) {
  if (i == 7) {
    test();
    return;
  }
  for (int j = 0; j < 3; j++) {
    groupid[i] = j;
    perebor(i + 1);
  }
}
int main(void) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string p, w, q;
    cin >> p >> w >> q;
    likes[getidx(p)][getidx(q)] = true;
  }
  cin >> a >> b >> c;
  perebor(0);
  cout << ansdiff << ' ' << anssym;
}
