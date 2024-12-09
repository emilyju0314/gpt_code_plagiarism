#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010], c[100010], n;
bool cmp(int x, int y) { return a[x] > a[y]; }
int main() {
  cin >> n;
  int somaa, somab;
  somaa = somab = 0;
  cerr << "c antes vale:" << endl;
  for (int i = 1; i <= n; i++) c[i] = i, cerr << c[i] << " ";
  cerr << endl;
  for (int i = 1; i <= n; i++) cin >> a[i], somaa += a[i];
  for (int i = 1; i <= n; i++) cin >> b[i], somab += b[i];
  sort(c + 1, c + n + 1, cmp);
  cerr << "c depois:" << endl;
  for (int i = 1; i <= n; i++) cerr << c[i] << " ";
  cerr << endl;
  cout << n / 2 + 1 << endl;
  cout << c[1];
  for (int i = 2; i <= n; i += 2)
    cout << " " << (b[c[i]] >= b[c[i + 1]] ? c[i] : c[i + 1]);
}
