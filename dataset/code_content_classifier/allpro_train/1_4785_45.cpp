#include <bits/stdc++.h>
#define maxn 5010
using namespace std;
typedef long long LL;
#define G c = getchar()
inline LL read() {
    LL x = 0, f = 1;
    char G;
    for (; c > 57 || c < 48; G)
        if (c == '-') f = -1;
    for (; c > 47 && c < 58; G) x = x * 10 + c - 48;
    return x * f;
}
struct Poi {
    LL x, y;
    int i;
};
LL dist(Poi a, Poi b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int main() {
    vector<Poi> V;
    int n = read();
    for (int i = 0; i < n; i++) {
        int u = read(), v = read();
        V.push_back({u, v, i + 1});
    }
    auto cur = V[0];
    V.erase(V.begin());
    printf("%d", cur.i);
    for (int _ = 1; _ < n; _++) {
        LL ans = 0, tmp;
        decltype(V.begin()) best;
        for (auto it = V.begin(); it != V.end(); it++) {
            if ((tmp = dist(cur, *it)) > ans) {
                ans = tmp;
                best = it;
            }
        }
        cur = *best;
        V.erase(best);
        printf(" %d", cur.i);
    }
    return 0;
}