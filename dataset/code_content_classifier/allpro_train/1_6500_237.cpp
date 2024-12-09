#include <bits/stdc++.h>
const int MAXN = 2e5 + 5;
using namespace std;
int n, v[MAXN];
vector<int> ans;
string raspuns;
void update(int &i, int &j, bool stanga) {
  if (stanga) {
    ans.push_back(v[i]);
    raspuns.push_back('L');
    i++;
  } else {
    ans.push_back(v[j]);
    raspuns.push_back('R');
    j--;
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> v[i];
  int i = 1, j = n;
  if (n == 1) {
    cout << 1 << "\n"
         << "L";
    return 0;
  }
  if (v[i] < v[j]) {
    ans.push_back(v[i]);
    raspuns.push_back('L');
    i++;
  } else if (v[j] < v[i]) {
    ans.push_back(v[j]);
    raspuns.push_back('R');
    j--;
  }
  while (i <= j) {
    int numar_curent = ans[ans.size() - 1];
    if (v[i] > numar_curent) {
      if (v[j] < v[i] && v[j] > numar_curent)
        update(i, j, false);
      else
        update(i, j, true);
    } else if (v[j] > numar_curent)
      update(i, j, false);
    else if (v[i] < numar_curent && v[j] < numar_curent)
      break;
  }
  cout << raspuns.size() << "\n" << raspuns;
  return 0;
}
