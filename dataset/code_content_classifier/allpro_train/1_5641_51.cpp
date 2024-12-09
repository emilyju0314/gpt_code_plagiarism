#include <bits/stdc++.h>
using namespace std;
const int T = 1 << 20;
long long lazy[T + T], tree[T + T];
const int duzo = int(1e9) + 100;
long long wynik;
int A, l, r;
int m;
void up(int a, int lewy, int prawy) {
  if (lewy < prawy) {
    lazy[a * 2] += lazy[a];
    lazy[a * 2 + 1] += lazy[a];
  }
  tree[a] += lazy[a];
  lazy[a] = 0;
}
void update(int a, int lewy, int prawy) {
  if (lewy < prawy) {
    lazy[a * 2] += lazy[a];
    lazy[a * 2 + 1] += lazy[a];
    up(a * 2, lewy, (lewy + prawy) / 2);
    up(a * 2 + 1, (lewy + prawy) / 2 + 1, prawy);
    lazy[a] = 0;
    tree[a] = min(tree[a * 2], tree[a * 2 + 1]);
  } else
    up(a, lewy, prawy);
}
long long mini(int left, int right, int a = 1, int lewy = 0, int prawy = m) {
  if (a == 1) wynik = 1e18;
  up(a, lewy, prawy);
  if (left <= lewy && right >= prawy) {
    if (wynik > tree[a]) {
      wynik = tree[a];
      A = a;
      l = lewy;
      r = prawy;
    }
    return tree[a];
  } else {
    long long ret = 0;
    if (left <= (lewy + prawy) / 2)
      ret = min(ret, mini(left, right, a * 2, lewy, (lewy + prawy) / 2));
    if (right > (lewy + prawy) / 2)
      ret =
          min(ret, mini(left, right, a * 2 + 1, (lewy + prawy) / 2 + 1, prawy));
    return ret;
  }
}
void add(int left, int right, long long x, int a = 1, int lewy = 0,
         int prawy = m) {
  up(a, lewy, prawy);
  if (left <= lewy && right >= prawy) {
    lazy[a] += x;
  } else {
    if (left <= (lewy + prawy) / 2)
      add(left, right, x, a * 2, lewy, (lewy + prawy) / 2);
    if (right > (lewy + prawy) / 2)
      add(left, right, x, a * 2 + 1, (lewy + prawy) / 2 + 1, prawy);
  }
  update(a, lewy, prawy);
}
int search(int a, int lewy, int prawy) {
  while (lewy < prawy) {
    update(a, lewy, prawy);
    if (tree[a * 2] < tree[a * 2 + 1]) {
      a *= 2;
      prawy = (lewy + prawy) / 2;
    } else {
      a = a * 2 + 1;
      lewy = (lewy + prawy) / 2 + 1;
    }
  }
  return lewy;
}
vector<int> liczby;
vector<int> kor;
map<int, int> mapa;
int main() {
  int n;
  scanf("%d", &n);
  vector<pair<pair<int, int>, long long> > pkt(n);
  liczby.resize(n * 2);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %lld", &pkt[i].first.first, &pkt[i].first.second,
          &pkt[i].second);
    liczby[i * 2] = pkt[i].first.first;
    liczby[i * 2 + 1] = pkt[i].first.second;
  }
  sort(liczby.begin(), liczby.end());
  int y = 0, z = 0;
  m = 0;
  kor.push_back(0);
  mapa[0] = 0;
  for (int x : liczby) {
    if (x > y) {
      y = x;
      kor.push_back(y);
      z++;
      m++;
      mapa[y] = z;
    }
  }
  for (auto &p : pkt) {
    p.first.first = mapa[p.first.first];
    p.first.second = mapa[p.first.second];
  }
  for (int i = 0; i < n; i++) {
    int a = max(pkt[i].first.first, pkt[i].first.second);
    int b = min(pkt[i].first.first, pkt[i].first.second);
    pkt[i].first.first = a;
    pkt[i].first.second = b;
  }
  for (int i = 0; i < m + 1; i++) {
    add(i, i, -kor[i]);
  }
  sort(pkt.begin(), pkt.end());
  long long res = 0LL;
  int x1, x2;
  x1 = x2 = duzo;
  y = 0;
  long long sum = 0LL;
  for (int i = 0; i < m + 1; i++) {
    while (y < n && pkt[y].first.first == i) {
      sum += pkt[y].second;
      add(pkt[y].first.second + 1, m, pkt[y].second);
      y++;
    }
    long long d = mini(0, i);
    int pos = search(A, l, r);
    long long r = sum - d - kor[i];
    if (res < r) {
      res = r;
      x2 = kor[i];
      x1 = kor[pos];
    }
  }
  printf("%lld\n%d %d %d %d\n", res, x1, x1, x2, x2);
}
