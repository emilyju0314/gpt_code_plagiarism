#include <bits/stdc++.h>
#define range(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) range(i, 0, a)
using namespace std;

bool dame(string & s) {
    if (s == "") return true;
    int n = stoi(s.c_str());
    if (n < 0 || 255 < n) return true;
    if (n == 0 && s != "0") return true;
    if (n != 0 && s[0] == '0') return true;
    return false;
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    range (i, 1, n) range (j, i + 1, n) range (k, j + 1, n) {
        string a, b, c, d;
        a = b = c = d = "";
        rep (l, i) a += s[l];
        if (dame(a)) continue;
        range (l, i, j) b += s[l];
        if (dame(b)) continue;
        range (l, j, k) c += s[l];
        if (dame(c)) continue;
        range (l, k, n) d += s[l];
        if (dame(d)) continue;
        ans++;
    }
    cout << ans << endl;

    return 0;
}
