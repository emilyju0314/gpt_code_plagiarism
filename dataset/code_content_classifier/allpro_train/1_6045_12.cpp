#include <stdio.h>
int m, n, a[100];
bool check(int x) {
    int pos = 0, r = 0;
    for(int i = 0; i < m; i++) {
        while(pos != n && r + a[pos] <= x) r += a[pos++];
        if(pos == n) return true; r = 0;
    }
    return false;
}
int main() {
    while(scanf("%d%d", &m, &n), n) {
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        int l = 0, r = 1000000000;
        while(r - l > 1) {
            int m = (l + r) / 2;
            if(check(m)) r = m;
            else l = m;
        }
        printf("%d\n", r);
    }
}