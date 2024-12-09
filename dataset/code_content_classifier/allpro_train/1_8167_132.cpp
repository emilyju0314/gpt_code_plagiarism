#include <bits/stdc++.h>
using namespace std;
template <typename T, typename TT>
ostream &operator<<(ostream &s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream &operator<<(ostream &s, vector<T> t) {
  s << "{";
  for (int i = 0; i < t.size(); i++)
    s << t[i] << (i == t.size() - 1 ? "" : ",");
  return s << "}" << endl;
}
const int id = 0;
inline int F(int a, int b) { return a + b; }
template <typename T, typename A>
struct WDrzewiec {
  T klucz;
  A dod;
  A suma;
  WDrzewiec *l;
  WDrzewiec *r;
  int pr;
  WDrzewiec(T _klucz, A _dod) {
    klucz = _klucz;
    dod = _dod;
    suma = _dod;
    l = r = NULL;
    pr = rand();
  }
  inline void aktualizuj(WDrzewiec *&t) {
    t->suma = id;
    if (t->l != NULL) t->suma = F(t->suma, t->l->suma);
    t->suma = F(t->suma, t->dod);
    if (t->r != NULL) t->suma = F(t->suma, t->r->suma);
  }
  inline void rot_lewo(WDrzewiec *&k2) {
    WDrzewiec *k1 = k2->l;
    k2->l = k1->r;
    k1->r = k2;
    k2 = k1;
    aktualizuj(k1->r);
    aktualizuj(k1);
  }
  inline void rot_prawo(WDrzewiec *&k1) {
    WDrzewiec *k2 = k1->r;
    k1->r = k2->l;
    k2->l = k1;
    k1 = k2;
    aktualizuj(k2->l);
    aktualizuj(k2);
  }
  bool usun(T _klucz, WDrzewiec *&t) {
    if (t == NULL) return 0;
    if (_klucz < t->klucz) {
      if (usun(_klucz, t->l)) {
        aktualizuj(t);
        return 1;
      }
      return 0;
    } else if (_klucz > t->klucz) {
      if (usun(_klucz, t->r)) {
        aktualizuj(t);
        return 1;
      }
      return 0;
    } else {
      ubij(t);
      return 1;
    }
  }
  void ubij(WDrzewiec *&t) {
    if (t->l == NULL) {
      WDrzewiec *temp = t->r;
      delete t;
      t = temp;
      return;
    } else if (t->r == NULL) {
      WDrzewiec *temp = t->l;
      delete t;
      t = temp;
      return;
    } else {
      if (t->l->pr < t->r->pr) {
        rot_lewo(t);
        ubij(t->r);
      } else {
        rot_prawo(t);
        ubij(t->l);
      }
      aktualizuj(t);
    }
  }
  inline void dodaj(T _klucz, A _dod, WDrzewiec *&t) {
    if (t == NULL)
      t = new WDrzewiec(_klucz, _dod);
    else if (_klucz < t->klucz) {
      dodaj(_klucz, _dod, t->l);
      if (t->l->pr < t->pr)
        rot_lewo(t);
      else
        aktualizuj(t);
    } else if (_klucz > t->klucz) {
      dodaj(_klucz, _dod, t->r);
      if (t->r->pr < t->pr)
        rot_prawo(t);
      else
        aktualizuj(t);
    } else {
      t->dod = F(t->dod, _dod);
      aktualizuj(t);
    }
  }
  A sumuj(T _mx, WDrzewiec *t) {
    A wyn1 = id;
    while (t != NULL) {
      if (t->klucz <= _mx) {
        if (t->l != NULL) wyn1 = F(wyn1, t->l->suma);
        if (t->klucz <= _mx) wyn1 = F(wyn1, t->dod);
        t = t->r;
      } else
        t = t->l;
    }
    return wyn1;
  }
  void wywal(WDrzewiec *&t) {
    if (t == NULL) return;
    if (t->l) wywal(t->l);
    if (t->r) wywal(t->r);
    delete t;
  }
  void wypisz(WDrzewiec *t) {
    if (t == NULL) {
      return;
    }
    cout << make_pair(t->klucz, t->pr) << " " << t->dod << " " << t->suma << " "
         << endl;
    wypisz(t->l);
    wypisz(t->r);
  }
};
template <typename T, typename A>
struct Drzewiec {
  WDrzewiec<T, A> *korzen;
  Drzewiec() { korzen = NULL; }
  bool usun(T _klucz) { return korzen->usun(_klucz, korzen); }
  void dodaj(T _klucz, A _dod) { korzen->dodaj(_klucz, _dod, korzen); }
  A sumuj(T _mx) { return korzen->sumuj(_mx, korzen); }
  void wyczysc() {
    korzen->wywal(korzen);
    korzen = NULL;
  }
  void wypisz() { korzen->wypisz(korzen); }
};
long long tab[200000 + 2];
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  long long k;
  cin >> k;
  for (int i = 0; i < n; i++) cin >> tab[i];
  for (int i = 0; i < n; i++) tab[i] *= -1;
  long long lo = -n * 1000000001LL, hi = n * 1000000001LL, mid;
  while (hi - lo > 1) {
    mid = (hi + lo) / 2;
    long long sum = 0;
    Drzewiec<long long, int> d;
    d.dodaj(0, 1);
    long long ile = 0;
    for (int i = 0; i < n; i++) {
      sum += tab[i];
      int z = i + 1 - d.sumuj(sum - mid - 1);
      ile += z;
      d.dodaj(sum, 1);
      if (ile >= k) {
        break;
      }
    }
    if (ile >= k)
      hi = mid;
    else
      lo = mid;
  }
  cout << -hi << "\n";
  return 0;
}
