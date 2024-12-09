#include <bits/stdc++.h>
using namespace std;
#define N 20
typedef long long LL;
const int mod = 1e9 + 7; int Pow2[N * N], from[N * N], to[N * N], cnt[1 << 16];
int f[2][1 << 16], n, m;
inline bool check(int s, int i) {return s & (1 << i - 1);}
inline int count(int s) {
    int res = 0, tmp = s;
    while (s) res++, s = (s - 1) & tmp;
    return res;
}
inline void calc(int i) {
    for (int s = 1; s < 1 << n;s++) if (check(s, i)) {
        int &sum = f[i - 1][s]; sum = Pow2[cnt[s]];
        for (int ss = s - 1;ss;ss = (ss - 1) & s) if (check(ss, i)) {
            int sgn = count(s - ss) & 1 ? mod - 1 : 1;
            sum = (sum + (LL)sgn * Pow2[cnt[s - ss]] % mod * f[i - 1][ss]) % mod;
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1;i <= m;i++) scanf("%d%d", &from[i], &to[i]);
    Pow2[0] = 1;
    for (int i = 1;i <= m;i++) Pow2[i] = Pow2[i - 1] * 2 % mod;
    for (int i = 0;i < 1 << n;i++)
        for (int j = 1;j <= m;j++)
            if (check(i, from[j]) && check(i, to[j]))
                cnt[i]++;
    // for (int i = 0;i < 1 << n;i++) cout << i << ' ' << cnt[i] << endl;
    calc(1), calc(2);
    int res = 0;
    for (int s = 1;s < 1 << n;s++) if (check(s, 1)) {
        int tmp = ((1 << n) - 1) - s;
        // cout << s << ' ' << tmp << endl;
        for (int ss = tmp;ss;ss = (ss - 1) & tmp) if (check(ss, 2)) {
            if (cnt[s] + cnt[ss] != cnt[s + ss]) continue;
            // cout << s << ' ' << ss << endl;
            res = (res + (LL)f[0][s] * f[1][ss] % mod * Pow2[cnt[tmp - ss]]) % mod;
        }
    }
    printf("%d\n", (Pow2[m] - res + mod) % mod);
    return 0;
}