#include <bits/stdc++.h>
struct nas {
  int blok;
  int where;
};
using namespace std;
vector<int> tim(200001);
vector<nas> mas;
int main() {
  int n;
  cin >> n;
  mas.resize(n);
  mas[0].blok = 0;
  mas[0].where = 1;
  int k = 1;
  for (int i = 1; i <= n; i++) {
    cin >> mas[i].blok;
    if (tim[mas[mas[i].blok].where] == mas[i].blok) {
      mas[i].where = mas[mas[i].blok].where;
      tim[mas[mas[i].blok].where] = i;
    } else {
      k++;
      tim[k] = i;
      mas[tim[k]].where = k;
    }
  }
  cout << k << endl;
}
