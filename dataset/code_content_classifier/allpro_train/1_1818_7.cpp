#include <bits/stdc++.h>

const int N = 1e2;

int n;
char str[N + 5];

bool check(int x) {
    bool flg = false;
    for (int i = x - 1; str[i] != '.' && i >= 1; i--) {
        if (str[i] == 'B') {
            flg = true;
            break;
        }
    }
    if (!flg) {
        return true;
    }
    for (int i = x + 1; str[i] != '.' && i <= n; i++) {
        if (str[i] == 'B') {
            return false;
        }
    }
    return true;
}
int calc(int x) {
    int ans = 0;
    for (int i = x - 1; str[i] != '.' && i >= 1; i--) {
        if (str[i] == 'W') {
            ans = std::max(ans, x - i - 1);
            break;
        }
    }
    for (int i = x + 1; str[i] != '.' && i <= n; i++) {
        if (str[i] == 'W') {
            ans = std::max(ans, i - x - 1);
            break;
        }
    }
    return ans;
}
int main() {
    scanf("%d %s", &n, str + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (str[i] == '.' && check(i)) {
            ans = std::max(ans, calc(i));
        }
    }
    printf("%d\n", ans);
    return 0;
}
