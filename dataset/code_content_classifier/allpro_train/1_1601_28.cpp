#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:40000000")
struct Item {
  Item(int cost, int delta, int amount)
      : first(cost), second(delta), z(amount) {}
  int first, second, z;
  inline bool operator<(const Item& other) const {
    double d1 = (double)first / z;
    double d2 = (double)other.first / other.z;
    return d1 < d2;
  }
  inline bool operator>(const Item& other) const {
    double d1 = (double)first / z;
    double d2 = (double)other.first / other.z;
    return d1 > d2;
  }
  inline void dec() { first -= second; }
};
int n, m, W;
int w[500000], c[500000], a[500000];
vector<Item> t;
long long integer;
double rest;
void grab(int left, int right, long long need) {
  int i = left, j = right, middle = (left + right) / 2;
  Item m = t[middle];
  while (i <= j) {
    while (t[i] < m) ++i;
    while (t[j] > m) j--;
    if (i <= j) {
      swap(t[i], t[j]);
      i++;
      j--;
    }
  }
  long long sum = 0;
  for (int(q) = (left); (q) < (i); ++(q)) sum += t[q].z;
  if (need <= sum) {
    if (left == right) {
      long long k = min(need, (long long)t[left].z);
      long long first = (long long)k * (long long)t[left].first;
      long long second = (long long)t[left].z;
      integer += first / second;
      first %= second;
      rest += (double)first / double(second);
      while (rest >= 1.0) {
        rest -= 1.0;
        integer++;
      }
    } else if (left < i)
      grab(left, i - 1, need);
    return;
  }
  int r = 0;
  for (int(q) = (left); (q) < (i); ++(q)) {
    integer += t[q].first;
    r += t[q].first;
  }
  if (i <= right) grab(i, right, need - sum);
}
int main() {
  cin >> n >> m >> W;
  for (int(i) = (0); (i) < (m); ++(i)) scanf("%d", &w[i]);
  for (int(i) = (0); (i) < (m); ++(i)) scanf("%d", &c[i]);
  for (int(i) = (0); (i) < (m); ++(i)) scanf("%d", &a[i]);
  t.reserve(m);
  for (int(i) = (0); (i) < (m); ++(i)) {
    t.push_back(Item(c[i], a[i], w[i]));
  }
  integer = 0;
  rest = 0.0;
  for (int(q) = (1); (q) <= (n); ++(q)) {
    grab(0, m - 1, (long long)W);
    for (int(i) = (0); (i) < (m); ++(i)) t[i].dec();
  }
  char store[15];
  sprintf(store, "%.11Lf\n", rest);
  printf("%I64d%s\n", integer, store + 1);
}
