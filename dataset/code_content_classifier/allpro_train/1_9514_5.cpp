#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

const int N = 1e6 + 10;
int pre[N], n, sub[N];
char s[N], t[N];

bool chkpre(int x) {
    return x % (x - pre[x]) > 0 || !pre[x];
}

bool chksub(int x) {
    return x % (x - sub[x]) > 0 || !sub[x];
}

void getfail(char *s, int *nxt) {
    nxt[0] = nxt[1] = 0;
    int j = 0;
    rep(i, 1, n - 1) {
        while(j && s[i] != s[j]) j = nxt[j];
        nxt[i + 1] = (s[i] == s[j] ? ++j : 0);
    }
}

int main() {
    scanf("%s", s);
    n = strlen(s);
    rep(i, 0, n - 1) t[i] = s[n - i - 1];
    t[n] = '\0';

    getfail(s, pre), getfail(t, sub);
    
    int flag = chkpre(n) ? 1 : 2;
    bool f = 1;
    // rep(i, 1, n - 1) if (s[i] != s[i - 1]) { f = 0; break; }
    // if (f) flag = n;
    if (n - pre[n] == 1) flag = n;
    printf("%d\n", flag);
    if (flag != 2) { puts("1"); return 0; }

    int ans = 0;
    rep(i, 0, n - 1) {
        int x = n - i - 1;
        if (chkpre(i + 1) && chksub(x)) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
