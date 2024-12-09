#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> in(n), out(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] != 0) {
      v[i]--;
      out[i]++;
      in[v[i]]++;
    }
  }
  vector<int> loops;
  for (int i = 0; i < n; i++) {
    if (in[i] == 0 && out[i] == 0) {
      loops.push_back(i);
    }
  }
  if (loops.size() == 1) {
    for (int i = 0; i < n; i++) {
      if (loops[0] != i && in[i] == 0) {
        out[loops[0]]++;
        in[i]++;
        v[loops[0]] = i;
        break;
      }
    }
  } else if (loops.size() > 1) {
    for (int i = 0; i < loops.size(); i++) {
      v[loops[i]] = loops[(i + 1) % int(loops.size())];
      out[loops[i]]++;
      in[loops[(i + 1) % int(loops.size())]]++;
    }
  }
  vector<int> inv, outv;
  for (int i = 0; i < n; i++) {
    if (in[i] == 0) {
      inv.push_back(i);
    }
    if (out[i] == 0) {
      outv.push_back(i);
    }
  }
  for (int i = 0; i < outv.size(); i++) {
    v[outv[i]] = inv[i];
  }
  for (int i = 0; i < n; i++) {
    cout << v[i] + 1;
    cout << " ";
  }
  return 0;
}
