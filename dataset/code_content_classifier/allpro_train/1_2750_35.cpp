#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000010;

int n, m, K, X[maxn<<1], Y[maxn<<1], sta[maxn<<1], top;
char buf[maxn];

void print(int *a) {
    int ok = 0;
    for (int i = 2000000; i >= 1; i--) {
        if (a[i]) ok = 1;
        if (ok) printf("%d", a[i]);
    }
    puts("");
}

int main() {
    scanf("%d%d%d", &n, &m, &K);
    scanf("%s", buf+1); for (int i = 1; i <= n; i++) X[n-i+1] = (buf[i] == '1');
    scanf("%s", buf+1); for (int i = 1; i <= m; i++) Y[m-i+1] = (buf[i] == '1');
    sta[++ top] = 0x3f3f3f3f;
    for (int i = max(n, m); i >= 1; i--) {
        if (X[i] && Y[i]) {
            X[i] = Y[i] = 0;
            int k = K, cur_p = i;
            stack<int> st; // cur_p 经过的 0 1
            while (cur_p && cur_p + k >= sta[top]) {
                int c = sta[top] - cur_p;
                cur_p = sta[top];
                k -= c;
                -- top;
                int add = 1, ty = 0;
                if (X[cur_p]) {
                    X[cur_p] = 0;
                    Y[cur_p] = 1;
                    ty = 1;
                } else {
                    X[cur_p] = 1;
                    Y[cur_p] = 0;
                    ty = 2;
                }
                st.push(cur_p);
                while (add) {
                    ++ cur_p;
                    if (X[cur_p] || Y[cur_p]) {
                        // 不会同时为 1
                        -- top;
                        if (X[cur_p]) {
                            if (ty == 1) {
                                add = 1;
                                X[cur_p] = 0;
                            } else {
                                add = 0;
                                X[cur_p] = 0;
                                // Y[cur_p] = 1;
                            }
                        } else {
                            if (ty == 2) {
                                add = 1;
                                Y[cur_p] = 0;
                            } else {
                                add = 0;
                                Y[cur_p] = 0;
                                // X[cur_p] = 1;
                            }
                        }
                    } else {
                        add = 0;
                        if (ty == 1) X[cur_p] = 1;
                        else Y[cur_p] = 1;
                        st.push(cur_p);
                        cur_p = 0;
                    }
                }
            }
            while (!st.empty()) {sta[++top] = st.top(); st.pop();}
            if (cur_p) {
                X[cur_p+k] = Y[cur_p+k] = 1;
            }
        } else if (X[i] || Y[i]) sta[++ top] = i;
    }
    print(X);
    print(Y);
    return 0;
}