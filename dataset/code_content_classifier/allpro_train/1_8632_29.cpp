#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return {i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
using ll = long long;
constexpr int nax = 200 * 1000 + 105;
bool wziety[nax];
vector<int> gdzie[nax];
struct Drzewo {
  set<int, greater<int>> kolory;
  int max_kolor = -1;
  int min_kolor = 0;
  void Przelicz(Drzewo& l, Drzewo& r) {
    max_kolor = max(l.max_kolor, r.max_kolor);
    min_kolor = min(l.min_kolor, r.min_kolor);
    if (!kolory.empty()) {
      const int kolor = *kolory.begin();
      if (kolor > min_kolor) {
        max_kolor = max(max_kolor, kolor);
        if (wziety[kolor] and max_kolor == kolor) {
          max_kolor = -1;
        }
        min_kolor = kolor;
      } else {
      }
    }
  }
  void DodajKolor(bool czy_dod, int kolor) {
    if (czy_dod) {
      const bool ok = kolory.insert(kolor).second;
      assert(ok);
    } else {
      auto it = kolory.find(kolor);
      assert(it != kolory.end());
      kolory.erase(it);
    }
  }
};
int n2;
Drzewo drz[nax * 2 * 2 * 2];
void Pozbieraj() {
  while (true) {
    const int kolor = drz[1].max_kolor;
    if (kolor == -1) break;
    assert(!wziety[kolor]);
    wziety[kolor] = true;
    for (int w : gdzie[kolor]) {
      drz[w].Przelicz(drz[w * 2], drz[w * 2 + 1]);
    }
  }
}
void Wrzuc(int w, int p, int k, int a, int b, bool czy_dod, int kolor) {
  if (k < a or b < p) return;
  if (a <= p and k <= b) {
    drz[w].DodajKolor(czy_dod, kolor);
    drz[w].Przelicz(drz[w * 2], drz[w * 2 + 1]);
    gdzie[kolor].push_back(w);
    return;
  }
  Wrzuc(w * 2, p, (p + k) / 2, a, b, czy_dod, kolor);
  Wrzuc(w * 2 + 1, (p + k) / 2 + 1, k, a, b, czy_dod, kolor);
  gdzie[kolor].push_back(w);
  drz[w].Przelicz(drz[w * 2], drz[w * 2 + 1]);
}
void Wydarz(bool czy_otw, int id, int y1, int y2) {
  assert(1 <= id);
  assert(0 <= y1 and y1 <= y2 and y2 < n2);
  Wrzuc(1, 0, n2 - 1, y1, y2, czy_otw, id);
}
vector<pair<int, pair<int, int>>> zdarzenia[nax];
int main() {
  int n;
  scanf("%d", &n);
  vector<int> numx, numy;
  vector<pair<pair<int, int>, pair<int, int>>> prostokaty;
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    numx.push_back(x1);
    numx.push_back(x2);
    numy.push_back(y1);
    numy.push_back(y2);
    prostokaty.emplace_back(make_pair(x1, x2), make_pair(y1, y2));
  }
  sort(numx.begin(), numx.end());
  numx.resize(unique(numx.begin(), numx.end()) - numx.begin());
  sort(numy.begin(), numy.end());
  numy.resize(unique(numy.begin(), numy.end()) - numy.begin());
  n2 = 1;
  while (n2 < (int)numy.size()) n2 *= 2;
  for (int i = 0; i < n; i++) {
    auto& p = prostokaty[i];
    int x1 = p.first.first;
    int x2 = p.first.second;
    int y1 = p.second.first;
    int y2 = p.second.second;
    for (int* x : {&x1, &x2}) {
      *x = lower_bound(numx.begin(), numx.end(), *x) - numx.begin();
    }
    for (int* y : {&y1, &y2}) {
      *y = lower_bound(numy.begin(), numy.end(), *y) - numy.begin();
    }
    y2--;
    zdarzenia[x1].emplace_back(+(i + 1), make_pair(y1, y2));
    zdarzenia[x2].emplace_back(-(i + 1), make_pair(y1, y2));
  }
  for (int i = 0; i < (int)numx.size(); i++) {
    for (auto& z : zdarzenia[i]) {
      Wydarz(z.first > 0, abs(z.first), z.second.first, z.second.second);
    }
    Pozbieraj();
  }
  int wynik = 0;
  for (int i = 1; i <= n; i++) {
    wynik += wziety[i];
  }
  printf("%d\n", wynik + 1);
  return 0;
}
