#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a, b;
map<int, int> p;

int group(int a) {
    if (p.find(a) == p.end() || p[a] == a) {
        return p[a] = a;
    }
    return p[a] = group(p[a]);
}

void merge(int a, int b) {
    a = group(a);
    b = group(b);
    p[a] = b;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    a = b = vector<int>(n+1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[n] ^= a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[n] ^= b[i];
    }
    n++;

    if (multiset<int>(a.begin(), a.end()) != multiset<int>(b.begin(), b.end())) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        ans += (a[i] != b[i]);
    }
    if (ans == 0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (i < n-1 && a[i] == b[i]) continue;
        merge(a[i], b[i]);
    }

    for (map<int, int>::iterator it = p.begin(); it != p.end(); it++) {
        int u = it->first;
        if (u == group(u)) ans++;
    }
    ans--;
    cout << ans << endl;
    return 0;
}