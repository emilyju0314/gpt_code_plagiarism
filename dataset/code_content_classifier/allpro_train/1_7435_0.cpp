#include <string.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
inline void cmin(string &a, const string& b) { if (a > b) a = b; }
inline void cmin(string &a, const string& b, const string& c) {
    if (a.size() == 0) return ;
    if (b.size() && b[0] == '|') return ;
    if (c.size() && c[0] == '|') return ;
    if (a.size() != b.size() + c.size()) {
        a = b+c;
        return ;
    }
    else {
        int y = 0;
        rep (i, b.size()) {
            if (b[i] < a[i]) { y = -1; break; }
            if (b[i] > a[i]) { y = 1; break; }
        }
        if (y == 0) rep (i, c.size()) {
            if (c[i] < a[b.size()+i]) { y = -1; break; }
            if (c[i] > a[b.size()+i]) { y = 1; break; }
        }
        if (y < 0) {
            rep (i, b.size()) a[i] = b[i];
            rep (i, c.size()) a[b.size()+i] = c[i];
        }
    }
}
 
int n, L;
char from[64];
string to[64];
 
int has[32][24];
string dp[32][24], sub[2][24];
int minL[32], maxL[32];
 
string solve() {
    memset(has, 0, sizeof(has));
    rep (i, 32) rep (j, 24) dp[i][j] = '-';
    rep (i, 32) minL[i] = 1<<20;
    rep (i, 32) maxL[i] = -(1<<20);
    rep (LL, L+1) {
        for (;;) {
            bool update = false;
            rep (k, n) {
                int minE = 0, maxE = 0;
                rep (i, to[k].size()) {
                    if (islower(to[k][i])) minE++, maxE++;
                    else {
                        const int t = to[k][i] - 'A';
                        minE += minL[t];
                        maxE += maxL[t];
                    }
                }
                if (LL < minE || maxE < LL) continue;
                int cur = 0, nxt = 1;
                rep (i, 24) sub[cur][i] = '|';
                sub[cur][0] = "";
                rep (i, to[k].size()) {
                    rep (j, 24) sub[nxt][j] = '|';
                    if (islower(to[k][i])) {
                        rep (x, LL) cmin(sub[nxt][x+1], sub[cur][x]+to[k][i]);
                    }
                    else {
                        const int t = to[k][i] - 'A';
                        rep (j, LL+1) if (has[t][j]) rep (x, LL-j+1) {
                            cmin(sub[nxt][x+j], sub[cur][x], dp[t][j]);
                        }
                    }
                    swap(cur, nxt);
                }
                const int f = from[k] - 'A';
                if (sub[cur][LL] != "|") {
                    if (!has[f][LL] || dp[f][LL] > sub[cur][LL]) {
                        minL[f] = min(minL[f], LL);
                        maxL[f] = max(maxL[f], LL);
                        has[f][LL] = true;
                        update = true;
                        dp[f][LL] = sub[cur][LL];
                    }
                }
            }
            if (!update) break;
        }
    }
    return dp['S'-'A'][L];
}

int main() {
    for (;;) {
        cin >> n >> L;
        if (n == 0) return 0;
        string buf;
        rep (i, n) {
            cin >> buf;
            from[i] = buf[0];
            to[i] = buf.substr(2);
        }
        cout << solve() << endl;
    }
}