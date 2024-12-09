#include <bits/stdc++.h>
using namespace std;
struct fagocito {
  vector<int> v, s, a;
  void acumula() {
    a = vector<int>(s.size());
    for (int j = 0; j < int(s.size()); j++)
      a[j] = s[j] + (j > 0 ? a[j - 1] : 0);
  }
};
void escribir(fagocito &fag) {
  cout << "FAG: ";
  for (int i = 0; i < int(fag.v.size()); i++) {
    if (i > 0) {
      if (fag.s[i])
        cout << "|";
      else
        cout << ",";
    }
    cout << fag.v[i];
  }
  cout << endl;
}
int n;
int m[510][510];
int mm[510][510];
vector<int> fila[1000];
int conjunto[1000];
bool incluido(fagocito &fag, int i) {
  for (int jj = 0; jj < int(fag.v.size()); jj++)
    if (m[i][fag.v[jj]] == 0) return false;
  return true;
}
bool puede(fagocito &fag, int i) {
  if (int(fila[i].size()) == 0) return false;
  int conj = conjunto[fila[i][0]];
  for (int jj = 1; jj < int(fila[i].size()); jj++)
    if (conj != conjunto[fila[i][jj]]) return true;
  return false;
}
void morir() {
  cout << "NO" << endl;
  exit(0);
}
void completas(fagocito &fag) {
  while (int(fag.s.size()) < int(fag.v.size())) fag.s.push_back(0);
}
void meterconjunto0(fagocito &fag, int i) {
  bool metido = false;
  for (int jj = 0; jj < int(fila[i].size()); jj++) {
    int j = fila[i][jj];
    if (conjunto[j] == 0) {
      fag.v.push_back(j);
      metido = true;
    }
  }
  if (metido) {
    fag.s.push_back(1);
    completas(fag);
  }
}
void meterlosdedentro(fagocito &fag, fagocito &nextfag, int iv, int k, int i) {
  bool metido = false;
  for (; iv < int(fag.v.size()) and fag.a[iv] == k; iv++) {
    if (m[i][fag.v[iv]]) {
      nextfag.v.push_back(fag.v[iv]);
      metido = true;
    }
  }
  if (metido) {
    nextfag.s.push_back(1);
    completas(nextfag);
  }
}
void meterlosdefuera(fagocito &fag, fagocito &nextfag, int iv, int k, int i) {
  bool metido = false;
  for (; iv < int(fag.v.size()) and fag.a[iv] == k; iv++) {
    if (m[i][fag.v[iv]] == 0) {
      nextfag.v.push_back(fag.v[iv]);
      metido = true;
    }
  }
  if (metido) {
    nextfag.s.push_back(1);
    completas(nextfag);
  }
}
void incluir(fagocito &fag, int i) {
  int numpartes = fag.a.back();
  if (numpartes == 1) {
    fagocito nextfag;
    meterconjunto0(nextfag, i);
    meterlosdedentro(fag, nextfag, 0, numpartes, i);
    meterlosdefuera(fag, nextfag, 0, numpartes, i);
    nextfag.acumula();
    fag = nextfag;
    return;
  }
  vector<int> cuantos(numpartes + 1, 0);
  for (int j = 0; j < int(fag.v.size()); j++) cuantos[fag.a[j]]++;
  vector<int> inside(numpartes + 1, 0);
  for (int jj = 0; jj < int(fila[i].size()); jj++) {
    int j = fila[i][jj];
    inside[conjunto[j]]++;
  }
  int primero;
  for (int k = 1; k <= numpartes; k++) {
    if (inside[k]) {
      primero = k;
      break;
    }
  }
  int ultimo;
  for (int k = numpartes; k >= 1; k--) {
    if (inside[k]) {
      ultimo = k;
      break;
    }
  }
  for (int k = primero + 1; k < ultimo; k++)
    if (inside[k] < cuantos[k]) morir();
  if (inside[0]) {
    if (primero > 1) {
      if (ultimo < numpartes)
        morir();
      else if (primero < ultimo and inside[ultimo] < cuantos[ultimo])
        morir();
    } else if (ultimo < numpartes) {
      if (primero < ultimo and inside[primero] < cuantos[primero]) morir();
    } else if (primero < ultimo and inside[primero] < cuantos[primero] and
               inside[ultimo] < cuantos[ultimo])
      morir();
  }
  fagocito nextfag;
  if (primero == 1 and
      (primero == ultimo or inside[primero] == cuantos[primero]))
    meterconjunto0(nextfag, i);
  int iv = 0;
  for (int k = 1; k <= numpartes; k++) {
    while (fag.a[iv] < k) iv++;
    if (inside[k] < cuantos[k]) {
      if (inside[0]) {
        if (primero == 1 and
            (primero == ultimo or inside[primero] == cuantos[primero])) {
          meterlosdedentro(fag, nextfag, iv, k, i);
          meterlosdefuera(fag, nextfag, iv, k, i);
        } else {
          meterlosdefuera(fag, nextfag, iv, k, i);
          meterlosdedentro(fag, nextfag, iv, k, i);
        }
      } else if (k == primero) {
        meterlosdefuera(fag, nextfag, iv, k, i);
        meterlosdedentro(fag, nextfag, iv, k, i);
      } else {
        meterlosdedentro(fag, nextfag, iv, k, i);
        meterlosdefuera(fag, nextfag, iv, k, i);
      }
    } else {
      meterlosdedentro(fag, nextfag, iv, k, i);
    }
  }
  if (not(primero == 1 and
          (primero == ultimo or inside[primero] == cuantos[primero])))
    meterconjunto0(nextfag, i);
  nextfag.acumula();
  fag = nextfag;
}
int vistof[1000];
fagocito fagocitar(int i) {
  fagocito fag;
  fag.v = fila[i];
  fag.s.push_back(1);
  completas(fag);
  fag.acumula();
  vistof[i] = 1;
  bool trobat = true;
  while (trobat) {
    trobat = false;
    for (int j = 1; j <= n; j++) conjunto[j] = 0;
    for (int jj = 0; jj < int(fag.v.size()); jj++)
      conjunto[fag.v[jj]] = fag.a[jj];
    for (int ii = 1; ii <= n and not trobat; ii++) {
      if (not vistof[ii]) {
        if (incluido(fag, ii)) {
          if (int(fag.v.size()) == int(fila[ii].size())) vistof[ii] = 1;
        } else if (puede(fag, ii)) {
          vistof[ii] = 1;
          incluir(fag, ii);
          trobat = true;
        }
      }
    }
  }
  return fag;
}
vector<fagocito> vf;
vector<vector<int> > g[1000];
vector<vector<int> > lista[1000];
int vistofag[1000];
bool noesraiz[1000];
int generado[1000];
struct taparece {
  int ivf, ia;
  taparece() {}
  taparece(int inivf, int inia) {
    ivf = inivf;
    ia = inia;
  }
};
bool operator<(taparece a1, taparece a2) {
  int tam1 = int(vf[a1.ivf].v.size());
  int tam2 = int(vf[a2.ivf].v.size());
  int p1 = vf[a1.ivf].a.back();
  int p2 = vf[a2.ivf].a.back();
  return tam1 < tam2 or (tam1 == tam2 and p1 > p2);
}
vector<taparece> aparece[1000];
vector<int> sol;
void genera(int k) {
  if (vistofag[k]) return;
  vistofag[k] = 1;
  for (int d = 0; d < int(lista[k].size()); d++) {
    vector<int> &ar = g[k][d];
    vector<int> &lis = lista[k][d];
    for (int h = 0; h < int(ar.size()); h++) genera(ar[h]);
    for (int jj = 0; jj < int(lis.size()); jj++) {
      int j = lis[jj];
      if (not generado[j]) {
        generado[j] = 1;
        sol.push_back(j);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char car;
      cin >> car;
      m[i][j] = car - '0';
      if (m[i][j]) fila[i].push_back(j);
    }
  }
  for (int j = 1; j <= n; j++) fila[n + 1].push_back(j);
  for (int i = n + 1; i >= 1; i--)
    if (not vistof[i] and int(fila[i].size())) vf.push_back(fagocitar(i));
  for (int k = 0; k < int(vf.size()); k++) {
    fagocito &fag = vf[k];
    g[k] = lista[k] = vector<vector<int> >(fag.a.back() + 1);
    for (int jj = 0; jj < int(fag.v.size()); jj++) {
      int j = fag.v[jj];
      lista[k][fag.a[jj]].push_back(j);
      aparece[j].push_back(taparece(k, fag.a[jj]));
    }
  }
  for (int j = 1; j <= n; j++) {
    vector<taparece> &ap = aparece[j];
    sort(ap.begin(), ap.end());
    for (int kk = 0; kk < int(ap.size()) - 1; kk++)
      for (int kk = 0; kk < int(ap.size()) - 1; kk++) {
        g[ap[kk + 1].ivf][ap[kk + 1].ia].push_back(ap[kk].ivf);
      }
  }
  genera(0);
  for (int jj = 0; jj < int(sol.size()); jj++) {
    int j = sol[jj];
    for (int i = 1; i <= n; i++) mm[i][jj + 1] = m[i][j];
  }
  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) cout << mm[i][j];
    cout << endl;
  }
}
