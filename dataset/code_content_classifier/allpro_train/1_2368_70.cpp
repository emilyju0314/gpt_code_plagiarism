#include <bits/stdc++.h>
using namespace std;
bool activ[100005];
bool chk[100005];
int primecnt[100005];
set<int> s[100005];
vector<int> primes[100005];
vector<int> v;
void pre() {
  int t = (int)(sqrt(100000));
  for (int i = 2; i <= t; i++) {
    if (!chk[i]) {
      for (int j = 2 * i; j <= 100000; j += i) {
        chk[j] = true;
      }
    }
  }
  for (int i = 2; i <= 100000; i++)
    if (!chk[i]) v.push_back(i);
  for (int i = 0; i < (int)(v.size()); i++) {
    for (int j = v[i]; j <= 100000; j += v[i]) {
      primes[j].push_back(v[i]);
    }
  }
  return;
}
int main() {
  pre();
  int n, m, x;
  string p;
  cin >> n >> m;
  while (m--) {
    cin >> p >> x;
    if (p == "+") {
      if (activ[x])
        cout << "Already on" << endl;
      else {
        for (int i = 0; i < primes[x].size(); i++) {
          if (primecnt[primes[x][i]] > 0) {
            cout << "Conflict with " << *(s[primes[x][i]].begin()) << endl;
            goto p;
          }
        }
        cout << "Success" << endl;
        activ[x] = true;
        for (int i = 0; i < primes[x].size(); i++) {
          primecnt[primes[x][i]]++;
          s[primes[x][i]].insert(x);
        }
      p : {}
      }
    } else {
      if (!activ[x])
        cout << "Already off" << endl;
      else {
        cout << "Success" << endl;
        activ[x] = false;
        for (int i = 0; i < primes[x].size(); i++) {
          primecnt[primes[x][i]]--;
          s[primes[x][i]].erase(s[primes[x][i]].find(x));
        }
      }
    }
  }
  return 0;
}
