#include <bits/stdc++.h>
using namespace std;
int n, m, number;
long long ans;
set<int> zeroes[18], ones[18];
set<int>::iterator my_it;
void fullfill(int number, int pos) {
  int k = 1;
  int d = -1;
  while (d < 19) {
    d++;
    if (d == 18) return;
    if (k & number) {
      ones[d].insert(pos);
    } else {
      zeroes[d].insert(pos);
    }
    k <<= 1;
  }
}
void refreshAns(int pos, int value) {
  long long k = 1;
  int d = -1;
  while (d < 19) {
    d++;
    if (d == 18) return;
    if (k & value) {
      my_it = ones[d].lower_bound(pos);
      if (*my_it != pos) {
        set<int>::iterator m_it = zeroes[d].lower_bound(pos);
        my_it = m_it;
        long long r = *++m_it;
        long long p = pos;
        long long l = *--my_it;
        ans += k * ((r - l - 1) * (r - l) - (p - l - 1) * (p - l) -
                    (r - p - 1) * (r - p));
        zeroes[d].erase(pos);
        ones[d].insert(pos);
      }
    } else {
      my_it = zeroes[d].lower_bound(pos);
      if (*my_it != pos) {
        long long p = pos;
        long long r = *my_it;
        long long l = *--my_it;
        ans -= k * ((r - l - 1) * (r - l) - (r - p - 1) * (r - p) -
                    (p - l - 1) * (p - l));
        ones[d].erase(pos);
        zeroes[d].insert(pos);
      }
    }
    k <<= 1;
  }
}
void getAns() {
  long long value = 1;
  for (int i = 0; i < 18; i++) {
    int posO = 0;
    int posZA = -1;
    int posZB = -1;
    while (1) {
      posO = *ones[i].lower_bound(posO);
      if (posO == n) {
        break;
      }
      my_it = zeroes[i].upper_bound(posO);
      posZA = *my_it;
      posZB = (*--my_it);
      long long l = posZA;
      long long r = posZB;
      ans += value * (l - r - 1) * (l - r);
      posO = *zeroes[i].lower_bound(posO);
    }
    value *= 2;
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < 18; i++) {
    zeroes[i].insert(n);
    ones[i].insert(n);
    zeroes[i].insert(-1);
    ones[i].insert(-1);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &number);
    fullfill(number, i);
  }
  getAns();
  for (int i = 0; i < m; i++) {
    int pos, v;
    scanf("%d %d", &pos, &v);
    refreshAns(pos - 1, v);
    printf("%I64d\n", ans / 2);
  }
  return 0;
}
