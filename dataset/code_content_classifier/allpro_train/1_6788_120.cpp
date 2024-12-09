#include <bits/stdc++.h>
using namespace std;
void affiche(int t[], int n) {
  for (int i = 0; i < n; i++) cout << t[i] << " ";
  cout << '\n';
}
void afficheV(vector<int> t) {
  for (int i = 0; i < t.size(); i++) cout << t[i] << " ";
  cout << '\n';
}
int n, x, q, type;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  int t[n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> x;
      if (i == j) t[i] = x;
    }
  cin >> q;
  while (q--) {
    cin >> type;
    if (type == 3)
      cout << accumulate(t, t + n, 0) % 2;
    else {
      cin >> x;
      t[x - 1] = 1 - t[x - 1];
    }
  }
}
