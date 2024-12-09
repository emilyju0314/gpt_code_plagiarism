#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, s1;
  vector<int> rpta;
  stack<int> pila;
  while (cin >> s1) s = s + s1;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == '/' && s[i + 2] == 'a') {
      if (!pila.empty()) rpta.push_back(pila.top());
      if (!pila.empty()) pila.pop();
    }
    if (s[i] == 'a' && s[i - 2] != '/') pila.push(0);
    if (s[i] == 'd' && s[i - 2] != '/') {
      int aux = pila.top();
      ++aux;
      pila.pop();
      pila.push(aux);
    }
  }
  sort(rpta.begin(), rpta.end());
  if (rpta.size() == 0) cout << 0;
  for (int i = 0; i < rpta.size(); ++i) cout << rpta[i] << " ";
  cout << endl;
  return 0;
}
