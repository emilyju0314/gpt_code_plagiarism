#include <bits/stdc++.h>
using namespace std;
int main () {
    map<char, int> m;
    char c;
    while (cin >> c) m[c]++;
    cout << 700 + 100*(m['o']) << endl;
}