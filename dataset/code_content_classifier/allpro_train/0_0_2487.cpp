#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> p(k);
    for (int i = 0; i < k; i++) {
        cin >> p[i];
    }

    stack<int> s;
    vector<int> a(n), b;
    iota(a.begin(), a.end(), 1);

    int idx = 0;
    for (int i = 0; i < k; i++) {
        if (s.empty() || p[i] > s.top()) {
            while (idx < n && a[idx] != p[i]) {
                s.push(a[idx]);
                idx++;
            }
            if (idx == n || a[idx] != p[i]) {
                cout << -1 << endl;
                return 0;
            }
            b.push_back(p[i]);
            s.pop();
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    
    int counter = n;
    while (!s.empty()) {
        while (idx < n && a[idx] != s.top()) {
            s.push(a[idx]);
            b.push_back(a[idx]);
            idx++;
        }
        if (idx == n || a[idx] != s.top()) {
            cout << -1 << endl;
            return 0;
        }
        b.push_back(s.top());
        s.pop();
    }

    for (int i = 0; i < n; i++) {
        if (find(p.begin(), p.end(), a[i]) == p.end()) {
            b.push_back(a[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}