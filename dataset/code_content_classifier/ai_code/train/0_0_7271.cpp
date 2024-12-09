#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int multiply(int a, int b) {
    return (long long) a * b % mod;
}

int add(int a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) {
        a += mod;
    }
    return a;
}

int power(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b % 2 == 0) {
            a = multiply(a, a);
            b /= 2;
        } else {
            res = multiply(res, a);
            b--;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adjT(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adjT[a].push_back(b);
        adjT[b].push_back(a);
    }

    vector<vector<int>> adjU(n + 1);
    for (int i = 1; i < n; i++) {
        int c, d;
        cin >> c >> d;
        adjU[c].push_back(d);
        adjU[d].push_back(c);
    }

    int P = 0;
    for (int i = 1; i <= n; i++) {
        int szT = adjT[i].size();
        int szU = adjU[i].size();
        P = add(P, szT + szU);
    }

    int Q = power(2, n);

    int invQ = power(Q, mod - 2);

    int ans = multiply(P, invQ);

    cout << ans << endl;

    return 0;
}