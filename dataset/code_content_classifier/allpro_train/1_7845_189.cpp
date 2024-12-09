#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int contar(string a) {
  int cont = 0;
  for (int i = 0; i < a.length(); i++)
    if (a.at(i) == 'a' || a.at(i) == 'e' || a.at(i) == 'i' || a.at(i) == 'o' ||
        a.at(i) == 'u')
      cont++;
  return cont;
}
int main() {
  string a, b, c;
  getline(cin, a);
  getline(cin, b);
  getline(cin, c);
  if (contar(a) == 5 && contar(b) == 7 && contar(c) == 5)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
