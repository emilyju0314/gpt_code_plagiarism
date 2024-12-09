#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
 
    if (m == 1)
       return 0;
 
    while (a > 1) {
        q = a / m;
 
        t = m;
 
        m = a % m, a = t;
        t = x0;
 
        x0 = x1 - q * x0;
        x1 = t;
    }
 
    if (x1 < 0)
       x1 += m0;
 
    return x1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, rb, cb, rd, cd, p;
        cin >> n >> m >> rb >> cb >> rd >> cd >> p;

        int dr = rd - rb;
        if (dr < 0) dr = -dr;
        int dc = cd - cb;
        if (dc < 0) dc = -dc;

        int prob = 100 - p;
        int inv_prob = modInverse(prob, MOD);

        int answer = (inv_prob * ((dr + dc) % MOD)) % MOD;

        cout << answer << endl;
    }

    return 0;
}