#include <bits/stdc++.h>
using namespace std;
struct nodo {
  int pudo, sobro, falto;
} m, res;
char A[1000005];
int izq, der, uso, ctos = 1, pregs, saca;
nodo T[2097160];
void crea(int x, int y, int dnde) {
  if (x == y) {
    m.pudo = 0;
    m.falto = 0;
    m.sobro = 0;
    if (A[x] == '(') {
      m.sobro = 1;
      T[dnde] = m;
      m.sobro = 0;
    } else {
      m.falto = 1;
      T[dnde] = m;
    }
    return;
  }
  crea(x, (x + y) / 2, dnde * 2);
  crea((x + y) / 2 + 1, y, dnde * 2 + 1);
  uso = min(T[dnde * 2 + 1].falto, T[dnde * 2].sobro);
  m.pudo = T[dnde * 2].pudo + T[dnde * 2 + 1].pudo + uso * 2;
  m.sobro = T[dnde * 2].sobro - uso + T[dnde * 2 + 1].sobro;
  m.falto = T[dnde * 2].falto + T[dnde * 2 + 1].falto - uso;
  T[dnde] = m;
}
void query(int x, int y, int dnde) {
  if (x >= izq and y <= der) {
    uso = min(T[dnde].falto, res.sobro);
    res.pudo = res.pudo + T[dnde].pudo + uso * 2;
    res.sobro = res.sobro - uso + T[dnde].sobro;
    res.falto = res.falto + T[dnde].falto - uso;
    return;
  }
  int mid = (x + y) / 2;
  if (izq <= mid and der >= x) query(x, mid, dnde * 2);
  if (izq <= y and der > mid) query(mid + 1, y, dnde * 2 + 1);
}
int main() {
  scanf("%s", A + 1);
  while (A[ctos] != '\0' and A[ctos] != '\n') ++ctos;
  --ctos;
  crea(1, ctos, 1);
  scanf("%d", &pregs);
  while (pregs--) {
    scanf("%d%d", &izq, &der);
    res.pudo = 0;
    res.falto = 0;
    res.sobro = 0;
    query(1, ctos, 1);
    saca = res.pudo;
    printf("%d\n", saca);
  }
  return 0;
}
